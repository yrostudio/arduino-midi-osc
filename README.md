# arduino-midi-osc
Both direction convertion midi / osc. 
Receive midi in Arduino converted to osc message ///// send midi to arduino converted to osc message

Sending / receiving midi on long distance using OSC.

For example, you need to send / receive midi from the stage to the control booth.


# HARDWARE

1. Arduino
I used the Arduino Uno.

2. Arduino ethernet shield
I used the official Arduino ethernet shield

3. Arduino midi shield
I used the Olimex midi shield : https://www.olimex.com/Products/Duino/Shields/SHIELD-MIDI/open-source-hardware

4. 2 Midi cables and ethernet cable

5. Audio card or midi/usb with midi out and midi in


# LIBRARY ARDUINO IDE

MIDI.h
Ethernet.h
EthernetUdp.h

OSSmessage.h
add via Library Manager (not working for me)
or download zip https://github.com/CNMAT/OSC
Then in Arduino IDE : Sketch/Include Library / Add .ZIP library





