/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "pwm/pwm_ifc.h"
#include "interrupt.h"
#include "iomux_config.h"
#include "registers/regspwm.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! Number of sample FIFO entries.
#define PWM_CNT_FIFO_SZ       (4)

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

int pwm_init(struct hw_module *port, uint16_t prescale, uint16_t period,
             uint16_t * sample, uint32_t smp_cnt)
{
    int idx;

    // Configure pins.
    pwm_iomux_config(port->instance);

    // Disable PWM first 
    HW_PWM_PWMCR(port->instance).B.EN = 0;

    // Verify and set clock source 
    if ((port->freq < kPwmClockSourceIpg) || (port->freq > kPwmClockSourceCkil))
    {
#if DEBUG
        printf("Invalid clock source selection.\n");
        return FALSE;
#endif
    }

    HW_PWM_PWMCR(port->instance).B.CLKSRC = port->freq;

    // Set FIFO watermark to 4 empty slots 
    HW_PWM_PWMCR(port->instance).B.FWM = 3;

    // Set prescale after checking its range.
    if (prescale >= (BM_PWM_PWMCR_PRESCALER >> BP_PWM_PWMCR_PRESCALER))
    {
#if DEBUG
        printf("Invalid prescaler value.\n");
#endif
        return FALSE;
    }

    HW_PWM_PWMCR(port->instance).B.PRESCALER = prescale;

    // Set period 
    HW_PWM_PWMPR(port->instance).B.PERIOD = period;

    // Write count to FIFO 
    if ((smp_cnt > PWM_CNT_FIFO_SZ) || (smp_cnt < 1))
    {
#if DEBUG
        printf("Invalid number of samples.\n");
#endif
        return FALSE;
    }

    for (idx = 0; idx < smp_cnt; idx++)
    {
        HW_PWM_PWMSAR(port->instance).B.SAMPLE = sample[idx];
    }

    return TRUE;
}

void pwm_clear_int_status(struct hw_module *port, uint32_t mask)
{
    // Convert mask from abstract constants to register bitmasks.
    uint32_t convertedMask = 0;
    if (mask & kPwmFifoEmptyIrq)
    {
        convertedMask |= BM_PWM_PWMSR_FE;
    }
    if (mask & kPwmRolloverIrq)
    {
        convertedMask |= BM_PWM_PWMSR_ROV;
    }
    if (mask & kPwmCompareIrq)
    {
        convertedMask |= BM_PWM_PWMSR_CMP;
    }

    // Clear status bits by writing 1s.
    HW_PWM_PWMSR_WR(port->instance, convertedMask);
}

void pwm_setup_interrupt(struct hw_module *port, bool state, uint8_t mask)
{
    if (state)
    {
        // Disable the IRQ first 
        disable_interrupt(port->irq_id, CPU_0);

        // Clear status register 
        HW_PWM_PWMSR_WR(port->instance, BM_PWM_PWMSR_FE | BM_PWM_PWMSR_ROV | BM_PWM_PWMSR_CMP | BM_PWM_PWMSR_FWE);

        // Register the IRQ sub-routine 
        register_interrupt_routine(port->irq_id, port->irq_subroutine);

        // Enable the IRQ at ARM core level 
        enable_interrupt(port->irq_id, CPU_0, 0);

        // Enable interrupt to status 
        HW_PWM_PWMIR(port->instance).B.FIE = ((mask & kPwmFifoEmptyIrq) != 0);
        HW_PWM_PWMIR(port->instance).B.RIE = ((mask & kPwmRolloverIrq) != 0);
        HW_PWM_PWMIR(port->instance).B.CIE = ((mask & kPwmCompareIrq) != 0);
    }
    else
    {
        // Disable the IRQ at ARM core level 
        disable_interrupt(port->irq_id, CPU_0);

        // Clear all interrupt enables.
        HW_PWM_PWMIR_WR(port->instance, 0);
    }
}

void pwm_enable(struct hw_module *port)
{
    HW_PWM_PWMCR(port->instance).B.EN = 1;
}

void pwm_disable(struct hw_module *port)
{
    HW_PWM_PWMCR(port->instance).B.EN = 0;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
