const int LED_PIN = 18;
const int SWITCH_PIN = 17;

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  switchState = digitalRead(SWITCH_PIN);
  if(switchState == HIGH){
    digitalWrite(LED_PIN, HIGH);
  } else{
    digitalWrite(LED_PIN, LOW);
  }
}