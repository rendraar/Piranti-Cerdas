/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "BLYNK_AUTH_TOKEN"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// Your WiFi credentials.
char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASSWORD";
const int ldrPin = 34; BlynkTimer timer;
void sendData()
{
int ldrValue = analogRead(ldrPin);
Serial.println("LDR VALUE: ");
Serial.println(ldrValue);
// You can send any value at any time.
// Please don't send more that 10 values per second.
Blynk.virtualWrite(V0, ldrValue);
}
void setup()
{
// Debug console
Serial.begin(9600);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
// Setup a function to be called every second timer.setInterval(1000L, sendData);
}
void loop()
}
Blynk.run();
timer.run(); // Initiates BlynkTimer
}