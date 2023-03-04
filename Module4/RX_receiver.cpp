#include <SPI.h>
#include <nRF24L01.h>   //Library needed in order to recognize our device
#include <RF24.h>

#define led1 A0 //LED


int buttonState = 0;//start off

RF24 radio(9, 8); // Chip eneable(CE), Chip set(CSN)
const byte address[6] = "00002"; // same as our TX

void setup() {
   Serial.begin(9600);
   pinMode(led1, OUTPUT); // set output LED
   digitalWrite(led1, HIGH);
   radio.begin();
   radio.openReadingPipe(0, address); // initialize radio transmitter
   radio.setPALevel(RF24_PA_MIN); // min power
}
//receive signals from TX
void loop() {
   radio.startListening();
   while (!radio.available());
   radio.read(&buttonState, sizeof(buttonState));
   Serial.println(buttonState);
   //LED State
   if (buttonState == 1) {
      digitalWrite(led1, LOW);
   }
   else  if (buttonState == 0) {
      digitalWrite(led1, HIGH);
   }
}