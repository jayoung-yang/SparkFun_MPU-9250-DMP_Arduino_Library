/******************************************************************************
arduino_mpu9250_i2c.cpp - MPU-9250 Digital Motion Processor Arduino Library 
Jim Lindblom @ SparkFun Electronics
original creation date: November 23, 2016
https://github.com/sparkfun/SparkFun_MPU9250_DMP_Arduino_Library

This library implements motion processing functions of Invensense's MPU-9250.
It is based on their Emedded MotionDriver 6.12 library.
	https://www.invensense.com/developers/software-downloads/

Development environment specifics:
Arduino IDE 1.6.12
SparkFun 9DoF Razor IMU M0

Supported Platforms:
- ATSAMD21 (Arduino Zero, SparkFun SAMD21 Breakouts)
******************************************************************************/
#include "arduino_mpu9250_i2c.h"
#include <pigpio.h>

#define I2C_DEVICE 1
#define I2C_DEVICE_ADDR 0x68
#define I2C_FLAGS 0

int arduino_i2c_open(int *i2c_handle)
{
	*i2c_handle = i2cOpen(I2C_DEVICE, I2C_DEVICE_ADDR, I2C_FLAGS);

	return 0;
}

int arduino_i2c_write(int i2c_handle, unsigned char reg_addr,
                       unsigned char length, char * data)
{
	i2cWriteI2CBlockData(i2c_handle, reg_addr, data, length);
	
	return 0;
}

int arduino_i2c_read(int i2c_handle, unsigned char reg_addr,
                       unsigned char length, char * data)
{
	i2cReadI2CBlockData(i2c_handle, reg_addr, data, length);
	
	return 0;
}
