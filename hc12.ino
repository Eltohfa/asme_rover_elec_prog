#include <SoftwareSerial.h>

SoftwareSerial HC12(4,5); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);       // HC-12 Serial Port
}

void loop() {
  while(HC12.available()) {   // If HC-12 has data
    Serial.write(HC12.read());  // Send the data to Serial monitor
  }
  while(Serial.available()) { // If Serial monitor has data
    HC12.write(Serial.read()); // Send that data to HC-12
  }
}
