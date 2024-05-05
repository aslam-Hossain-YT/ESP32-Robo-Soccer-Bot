#include "BluetoothSerial.h"
#include <Arduino.h>
BluetoothSerial serialBT;
char BT;
int Speed = 100;
//Right
int R1PWM = 19;
int R2PWM = 21;
//Left
int L1PWM = 23;
int L2PWM = 22;

#define rmf 0
#define rmb 1
#define lmf 2
#define lmb 3

void setup() {
  Serial.begin(115200);
  serialBT.begin("My Soccer Bot YT");  //Your BOT Name
  pinMode(R1PWM, OUTPUT);
  pinMode(R2PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);
  // Setup PWM channels
  ledcSetup(rmf, 5000, 8); 
  ledcAttachPin(R1PWM, rmf);
  ledcSetup(rmb, 5000, 8);  
  ledcAttachPin(R2PWM, rmb);
  ledcSetup(lmf, 5000, 8);  
  ledcAttachPin(L1PWM, lmf);
  ledcSetup(lmb, 5000, 8);
  ledcAttachPin(L2PWM, lmb);
}

void loop() {
  while (serialBT.available()) {
    BT = serialBT.read();
//speed control
    if (BT == '0') Speed = 100;
    if (BT == '1') Speed = 110;
    if (BT == '2') Speed = 120;
    if (BT == '3') Speed = 130;
    if (BT == '4') Speed = 140;
    if (BT == '5') Speed = 150;
    if (BT == '6') Speed = 180;
    if (BT == '7') Speed = 200;
    if (BT == '8') Speed = 220;
    if (BT == '9') Speed = 240;
    if (BT == 'q') Speed = 255;
//movement
    if (BT == 'F') go_forward();
    else if (BT == 'B') go_backward();
    else if (BT == 'L') go_left();
    else if (BT == 'R') go_right();
    else if (BT == 'S') stop();
    else if (BT == 'I') forward_right();
    else if (BT == 'J') backward_right();
    else if (BT == 'G') forward_left();
    else if (BT == 'H') backward_left();
  }
}

void go_forward() {
  ledcWrite(rmf, Speed);     //right motor forward 
  ledcWrite(rmb, 0);        //right motor backward
  ledcWrite(lmf, Speed);   //left motor forward
  ledcWrite(lmb, 0);      //left motor backward
}
void go_backward() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, Speed);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, Speed);
}
void go_left() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, Speed);
  ledcWrite(lmf, Speed);
  ledcWrite(lmb, 0);
}
void go_right() {
  ledcWrite(rmf, Speed);
  ledcWrite(rmb, 0);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, Speed);
}
void stop() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, 0);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, 0);
}
void forward_right() {
  ledcWrite(rmf, Speed);
  ledcWrite(rmb, 0);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, 0);
}
void backward_right() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, Speed);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, 0);
}
void forward_left() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, 0);
  ledcWrite(lmf, Speed);
  ledcWrite(lmb, 0);
}
void backward_left() {
  ledcWrite(rmf, 0);
  ledcWrite(rmb, 0);
  ledcWrite(lmf, 0);
  ledcWrite(lmb, Speed);
}
