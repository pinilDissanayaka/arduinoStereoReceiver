//defines the eepromWrite function
void eepromWrite(byte highAddress, byte lowAddress, byte data) {
  Wire.beginTransmission(eeprom);
  Wire.write(highAddress);
  Wire.write(lowAddress);
  Wire.write(data);
  Wire.endTransmission();
}

//defines the eepromRead function
byte eepromRead(byte highAddress, byte lowAddress) {
  Wire.beginTransmission(eeprom);
  Wire.write(highAddress);
  Wire.write(lowAddress);
  Wire.endTransmission();

  Wire.requestFrom(eeprom, 1);
  while (!Wire.available()) {
  }
  return Wire.read();
}


/*
   highAddress = chip address
   lowAddress = memory cell address
   data = value to be store in the memory cell
*/
