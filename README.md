# pir-ldr-relay

**Background**

I needed some lighting to my hallway when entering the apartment, but there is no power sockets in the whole hallway, 
nor am I allowed to modify the fixed lights (with impractically located switch). So the best solution I found was a PIR (motion) sensor
driven LED stripe located to the other end of hallway (where it would have access to power socket). 

Altough the hallway is quite dark all
times, I wanted it to be lighted only when necessary, so the PIR sensor got accompanied by a photoresistor, which tells whether it is dark
enough to switch the lights on. Photoresistor with an _analog output_ is also the reason this project actually needed a microcontroller.

I also needed a relay to separate the 5V and 12V currents for the controller/sensors system and the LED respectively.

With all the components gathered, I got to build my first all-by-myself microcontroller project with practical use!


**System itself**

The system consists of 
- AtMega328P microcontroller (running standalone, programmed with Arduino)
- Passive InfraRed (PIR) sensor HC-SR501
- Photoresistor KY-018
- 5V Relay KY-019
- 5V Voltage Regulator L7805ACV 
- Resistors, capasitors, clock crystal
