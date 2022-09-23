/*
  Projet : Déplacer un personnage sur un écran LCD
  Le faire sauter en fonction de l'intensité du son
  Matériels utilisés : 
  - Microphone, 
  - Carte Arduino,
  - Ecarn LCD 
/

#include <LiquidCrystal.h>

int seconds = 0;
int valueSound = 0;
int posCursorY = 1;
int posCursorX = 0;
int pinMicro = A0;
int valMicroBrute = 0;
 

byte person[8] = {
    B00000,
    B10001,
    B00100,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
};

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(pinMicro, INPUT);
  pinMode(ledSaut, OUTPUT);

  lcd_1.createChar(0, person); // apprend le caractère à l'écran LCD
  lcd_1.begin(16, 2); 
  lcd_1.setCursor(posCursorX, posCursorY);
  lcd_1.write((uint8_t) 0); // affiche le caractère de l'adresse 0
}

void loop()
{
  valMicroBrute = analogRead(pinMicro);
  ///valPos = valBrute 15/1023;

  /* Saut du personnage si la valeur du potentiometre est supérieure à 500 */
  if(valMicroBrute > 500){
    posCursorY = 0;
  }else{
    posCursorY = 1;
  }

  if(posCursorX == 16){
     posCursorX = 0;
  }
  lcd_1.createChar(0, person);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(posCursorX, posCursorY);
  lcd_1.write((uint8_t) 0);
  posCursorX ++;
  delay(300); // Wait for 300 millisecond(s)

  if(posCursorX == 16){
     posCursorX = 0;
  }
  lcd_1.createChar(0, person);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(posCursorX, posCursorY);
  lcd_1.write((uint8_t) 0);
  posCursorX ++;
  delay(500); // Wait for 1000 millisecond(s)
}
