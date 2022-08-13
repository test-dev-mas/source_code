void setup() {
  init_board();

  DDRF = (1<<PF4)|(1<<PF5)|(1<<PF6)|(1<<PF7);
  PORTF = 0;

  DDRB |= (1<<PB7);
  Serial.begin(115200);

  for (;;) {
    if (Serial.available()) {
      uint8_t u = Serial.read();
      if (u == '0') {
        break;
      }
    }
  }

  Serial.println("master ready");

  for(uint8_t i=1;i<16;i++) {
    uint8_t j = i << 4;
    // PORTF |= (i<<4);
    // PORTF |= (1<<PF4)|(1<<PF5)|(1<<PF6)|(1<<PF7);

    PORTF = j;
    Serial.println(j, BIN);
    PORTB ^= (1<<PB7);
    delay(500);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}

void init_board() {
  DDRE |= (1 << PE3) | (1 << PE4) | (1 << PE5);                   // D5/2/3
  PORTE |= (1 << PE3) | (1 << PE4) | (1 << PE5);                  

  DDRG |= (1 << PG5);                                             // D4
  PORTG |= (1 << PG5);
}
