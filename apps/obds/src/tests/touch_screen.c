/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//#include "imx_i2c.h"
#include "obds.h"
#include "hardware.h"
#include "io.h"
#include <stdio.h>

#define PMIC_DA9053_I2C_NUM                  0  // Which I2C used to interface with the PMIC; 0=I2C1, 1=I2C2
#define PMIC_DA9053_I2C_ADDR                (0x90>>1)   // PMIC I2C Slave address
#define PMIC_DA9053_I2C_REG_BYTE         0x1    // Number of Bytes to transfer the PMIC reg number
#define PMIC_DA9053_I2C_DATA_BYTE      0x1  // Number of Bytes to transfer the PMIC reg data
#define PMIC_DA9053_I2C_BASE       		I2C1_BASE_ADDR  // pmic on i2c1
#define PMIC_DA9053_I2C_ID         		0x90

#define  DA9053_IRQ_MASK_A		10
#define  DA9053_IRQ_MASK_B  	11
#define  DA9053_IRQ_MASK_C		12
#define  DA9053_IRQ_MASK_D  	13

#define DA9053_EVENT_B  		0x06

#define DA9053_TSI_CONT_A 		105
#define DA9053_TSI_CONT_B 		106
#define DA9053_TSI_X_MSB 		107
#define DA9053_TSI_Y_MSB 		108
#define DA9053_TSI_XY_LSB		109
#define DA9053_TSI_Z_MSB		110

#define DA9053_LDO8       			57
#define DA9053_ADC_MAN		81

#define TSI_CONT_A_PEN_DETECT 		(0x01<<1)
#define TSI_CONT_A_AUTO_TSI_EN      0x01

#define EVENT_B_E_PEN_DOWN		(0x01<<6)
#define EVENT_B_E_TSI_READY		(0x01<<7)

#define TSI_CONT_B_TSI_MAN			(0x01<<6)

bool pen_status[2] = { false, false };

void DA9053_Write(unsigned char val, unsigned int reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[4];

    buf[0] = val;

    rq.ctl_addr = PMIC_DA9053_I2C_BASE;
    rq.dev_addr = PMIC_DA9053_I2C_ADDR;
    rq.reg_addr_sz = PMIC_DA9053_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_DA9053_I2C_DATA_BYTE;
    rq.buffer = buf;
    rq.reg_addr = reg_addr;

    i2c_xfer(&rq, I2C_WRITE);
//    i2c_xfer(PMIC_DA9053_I2C_BASE, &rq, I2C_WRITE);
}

unsigned char DA9053_Read(unsigned int reg_addr)
{
    struct imx_i2c_request rq;
    unsigned char buf[4];

    rq.ctl_addr = PMIC_DA9053_I2C_BASE;
    rq.dev_addr = PMIC_DA9053_I2C_ADDR;
    rq.reg_addr_sz = PMIC_DA9053_I2C_REG_BYTE;
    rq.buffer_sz = PMIC_DA9053_I2C_DATA_BYTE;
    rq.buffer = buf;
    rq.reg_addr = reg_addr;

    i2c_xfer(&rq, I2C_READ);
//    i2c_xfer(PMIC_DA9053_I2C_BASE, &rq, I2C_READ);

    return buf[0];
}

void touch_init(void)
{
    i2c_init(I2C1_BASE_ADDR, 170000);

    //Clear the event bit.
    DA9053_Write(0xFF, DA9053_EVENT_B);

    //Disable the interrupt
    DA9053_Write(0xFF, DA9053_IRQ_MASK_B);

    //Enable LDO8 at 1.8V output
    DA9053_Write(0x4C, DA9053_LDO8);

    //4slot delay, 5 slot skip,enable pen detect
    DA9053_Write(0xD2, DA9053_TSI_CONT_A);

    DA9053_Write(0x00, DA9053_TSI_CONT_B);

    //select tsi as adc7's input
    DA9053_Write(0x07, DA9053_ADC_MAN);
}

unsigned int touch_get_xy_value(unsigned int *x, unsigned int *y)
{
    unsigned int Xmsb = 0, Ymsb = 0, XYlsb = 0;;
    unsigned char val = 0;

    //Clear the event bit
    DA9053_Write(0xFF, DA9053_EVENT_B);

    //enable auto_tsi_en
    val = DA9053_Read(DA9053_TSI_CONT_A);
    val |= TSI_CONT_A_AUTO_TSI_EN;
    DA9053_Write(val, DA9053_TSI_CONT_A);

    //wait until tsi is ready
    do {
        val = DA9053_Read(DA9053_EVENT_B);
        hal_delay_us(1000);
    } while (!(val & EVENT_B_E_TSI_READY));

    //disable auto_tsi_en
    val = DA9053_Read(DA9053_TSI_CONT_A);
    val &= ~TSI_CONT_A_AUTO_TSI_EN;
    DA9053_Write(val, DA9053_TSI_CONT_A);

    Xmsb = DA9053_Read(DA9053_TSI_X_MSB);
    Ymsb = DA9053_Read(DA9053_TSI_Y_MSB);
    XYlsb = DA9053_Read(DA9053_TSI_XY_LSB);

    //Clear the event bit
    DA9053_Write(0xFF, DA9053_EVENT_B);

    *x = (Xmsb << 2) + (XYlsb & 0x03);
    *y = (Ymsb << 2) + ((XYlsb << 2) & 0x03);

    return 0;
}

int touch_detect(int timeout)
{
    unsigned char val = 0;

    //Enable pen detect
    val = DA9053_Read(DA9053_TSI_CONT_A);
    val |= TSI_CONT_A_PEN_DETECT;
    DA9053_Write(val, DA9053_TSI_CONT_A);

    DA9053_Write(0xFF, DA9053_EVENT_B);
    while (timeout >= 0) {
        hal_delay_us(1000);
        pen_status[0] = pen_status[1];
        val = DA9053_Read(DA9053_EVENT_B);
        if (val & EVENT_B_E_PEN_DOWN) {
            DA9053_Write(0xFF, DA9053_EVENT_B);
            pen_status[1] = 1;
            return 0;           // get touched
        } else {
            timeout--;
            pen_status[1] = 0;
        }
    }
    return -1;
}

int touch_screen_prompt(void)
{
    unsigned char recvCh = 0;

    printf("\tQuit touch screen test? y=pass&quit, n=fail&quit, others=try again\n");

    do {
        recvCh = getchar();
//        recvCh = receive_char();
    } while (recvCh == NONE_CHAR);
    printf("%c\n", recvCh);

    if (('y' == recvCh) || ('Y' == recvCh))
        return 0;               //pass
    else if (('n' == recvCh) || ('N' == recvCh))
        return 1;               //fail
    else
        return 3;               //try again
}

int touch_screen_test_enable;
int touch_screen_test(void)
{
    int ret = 3, event;
    unsigned int x = 0, y = 0;

    if (!touch_screen_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("TOUCH SCREEN");

    printf("Touch screen test. Press the screen and you'll get the coordinate. \n");
    printf("To exit test, just left the screen un-touched for a while. \n");

    touch_init();

    while (1) {
        event = touch_detect(0x200);    //detect pen_down event

        if (0 == event)         //pen_down
        {
            if ((0 == pen_status[0]) && (1 == pen_status[1])) {
                //read coordinate
                touch_get_xy_value(&x, &y);
                printf("\tCoordinate: (%4d, %4d)\n", x, y);
            }
            ret = 3;
        } else                  //timeout
            ret = touch_screen_prompt();
        if (3 == ret)
            continue;
        else
            break;
    }

    return ret;
}

//RUN_TEST_INTERACTIVE("TOUCH SCREEN", touch_screen_test)