/*  PINOUT
*   A0 - PF4 (ATMEGA 2560)
*   A1 - PF5 (ATMEGA 2560)
*   A2 - PF6 (ATMEGA 2560)
*   A3 - PF7 (ATMEGA 2560)
*   A4 - SDA (PD3603A)
*   A5 - SCL (PD3603A)
*   D13- EN  (PD3603A)
*/

#include <Wire.h>

#define PSU_ADDR  0x28

void setup() {
  uint8_t d0 = 80;                    // inital reference voltage
  uint8_t d1 = 112;                   // initial output range
  uint8_t signal = 0;
  uint8_t signal_temp = 0;

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);              // disable PSU
  
  Wire.begin();
  Serial.begin(115200);
  Serial.println("psu ready");
  for (;;) {
    signal_temp = PINC&0x0F;          // extract low 4 bits
    Serial.println(signal_temp);
    if (signal_temp == signal) {
      continue;
    }
    
    signal = signal_temp;
    
    if (signal > 0) {
      digitalWrite(13, HIGH);         // enable PSU
      send(d0+signal*2, d1);
    }
    else {
      digitalWrite(13, LOW);          // disable PSU
    }

    // static uint8_t i = 90;
    // send(i++,d1);
    // delay(2000);

    // uint8_t signal_temp = PINC&0x0F;
    // Serial.println(signal_temp);
    // delay(2000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}

void send(uint8_t d0, uint8_t d1) {
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDB);
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDB);
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDD);
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDB);
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD0);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD7);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(20);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(d0);                     // D0
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                  
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(d1);                     // D1
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x0A);                   // D2
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x1B);                   // D3
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x40);                   // D4
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x21);                   // D5
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x06);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x04);                   // D6
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x07);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x8A);                   // D7
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x04);                   // D8
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                  
  Wire.write(0x09);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0xDE);                   // D9
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x0A);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x50);                   // DA
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x0B);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x88);                   // DB
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   
  Wire.write(0x0C);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD6);
  Wire.write(0x00);                   // DC
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD3);
  Wire.write(0x00);
  
  Wire.endTransmission();

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD0);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(20);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 1
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 2
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);

  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 3
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 4
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 5
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 6
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 7
  Wire.write(0x06);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 8
  Wire.write(0x07);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 9
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 10
  Wire.write(0x09);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 11
  Wire.write(0x0A);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 12
  Wire.write(0x0B);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);
  Wire.endTransmission();

  delay(108);
  
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xD5);                   // 13
  Wire.write(0x0C);
  Wire.endTransmission();
  Wire.beginTransmission(PSU_ADDR);
  Wire.write(0xDC);  
  Wire.endTransmission();
}
