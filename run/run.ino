#define _CLAW_DEBUG_
#include<Claw.h>
using namespace xzj;
MyServo servo(2, 1e6, 9600);
Sensor sensor(0,7);
Alarm alarm(4);
Controller control(servo,sensor,alarm);
double Temperature, Voltage, Position, Load, Speed;
double min_angle, max_angle;
double* speed=new double(5);
void setup() {
  servo.init(ON);
}


void loop(){
  //alarm.start();
  
  servo.open_claw(speed);
  time_t start=millis();

while(!servo.is_in_place(servo.min_ang));

 servo.print("open");

  servo.print(millis()-start);

  servo.close_claw(speed);
  start=millis();


while(!servo.is_in_place(servo.max_ang));

  servo.print("close");
  servo.print(millis()-start);

}

