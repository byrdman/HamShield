/* 

Morse Code Beacon

Test beacon will transmit and wait 30 seconds. 
Beacon will check to see if the channel is clear before it will transmit.


*/

#include <HAMShield.h>
#include <Wire.h>

#define DOT 100

HAMShield radio;

void setup() { 
  Serial.begin(9600);
  Serial.println("starting up..");
  Wire.begin();
  Serial.print("Radio status: ");
  int result = radio.testConnection();
  Serial.println(result,DEC);
  radio.initialize();
  radio.setFrequency(446000);
  Serial.println("Done with radio beacon setup.");
}

void loop() {
   if(radio.waitForChannel(1000,2000)) {
      Serial.println("Signal is clear -- Transmitting");
      radio.setModeTransmit();
      radio.morseOut("1ZZ9ZZ/B CN87 ARDUINO HAMSHIELD");
      radio.setTX(0);
        radio.setModeReceive();
      Serial.print("TX Off");
      delay(30000);    
   } else { Serial.println("The channel was busy. Waiting 30 seconds."); delay(30000); } 
}


