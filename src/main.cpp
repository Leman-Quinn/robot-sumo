#include <Arduino.h>
#include "config.h"
#include "Ultrasonic.h"
#include "Motors.h" 

void setup() { 
  // SERIAL SET UP
  Serial.begin(9600);

  UltrasonicInit();
  MotorsInit();
}

void loop() {
  
  // SIMPLE LOGIC TEST
  float dist_FL = ReadFrontLeftDistance();

  if (dist_FL >= 0 && dist_FL <= 10){
    MoveForward();
  }
  else{
    Brake();
  }
  
  delay(100);
  
  /*
  // ULTRASONIC TEST
  
  float FrontRight = ReadFrontRightDistance();
  
  Serial.print("Front Right Distance = ");
  Serial.println(FrontRight);
  delay(500);
  
  float FrontLeft = ReadFrontLeftDistance();
  
  Serial.print("Front Left Distance = ");
  Serial.println(FrontLeft);
  delay(500);
  
  float Left = ReadLeftDistance();
  
  Serial.print("Left Distance = ");
  Serial.println(Left);
  delay(500);

  float Right = ReadRightDistance();
  
  Serial.print("Right Distance = ");
  Serial.println(Right);
  delay(500);

  // MOVEMENT DEMO
  MoveForward();
  delay(1500);

  Brake();
  delay(1000);
  
  RotateLeft();
  delay(1500);

  Brake();
  delay(1000);

  MoveBackward();
  delay(1500);

  Brake();
  delay(1000);

  RotateRight();
  delay(3000);

  MoveForward();
  delay(500);
  */
}