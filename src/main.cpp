#include <Arduino.h>

volatile int AnalogInput = A0;
int raw = 0;
float V, Volts = 0.0;

#define Interval_Bat 1000
unsigned long TimeNow;

void setup() {
  pinMode (AnalogInput, INPUT);
  Serial.begin(9600);
  Serial.println("inicio");
    // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() > TimeNow + Interval_Bat){
    TimeNow = millis();
    raw = analogRead(AnalogInput);
    V = raw / 1023.0;
    Volts = V * 12.59;
    Serial.print(raw);
    Serial.print(":");
    Serial.println(Volts);    
  }

}