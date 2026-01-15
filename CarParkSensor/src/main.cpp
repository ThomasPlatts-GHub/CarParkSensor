#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Define lcd object and assign LCD Pin Numbers
const int RS = 22, RW = 23, E = 24, D0 = 2, D1 = 3, D2 = 4, D3 = 5, D4 = 6, D5 = 7, D6 = 8, D7 = 9;
LiquidCrystal lcd(RS, RW, E, D0, D1, D2, D3, D4, D5, D6, D7);

// Define Servo object and assign vars
Servo servo;
int val;
const int servoPin = 10;

// ultrasonic vars
const int usTrig = 11;
const int usEcho = 12;
const float speedOfSound = 343.2611; // m/s 
const float conversionFactor = .0001; // conversion factor for meters to cm and uSec to sec
int distance;
long duration;

// Button pin
const int buttonPin = 26;

// Parking spots
int spots = 3;

void setup() {
  // Pins
  pinMode(usTrig, OUTPUT);
  pinMode(usEcho, INPUT);
  pinMode(buttonPin, INPUT);
  // Serial
  Serial.begin(9600);
  // LCD
  lcd.begin(16, 2);
  lcd.print("Parking Spots: ");
  lcd.setCursor(15, 0);
  lcd.print(spots);
  // Servo
  servo.attach(servoPin);
  servo.write(0);
  delay(1000);
}

void loop() {
  // Ping ultrasonic sensor
  lcd.clear();
  lcd.print("Parking Spots: ");
  lcd.setCursor(15, 0);
  lcd.print(spots);
  digitalWrite(usTrig, 0);
  delayMicroseconds(2);
  digitalWrite(usTrig, 1);
  delayMicroseconds(10);
  digitalWrite(usTrig, 0);

  duration = pulseIn(usEcho, 1);
  distance = duration * (speedOfSound*conversionFactor)/2;

  if (spots > 0 && spots <= 3){
    if (distance > 0 && distance < 10){
    servo.write(100);
    lcd.setCursor(15, 0);
    lcd.print(spots--);
    delay(2000);
  } else {
    servo.write(0);
    delay(15);
  }
  } else {
      servo.write(0);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No Spots Left");
      lcd.setCursor(0, 1);
      lcd.print("Please wait...");
  }

  if(digitalRead(buttonPin) == 0){
    delay(100);
  } else {
      if(spots == 3){
        digitalWrite(buttonPin, 1);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Car Park Empty");
        delay(1000);
        digitalWrite(buttonPin, 0);
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Parking Spots: ");
        lcd.setCursor(15, 0);
        lcd.print(spots++);
        servo.write(100);
        delay(2000);
      }
  }

}