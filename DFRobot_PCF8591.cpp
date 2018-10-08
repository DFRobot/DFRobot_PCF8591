/*!
 * @file DFRobot_PCF8591.h
 * @brief Read PCF8591's data of 4 ADC channel 
 * @n 
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 * @author [DFRobot]
 * @version  V1.0
 * @date  2017-12-22
 * @https://github.com/DFRobot/DFRobot_PCF8591
 */
 
#include <DFRobot_PCF8591.h>
#include "Wire.h"
/**
 * @param addr: i2c address 
 */
void DFRobot_PCF8591::init(uint8_t addr) {
    _i2caddr = addr;
    Wire.begin();
	/*PCF8591's ADC sampling frequency is related to i2c frequency, 10K in default is too high*/
    Wire.setClock(50000);
}

/**
 * Read one specified channel
 * @param channel [0 - 3]
 * @param readType 
 * 	SINGLE_ENDED_INPUT
 *	TREE_DIFFERENTIAL_INPUT
 *	TWO_SINGLE_ONE_DIFFERENTIAL_INPUT  
 * 	TWO_DIFFERENTIAL_INPUT
 * @return
 */
uint8_t DFRobot_PCF8591::analogRead(uint8_t channel,uint8_t readType) {
    if (channel > 3)
        return 0;
    uint8_t retValue=0;

    // read the current channel
    Wire.beginTransmission(_i2caddr);
    Wire.write(readType | channel);
    Wire.endTransmission();
  
    Wire.requestFrom(_i2caddr, 3);
    //the first 2 bytes are the data of last ADC sampling
    Wire.read();
    Wire.read();
    retValue=Wire.read();
  
    return (retValue);
}