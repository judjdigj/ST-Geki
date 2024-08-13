#include <Joystick.h>
#include <ResponsiveAnalogRead.h>

Joystick_ Joystick;

const int ANALOG_PIN = A0;
ResponsiveAnalogRead analog(ANALOG_PIN, true);



#define LSTART 0
#define RSTART 1
#define LRED 2
#define LGREEN 3
#define LBLUE 4
#define RRED 5
#define RGREEN 6
#define RBLUE 7
#define LSIDE 8
#define RSIDE 9

void setup(){
  Serial.begin(9600);
  pinMode(LSTART, INPUT_PULLUP);
  pinMode(RSTART, INPUT_PULLUP);
  pinMode(LRED, INPUT_PULLUP);
  pinMode(LGREEN, INPUT_PULLUP);
  pinMode(LBLUE, INPUT_PULLUP);
  pinMode(RRED, INPUT_PULLUP);
  pinMode(RGREEN, INPUT_PULLUP);
  pinMode(RBLUE, INPUT_PULLUP);
  pinMode(LSIDE, INPUT_PULLUP);
  pinMode(RSIDE, INPUT_PULLUP);
  Joystick.begin();
}

void loop(){
  leverUpdate();
  buttonUpdate();
}

void leverUpdate(){
  analog.update();
  Joystick.setXAxis(analog.getValue());
}

void buttonUpdate(){
  for(int i=0;i<10;i++){
    if(digitalRead(i)){
      Joystick.releaseButton(i);
    }
    else{
      Joystick.pressButton(i);
    }
  }
}