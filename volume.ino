void volUp() {
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  delay(30);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);

}

void volDown() {
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  delay(30);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);

}
