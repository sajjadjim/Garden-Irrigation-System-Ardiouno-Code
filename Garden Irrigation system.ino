#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C dis(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dis.init();
  dis.backlight();
  dis.clear();

  // Step 1: Display school name
  dis.setCursor(0, 0);
  dis.print("Daulatpur Pilot");
  dis.setCursor(0, 1);
  dis.print("Girl's School");
  delay(3000);
  dis.clear();

  // Step 2: Display Welcome message
  dis.setCursor(3, 0); // Centered-ish
  dis.print("Welcome !!!");
  delay(2000);
  dis.clear();

  // Step 3: IRRIGATION SYSTEM startup message
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

  dis.setCursor(0, 0);
  if (value > 950) {
    digitalWrite(2, LOW);
    dis.print("MOTOR IS ON ");
  } else {
    digitalWrite(2, HIGH);
    dis.print("MOTOR IS OFF");
  }

  dis.setCursor(0, 1);
  if (value < 300) {
    dis.print("MOISTURE : HIGH");
  } else if (value < 950) {
    dis.print("MOISTURE : MID ");
  } else {
    dis.print("MOISTURE : LOW ");
  }

  delay(500); // slow down loop
}
