
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

int motorPin = 3;

char north = 'N';

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

  Serial.println(azimuthArray[1]);

  if (azimuthArray[1] == 'N') {
    digitalWrite(motorPin, HIGH); //vibrate
    delay(250);  // delay one second
  } else {
    digitalWrite(motorPin, LOW);
    delay(250);  // delay one second
  }

  delay(50);
}
