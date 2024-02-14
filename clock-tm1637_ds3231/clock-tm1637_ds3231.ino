#include <Arduino.h>
#include <GyverSegment.h>

#define DIO_PIN 2
#define CLK_PIN 3

#include <microDS3231.h>
MicroDS3231 rtc;

Disp1637Colon disp(DIO_PIN, CLK_PIN);


void setup() {
  

}

void loop() {
  String hours;
  if(rtc.getHours() <= 9){
    hours = "0";
    hours += String(rtc.getHours());
  }
  else {
    hours = String(rtc.getHours());
  }

  String minutes;
  if(rtc.getMinutes() <= 9){
    minutes = "0";
    minutes += String(rtc.getMinutes());
  }
  else {
    minutes = String(rtc.getMinutes());
  }

  
  disp.tick();
  disp.setCursor(0);
  disp.print(hours);
  disp.setCursor(2);
  disp.print(minutes);
  disp.colon(1);
  disp.delay(700);
  disp.colon(0);
  disp.delay(700);

}
