#include<Claw.h>
using namespace xzj;
MyServo servo;
const int max_angle=160;
const int min_angle=60;
const int baud=1000000;

double Temperature,Voltage,Position,Load,Speed; 

void setup(){
 servo.begin(115200,2);  // Inicialize the servo at 1Mbps and Pin Control 2
delay(1000);
int pre=0;
 servo.torqueStatus(ON);
 servo.is_cw=false;
}

bool turn;
void loop(){
  servo.mov_speed(min_angle,30);
 do{
   Position=servo.read_pos();
   Load=servo.readLoad();
  servo.end();
  Serial.begin(115200);
  Serial.println(Load);
  Serial.end();
  servo.begin(115200);
 }while(abs(Position-min_angle)>2);
  delay(100);
  
  servo.mov_speed(max_angle,30);
   do{
   Position=servo.read_pos();
    Load=servo.readLoad();
  servo.end();
  Serial.begin(115200);
  Serial.println(Load);
  Serial.end();
  servo.begin(115200);
 }while(abs(Position-max_angle)>2);
  delay(100);
}
