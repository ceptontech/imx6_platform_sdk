/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*
 * @file camera_def.h
 * @brief common macro and data structre defination of camera.
 * @ingroup diag_camera
 */

#ifndef __CAMERA_DEF_H__
#define __CAMERA_DEF_H__

#include "i2c/imx_i2c.h"
#include "hardware.h"

//! @addtogroup diag_camera

//! @{

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

//! @brief The common structure for accessing camera sensor I2C interface.
//!
//! @a address is a 16-bit sensor register address.
//! @a value can be both 16-bit or 8-bit, it is determined by @a is_16bits.
typedef struct {
    uint16_t addr;			//!< Sensor register address.
    uint16_t value;			//!< Data along with the register address.
    uint16_t is_16bits;		//!< If the @a value is a 16bit or 8bit
    uint32_t delay_ms;		//!< Time delay needed after setting regiter
    uint8_t verify;			//!< If need to verify the set operation is correctly
} reg_param_t;

//! @brief The register setting information for specific camera mode
//!
//! When the camera need to work at specific mode, a serie of regiter settings are need to be downloaded to sensor.
//
//!	The register setting should be hold in array.
//
//! @a setting is the start address of the register setting array.
//! @a size if the size of the register setting array.
typedef struct {
    reg_param_t *setting;	//!< Pointer to register setting array
    int32_t size;			//!< Size of register setting array
} camera_mode_t;

//! @brief The available informations for the some type of sensor.
//!
//! The information include sensor name, voltage, i2c device address, and several setting arrays: detection mode, capture mode, auto focus mode, trigger mode.
//!
//! There are 3 voltages needed by sensor: avdd, dovdd and dvdd. They might be used when power up.
//! @a i2c_dev_addr is in lower 7 bits
typedef struct {
    int8_t sensor_name[30];			//!< Char array holds sensor name
    uint32_t avdd_mv;				//!< Power for I/O circuit
	uint32_t dovdd_mv;				//!< Power for digital circuit
	uint32_t dvdd_mv;				//!< Power for analog circuit
    int32_t i2c_dev_addr;			//!< Sensor slave address (in lower 7 bits)
    reg_param_t *sensor_detection;	//!< Pointer to register setting array which holds sensor detection mode
    int32_t sensor_detection_size;	//!< Size of sensor detection mode array
    int32_t mode_id;				//!< Working mode id for this sensor
    camera_mode_t *modes;			//!< Pointer to the register setting array which holds sensor capture mode
    int32_t auto_focus_enable;		//!< To specify if the auto focus function is enable for this sensor
    reg_param_t *af_firmware;		//!< Pointer to the register setting array which holds sensor auto focus mode
    int32_t af_firmware_size;		//!< Size of sensor auto focus mode array
    reg_param_t *af_trigger;		//!< Pointer to the register setting array which holds sensor trigger mode
    int32_t af_trigger_size;		//!< Size of sensor trigger mode
    reg_param_t *af_ready;			//!< Pointer to the register setting array which holds sensor auto focus ready mode
    int32_t af_ready_size;			//!< size of sensor auto focus reaady mode.
} camera_profile_t;


//! @brief Sensor capture mode id
//!
//! The mode id is corresponding to index of @a camera_mode array.
enum {
    OV3640_MODE_VGA_640_480_30FPS = 0,
    OV5640_MODE_VGA_640_480_30FPS,
    OV5642_MODE_VGA_640_480_30FPS,
    MT9P111_MODE_VGA_640_480_30FPS,
    CAMERA_MODE_NUM
};

//! @brief Sensor id
//!
//! The sensor id is corresponding to index of @a camera_profiles.
//! It can be used to search inside camera profiles for specific sensor.
enum {
    OV3640 = 0,
    OV5640,
    OV5642,
    MT9P111,
    SENSOR_NUM
};


extern camera_mode_t camera_modes[CAMERA_MODE_NUM];
extern camera_profile_t camera_profiles[SENSOR_NUM];

extern reg_param_t ov3640_sensor_detection[];
extern reg_param_t ov5640_sensor_detection[];
extern reg_param_t ov5642_sensor_detection[];
extern reg_param_t mt9p111_sensor_detection[];
extern reg_param_t ov3640_mode_vga_640_480_30fps[];
extern reg_param_t ov5640_mode_vga_640_480_30fps[];
extern reg_param_t ov5642_mode_vga_640_480_30fps[];
extern reg_param_t ov5642_af_firmware[];
extern reg_param_t ov5642_af_trigger[];
extern reg_param_t ov5642_af_ready[];
extern reg_param_t mt9p111_mode_vga_640_480_30fps[];
extern reg_param_t mt9p111_af_firmware[];
extern reg_param_t mt9p111_af_trigger[];
extern reg_param_t mt9p111_af_ready[];

//! @brief The I2C port number to which the camera is connected.
//!
//! This global must be provided by the board library or application.
extern uint8_t g_camera_i2c_port;

/*!
 * @brief Perform sensor reset operation
 *
 * Reset camera sensor through GPIO according to the timing specified by datasheet
 *
 */
void sensor_reset(void);

/*!
 * @brief Perform sensor standy operation
 *
 * When @enable equals 1, it initiates hardware standy mode
 * Before entering work mode, make sure call this function with @enable 0.
 *
 * @param	enable parameter controlis if initiate a hardware standby mode or normal work mode. 1 for standby mode, 0 for normal work mode.
 */
void sensor_standby(int32_t enable);

/*!
 * @brief Set sensor input clock
 *
 * Sensor input clock comes from IPU. A typical camera sensor clock is 24MHz. 
 *
 */
void sensor_clock_setting(void);

/*!
 * @brief Search which camera sensor is pluged in
 *
 * It searches in the available camera_profiles.
 *
 * @return Pointer to the sensor profile information when matched sensor is found. NULL is no valid sensor is found.
 */
camera_profile_t *sensor_search(void);

/*!
 * @brief Configure csi port and initialize camera sensor
 *
 * @param	sensor: sensor profile information
 *
 * @return 0 on success; non-zero otherwise
 *
 */
int32_t sensor_config(camera_profile_t * sensor);


/*!
 * @brief Initialize camera sensor according to sensor profile
 *
 * @param	sensor: sensor profile information
 *
 * @return 0 on success; non-zero otherwise
 */
int32_t sensor_init(camera_profile_t * sensor);

/*!
 * @brief configure camera sensor to af trigger mode
 *
 * @param	sensor: sensor profile information
 *
 * @return 0 on success; non-zero otherwise
 *
 */
int32_t sensor_af_trigger(camera_profile_t * sensor);

/*!
 * @brief configure camera sensor to auto focus mode
 *
 * @param	sensor: sensor profile information
 *
 * @return 0 on success; non-zero otherwise
 */
int32_t sensor_autofocus_init(camera_profile_t * sensor);

//! @}
#endif
