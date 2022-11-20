#include <iostream>
#include <stdint.h>
#include <unistd.h>				
#include <fcntl.h>				
#include <sys/ioctl.h>	
// https://www.kernel.org/doc/Documentation/i2c/dev-interface 
extern "C" {
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
}
#include <stdio.h>
#include "../include/I2CDevice.h"

// Public //

I2CDevice::I2CDevice(const int slaveAddr) : slaveAddress(slaveAddr) {

    I2CBus bus;
    deviceFilenum = bus.openI2CBus();
    std::cout << "I2C Bus:" << deviceFilenum << "\n";

    if (ioctl(deviceFilenum, I2C_SLAVE, slaveAddress) < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
    	std::cout << "Bad ioctl to slave:" << slaveAddress << "\n";
        perror("error");
    } else {
        std::cout << "Successfully addressed device\n";
    }

}

// Protected //

uint8_t I2CDevice::readRegister(uint16_t regAddress) {
    uint8_t buf = 0;
    buf = i2c_smbus_read_byte_data(deviceFilenum, regAddress);
    return buf;
}

uint8_t I2CDevice::writeRegister(uint16_t regAddress, uint8_t val) {
    uint8_t buf = 0;
    buf = i2c_smbus_write_byte_data(deviceFilenum, regAddress, val);
    return buf;
}

// Private //

