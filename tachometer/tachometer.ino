#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 6, 5, 4, 3); 

float revolutionCount = 0; 
float previousTime = 0; 
int currentTime; 
int rpm; 
int secondsPerMinute; 

void countRevolutions()
{
    revolutionCount++;
}

void setup()
{
    lcd.begin(16, 2);
    attachInterrupt(digitalPinToInterrupt(2), countRevolutions, RISING);
}

void loop()
{
    delay(1000); 
    detachInterrupt(digitalPinToInterrupt(2));
    
    currentTime = millis();
    int elapsedTime = currentTime - previousTime;
    rpm = (revolutionCount / elapsedTime) * 60000;
    
    previousTime = currentTime;
    revolutionCount = 0;
    
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("  RPM COUNTER  "); 
    lcd.setCursor(0, 1);
    lcd.print(rpm);
    lcd.print(" RPM "); 
    
    secondsPerMinute = rpm / 60; 
    lcd.print(secondsPerMinute); 
    lcd.print("/s");
    
    attachInterrupt(digitalPinToInterrupt(2), countRevolutions, RISING);
}
