// Code Ultrasonic Range Finder
#define ECHOPIN 10                            
#define TRIGPIN 11       
#include <Wire.h>                      
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.print("Range Finder");
  lcd.setCursor(0, 1);
  lcd.print("Range=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  delay(1000);
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  int distance = pulseIn(ECHOPIN, HIGH);        
  distance= distance/58;                        
                      
  lcd.setCursor(6, 1);
  lcd.print(distance); 
  lcd.print(" cm ");
  delay(1000);    
}

