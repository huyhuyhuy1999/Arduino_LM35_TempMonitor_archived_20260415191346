const int LM35_PINS[3] = {A0, A1, A2};

float readTemperatureC(int adcValue) {
  return (adcValue * 500.0) / 1023.0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValues[3];
  float temperatures[3];

  for (int i = 0; i < 3; i++) {
    adcValues[i] = analogRead(LM35_PINS[i]);
    temperatures[i] = readTemperatureC(adcValues[i]);
  }

  Serial.print(temperatures[0]);
  Serial.print(",");
  Serial.print(temperatures[1]);
  Serial.print(",");
  Serial.println(temperatures[2]);

  delay(1000);
}
