#include<Servo.h>

Servo myservo;

float buzzer = A1; // Define Buzzer pin

long t; // declaring variable for calculating time

long cm; //declaring variable for calculating distance

void setup() {
  pinMode(2, OUTPUT);//define trigger pin out
  pinMode(4, INPUT);//define echo pin out
  pinMode(6, OUTPUT);//define trigger  pin in
  pinMode(8, INPUT);//define echo pin in
  myservo.attach(7);
  pinMode(10,OUTPUT);//define red colour 
  pinMode(11,OUTPUT);//define green colour
  pinMode(12,OUTPUT);//define blue colour
  Serial.begin(9600);//enable serial monitor

}
void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(10);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  
  t = pulseIn(4, HIGH);//input pulse and save it 
  Serial.println();//print spacevariable
  cm = t / 29 / 2; //time convert distance
  String CM = " cm1";
  Serial.println(cm +CM);//print serial monitor cm

  if(cm < 8 )
  {
    myservo.write(170);
    delay(2000);
  }
  else
  {
    myservo.write(90);
    delay(50);
  }

  digitalWrite(6, LOW);
  delayMicroseconds(10);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  
  t = pulseIn(8, HIGH);//input pulse and save it 
  Serial.println();//print spacevariable
  
  cm = t / 29 / 2; //time convert distance
  CM = " cm2";

  Serial.println(cm +CM);//print serial monitor cm
  if(cm < 10 )
  {
    if(cm < 3) //red light if dustbin is full
    {
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);   
    }
    else //blue light if dustbin is not empty
    {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
    }
    analogWrite(buzzer,255);
    delay(200);
  }
  else //green light if dustbin is empty
  {
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    analogWrite(buzzer,0);
    delay(200);
  }

}