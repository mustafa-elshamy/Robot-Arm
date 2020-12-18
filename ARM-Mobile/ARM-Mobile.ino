#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial Bluetooth(0,1);
Servo servo1,servo2, servo3, servo4, servo5;

int servo1_pos = 85, servo2_pos = 85, servo3_pos = 150, 
    servo4_pos = 50, servo5_pos = 180;

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  
  servo1.write(servo1_pos);
  servo2.write(servo2_pos);
  servo3.write(servo3_pos);
  servo4.write(servo4_pos);
  servo5.write(servo5_pos);
}

void loop() {
  if(Bluetooth.available())
  {
    String c = Bluetooth.readStringUntil('\n');
    Serial.println(c);
    if(!c.startsWith("S"))
    { 
    if(c == "1")
        down(servo1_pos - 15 , servo1_pos,servo1,0);
    else if(c == "2")
      up(servo1_pos + 15 , servo1_pos,servo1,150);
    else if(c == "3")
    { 
      down(servo2_pos - 10 , servo2_pos,servo2,60);
      down(servo3_pos - 5 , servo3_pos,servo3,110);
      up(servo4_pos + 10 , servo4_pos,servo4,50); 
    } 
    else if(c == "4")
    { 
      up(servo2_pos + 10 , servo2_pos,servo2,130);
      up(servo3_pos + 15 , servo3_pos,servo3,190);
      down(servo4_pos - 8 , servo4_pos,servo4,10);
    }
     else if(c == "5")
      gripperClose();
    else if(c == "6")
      gripperOpen();
    }
    else
    {
      int value = (c.substring(2,c.length())).toInt();
      if(c.startsWith("S1"))
      {
        if(value > servo1_pos)
          for(;servo1_pos<=value;servo1_pos++)
          {
            servo1.write(servo1_pos);
            delay(20);
          }
        else
        { 
          for(;servo1_pos>=value;servo1_pos--)
          {
            servo1.write(servo1_pos);
            delay(20);
          }
         }
      }
      else if(c.startsWith("S2"))
      {
        if(value > servo2_pos)
          for(;servo2_pos<=value;servo2_pos++)
          {
            servo2.write(servo2_pos);
            delay(20);
          }
        else
        { 
          for(;servo2_pos>=value;servo2_pos--)
          {
            servo2.write(servo2_pos);
            delay(20);
          }
         }
      }
      else if(c.startsWith("S3"))
      {
       if(value > servo3_pos)
          for(;servo3_pos<=value;servo3_pos++)
          {
            servo3.write(servo3_pos);
            delay(20);
          }
        else
        { 
          for(;servo3_pos>=value;servo3_pos--)
          {
            servo3.write(servo3_pos);
            delay(20);
          }
         } 
      }
      else if(c.startsWith("S4"))
      {
       if(value > servo4_pos)
          for(;servo4_pos<=value;servo4_pos++)
          {
            servo4.write(servo4_pos);
            delay(20);
          }
        else
        { 
          for(;servo4_pos>=value;servo4_pos--)
          {
            servo4.write(servo4_pos);
            delay(20);
          }
         } 
      }
      else if(c.startsWith("S5"))
      {
       if(value > servo5_pos)
          for(;servo5_pos<=value;servo5_pos++)
          {
            servo5.write(servo5_pos);
            delay(20);
          }
        else
        { 
          for(;servo5_pos>=value;servo5_pos--)
          {
            servo5.write(servo5_pos);
            delay(20);
          }
         } 
      }
    }
  }
  else
  {
 // Serial.println("No data");
    delay(200);
  }
}

void up(int newVal , int& start , Servo servo,int maximum)
{
  if(start >= maximum)
  {
    start = maximum;
    return;
   }
    
  for(start + 1 ; start <= newVal ;start++)
  {
    servo.write(start);
    delay(10);
  }
}
void down(int newVal , int &start , Servo servo ,int minimum)
{
  if(start <= minimum)
  {
    start = minimum;
    return;
  }
    
  for(start - 1 ; start >= newVal ;start--)
  {
    servo.write(start);
    delay(10);
  }
}
void gripperOpen()
{
  for(; servo5_pos<= 180 ;servo5_pos++)
  {
      servo5.write(servo5_pos);
      delay(10);
 
  }
}
  void gripperClose()
{
  for(; servo5_pos >= 110 ;servo5_pos--)
  {
      servo5.write(servo5_pos);
      delay(10);
 
  }
}
