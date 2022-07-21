/* THE ENTIRE SEQUENCE OF WRITING TO REGISTERS IS COPID FROM MONOLITHIC VIRTUAL BENCH 2.0 I2C TRANSMISSION
  EXCEPT SOME READ OPERATIONS
  LOOKS LIKE VALUES WRITTEN TO REGISTER D6 CONTROL VOUT
  BECAUSE THE FIRST VALUES WIRTTEN TO D6 ARE IDENTICAL FOR 2V AND 5V
  THE SECOND VALUE (0x70 vs 0x71) MAY BE THE KEY
  UTIMATELY, THE VOUT MIGHT BE CONTROLLED BY TWO BYTES
*/

#include <Wire.h>

#define PSU_ADDR  0x21

uint8_t buffer[2] = {0};
uint8_t i = 0;

void setup() {
  DDRB |= (1 << PB7);

  Serial.begin(115200);
  
  Wire.begin();

  Serial.println("PSU ready");

  uint8_t d0 = 60;
  uint8_t d1 = 0x71;

  send(d0, d1);

  // for (;;) {
  //   while (Serial.available()) {
  //     uint8_t u = Serial.read();
  //     if (u == '\r') {
  //       i = 0;
  //       break;
  //     }
  //     buffer[i++] = u;
  //   }

  //   send(buffer[0], buffer[1]);
  // }

  /* setps through all values, works with terminal or python script */
  // for (;;) {
  //   if (Serial.available()) {
  //     uint8_t u = Serial.read();

  //     switch(u) {
  //       case '0':
  //         d1 = 0x70;
  //         break;

  //       case '1':
  //         d1 = 0x71;
  //         break;

  //       case '2':
  //         d1 = 0x73;
  //         break;

  //       case '+':
  //         d0++;
  //         send(d0, d1);
  //         break;

  //       case '-':
  //         d0--;
  //         send(d0, d1);
  //         break;

  //       default:
  //         break;
  //     }
  //   }
  // }

  // for (uint8_t i=0x3C;i<0xFF;i++) {   // steps through 0.60 ~ 1.99 (V)
  //   send(i, 0x73);
  //   Serial.print("Write to register: ");
  //   Serial.println(i, HEX);
  //   PORTB ^= (1 << PB7);
  // }

  // for (uint8_t i=0xFF;i>0x3C;i--) {   // steps through 2.00 ~ 2.99 (V)
  //   send(i, 0x70);
  //   Serial.print("Write to register: ");
  //   Serial.println(i, HEX);
  //   PORTB ^= (1 << PB7);
  // }

  // for (uint8_t i=0x3C;i<0xFF;i++) {   // steps through 3.00 ~ 12.57 (V)
  //   send(i, 0x71);
  //   Serial.print("Write to register: ");
  //   Serial.println(i, HEX);
  //   PORTB ^= (1 << PB7);
  // }  
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