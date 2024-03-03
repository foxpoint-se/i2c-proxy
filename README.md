# i2c-proxy
A proxy module that reads from a I2C device and publishes data over serial, the idea is to reduce the length of a I2C cable and instead use the more noise resistant serial communication to bypass I2C disruptions.

## Functionaltiy 
Background, in the Alen project a depth sensor MS5837_02BA by Blue Robotics is beeing used. A problem with this sensor is that it is communicating over I2C and the I2C protocol is not very reliable in noisy environments, unless you have good understanding of the protocol and can implement error handling.

So to avoid the noise issue we have experienced we reduced the length of the I2C cable to bare minimum and added this I2C proxy module, the module is reading from I2C and publishes the value over serial which is much more noise tolerant.

The sampling rate of the sensor is set to 5Hz (200ms), as used by the ROS node consuming the data. Note that it is wise to have a check on the serial in-buffer in case the consumer starts falling behind over time, this could lead to old data beeing processed.

## Components
I2C proxy is made up by the following components.

- Arduino Nano
- MS5837_02BA Depth sensor

## Dependencies & installation
There is one external dependencie to other Arduino libraries. It is to the MS5837 library by blue robotics.

MSB5837 Library:
https://github.com/bluerobotics/BlueRobotics_MS5837_Library
