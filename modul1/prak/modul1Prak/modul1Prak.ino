const int rledPin = 21;
const int gledPin = 19;
const int bledPin = 18;
const int switchPin = 17;

int switchState = 0;
unsigned long previousMillis = 0;  
const long interval = 1000;  // 1 detik
int ledStep = 0;  // Melacak langkah LED mana yang akan dinyalakan

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT);
  pinMode(rledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);
  pinMode(bledPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);
  
  if (switchState == HIGH) {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Mengatur langkah mana yang terjadi dan menyalakan/mematikan LED
      if (ledStep == 0) {
        digitalWrite(rledPin, HIGH);
      } else if (ledStep == 1) {
        digitalWrite(gledPin, HIGH);
      } else if (ledStep == 2) {
        digitalWrite(bledPin, HIGH);
      } else if (ledStep == 3) {
        digitalWrite(rledPin, LOW);
      } else if (ledStep == 4) {
        digitalWrite(gledPin, LOW);
      } else if (ledStep == 5) {
        digitalWrite(bledPin, LOW);
        ledStep = -1;  // Reset setelah semua LED mati
      }
      ledStep++;  // Lanjut ke langkah berikutnya
    }
  } else {
    // Mematikan semua LED saat switch dilepas
    digitalWrite(rledPin, LOW);
    digitalWrite(gledPin, LOW);
    digitalWrite(bledPin, LOW);
    ledStep = 0;  // Reset ke langkah pertama
  }
}
