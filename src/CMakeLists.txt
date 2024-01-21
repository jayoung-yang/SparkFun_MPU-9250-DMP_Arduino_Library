cmake_minimum_required(VERSION 3.10)
project(arduino_mpu9250)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(arduino_mpu9250 
	main.cpp
	SparkFunMPU9250-DMP.cpp
	util/arduino_mpu9250_clk.c
	util/arduino_mpu9250_i2c.cpp
	util/arduino_mpu9250_log.cpp
	util/inv_mpu_dmp_motion_driver.c
	util/inv_mpu.c
)	

target_link_libraries(arduino_mpu9250 pigpio)
