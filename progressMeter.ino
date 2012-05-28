/*
progressMeter.ino
 William W. Ward
 wwward@pobox.com
 May 28, 2012
 version 0.1
 E-mail me with questions for now.
 When running, reads a byte from serial and sets the PWM on meterPin.
 Input can be 0-99 as a byte (not ASCII) and the PWM out is from
 the minVal up to the maxVal as set in the readSerial routine.
 These constants should be adjusted depending on the meter's min-max voltage.
 This code is licensed under GPL.
 */

int meterPin = 9;
int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = readSerial();
  if (value != 255) {
    setMeter(meterPin, value);
  }
  //Serial.println(value);
  value = 255;
}

int readSerial() {
  //calibration constants
  int maxVal = 255;
  int minVal = 0;
  byte b = 255;
  if (Serial.available() > 0) {
    b = Serial.read();
    Serial.print("Read: "); //debug
    Serial.println(b); //debug
    if (b > 99) {
      b = 99;
    }
    if (b < 0 ) {
      b = 0;
    }
  }
  int multiplier = (maxVal / 100);
  int setVal = 255;
  if (b != 255) {
    Serial.print("b is: "); //debug
    Serial.println(b); //debug
    setVal = (multiplier * b);
    if (setVal > maxVal) {
      setVal = maxVal;
    }
    if (setVal < minVal) {
      setVal = minVal;
    }
  }
  //Serial.println(setVal);
  return setVal;
}

void setMeter(int pin, int value) {
  delay(30);
  analogWrite(pin, value);
}






