#include<Claw.h>
using namespace xzj;
MyServo servo(2,1e6,9600);
double Position,Load,Speed; 
void setup(){
servo.init(OFF);
}

void loop(){

 // Speed=servo.read_speed();
  //Load=servo.read_load();
  servo.print(servo.readPosition());
}
