int estado = 0;

void setup()
{
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if (digitalRead(9) == HIGH) {
    if (estado == 1) {
      estado = 0;
      digitalWrite(8, LOW);
    } else {
      estado = 1;
      digitalWrite(8, HIGH);
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}