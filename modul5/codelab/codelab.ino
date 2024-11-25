#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

// Uncomment this line to enable debug prints
#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "";
char pass[] = "";

// Pin configuration
const int ldrPin = 34; 

// Timer
BlynkTimer timer;

// Function to read and send LDR data
void sendData() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR VALUE: ");
  Serial.println(ldrValue);
  
  // Send value to Blynk app
  Blynk.virtualWrite(V0, ldrValue);
}

void setup() {
  // Debug console
  Serial.begin(9600);
  delay(1000);

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Check if connected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection failed!");
  } else {
    Serial.println("WiFi connected.");
  }

  // Setup timer to send LDR data every second
  timer.setInterval(1000L, sendData);
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run timer
}
