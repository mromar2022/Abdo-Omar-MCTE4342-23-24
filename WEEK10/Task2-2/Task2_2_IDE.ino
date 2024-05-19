//ligando o motor pressionando o botão
//Ligar motor no pino 2

const int motorPin = 2;
const int buttonPin = 7;
int buttonState = 0;
int motorState = 0;
void setup () {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

//APERTANDO PARA FUNCIONAR
void loop (){
  motorState = digitalRead (motorPin);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    while (digitalRead (buttonPin)==HIGH) {delay (100);
  }
           if (motorState == LOW){
             digitalWrite (motorPin, HIGH);
           }else {
             digitalWrite (motorPin, LOW);
           }
           }
   }
           
