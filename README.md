# arduino-midi-osc
Both direction midi to osc. 
Receive midi in Arduino converted to osc message ///// send midi to arduino converted to osc message

Sending / receiving midi on long distance using OSC.

For example, you need to send / receive midi from the theatre stage to the control booth.


# HARDWARE

1. Arduino
I used the Arduino Uno.

2. Arduino ethernet shield
I used the official Arduino ethernet shield

3. Arduino midi shield
I used the Olimex midi shield : https://www.olimex.com/Products/Duino/Shields/SHIELD-MIDI/open-source-hardware

4. 2 Midi cables and ethernet cable

5. Audio card or midi/usb with midi out and midi in (i use m-audio usb/midi)


# LIBRARY ARDUINO IDE

MIDI.h / Ethernet.h / EthernetUdp.h


And also :

OSSmessage.h

add via in Arduino IDE with Library Manager (not working for me)

or download zip https://github.com/CNMAT/OSC

Then in Arduino IDE : Sketch/Include Library / Add .ZIP library


# UPLOAD CODE TO ARDUINO
With Arduino IDE

!!! If you're using OLIMEX MIDI SHIELD, be sure to unplugged the TX/RX jumper on the shield before trying to upload the code on the arduino, then plug back the jumper on the shield.


# COMMUNICATION
Connect Arduino with ethernet cable and configure your computer ip's address on ethernet port (2.0.0.101 by default).

If you're using an apple computer

Go to Apple / System Preferences / Network

![Screenshot 2023-05-04 at 19 47 10](https://user-images.githubusercontent.com/59850990/236286908-139f3726-21ad-49f4-92f0-f8ea0d0d6608.png)


Connect midi cables, electric plug, ethernet ...

![ARDUINO_MIDI_OSC](https://user-images.githubusercontent.com/59850990/236285776-25273106-3389-4f2b-8589-a0357e21650b.jpg)


# MESSAGES

Midi to OSC

convert midi note to osc message /note i i i (note,velocity, channel)

convert midi control change to osc message /cc i i i (value, control change, number channel)


OSC to Midi
convert osc message /note i i i (note, velocity, channel) to midi note 

convert osc message /cc i i i (value, control change number, channel) to midi control change




# MAXMSP PATCH 
To try the communication

![MAX_PATCH](https://user-images.githubusercontent.com/59850990/236284361-b6877bfb-6c16-496d-9662-5ad811449646.png)




