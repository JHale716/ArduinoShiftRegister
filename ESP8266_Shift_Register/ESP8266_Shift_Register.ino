/*
  This code lights up each LED connected to a 74HC595 as determined by the binary value of a counter. */

void setup() {

}

void loop() {
  for (int j = 0; j < 256; j++) { // Example data for 8bit shift register 
    shiftRegisterOutput(j);
//    delay(100);
  }
}

void shiftRegisterOutput(int shiftData) {
  int CLOCK = D5; // Pin connected to SRCLK of 74HC595 = Pin 11 (Clock signal for the data input, active on low-high transistion)
  int LATCH = D6; // Pin connected to SER of 74HC595 = Pin 14 (The latch that send ths data out, low for entry high to send)
  int DATA = D7;  // Pin connected to RCLK of 74HC595 = Pin 12 (the data shifted into the shift register)
  //  int OE = D1;  // Pin connected to OE of 74HC595 = Pin 13 (Set low to enabel output, nothing works if high)
  //  int SRCLR = D0; // Pin connected to SRCLR of 74HC595 = Pin 10 (Clear Shift Register when low, hold high unless using to clear)
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  digitalWrite(LATCH, 1);
  delay(2);
  digitalWrite(LATCH, 0);
  delay(2);
  int i = 0;
  int pinState;
  digitalWrite(DATA, 0);
  delay(2);
  digitalWrite(CLOCK, 0);
  for (i = 7; i >= 0; i--)  {
    digitalWrite(CLOCK, 0);
    if ( shiftData & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }
    digitalWrite(DATA, pinState);
    digitalWrite(CLOCK, 1);
    digitalWrite(DATA, 0);
  }
  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 1);
}
