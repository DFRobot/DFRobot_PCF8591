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

DFRobot_PCF8591 PCF8591;

void setup()
{
	/*init PCF8591 with i2c address*/
    PCF8591.init(PCF8591_I2C_ADDRESS);
    Serial.begin(9600);
}

void loop()
{
	
	/*read the values of 4 channels*/
    for(int i = 0;i < 4;i++)
    {
        byte res =PCF8591.analogRead(i);
		//3.3 is the reference voltage
        float value = ((float)res)/255*3.3;
		Serial.print("channel ");
		Serial.print(i);
		Serial.print(" --> ");
        Serial.print(value); Serial.println("V  ");
    }
    delay(300);
}
