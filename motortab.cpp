#include <SPI.h>

#include "motorlib.h"
#include "Arduino.h"
#include "TableData.h"
#include <Math.h>

int motorlib::motorcount = 0;

motorlib::motorlib(int cspin, int step, int dir)
{
//  Serial.begin(9600);
  _cspin = cspin;
  _stepsetting = 32;
  _motortype = 1; // 1 for 1.8 deg/step and 2 for 0.9 deg/step
  _step = step;
  _dir = dir;
  _motornum = ++motorcount;
  if (_step == _dir){
    Serial.print("Step and Dir must be unique pins");
  }
  pinMode(_step, OUTPUT);
  pinMode(_dir, OUTPUT);
  pinMode(_cspin, OUTPUT);
  Serial.print("new motor: ");
  Serial.println(motorcount);
//  Serial.end();
  // To do later
  // Array of pins already in use by motors
  // For loop to check new pins and throw error message
  // Try/catch errors in pin assignments 
  // Try/Catch errors in motor and encoder function
}

motorlib::motorlib(int cspin, int stepsetting, int motortype, int step, int dir)
{
  Serial.begin(9600);
  _cspin = cspin;
  _stepsetting = stepsetting;
  _motortype = motortype; 
  _step = step;
  _dir = dir;
  _motornum = ++motorcount;
  if (_step == _dir){
    Serial.print("Step and Dir must be unique pins");
  }
  pinMode(_step, OUTPUT);
  pinMode(_dir, OUTPUT);
  Serial.print("new motor: ");
  Serial.println(motorcount);
  Serial.end();
}

void motorlib::moves(int steps)
{
//  Serial.begin(9600);
  if (steps < 0)
    digitalWrite(_dir, LOW);
  else
    digitalWrite(_dir, HIGH);
    
  for (int i = 0; i<abs(steps);i++) {
    digitalWrite(_step, LOW);
    delayMicroseconds(5);
    digitalWrite(_step, HIGH); 
    delayMicroseconds(600); 
  }
//  Serial.print("Moved ");
//  Serial.println(steps);
//  Serial.end();
}

void motorlib::movedeg(float deg)
{
  float type = 1.8/_motortype;
  int steps = round((deg/type)*_stepsetting);
  moves(steps);
}

float motorlib::getEncoderReading()
{
  digitalWrite(_cspin, LOW);
  byte half1 = SPI.transfer(0xFF);
  byte half2 = SPI.transfer(0xFF);
  digitalWrite(_cspin, HIGH);
  return (((half1 << 8) | half2) & 0B0011111111111111);
}

float motorlib::getAngleReading()
{ float sum = 0;
  int numreadings = 10;
  for (int i = 0; i < numreadings; i++) {
    sum += getEncoderReading();
    delay(10);
    }
  float avg = sum/numreadings;
  float angle = ((avg+16384)*360)/(32768);
  return angle;
}

float motorlib::getReading()
{ float sum = 0;
  int numreadings = 10;
  for (int i = 0; i < numreadings; i++) {
    sum += getEncoderReading();
    delay(20);
    }
  float avg = sum/numreadings;
  return avg;
}

void motorlib::setZero()
{
  float encoder = getEncoderReading();
  
}

void motorlib::runCalibration()
{
  
}

