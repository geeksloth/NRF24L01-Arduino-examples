#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(9, 8); // CE, CSN
const byte addresses[][10] = {"ADDRESS01","ADDRESS02"};

void setup() {
  Serial.begin(9600);  
  radio.begin();  
  radio.openWritingPipe(addresses[1]);    // ADDRESS02
  radio.openReadingPipe(1, addresses[0]); // ADDRESS01
  radio.setPALevel(RF24_PA_MAX);
};

void loop() {  
  radio.startListening();
  if (radio.available()) { // Receive
    char txt_received[10] = "";
    radio.read(&txt_received, sizeof(txt_received)); 
    Serial.print("Received from: ");
    Serial.println(txt_received);
  };
  delay(10);
  radio.stopListening(); // Transmit
  const char txt_sent[] = "Node 2";
  radio.write(&txt_sent, sizeof(txt_sent));  
  Serial.print("Sent to: ");
  Serial.println(txt_sent);
  delay(10);
};
