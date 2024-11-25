#include <WiFi.h>
#include <HTTPClient.h>

#define SENSORPIN 34
#define LEDPIN 25

// Replace with your network credentials
const char* ssid = "Farras";
const char* password = "mahasiswa";

// API endpoint
String serverName = String("http://172.20.10.3/pirdas_modul4/cahaya.php");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(SENSORPIN, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("\nIP Lokal: ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  int ldr_value = analogRead(SENSORPIN);
  if(ldr_value > 3000) {
    Serial.println(" Cahaya Gelap ");

    digitalWrite(LEDPIN, HIGH);

    Serial.print("Intensitas Cahaya: ");

    Serial.print(ldr_value);

    Serial.println();

  } else {
    Serial.println("Cahaya Terang ");

    digitalWrite(LEDPIN, LOW);

    Serial.print("Intensitas Cahaya: ");

    Serial.print(ldr_value);

    Serial.println();
  }
  // put your main code here, to run repeatedly:
  String url = serverName;
  url += "?ldr_value=";
  url += String(ldr_value);
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    // Construct the request
    http.begin(url);
    // Make the GET request
    int httpResponseCode = http.GET();
    if (httpResponseCode = 200) {
      Serial.println("Data sent successfully");
    }else{
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end(); // Close connection
    delay(2000);
  }
}
