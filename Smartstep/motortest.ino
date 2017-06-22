#include <SPI.h>
#include "motorlib.h"

  // put your setup code here, to run once:
  motorlib m1 = motorlib(8,10,9);
  motorlib m2 = motorlib(7,5,6);
  motorlib m3 = motorlib(3,4,12);
  float prev = 0;
  float curr = 0;
    int s = 1;
    
void setup() {
    
  Serial.begin(9600);
  SPI.begin();
  
  Serial.print("Starting: ");
  delay(2000);
  Serial.println(m1.getReading());
  delay(1000);
  Serial.println(m1.getReading());
  delay(1000);
  Serial.println(m1.getReading());
  delay(1000);
}

void loop() {
  int scale = 2048;
  Serial.println(s);
  m1.moves(s*scale);
  curr = m1.getReading();
  Serial.println(curr);
  Serial.print("Moved: ");
  if (curr-prev>0)
    Serial.println(8196-curr+prev);
//  else if (prev-curr>6000)
//    Serial.println(8196-prev+curr);
  else
    Serial.println(curr+8196-prev);
    
  prev = curr;
  delay(200);

  if (s >0){
    s = -1;
  }
  else {
    s = 1;
  }
  // put your main code here, to run repeatedly:
}
