void relayOnOff(int relay) {

  switch (relay) {
    case 1:
      if (toggleState_1 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_1, HIGH); // turn on relay 1 SP A
        eepromWrite(0 , 11 , HIGH);
        toggleState_1 = 1;
        lcd.setCursor(0, 0);
        lcd.print("SP A");
      }
      else {
        digitalWrite(relay_1, LOW); // turn off relay 1
        eepromWrite(0 , 11 , LOW);
        toggleState_1 = 0;
        lcd.setCursor(0, 0);
        lcd.print("    ");
      }
      delay(100);
      break;

    case 2:
      if (toggleState_2 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_2, HIGH); // turn on relay 2 SP B
        eepromWrite(0 , 12 , HIGH);
        toggleState_2 = 1;
        lcd.setCursor(4, 0);
        lcd.print("SP B");
      }
      else {
        digitalWrite(relay_2, LOW); // turn off relay 2
        eepromWrite(0 , 12 , LOW);
        toggleState_2 = 0;
        lcd.setCursor(4, 0);
        lcd.print("    ");
      }
      delay(100);
      break;

    case 3:
      if (toggleState_3 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, HIGH);// turn on relay 3 USB MP3
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , HIGH);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17, LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 1;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(7, 2);
        lcd.print("USB");
        usb();
      } /*else {
        digitalWrite(relay_3, LOW); // turn off relay 3
        toggleState_3 = 0;
      }*/
      delay(100);
      break;

    case 4:
      if (toggleState_4 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 4 FM
        digitalWrite(relay_4, HIGH);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , HIGH);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 1;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(6, 2);
        lcd.print("FM");
        fm();
      }
      /*else {
        digitalWrite(relay_4, LOW); // turn off relay 4
        toggleState_4 = 0;
        }*/
      delay(100);
      break;

    case 5:
      if (toggleState_5 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 5 BT
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, HIGH);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , HIGH);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 1;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(6, 2);
        lcd.print("BT");
      }
      /*else {
        digitalWrite(relay_1, LOW); // turn off relay 5
        toggleState_5 = 0;
        }*/
      delay(100);
      break;

    case 6:
      if (toggleState_6 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 6 LINE 1
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, HIGH);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , HIGH);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 1;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(5, 2);
        lcd.print("LINE 1");
      }
      /*else {
        digitalWrite(relay_2, LOW); // turn off relay 6
        toggleState_6 = 0;
        }*/
      delay(100);
      break;

    case 7:
      if (toggleState_7 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 7 LINE 2
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, HIGH);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , HIGH);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 1;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(5, 2);
        lcd.print("LINE 2");
      }/* else {
        digitalWrite(relay_3, LOW); // turn off relay 7
        toggleState_7 = 0;
      }*/
      delay(100);
      break;

    case 8:
      if (toggleState_8 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 8 LINE 3
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, HIGH);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , HIGH);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 1;
        toggleState_9 = 0;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(5, 2);
        lcd.print("LINE 3");
      }
      /*else {
        digitalWrite(relay_4, LOW); // turn off relay 8
        toggleState_8 = 0;
        }*/
      delay(100);
      break;

    case 9:
      if (toggleState_9 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 9 CD
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, HIGH);
        digitalWrite(relay_10, LOW);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , HIGH);
        eepromWrite(0 , 20 , LOW);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 1;
        toggleState_10 = 0;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(6, 2);
        lcd.print("CD");
      }
      /*else {
        digitalWrite(relay_1, LOW); // turn off relay 9
        toggleState_9 = 0;
        }*/
      delay(100);
      break;

    case 10:
      if (toggleState_10 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_3, LOW);// turn on relay 10 DIGITAL
        digitalWrite(relay_4, LOW);
        digitalWrite(relay_5, LOW);
        digitalWrite(relay_6, LOW);
        digitalWrite(relay_7, LOW);
        digitalWrite(relay_8, LOW);
        digitalWrite(relay_9, LOW);
        digitalWrite(relay_10, HIGH);
        digitalWrite(relay_11, LOW);
        eepromWrite(0 , 13 , LOW);
        eepromWrite(0 , 14 , LOW);
        eepromWrite(0 , 15 , LOW);
        eepromWrite(0 , 16 , LOW);
        eepromWrite(0 , 17 , LOW);
        eepromWrite(0 , 18 , LOW);
        eepromWrite(0 , 19 , LOW);
        eepromWrite(0 , 20 , HIGH);
        toggleState_3 = 0;
        toggleState_4 = 0;
        toggleState_5 = 0;
        toggleState_6 = 0;
        toggleState_7 = 0;
        toggleState_8 = 0;
        toggleState_9 = 0;
        toggleState_10 = 1;
        lcd.setCursor(0, 2);
        lcd.print("                ");
        lcd.setCursor(4, 2);
        lcd.print("DIGITAL");
      }
      /*else {
        digitalWrite(relay_2, LOW); // turn off relay 10
        toggleState_10 = 0;
        }*/
      delay(100);
      break;

    case 11:
      if (toggleState_11 == 0 && toggleState_12 == 1) {
        digitalWrite(relay_11, HIGH);// turn on relay 11 MUTE
        eepromWrite(0 , 21 , HIGH);
        toggleState_11 = 1;
        lcd.setCursor(8, 0);
        lcd.print("MUTE");
      } else {
        digitalWrite(relay_11, LOW); // turn off relay 11
        toggleState_11 = 0;
        eepromWrite(0 , 21 , LOW);
        lcd.setCursor(5, 2);
        lcd.print("    ");
      }
      delay(100);
      break;

    case 12:
      if (toggleState_12 == 0) {
        digitalWrite(relay_12, HIGH); // turn on relay 12 POWER
        toggleState_12 = 1;
      }
      else {
        digitalWrite(relay_12, LOW); // turn off relay 12
        toggleState_12 = 0;
      }
      delay(100);
      break;

    default : break;
  }

}
