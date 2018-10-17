# PCF8591

The PCF8591 is a single-chip, single-supply low-power 8-bit CMOS data acquisition device.<br>
The PCF8591 on the Automatic Watering System has only four analog inputs.<br>

## DFRobot_PCF8591 Library for Arduino
---------------------------------------------------------
Provide a library faciltates operations in the PCF8591 modules.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)

* [Compatibility](#compatibility)
* [Credits](#credits)
<snippet>
<content>

## Summary
This is for Automatic Watering System, only 4 ADC channels.

## Feature
1. Low standby current
2. Serial input via I2C-bus
3. Max sampling rate given by I2C-bus speed
4. 4 analog inputs configurable as single ended or differential inputs
5. Auto-incremented channel selection
6. Analog voltage range from 0 to 3.3V

## Installation

Download the library ZIP file and unzip it to the Arduino folder of the library.<br>

## Methods

```C++

#include "DFRobot_PCF8591.h"

/*
 * @brief set i2c address
 *
 * @param addr        i2c address
 */
void init(uint8_t addr);

/*
 * @brief analogRead
 * 
 * @param channel        analog input channel
 *        readType       analog input style
 */
uint8_t analogRead(uint8_t channel, uint8_t readType = SINGLE_ENDED_INPUT);

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
ESP32 |       √      |             |            | 


## Credits

Written by DFRobot, 2018. (Welcome to our [website](https://www.dfrobot.com/))
