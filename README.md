# CarSharingSystem
This repo contains all data to the small, arduino based, car sharing system.

It is designed to give multiple users of a (privately) shared car a cheap and easy possibility for tracking each users travelled distance.

See the documentation on [hackaday.io](https://hackaday.io/project/179145-car-sharing-system) for more background information.
For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework.

## Using the system
To use this system it has to be connected to the car with three wires: +12V, Ignition, GND.
If the ignition is on, the mcu wakes from sleep and it is ready.

To use this car sharing system, the user only has to identify himself with his RFID token on the reader. 

For later analysis, a log entry containing ID and travel distance is saved on a SD card. 

To evaluate, which user drove what distance, as python script is provided.
## Hardware
As it can be seen in graphic "System Overview", core of the CarSharingSystem is an ESP32, since I have one on hand and the available computing power won't hurt.
To determine the travelled distance a GPS module "GY-GPS6MV2" is chosen for wide availability and the cheap price. Since the planned, cheaper RC522 card reader made a lot of problems, a "PN532" reader is used instead.
For logging the data a µSD Card is the way to provide persistant data storage.
To give the user a clear idea of the devices functional state a single LED is used as a concise User Interface.

![System Overview](/documentation/CarSharingSystem.png)

### Schematic
A (probably permanent) prototype of the aforementioned modules is assembled on a breadboard. A schematic is available as PDF in the documentation folder.

## Software
For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework. It uses some great libraries which were written by other people. To not have dependencies on other repos they are included in the software/lib folder. To switch to the most current library versions, I'll link the sources here. TODO