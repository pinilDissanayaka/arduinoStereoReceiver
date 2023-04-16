void eepromcheckstate()
{
  toggleState_1 = eepromRead(0, 11);
  if (toggleState_1 == HIGH) {
    digitalWrite(relay_1, HIGH);
  }
  if (toggleState_1 == LOW) {
    digitalWrite(relay_1, LOW);
  }

  toggleState_2 = eepromRead(0, 12);
  if (toggleState_2 == HIGH) {
    digitalWrite(relay_2, HIGH);
  }
  if (toggleState_2 == LOW) {
    digitalWrite(relay_2, LOW);
  }

  toggleState_3 = eepromRead(0, 13);
  if (toggleState_3 == HIGH) {
    digitalWrite(relay_3, HIGH);
  }
  if (toggleState_3 == LOW) {
    digitalWrite(relay_3, LOW);
  }

  toggleState_4 = eepromRead(0, 14);
  if (toggleState_4 == HIGH) {
    digitalWrite(relay_4, HIGH);
  }
  if (toggleState_4 == LOW) {
    digitalWrite(relay_4, LOW);
  }

  toggleState_5 = eepromRead(0, 15);
  if (toggleState_5 == HIGH) {
    digitalWrite(relay_5, HIGH);
  }
  if (toggleState_5 == LOW) {
    digitalWrite(relay_5, LOW);
  }

  toggleState_6 = eepromRead(0, 16);
  if (toggleState_6 == HIGH) {
    digitalWrite(relay_6, HIGH);
  }
  if (toggleState_6 == LOW) {
    digitalWrite(relay_6, LOW);
  }

  toggleState_7 = eepromRead(0, 17);
  if (toggleState_7 == HIGH) {
    digitalWrite(relay_7, HIGH);
  }
  if (toggleState_7 == LOW) {
    digitalWrite(relay_7, LOW);
  }

  toggleState_8 = eepromRead(0, 18);
  if (toggleState_8 == HIGH) {
    digitalWrite(relay_8, HIGH);
  }
  if (toggleState_8 == LOW) {
    digitalWrite(relay_8, LOW);
  }

  toggleState_9 = eepromRead(0, 19);
  if (toggleState_9 == HIGH) {
    digitalWrite(relay_9, HIGH);
  }
  if (toggleState_9 == LOW) {
    digitalWrite(relay_9, LOW);
  }

  toggleState_10 = eepromRead(0, 20);
  if (toggleState_10 == HIGH) {
    digitalWrite(relay_10, HIGH);
  }
  if (toggleState_10 == LOW) {
    digitalWrite(relay_10, LOW);
  }

  toggleState_11 = eepromRead(0, 21);
  if (toggleState_11 == HIGH) {
    digitalWrite(relay_11, HIGH);
  }
  if (toggleState_11 == LOW) {
    digitalWrite(relay_11, LOW);
  }
}
