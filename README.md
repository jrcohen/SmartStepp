# SmartStepp

### Combination Driver and Encoder for Nema 17 stepper motors
Features:

 * Compact design mounts on the back of the motor
 * Chainable connections (12V Power, Logic Power, SPI) - Hook up multiple motors in series connected to just one microcontroller
 * Compatible with A4988 and DRV8825 stepper motor drivers
 * 14-bit magnetic encoder (AS5047d)
 * Encoder only version is RAMPS 1.4 compatible 


The aim of this project is to create inexpensive Nema 17 and Nema 23 motor encoders/drivers. These boards allow for plug-and-play stepper motor control with extremely precise position readouts once fully calibrated. 

Useful for 3D printers to provide higher precision movement and dynamic error correction for any missed steps (like if the printer gets bumped or stops mid-print).
Other potential applications include robotics/robot arms, process automation machines, hobby CNC machines, any other application needing precise repeatability under different loads.

Project hardware variants:

 * Motor driver only - target cost under $10
 * Encoder only - target cost under $15
 * Driver/Encoder combo - target cost under $20

Future Software compatibility:

 * Arduino Library
 * Python Library (for standalone raspberry pi use)
 * Marlin 
 * GRBL
 
![Prototype](/Images/test1.JPG)

This project draws inspiration from [Mechaduino](https://github.com/jcchurch13/Mechaduino-Firmware/blob/master/README.md), but hopefully will have its own niche applications

Released under the Creative Commons Attribution Share-Alike 4.0 License
