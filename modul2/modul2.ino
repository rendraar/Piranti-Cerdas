
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

const int buzzerPin = 18; // Pin yang terhubung ke buzzer

// Frekuensi nada dalam Hertz
#define note_c4 261.63
#define note_c4has 277.18
#define note_d4 293.66
#define note_d4has 311.13
#define note_g4 392.00
#define note_g4has 415.30
#define note_a4has 466.16
#define note_c5 523.25


void setup(void) {
  Serial.begin(9600);

  while (!mpu.begin()) {
    Serial.println("MPU6050 not connected!");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");
}

sensors_event_t event;

void loop() {
  mpu.getAccelerometerSensor()->getEvent(&event);

  Serial.print("[");
  Serial.print(millis());
  Serial.print("] X: ");
  Serial.print(event.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(event.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(event.acceleration.z);
  Serial.println(" m/s^2");
  delay(500);

  // if(event.acceleration.x >= 5){
  //   playMusic();
  // }
}

void playMusic(){
  tone(buzzerPin, note_c4, 860); delay(300);
  tone(buzzerPin, note_c4has, 350); delay(300);
  tone(buzzerPin, note_d4has, 200); delay(650);
  tone(buzzerPin, note_d4has, 200); delay(650);
  tone(buzzerPin, note_d4has, 200); delay(690);
  tone(buzzerPin, note_g4has, 210); delay(550);
  tone(buzzerPin, note_g4has, 210); delay(650);
  tone(buzzerPin, note_c5, 230); delay(500);
  tone(buzzerPin, note_c5, 600); delay(350);
  tone(buzzerPin, note_a4has, 220); delay(390);
  tone(buzzerPin, note_g4has, 170); delay(600);
  tone(buzzerPin, note_g4, 150); delay(300);
  tone(buzzerPin, note_g4has, 150); delay(300);
  tone(buzzerPin, note_a4has, 150); delay(600);
  tone(buzzerPin, note_c5, 600); delay(500);
  tone(buzzerPin, note_a4has, 170); delay(390);
  tone(buzzerPin, note_g4has, 150); delay(1000);
}