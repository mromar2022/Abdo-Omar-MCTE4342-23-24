//Library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

//Pin definition
#define LED 1 

//Variables
volatile int output = LOW;                      
int i = 0;

//void button1pressed();
//void button2pressed();

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Interrupt");
  delay(1000);
  
  pinMode(LED, OUTPUT);
  
  //Attaching interrupt
  attachInterrupt(digitalPinToInterrupt(2),button1pressed,RISING);  //function for creating external interrupts on Rising (LOW to HIGH)
  attachInterrupt(digitalPinToInterrupt(3),button2pressed,RISING);    
  
}


void loop()
{
  lcd.clear();
  lcd.print("Counter:");
  lcd.print(i);
  i++;
  delay(1000);
  digitalWrite(LED, OUTPUT);
  
}

//When button 1 pressed, interrupt 1 will be displayed and Led turned off
void button1pressed()
{
  output = LOW;
  lcd.setCursor(0,1);
  lcd.print("Interrupt 1");
}

//When button 2 pressed, interrupt 2 will be displayed and Led turned on
void button2pressed()
{
  output = HIGH;
  lcd.setCursor(0,1);
  lcd.print("Interrupt 2");
}