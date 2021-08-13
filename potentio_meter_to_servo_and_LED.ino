// File takes potentiometer input (0-1023) converts to 0-180 degrees for servo output 
// AND reads it to turn on or turn off an LED on for set intervals


#include <Servo.h>      //add servo library
int pot = A0;           //set potentiometer IN pin at A0
int sg90_pin = 2;       //set servo OUT pin at digital pin 2
int angle;              //set var for storing the angle on Servo
Servo sg90;             //set var for servo in general
int LED=7;              // LED output on pin 7

//one time run
void setup()
{
  Serial.begin(9600);     //used for serial monitor output if needed
  sg90.attach(sg90_pin);  //Control pin 2  (as set above)for servo
  pinMode (LED,OUTPUT);   //sets LED (pin7) to output mode
}

//looping run
void loop()
{
  int pot_value = analogRead(pot);         //pot_value from the potentiometer
  angle = map (pot_value,0,1023,0,180);    //mapping the values from 0-1023 to 0-180
  sg90.write(angle);                       //Giving the command to move the servo motor
// Serial.println(analogRead(pot));          // to see pot_value in consol
 if (pot_value <= 500) digitalWrite(LED, HIGH); //if pot_value below OR = to 500 >> LED ON
 if (pot_value > 500) digitalWrite(LED, LOW);  //if pot_value bigger than 500 >> LED OFF
}
