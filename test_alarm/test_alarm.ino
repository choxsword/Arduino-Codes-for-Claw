#include<Alarm.h>
using namespace xzj;
Alarm alarm(5);
void setup()
{
  pinMode(5,OUTPUT);//设置蜂鸣器的pin为输出模式
}

void loop()
{

  alarm.warning();
}

