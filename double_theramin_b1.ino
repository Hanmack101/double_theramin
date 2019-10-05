/*
  Arduino Starter Kit example
  Project 6 - Light Theremin

  This sketch is written to accompany Project 6 in the Arduino Starter Kit

  Parts required:
  - photoresistor
  - 10 kilohm resistor
  - piezo

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/
//first sensor
// variable to hold sensor values
int sensorValue1;
int sensorValue2;

// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;


// LED pin
const int ledPin = 13;

void setup() {
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {

    //calibrate first sensor - on board
    sensorValue1 = analogRead(A0);
    if (sensorValue1 > sensorHigh) {
      sensorHigh = sensorValue1;
    }
    if (sensorValue1 < sensorLow) {
      sensorLow = sensorValue1;
    }


    //second (pot) sensor
        sensorValue2 = analogRead(A1);
    if (sensorValue2 > sensorHigh) {
      sensorHigh = sensorValue2;
    }
    if (sensorValue2 < sensorLow) {
      sensorLow = sensorValue2;
    }

  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
    Serial.print("first sensor callibrated");
    Serial.println(sensorValue1);
    Serial.print("second sensor callibrated");
    Serial.println(sensorValue2);
    

}
/////-------- functions --------/////


void firstSensorResponse(){
  //read the input from A0 and store it in a variable
  sensorValue1 = analogRead(A0);
  int pitch = map(sensorValue1, sensorLow, sensorHigh, 50, 4000);
  tone(10, pitch, 20);
  Serial.print("first sensor value is ");
  Serial.println(sensorValue1);
  delay(10);
  }

void secondSensorResponse(){
  //read the input from A1 and store it in a variable
  sensorValue2 = analogRead(A1);
  int pitch = map(sensorValue2, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  Serial.print("pot sensor value is ");
  Serial.println(sensorValue2);
  delay(10);
  }


void loop() {
  if (sensorValue1 >1 || sensorValue2 > 1){
    firstSensorResponse();
    Serial.println(sensorValue1);
    secondSensorResponse();
    Serial.println(sensorValue2);
    }
} 


