void fm() {

  do {
    double test;
    Wire.begin();
    Radio.init();
    test = (87.5 + ((double)eepromRead(0, default_index)) / 10);
    if (test < 108.1) {
      Radio.set_frequency (test);
    }
    else
    {
      Radio.set_frequency (98.0);
    }
    scan_mode = 0;
    mem_index = -1;
    lcd.begin(16, 2);
    lcd.createChar(1, LED);
    lcd.createChar(2, PEAK);
    lcd.createChar(3, HPEAK);
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(0, 2);
    lcd.print("FM:         ");
  } while (0);


  while (toggleState_4 == 1) {

    now = millis();

    if ((now - last_pressed) < timegap)if (Radio.read_status(buf) == 1) {
        current_freq =  floor (Radio.frequency_available (buf) / 100000 + .5) / 10;
        stereo = Radio.stereo(buf);
        signal_level = Radio.signal_level(buf);
        lcd.setCursor(5, 2);
        lcd.print("        ");
        lcd.setCursor(5, 2);
        lcd.print(current_freq);
        lcd.setCursor(0, 3);
        if (stereo) {
          lcd.print("STEREO         ");
        } else {
          lcd.print("MONO           ");
        }
        lcd.setCursor(7, 3);
        bar(signal_level);
      }

    if (search_mode == 1) {
      if (Radio.process_search (buf, search_direction) == 1) {
        search_mode = 0;
      }
    }

    if (btn_forward.checkPress()) {
      last_pressed = millis();
      if (scan_mode == 0) {
        search_mode = 1;
        search_direction = TEA5767_SEARCH_DIR_UP;
        Radio.search_up(buf);
        delay(200);
      }
      if (scan_mode == 1)if (current_freq < 108) {
          Radio.set_frequency(current_freq + 0.1);
          delay(30);
        }
    }

    if (btn_backward.checkPress()) {
      last_pressed = millis();
      if (scan_mode == 0) {
        search_mode = 1;
        search_direction = TEA5767_SEARCH_DIR_DOWN;
        Radio.search_down(buf);
        delay(200);
      }
      if (scan_mode == 1)if (current_freq > 87.5) {
          Radio.set_frequency(current_freq - 0.1);
          delay(30);
        }
    }

    if (btn_enter.checkPress() == 1) {
      switch (scan_mode)
      {
        case 0:
          scan_mode = 1;
          lcd.setCursor(15, 2);
          lcd.print("'");
          break;

        case 1:
          lcd.setCursor(15, 2);
          lcd.print(" ");
          scan_mode = 0;
          break;


        default:
          scan_mode = 0;
          break;
      }


      delay(100);
    }


    if (btn_mode.checkPress() == 1) {

      mem_index++;
      if (mem_index > 9) {
        mem_index = 0;
      }
      Radio.set_frequency (87.5 + ((double)eepromRead(0, mem_index)) / 10);
      lcd.setCursor(0, 0);
      lcd.print("FM");
      lcd.print(mem_index);
      lcd.print("         ");
      //lcd.setCursor(5,0);
      last_pressed = millis();
      delay(30);
    }


    if (btn_mode.checkPress() == -1) {

      if (mem_index > -1) {
        eepromWrite(0, mem_index, (int)(current_freq * 10 - 875));
      }
      lcd.setCursor(0, 2);
      lcd.print("FM");
      lcd.print(mem_index);
      lcd.print(":        ");
      lcd.setCursor(5, 2);
      //lcd.print(current_freq);
      last_pressed = millis();
      delay(30);
    }



    if (btn_enter.checkPress() == -1) {

      eepromWrite(0, default_index, (int)(current_freq * 10 - 875));
      lcd.setCursor(0, 2);
      lcd.print("FM");
      lcd.print("#");
      lcd.print("         ");
      lcd.setCursor(5, 2);
      //lcd.print(current_freq);
      last_pressed = millis();
      delay(100);
    }

    delay(50);

    input();

  }
}


/********************************************************************/
void bar(int signal_lev)
{
  switch (signal_lev)
  {
    case 1:
      lcd.write(3);
      break;

    case 2:
      lcd.write(2);
      break;

    case 3:
      lcd.write(1);
      lcd.write(3);
      break;

    case 4:
      lcd.write(1);
      lcd.write(2);
      break;

    case 5:
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;

    case 6:
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      break;

    case 7:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;


    case 8:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      break;


    case 9:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;

    case 10:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      break;


    case 11:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;


    case 12:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      break;

    case 13:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;

    case 14:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      break;

    case 15:
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(3);
      break;

  }

}
