/* 
  File: Bionic_Arm.ccp
  Author: Sami Fadhili
  Date: 2025-02-18
  Description: this program takes the inputs of a joystick and a button in order to move and control a robotic arm.
*/

#include <Servo.h> 

const int SW_pin = 4; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

const int servoxPin = 7; 
const int servoy1Pin = 8;
const int servoy2Pin = 9;
const int servoGPin = 10;

int button = 0;

// adding all servomoters
Servo myservox;
Servo myservoy1;
Servo myservoy2;
Servo myservoG;



void setup() {
  pinMode(SW_pin, INPUT); // sets SW_pin as a input

  Serial.begin(9600);

  myservox.attach(servoxPin); // attaches myservox to servoxPin
  myservoy1.attach(servoy1Pin); // attaches myservoy1Pin to servoy1Pin
  myservoy2.attach(servoy2Pin);
  myservoG.attach(servoGPin);
}

void loop() {
  
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.println(" | ");
  delay(200);

  Serial.println(X_map()); 

  Serial.println(Y_map());


  myservox.write(X_map()); //  moves the servomoters acording to the X_map integer

  myservoy1.write(Y_map()); //  moves the servomoters acording to the Y_map integer 

  myservoy2.write(Y_map()); //  moves the servomoters acording to the Y_map integer

/*
  if statment that turns myservoG 90 degrees when SW_pin is high
*/
  if (digitalRead(SW_pin) == HIGH) {

  myservoG.write(90);
  
} else {

  myservoG.write(0);
  
}
}

/*
  reads the joyticks x coardinates (X_pin) as a input and maps it to a integer
  Paramaters:
    reads: X_pin
    maps the value
    returns: maped integer
*/

int X_map() {
  return (map(analogRead(X_pin), 10, 1025, 0, 180));
}


/*
  reads the joyticks y coardinates (Y_pin) as a input and maps it to a integer
  Paramaters:
    reads: Y_pin
    maps the value
    returns: maped integer
*/

int Y_map() {
  return (map(analogRead(Y_pin), 10, 1025, 0, 90));
}

