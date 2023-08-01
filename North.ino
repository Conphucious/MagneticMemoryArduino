
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

int motorPin = 3;

void setup() {
  Serial.begin(9600);
  compass.init();
  pinMode(motorPin, OUTPUT);

}

void loop() {
  compass.read();
  byte azimuth = compass.getAzimuth();
  char azimuthArray[3];
  compass.getDirection(azimuthArray, azimuth);

Serial.print("A: ");
  Serial.print(azimuthArray[0]);
  Serial.print(" .  B: ");
  Serial.print(azimuthArray[1]);
  Serial.print(" .  C: ");
  Serial.print(azimuthArray[2]);
  Serial.println("------");

  char x = azimuthArray[0];
  char y = azimuthArray[1];
  char z = azimuthArray[2];

// If North is main or secondary north is empty
  if ((x == 'E' && y == 'N') && z == 'E') {
    digitalWrite(motorPin, HIGH); //vibrate
    delay(250);  // delay quarter sec
  } else {
    digitalWrite(motorPin, LOW);
    delay(250);  // delay quarter sec
  }

  delay(50);
}
