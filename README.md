# CarSharingSystem
This repo contains all data to the small, arduino based, car sharing system.

It is designed to give multiple users of a (privately) shared car a cheap and easy possibility for tracking each users travelled distance.

For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework.

## Hardware
As it can be seen in graphic 1, core of the CarSharingSystem is an ESP32, since I have one on hand and the available computing power won't hurt.
To determine the travelled distance a GPS module "GY-GPS6MV2" is chosen for wide availability and the cheap price. Same applies to the RFID reader "RC522".
For logging the data a µSD Card is the way to provide persistant data storage.
To give the user a clear idea of the devices functional state some LEDs are planned as a concise User Interface.

The power supply is still to be decided on, maybe all elements of the system can be powered by the ESP32 dev board. But this has to be verified yet.
The connection to the cars signals is not yet decided upon. 
![System Overview](/documentation/CarSharingSystemOverview.pdf)

Details on the schematic will be added as soon as the parts for the prototype arrive and are assembled on a breadboard.
## Software
For the availability of usable libraries to communicate with the subsystems this project uses the Arduino Framework.