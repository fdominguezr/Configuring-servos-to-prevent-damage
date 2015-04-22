/*
See full description and project at:
http://letsmakerobots.com/node/39297

Most students and hobbyist will use servos at some stage when building a robot. This tutorial uses Arduino sample code but the concepts are the same with any micro controller. These days there are hundreds of factories producing servos and as a result, they vary greatly in terms not only of quality but also the range of the signal required to drive them.

The original standard for the servo control signal was a pulse between 1000uS and 2000uS in width that was repeated every 20mS with 90º being a typical range of rotation. Now hobby servos often have a rotation of 180° and can accept pulses from as low as 400uS to as high as 2600uS depending on the make and model. 

So now when you build a robot with servo you really need to test the servos to determine what signal range is required. If you send the servo a signal outside of it's range then for some brands it can force the motor to stall and eventually either the motor or the motor control circuit will burn out. Even if your signal is within the servos range it is still possible to burn it out if your robots design does not allow the servo to rotate fully.

The best way to solve this problem is to manually test each servo in your robot before you start writing your code. The attached sample code will work with most Arduino or Arduino compatible controllers. It is currently configured for 8 servos but that is easily changed by redefining the constant "servos" at the start of the program.

Modification:

To calibrate only one servo at Digital out 9
Knob at Analogue Pin 0 (A0)

*/
#include <Servo.h>
#define servos 1


Servo servo[servos];                                                                      // create an array of servos
byte  svpin[servos]={   9};                            // digital I/O pins to connect servos to
int   svcen[servos]={1500};                            // stores the center  position of each servo - used for calibration
int   svmin[servos]={ 200};                            // stores the minimum position of each servo - prevents damage from over driving the servo
int   svmax[servos]={2800};                            // stores the maximum position of each servo - prevents damage from over driving the servo


void setup()
{
  for(byte i=0;i<servos;i++)                                                              // scan through servos
  {
    servo[i].attach(svpin[i],svmin[i],svmax[i]);                                          // attach servo to IO pin and set minimum and maximum limits
    servo[i].writeMicroseconds(svcen[i]);                                                 // start  servo in center position
  }
  Serial.begin(9600);
}

void loop()
{ 
  int pos=analogRead(0)*3;
  Serial.println(pos);
  servo[0].writeMicroseconds(pos);
}

