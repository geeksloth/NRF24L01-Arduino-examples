#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7, 8); // CE, CSN
const byte address[10] = "ADDRESS01";
int count = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
};

void loop() {
  char txt[] = "Hi, GeekSloth";
  char ChValue[10];
  dtostrf(count, 10, 8, ChValue);
  strcat(txt, ChValue);
  
  radio.write(&txt, sizeof(txt)+sizeof(ChValue));
  Serial.println(txt);
  count += 1;
  delay(1000);
};