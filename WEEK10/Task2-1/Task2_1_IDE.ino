#include <Servo.h>

Servo servo;
int ledArriba=13;
int ledAbajo=12;

int btnArriba=0;
int btnAbajo=0;

void setup()
{
  
  //delay(5000);
  Serial.begin(9600);
  
  pinMode(btnArriba,INPUT);
  
  pinMode(ledArriba, OUTPUT);
  
  pinMode(ledAbajo, OUTPUT);
  pinMode(btnAbajo,INPUT);
  
  servo.attach(8);
  
  servo.write(0);
}

void loop()
{
  btnArriba=digitalRead(11);
  btnAbajo = digitalRead(10);
  
  if(btnArriba==HIGH)
  {
  digitalWrite(ledArriba, HIGH);
  digitalWrite(ledAbajo, LOW);
  servo.write(180);
    //delay(1000);
  }
  if(btnAbajo==HIGH)
  {
  digitalWrite(ledAbajo, HIGH);
  digitalWrite(ledArriba, LOW);
  servo.write(0); 
  }
  
  /*digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)*/
}