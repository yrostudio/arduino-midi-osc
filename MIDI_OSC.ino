#include <MIDI.h>
#include <OSCMessage.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// IP Adresse destination and port
IPAddress destIp(2, 0, 0, 101);
unsigned int destPort = 8000;

//Timer statut réception Arduino for the debug
unsigned long previousMillis = 0; 
const long interval = 1000;

// Adress MAC and IP ARDUINO
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xCB}; 
IPAddress ip(2, 0, 0, 10);


int osc1;
int osc2;
int osc3;
const char* messageOsc;

// UDP
EthernetUDP Udp;


void setup() {

  MIDI.begin(MIDI_CHANNEL_OMNI);
  Ethernet.begin(mac,ip);
  Udp.begin(destPort);

}

// OSC MESSAGE FUNCTION

void handleOSC(const char* messageOsc, int numParams, ...) 
{
  OSCMessage msg(messageOsc);
  va_list args;
  va_start(args, numParams);
  for(int i = 0; i < numParams; i++){
    int arg = va_arg(args, int);
    msg.add(arg);
  }
  va_end(args);
  Udp.beginPacket(destIp, destPort);
  msg.send(Udp);
  Udp.endPacket(); 
  msg.empty(); 
}



void loop() {


  OSCMessage messagein;
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    while (packetSize--) {
      messagein.fill(Udp.read());
    }
    if (!messagein.hasError()) {
        if (messagein.match("/note")) {
        int note = messagein.getInt(0);
        int velocity = messagein.getInt(1);
        int channel = messagein.getInt(2);
        MIDI.sendNoteOn(note, velocity, channel);
      } else if (messagein.match("/cc")) {
        int cc = messagein.getInt(0);
        int value = messagein.getInt(1);
        int channel = messagein.getInt(2);
        MIDI.sendControlChange(cc, value, channel);
      }
    }
    messagein.empty();
  }


  if (MIDI.read()) {
    midi::MidiType type = MIDI.getType();

     if (type == midi::NoteOn || type == midi::NoteOff) {
        int note = MIDI.getData1();
        int velocity = MIDI.getData2();
        int channel = MIDI.getChannel();
        osc1 = note;
        osc2 = velocity;
        osc3 = channel; 
        messageOsc = "/note";
        handleOSC(messageOsc, 3, osc1,osc2,osc3);
      
     }

    if (type ==  midi::ControlChange) {
        int cc = MIDI.getData1();
        int value_cc = MIDI.getData2();
        int channel = MIDI.getChannel();
        osc1 = cc;
        osc2 = value_cc;
        osc3 = channel;
        messageOsc = "/cc";
        handleOSC(messageOsc, 3, osc1,osc2,osc3);

      }

      // here you can add different midi type ProgramChange, Clock, ...

    }



// A piezo connected on the Olimex shield

  int analogValue = analogRead(A0);
  int oldAnalogValue;

  //if (analogValue > oldAnalogValue + 2 || analogValue < oldAnalogValue - 2)  {

    osc1 = analogValue ;
    messageOsc = "/piezo1";
    handleOSC(messageOsc, 1, osc1);

 //   oldAnalogValue = analogValue;
 //}



 unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    osc1 = 1;
    messageOsc = "/debug";
    handleOSC(messageOsc, 1, osc1);
  }

  delay(1); 
}


