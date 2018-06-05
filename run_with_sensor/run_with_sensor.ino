#include<Claw.h>
using namespace xzj;
MyServo servo(2, 1e6, 9600);
Sensor sensor(0,7);

double Temperature, Voltage, Position, Load, Speed;
double min_angle, max_angle;
void setup() {
  servo.init(ON);
  min_angle = servo.min_ang;
  max_angle = servo.max_ang;
}

void loop() {
  servo.ledStatus(OFF);
  servo.mov_speed(min_angle, 40);
  do {
    Position = servo.read_pos();
    Load = servo.readLoad();
    servo.print(sensor.read_load());
  } while (abs(Position - min_angle) > 2);
  delay(100);
  servo.mov_speed(max_angle, 10);
  do {
    double load = sensor.read_load();
    if (load > 7) {
      servo.ledStatus(ON);
      servo.mov_to(Position+0.29);
     unsigned long  start=millis();
      servo.shut();
      while(millis()-start<3000){
         Serial.println(sensor.read_load());
      }
      servo.launch();
      break;
    }
    servo.print(load);
  } while (abs(Position - max_angle) > 2);
  delay(100);
}
