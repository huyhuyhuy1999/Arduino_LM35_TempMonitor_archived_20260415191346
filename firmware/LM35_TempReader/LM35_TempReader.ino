const int LM35_PIN = A0;

float readTemperatureC(int adcValue) {
  return (adcValue * 500.0) / 1023.0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(LM35_PIN);
  float temperatureC = readTemperatureC(adcValue);

  Serial.print("LM35_A0=");
  Serial.println(temperatureC);

  delay(1000);
}
