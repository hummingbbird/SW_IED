#include <Servo.h>

// Arduino pin assignment
#define PIN_IR A0
#define PIN_SERVO 10

//Framework setting
#define _DIST_TARGET 250 
#define _DIST_MIN 100
#define _DIST_MAX 410

//Servo range
#define _DUTY_MIN 1450   // servo 위로 향하는
#define _DUTY_NEU 1500 // servo 중앙
#define _DUTY_MAX 1700 // servo 아래로 향하는

#define _SERVO_SPEED 30 // servo speed limit (unit: degree/second)
#define INTERVAL 20

// global variables
Servo myservo;
float dist_target;
float raw_dist;
unsigned long last_sampling_time; // unit: ms

void setup() {
// initialize GPIO pins
  myservo.attach(PIN_SERVO); 
  myservo.writeMicroseconds(_DUTY_NEU);

// initialize serial port
  Serial.begin(57600);

//initialize global variables
dist_target = _DIST_TARGET;
}

float ir_distance(void){ // return value unit: mm
  int a = 85;
  int b = 362;
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  val = 100 + 300.0 / (b - a) * (val - a);
  return val;
}



void loop() {
  float raw_dist = ir_distance();
  float dist_cali = 100.0 + 300/(286.0) * (raw_dist - 86.0);
  Serial.print("min:0,max:500,dist:");
  Serial.print(raw_dist);
  Serial.print(", dist_cali:");
  Serial.print(dist_cali);
  
//  delay(20);
  if (dist_cali < 235){
    myservo.writeMicroseconds(_DUTY_MAX);
  }
  else {
    myservo.writeMicroseconds(_DUTY_MIN);
  }

}
