#ifndef _I2CDEVICE_H
#define _I2CDEVICE_H

#include <stdint.h>
#include <unistd.h>				
#include <fcntl.h>				
#include <sys/ioctl.h>	

#include "I2CBus.h"
//#include "LSM6DSOX.h"

/*!
 * @brief Class that represents communication with a general i2c slave device
 */
class I2CDevice {

    public:

    I2CDevice(const int slaveAddr);
    
    protected:

    int deviceFilenum;
    const int slaveAddress;

    uint8_t readRegisterByte(uint16_t regAddress);
    uint8_t writeRegisterByte(uint16_t regAddress, uint8_t val);
    uint8_t writeRegisterWordBits(uint16_t regAddress, uint16_t val, uint8_t numBits, uint8_t offset);


    private:

};


#endif
