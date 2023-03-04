#include <SPI.h>
#include <nRF24L01.h>  //Library needed in order to recognize our device
#include <RF24.h>

#define buttonPin1 3 //button

int buttonState1 = 0; 
RF24 radio(9, 8); // Chip eneable(CE), Chip set(CSN)

const byte address[6] = "00002"; // our address, must be the same on the RX

void setup() {
   pinMode(buttonPin1, INPUT_PULLUP); // input button
   Serial.begin(9600);
   radio.begin();
   radio.openWritingPipe(address); // initialize the radio transmitter
   radio.setPALevel(RF24_PA_MIN); // our modules don't take much power, use minimum
   radio.stopListening();           // set it as transmitter
}
void loop() {
   buttonState1 = digitalRead(buttonPin1); // here we will check the state of the button

   if (buttonState1 == 1)
   {
      buttonState1 = 1;
   }
   else  if (buttonState1 == 0)
   {
      buttonState1 = 0;
   }
   // send messages
   Serial.print(buttonState1);
   Serial.print("\t");
   radio.write(&buttonState1, sizeof(buttonState1));
}