#include <Arduino.h>
#include <Cocktail.h>
#include <Soda.h>
#include <Liquor.h>
#include <TaskHelper.h>

void TestLoop1(void* parameters)
{
  Serial.print("Task 1 running on core ");
  Serial.println(xPortGetCoreID());

  while(true)
  {

  }
}

void TestLoop2(void* parameters)
{
  Serial.print("Task 2 running on core ");
  Serial.println(xPortGetCoreID());

}

void setup() {
  Serial.begin(115200);
  std::string name = "test1";
  TaskHelper task1(name, TestLoop1, 1000, NULL, 0, TASKHELPER_PRIO_MEDIUM);
  TaskHelper task2("test2", TestLoop2, 1000, NULL, 0, TASKHELPER_PRIO_HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
}