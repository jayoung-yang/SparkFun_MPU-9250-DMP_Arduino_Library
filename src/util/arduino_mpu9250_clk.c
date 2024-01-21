/******************************************************************************
arduino_mpu9250_clk.c - MPU-9250 Digital Motion Processor Arduino Library 
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
#include "arduino_mpu9250_clk.h"

#include <unistd.h>
#include <time.h>

int arduino_get_clock_ms(unsigned long *count)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    *count = (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
	return 0;
}

int arduino_delay_ms(unsigned long num_ms)
{
	usleep(num_ms * 1000);
	return 0;
}