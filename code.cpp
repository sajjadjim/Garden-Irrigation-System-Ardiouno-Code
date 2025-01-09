#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C dis(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  dis.init();
  dis.backlight();
  dis.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  dis.setCursor(0, 0);
  dis.print("IRRIGATION");
  dis.setCursor(0, 1);
  dis.print("SYSTEM IS ON ");
  for (int a = 12; a <= 15; a++) {
    dis.setCursor(a, 1);
    dis.print(".");
    delay(1500);
  }
  dis.clear();
}
 
void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  if (value > 950) {
    digitalWrite(2, LOW);
    dis.setCursor(0, 0);
    dis.print("MOTOR IS ON ");
  } else {
    digitalWrite(2, HIGH);
    dis.setCursor(0, 0);
    dis.print("MOTOR IS OFF");
  }
 
  if (value < 300) {
    dis.setCursor(0, 1);
    dis.print("MOISTURE : HIGH");
  } else if (value > 300 && value < 950) {
    dis.setCursor(0, 1);
    dis.print("MOISTURE : MID ");
  } else if (value > 950) {
    dis.setCursor(0, 1);
    dis.print("MOISTURE : LOW ");
  }
}
