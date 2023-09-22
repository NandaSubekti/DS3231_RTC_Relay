#include <DS3231.h>
#include <Wire.h>
DS3231 rtc;

const int relay=4;
bool on=LOW;
bool off=HIGH;
String hari;
String waktu;
String tanggal;
bool h12Flag;
bool pmFlag;

void setup() {
//  rtc.begin();
  Wire.begin();
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,off);
  //rtc.setDOW(THURSDAY);
  //rtc.setTime(14,20,0);
  //rtc.setDate(23,1,2020);
}

void loop() {
  hari=rtc.getDoW();
  waktu=rtc.getHour(h12Flag, pmFlag)+":"+myRTC.getMinute();
  tanggal=rtc.getDate();
  Serial.println(waktu);
  if(waktu=="14:25:00"){
    digitalWrite(relay,on);
    delay(2000);
    digitalWrite(relay,off);
  }
  delay(1000);
}
