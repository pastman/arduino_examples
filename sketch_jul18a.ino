#include <Servo.h>

#define SERVO_LEFT 10
#define SERVO_RIGHT 11
#define TRIGGER 12
#define ECHO 13

#define MAX 150
#define MIN 50

#define DELAY_TIME 1800

Servo servoLeft;
Servo servoRight;

void setup() {
  
  pinMode(SERVO_LEFT, OUTPUT);
  pinMode(SERVO_RIGHT, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  servoLeft.attach(SERVO_LEFT);
  servoRight.attach(SERVO_RIGHT);

  servoLeft.write(101);
  servoRight.write(102);

  // Iniciar el puerto:
  Serial.begin(9600); // Baudios a los que escribe...
  
  //digitalWrite(SERVO_LEFT, HIGH);

}

void loop() {

  //int distance = getDistance();
  int incomingByte = 0;   // for incoming serial data
  
  /*
  if (distance > 10) {
    forward();  
  } else {
    backward();
    delay(1000);
    left();
    delay(500); 
  }
  
  delay(250);
  */

  if (Serial.available() > 0) {
    
    // read the incoming byte:
    int order = Serial.read();

    if (order == 48) {
      forward();  
    } else if (order == 49){
      backward();
    }

    // say what you got:
    Serial.print("I received: ");
    Serial.println(order, DEC);
  }
}

void forward(){
  
  servoLeft.write(MIN);
  servoRight.write(MAX);  

}

void backward(){
  
  servoLeft.write(MAX);
  servoRight.write(MIN);  

}

void left(){
  
}

void right(){
  
}

int getDistance(){

  // Código que hace cosas...
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  // Código que escucha cosas hasta que pase algo...
  // Función pulseIn() detecta flancos (cambios de arriba HIGH a abajo LOW y de abajo LOW a arriba HIGH)
  int time = pulseIn(ECHO, HIGH); // Nos da el tiempo que tarda en rebotar desde que recibe la instrucción hasta que salta el pulso
  int distance = time * 10 / 298 / 2; // En centímetros

  // Sacar la distancia por consola (Puerto Serie)
  Serial.println(distance);

  return distance;

}
