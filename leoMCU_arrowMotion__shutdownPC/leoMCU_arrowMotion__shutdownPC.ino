#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
#include "HID-Project.h"
const int Pin = 7;
int milsec = 200;

#define HT_DATA 2                           // winggate2
#define HT_WR   3
#define HT_CS   4

Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS);
 
void setup() {
  pinMode(Pin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Pin),shutdowm,FALLING);
  
//  Serial.begin(115200);
  matrix.begin(ADA_HT1632_COMMON_16NMOS);
  System.begin();
  delay(500);
}

void loop() {
  r_motion();
  matrix.writeScreen();
  delay(milsec);
  r_motion1();
  matrix.writeScreen();
  delay(milsec);
  r_motion2();
  matrix.writeScreen();
  delay(milsec);
  r_motion3();
  matrix.writeScreen();
  delay(milsec);
  r_motion4();
  matrix.writeScreen();
  delay(milsec);
  r_motion5();
  matrix.writeScreen();
  delay(milsec);
  r_motion6();
  matrix.writeScreen();
  delay(milsec);
  r_motion7();
  matrix.writeScreen();
  delay(milsec);
  r_motion8();
  matrix.writeScreen();
  delay(milsec);
  r_motion9();
  matrix.writeScreen();
  delay(milsec);
  r_motion10();
  matrix.writeScreen();
  delay(milsec);
  r_motion11();
  matrix.writeScreen();
  delay(milsec);
  r_motion12();
  matrix.writeScreen();
  delay(milsec);
  r_motion13();
  matrix.writeScreen();
  delay(milsec);
  r_motion14();
  matrix.writeScreen();
  delay(milsec);
  r_motion15();
  matrix.writeScreen();
  delay(milsec);
  r_motion16();
  matrix.writeScreen();
  delay(milsec);
  r_motion17();
  matrix.writeScreen();
  delay(milsec);
  r_motion18();
  matrix.writeScreen();
  delay(milsec);
  r_motion19();
  matrix.writeScreen();
  delay(milsec);
  r_motion20();
  matrix.writeScreen();
  delay(milsec);
  r_motion21();
  matrix.writeScreen();
  delay(milsec);
  r_motion22();
  matrix.writeScreen();
  delay(milsec);
  r_motion23();
  matrix.writeScreen();
  delay(milsec);
  r_motion24();
  matrix.writeScreen();
  delay(milsec);
  r_motion25();
  matrix.writeScreen();
  delay(milsec);
  r_motion26();
  matrix.writeScreen();
  delay(milsec);
  r_motion27();
  matrix.writeScreen();
  delay(milsec);
  r_motion28();
  matrix.writeScreen();
  delay(milsec);
  r_motion29();
  matrix.writeScreen();
  delay(milsec);
  r_motion30();
  matrix.writeScreen();
  delay(milsec);
  r_motion31();
  matrix.writeScreen();
  delay(milsec);
  r_motion32();
  matrix.writeScreen();
  delay(milsec);
  r_motion33();
  matrix.writeScreen();
  delay(milsec);
  r_motion34();
  matrix.writeScreen();
  delay(milsec);
}

void shutdowm(){
    System.write(SYSTEM_POWER_DOWN);
//  Serial.println("OK");               //for test
}
