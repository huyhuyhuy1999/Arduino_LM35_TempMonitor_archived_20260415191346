const int LM35_PINS[2] = {A0, A1};

float readTemperatureC(int adcValue) {
  return (adcValue * 500.0) / 1023.0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValues[2];
  float temperatures[2];

  for (int i = 0; i < 2; i++) {
    adcValues[i] = analogRead(LM35_PINS[i]);
    temperatures[i] = readTemperatureC(adcValues[i]);
  }

  Serial.print(temperatures[0]);
  Serial.print(",");
  Serial.println(temperatures[1]);

  delay(1000);
}
