// display all keycodes
void displayKeyCodes(void) {
  uint8_t i = 0;

  // while (1) {
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.print("Codes 0x");
  lcd.print(i, HEX);
  lcd.print("-0x");
  lcd.print(i + 16, HEX);
  lcd.setCursor(0, 3);

  for (int j = 0; j < 16; j++) {
    lcd.write(i + j);
  }
  i += 16;

  delay(4000);
  // }
}

void usb () {

  do {
    dfpSerial.begin(9600);
    delay(1000);
    //playFirst();
    isPlaying = false;

    setVolume(currVolume);
    delay(500);

    Serial.println("Setup Completed.");
  } while (0);


  while (toggleState_3 == 1) {
    // Button PREVIOUS / Volume DOWN
    if (digitalRead(buttonPrevious) == LOW) {
      if (buttonActiveL == false) {
        buttonActiveL = true;
        buttonTimerL = millis();
      }
      //if ((millis() - buttonTimerL > longPressTimeL) && (longPressActiveL == false)) {
      if (millis() - buttonTimerL > longPressTimeL) { // multiple long press
        longPressActiveL = true;
        volumeDown();
        Serial.println("Volume DOWN: ");
        Serial.println(currVolume);
      }
    }
    else {
      if (buttonActiveL == true) {
        if (longPressActiveL == true) {
          longPressActiveL = false;
        } else {
          playPrevious();
          Serial.println("Playing PREVIOUS song");

        }
        buttonActiveL = false;
      }
    }

    // Button PLAY / PAUSE
    if (digitalRead(buttonPause) == ACTIVATED)
    {
      Serial.println("Button PLAY");
      if (isPlaying)
      {
        pause();
        isPlaying = false;
        Serial.println("Pause");

      } else
      {
        isPlaying = true;
        play();
        Serial.println("Play");

      }
    }

    // Button NEXT / Volume UP
    if (digitalRead(buttonNext) == LOW) {
      if (buttonActiveR == false) {
        buttonActiveR = true;
        buttonTimerR = millis();
      }

      //if ((millis() - buttonTimerR > longPressTimeR) && (longPressActiveR == false)) {
      if (millis() - buttonTimerR > longPressTimeR) { // Try multiple long press
        longPressActiveR = true;
        volumeUp();
        Serial.println("Volume UP: ");

        Serial.println(currVolume);
      }

    }
    else {
      if (buttonActiveR == true) {
        if (longPressActiveR == true) {
          longPressActiveR = false;
        } else {
          playNext();
          Serial.println("Playing NEXT song");

        }
        buttonActiveR = false;
      }
    }

    input() ;
  
  }
}


void play() {
  // Playback
  execute_CMD(0x0D, 0, 1);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("Play");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(6, 3);
  lcd.print("Play");
  delay(500);
}

void pause() {
  execute_CMD(0x0E, 0, 0);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(14, 3);
  lcd.write(1);
  lcd.setCursor(0, 3);
  lcd.print("Pause");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(5, 3);
  lcd.print("Pause");
  delay(500);
}

void playNext() {
  // Next
  execute_CMD(0x01, 0, 1);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(14, 3);
  lcd.write(2);
  lcd.setCursor(0, 3);
  lcd.print("Next");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(6, 3);
  lcd.print("Play");
  delay(500);
}

void playPrevious() {
  // Previous
  execute_CMD(0x02, 0, 1);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(14, 3);
  lcd.write(3);
  lcd.setCursor(0, 3);
  lcd.print("Previous");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 3);
  lcd.print("                ");
  lcd.setCursor(6, 3);
  lcd.print("Play");
  delay(500);
}

void volumeUp() {
  if (currVolume < 30) {
    currVolume++;
    setVolume(currVolume);
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(14, 3);
    lcd.write(4);
    lcd.setCursor(0, 3);
    lcd.print("Vol-UP");
    delay(1000);
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(6, 3);
    lcd.print("Play");
    delay(500);
  }
}


void volumeDown() {
  if (currVolume > 0) {
    currVolume--;
    setVolume(currVolume);
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(14, 3);
    lcd.write(5);
    lcd.setCursor(0, 3);
    lcd.print("Vol-DOWN");
    delay(1000);
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(6, 3);
    lcd.print("Play");
    delay(500);
  }
}

void setVolume(int volume) {
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2) {
  // Excecute the command and parameters

  // Calculate the checksum (2 bytes)
  word checksum = -(VERSION + LENGTH + CMD + FEEDBACK + Par1 + Par2);

  // Build the command line
  byte Command_line[10] = { START_BYTE, VERSION, LENGTH, CMD, FEEDBACK,
                            Par1, Par2, highByte(checksum), lowByte(checksum), END_BYTE
                          };

  //Send the command line to the module
  for (byte k = 0; k < 10; k++) {
    dfpSerial.write(Command_line[k]);
  }
}
