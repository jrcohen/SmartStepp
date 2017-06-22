//arduino Library for combo encoder/driver with AS5047d and DRV8825
#ifndef motorlib_h
#define motorlib_h

#include "Arduino.h"

class motorlib
{
  public:
    motorlib(int cspin, int step, int dir);
    motorlib(int cspin, int stepsetting, int motortype, int step, int dir);
    void moves(int steps);
    void movedeg(float degrees);
    float getEncoderReading();
    float getAngleReading();
    float getReading();
    void setZero();
    void runCalibration();
  private:
    int _cspin;
    int _stepsetting;
    int _motortype;
    int _motornum;
    int _step;
    int _dir;
    float offset;
    static int motorcount;
    bool calibrated;
};

#endif

