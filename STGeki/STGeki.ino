#include <XInput.h>
#include <ResponsiveAnalogRead.h>

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
  XInput.begin();
}

void loop(){
  leverUpdate();
  buttonUpdate();
}

void leverUpdate(){
  analog.update();
  XInput.setJoystickRange(390, 520);
  XInput.setJoystickX(JOY_LEFT, analog.getValue(), true);
}

void buttonUpdate(){
  XInput.setButton(BUTTON_BACK,!digitalRead(LSTART));
  XInput.setButton(BUTTON_START,!digitalRead(RSTART));
  XInput.setButton(DPAD_LEFT,!digitalRead(LRED));
  XInput.setButton(DPAD_UP,!digitalRead(LGREEN));
  XInput.setButton(DPAD_RIGHT,!digitalRead(LBLUE));
  XInput.setButton(BUTTON_X,!digitalRead(RRED));
  XInput.setButton(BUTTON_Y,!digitalRead(RGREEN));
  XInput.setButton(BUTTON_B,!digitalRead(RBLUE));
  XInput.setButton(BUTTON_LB,!digitalRead(LSIDE));
  XInput.setButton(BUTTON_RB,!digitalRead(RSIDE));
}