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


#ifndef DFROBOT_PCF8591_H
#define DFROBOT_PCF8591_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define PCF8591_I2C_ADDRESS 0x48
//analog input style
#define AUTOINCREMENT_READ                B00000100
#define SINGLE_ENDED_INPUT                B00000000
#define TREE_DIFFERENTIAL_INPUT           B00010000
#define TWO_SINGLE_ONE_DIFFERENTIAL_INPUT B00100000
#define TWO_DIFFERENTIAL_INPUT            B00110000

class DFRobot_PCF8591 {
public:
    /*Initialization function*/
    void init(uint8_t addr);
    /*read 4 channel */
    uint8_t analogRead(uint8_t channel, uint8_t readType = SINGLE_ENDED_INPUT);

private:
    uint8_t _i2caddr;
    uint8_t _register;
};
#endif //DFROBOT_PCF8591_H