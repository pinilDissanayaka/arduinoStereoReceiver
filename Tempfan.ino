void temp() {

  float t = dht.readTemperature();


  if ((t >= tempMin) && (t <= tempMax) && toggleState_12 == 1) { // if tempurature is higher than minimum temp
    fanSpeed = map(t, tempMin, tempMax, 32, 255); // the actual speed of fan
    analogWrite(fan, fanSpeed);  // spin the fan at the fanSpeed speed
  }

  if (t < tempMin && toggleState_12 == 1) {  // if t is lower than minimum temp
    fanSpeed = 0;      // fan is not spinning
    digitalWrite(fan, LOW);
  }

  if (t > tempMax && toggleState_12 == 1) {       // if t is higher than tempMax
    digitalWrite(fan, HIGH);
  }

  if (t > (tempMax + 2) && toggleState_12 == 1) {       // if t is higher than tempMax + 2
    digitalWrite(fan, HIGH);
  }

  if ((t > tempMax + 4) && toggleState_12 == 1) {       // if t is higher than tempMax + 4 amplifier should be sleep
    lcd.clear();
    lcd.setCursor(5, 2);
    lcd.print("*TEMP*");
    delay(1000);
    digitalWrite(relay_12, LOW);
    toggleState_12 = 0;
  }
}
