#include <Servo.h>
#include <LiquidCrystal.h>

const int servoPin = 8;
const int servoSpeed = 5;

Servo servomotore;
LiquidCrystal lcd(12,11,5,4,3,2);

int potVal;
int angle;
boolean ascending = true;
int r = 0;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
    
    lcd.print("Viva mengo");
    lcd.setCursor(0,1);
    lcd.print("viva noi");
    
    servomotore.attach(servoPin);
}

void loop()
{
  // potVal = analogRead(potenziometroPin);
  
//  Serial.print("Potenziometro valore: ");
//  Serial.print(potVal);
//  Serial.print("V");
  
  if(ascending){
     potVal += servoSpeed;
  }
  else{
    potVal -= servoSpeed;
  }
  
  if(potVal >= 900)
  {
    potVal = 900;
    ascending = false; 
  }
  else if (potVal <= 0)
  {
    potVal = 0;
    ascending = true;
  }
  
  angle = map(potVal, 0, 1023, 0, 179);
  
  if(r++ == 20)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Angolo: ");
    lcd.setCursor(8,0);
    lcd.print(angle);
    r = 0;
  }
  
  servomotore.write(angle);
  delay(15);
}
