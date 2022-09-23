#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2 );
const int micPin = A1;
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
int micVal= 0;

void readMicrophone( ) { 
      /* function readMicrophone */
     ////Test routine for Microphone
     micVal = analogRead(micPin);
     Serial.print(F("mic val ")); Serial.println(micVal);
     if (micVal > 600) {
            Serial.println("mic detected");
            Serial.begin(9600);
            Serial.println(F("Initialize System"));
            //Init Microphone
            pinMode(micPin, INPUT);
     }
void setup(){
  lcd.begin(16,2);
  pinMode(switchPin,INPUT);
  lcd.print("Google");
  lcd.setCursor(0,1);
  lcd.print("dinosaur");
  delay(1000000);
  pinMode(micPin, INPUT);
}
void loop(){
  readMicrophone();
  switchState=digitalRead(switchPin);
  if (switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("the ball says");
      lcd.setCursor(0,1);
      switch(reply){
        case 0:
        lcd.print("yes");
        break;
        case 1:
        lcd.print("no");
        break;
        case 2:
        lcd.print("maybe");
        break;
        
      }
    }
  }
  prevSwitchState = switchState;
}
