#define RPWM 3 // RPWM pin (output)
#define R_EN 2 // R_EN pin (input)
#define R_IS 4 // R_IS pin (output)

#define LPWM 5 // LPWM pin (output)
#define L_EN 6 //L_EN pin (input)
#define L_IS 7 // L_IS pin (output)
#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 1 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view


#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor(R_EN, RPWM, R_IS, L_EN, LPWM, L_IS, debug);
boolean b0, c0;
boolean state = 1;

void setup()
{
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(9, INPUT_PULLUP);

  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(11, INPUT_PULLUP);

  motor.begin();
}

void loop()
{
  b0 = digitalRead(9); //uppwer switch
  c0 = digitalRead(11); //lower switch


  if (b0 == HIGH && state == 1)
  {
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
  }

  if (b0 == LOW && state == 1)
  {
    motor.stop(); // stops motor after  switch is pressed
    state = 0;
  }

  if (b0 == LOW && state == 0)
  {
    delay(5000); // requred delay for lower switch here
    motor.rotate(100, CCW); // run motor with 100% speed in CCW direction
  }



  if (c0 == HIGH && state == 0)
  {
    motor.rotate(100, CCW); // run motor with 100% speed in CCW direction
  }

  if (c0 == LOW && state == 0)
  {
    motor.stop(); // stops motor after switch is pressed
    state = 1;
  }

  if (c0 == LOW && state == 1)
  {
    delay(2000); // requred delay for upper switch here
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
  }

}
