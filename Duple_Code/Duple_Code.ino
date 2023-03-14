#include <AccelStepper.h>

int light = 100;
int lightthresh = 800;
AccelStepper stepper(1, PB2, PB4); // (Typeof driver: with 2 pins, STEP, DIR)
float maxSpeed = 2000;  // # of steps per second to speeed up to

float Stop = 0;
unsigned long time;
unsigned long previousAccel = 0;
int interval = 1000;  // # of milliseconds between speed increases

int pot,PotVal,S;

void setup() {
  stepper.setSpeed(20);
  stepper.setMaxSpeed(maxSpeed); 
}

void loop() {

light = analogRead(3);
PotVal = analogRead(0);
S = map(PotVal, 0,1023, 1000 ,maxSpeed);

if (light > lightthresh){
  //while (stepper.speed() < S) {
	   // time = millis();
	  //  if (time > previousAccel + interval) {
	   //   previousAccel = time;
	  //    stepper.setSpeed(stepper.speed() + 20);
	  //  }
	    //stepper.runSpeed();
	 // }
	stepper.setSpeed(S);
	stepper.runSpeed();
	}

if (light < lightthresh){
	  while (stepper.speed() > Stop) {
	    time = millis();
	    if (time > previousAccel + interval) {
	      previousAccel = time;
	      stepper.setSpeed(stepper.speed() - 50);
	    }
	    stepper.runSpeed();
	  }
	  stepper.setSpeed(Stop);
	  stepper.runSpeed();
	}
}