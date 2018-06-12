
#include<Claw.h>
using namespace xzj;
MyServo servo(2, 1e6, 9600);
Sensor sensor(0,7);
Alarm alarm(4);
Controller control(servo,sensor,alarm);
double Temperature, Voltage, Position, Load, Speed;
double min_angle, max_angle;
void setup() {
  servo.init(ON);
  min_angle = servo.min_ang;
  max_angle = servo.max_ang;
   control.grab_by_p(2,70);
  control.wait_print_sensor(3000);
}
void loop() {
    servo.print(sensor.read_load());
} 
