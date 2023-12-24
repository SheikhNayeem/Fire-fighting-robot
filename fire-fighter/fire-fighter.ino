#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int command;
int S_A = 10;  //speed motor a
//int M_A1 = 2; //motor a = +
//int M_A2 = 3; //motor a = -
int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +
int S_B = 9;  //speed motor b

int L_S = A5; //sincer L

int ras=255;




void setup()
{ Serial.begin(9600);
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
//pinMode(M_A1, OUTPUT);
//pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
analogWrite(S_A, 250); 
analogWrite(S_B, 250);





}
void loop()
{ if(Serial.available() > 0)

{ command = Serial.read(); 
/*if (command==7)
{ ras++;}
else if(command==8)
{ras--;}*/
Serial.print(ras);
Stop();
switch(command)
{ case 1: forward();
break; 
case 3: back();
break;
case 4: left();
break;
case 2 : right();
break;
case 5: on();
break;
case 6: off();
break;

}

}
/*if (digitalRead(L_S) == 0)
{on();}*/

}
void forward()
{ motor1.setSpeed(255);
motor1.run(FORWARD);
motor2.setSpeed(255);
motor2.run(FORWARD);
motor3.setSpeed(255);
motor3.run(FORWARD);
motor4.setSpeed(255);
motor4.run(FORWARD); }
void back() 
{ motor1.setSpeed(255);
motor1.run(BACKWARD);
motor2.setSpeed(255);
motor2.run(BACKWARD); 
motor3.setSpeed(255); 
motor3.run(BACKWARD);
motor4.setSpeed(255);
motor4.run(BACKWARD); }
void left() 
{ motor1.setSpeed(255);
motor1.run(BACKWARD);
motor2.setSpeed(255);
motor2.run(BACKWARD);
motor3.setSpeed(255); 
motor3.run(FORWARD);
motor4.setSpeed(255);
motor4.run(FORWARD); }
void right()
{ motor1.setSpeed(255);
motor1.run(FORWARD);
motor2.setSpeed(255);
motor2.run(FORWARD);
motor3.setSpeed(255);
motor3.run(BACKWARD);
motor4.setSpeed(255);
motor4.run(BACKWARD); }
void Stop() 
{ motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0); 
motor3.run(RELEASE);
motor4.setSpeed(0);
motor4.run(RELEASE); }
void on(){
//digitalWrite(M_A1, LOW);
//digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}
void off(){
//digitalWrite(M_A1, LOW);
//digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}
