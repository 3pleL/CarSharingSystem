# CarSharingSystem
This repo contains all data to the small, arduino based, car sharing system.

It is designed to give multiple users of a (privately) shared car a cheap and easy possibility for tracking each users travelled distance.

For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework.

## Hardware
As it can be seen in graphic "System Overview", core of the CarSharingSystem is an ESP32, since I have one on hand and the available computing power won't hurt.
To determine the travelled distance a GPS module "GY-GPS6MV2" is chosen for wide availability and the cheap price. Since the planned, cheaper RC522 card reader made a lot of problems, a "PN532" reader is used instead.
For logging the data a µSD Card is the way to provide persistant data storage.
To give the user a clear idea of the devices functional state a single LED is planned as a concise User Interface.

The power supply is still to be decided on, maybe all elements of the system can be powered by the ESP32 dev board. But this has to be verified yet.
The connection to the cars signals is not yet decided upon.  
![System Overview](/documentation/CarSharingSystem.png)

### Schematic
![Preliminary Schematic](/documentation/CarSharingSystemSchematic.png)  
A prototype of the aforementioned modules is assembled on a breadboard as depicted above. A proper schematic might follow if I do a PCB layout and decide not to assemble it on perfboard.

## Software
For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework. It uses some great libraries which were written by other people. To not have dependencies on other repos they are included in the software/lib folder. To switch to the most current library versions, I'll link the sources here. TODO