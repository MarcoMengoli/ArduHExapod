#include <Servo.h>
#include <LiquidCrystal.h>

const int servoPin = 8;
const int servoSpeed = 5;

Servo ser;
LiquidCrystal lcd(12,11,5,4,3,2);

int val;
int angle;
boolean ascending = true;
int r = 0;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
    
    lcd.print("Row1");
    lcd.setCursor(0,1);
    lcd.print("Row2");
    
    ser.attach(servoPin);
}

void loop()
{
  if(ascending){
    val += servoSpeed;
  }
  else{
    val -= servoSpeed;
  }
  
  if(val >= 900)
  {
    val = 900;
    ascending = false; 
  }
  else if (val <= 0)
  {
    val = 0;
    ascending = true;
  }
  
  angle = map(val, 0, 1023, 0, 179);
  
  if(r++ == 20)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Angle: ");
    lcd.setCursor(8,0);
    lcd.print(angle);
    r = 0;
  }
  
  ser.write(angle);
  delay(15);
}
