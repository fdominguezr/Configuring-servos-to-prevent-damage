# Configuring-servos-to-prevent-damage
Calibrates servo for Arduino with a knob in microseconds reads values via serial

With an Arduino you can test a servo with a knob and reads the values in microseconds via serial. 
This soft comes from OddBot at Let's make robots here: http://letsmakerobots.com/node/39297

Text from original post from OddBot is here:

"Most students and hobbyist will use servos at some stage when building a robot. This tutorial uses Arduino sample code but the concepts are the same with any micro controller. These days there are hundreds of factories producing servos and as a result, they vary greatly in terms not only of quality but also the range of the signal required to drive them.

The original standard for the servo control signal was a pulse between 1000uS and 2000uS in width that was repeated every 20mS with 90º being a typical range of rotation. Now hobby servos often have a rotation of 180° and can accept pulses from as low as 400uS to as high as 2600uS depending on the make and model. 

So now when you build a robot with servo you really need to test the servos to determine what signal range is required. If you send the servo a signal outside of it's range then for some brands it can force the motor to stall and eventually either the motor or the motor control circuit will burn out. Even if your signal is within the servos range it is still possible to burn it out if your robots design does not allow the servo to rotate fully.

The best way to solve this problem is to manually test each servo in your robot before you start writing your code. The attached sample code will work with most Arduino or Arduino compatible controllers. It is currently configured for 8 servos but that is easily changed by redefining the constant "servos" at the start of the program."

I did a modification here to calibrate a servo at a time.
