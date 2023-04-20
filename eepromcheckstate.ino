void eepromcheckstate()
{
  toggleState_1 = eepromRead(0, 11);
  if (toggleState_1 == HIGH) {
    digitalWrite(relay_1, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("SP A");
  }
  if (toggleState_1 == LOW) {
    digitalWrite(relay_1, LOW);
    lcd.setCursor(0, 0);
    lcd.print("    ");
  }

  toggleState_2 = eepromRead(0, 12);
  if (toggleState_2 == HIGH) {
    digitalWrite(relay_2, HIGH);
    lcd.setCursor(4, 0);
    lcd.print("SP B");
  }
  if (toggleState_2 == LOW) {
    digitalWrite(relay_2, LOW);
    lcd.setCursor(4, 0);
    lcd.print("    ");
  }

  toggleState_3 = eepromRead(0, 13);
  if (toggleState_3 == HIGH) {
    digitalWrite(relay_3, HIGH);// turn on relay 3 USB MP3
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(7, 1);
    lcd.print("USB");
    usb();
  }
  if (toggleState_3 == LOW) {
    digitalWrite(relay_3, LOW);
  }

  toggleState_4 = eepromRead(0, 14);
  if (toggleState_4 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 4 FM
    digitalWrite(relay_4, HIGH);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(6, 1);
    lcd.print("FM");
    delay(200);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    fm();
  }
  if (toggleState_4 == LOW) {
    digitalWrite(relay_4, LOW);
  }

  toggleState_5 = eepromRead(0, 15);
  if (toggleState_5 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 5 BT
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, HIGH);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(6, 1);
    lcd.print("BT");
  }
  if (toggleState_5 == LOW) {
    digitalWrite(relay_5, LOW);
  }

  toggleState_6 = eepromRead(0, 16);
  if (toggleState_6 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 6 LINE 1
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, HIGH);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(5, 1);
    lcd.print("LINE 1");
  }
  if (toggleState_6 == LOW) {
    digitalWrite(relay_6, LOW);
  }

  toggleState_7 = eepromRead(0, 17);
  if (toggleState_7 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 7 LINE 2
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, HIGH);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(5, 1);
    lcd.print("LINE 2");
  }
  if (toggleState_7 == LOW) {
    digitalWrite(relay_7, LOW);
  }

  toggleState_8 = eepromRead(0, 18);
  if (toggleState_8 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 8 LINE 3
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, HIGH);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(5, 1);
    lcd.print("LINE 3");
  }
  if (toggleState_8 == LOW) {
    digitalWrite(relay_8, LOW);
  }

  toggleState_9 = eepromRead(0, 19);
  if (toggleState_9 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 9 CD
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, HIGH);
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(6, 1);
    lcd.print("CD");
  }
  if (toggleState_9 == LOW) {
    digitalWrite(relay_9, LOW);
  }

  toggleState_10 = eepromRead(0, 20);
  if (toggleState_10 == HIGH) {
    digitalWrite(relay_3, LOW);// turn on relay 10 DIGITAL
    digitalWrite(relay_4, LOW);
    digitalWrite(relay_5, LOW);
    digitalWrite(relay_6, LOW);
    digitalWrite(relay_7, LOW);
    digitalWrite(relay_8, LOW);
    digitalWrite(relay_9, LOW);
    digitalWrite(relay_10, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(4, 1);
    lcd.print("DIGITAL");
  }
  if (toggleState_10 == LOW) {
    digitalWrite(relay_10, LOW);
    lcd.setCursor(0, 2);
  }

  toggleState_11 = eepromRead(0, 21);
  if (toggleState_11 == HIGH) {
    digitalWrite(relay_11, HIGH);
    lcd.setCursor(8, 0);
    lcd.print("MUTE");
  }
  if (toggleState_11 == LOW) {
    digitalWrite(relay_11, LOW);
    lcd.setCursor(8, 0);
    lcd.print("    ");
  }
}
