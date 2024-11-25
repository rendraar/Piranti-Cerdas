const int ldrPin = 34;    // Pin untuk potensiometer
const int ledPin = 14;    // Pin untuk LED

void setup() {
  Serial.begin(115200);

  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int ledBrightness = map(ldrValue, 0, 4095, 0, 255);

  analogWrite(ledPin, ledBrightness);

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(ledBrightness);
  delay(500);
}
