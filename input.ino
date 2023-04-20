void input() {

  int z = analogRead(5);

  if (z > 1021) {
    delay(100);
    relayOnOff(1);
  }
  else if (z > 1000 && z < 1021) {
    delay(100);
    relayOnOff(2);
  }
  else if (z > 950 && z < 1000) {
    delay(100);
    relayOnOff(3);
  }
  else if (z > 900 && z < 950) {
    delay(100);
    relayOnOff(4);
  }
  else if (z > 850 && z < 900) {
    delay(100);
    relayOnOff(5);
  }
  else if (z > 800 && z < 850) {
    delay(100);
    relayOnOff(6);
  }
  else if (z > 750 && z < 800) {
    delay(100);
    relayOnOff(7);
  }
  else if (z > 700 && z < 750) {
    delay(100);
    relayOnOff(8);
  }
  else if (z > 650 && z < 700) {
    delay(100);
    relayOnOff(9);
  }
  else if (z > 550 && z < 600) {
    delay(100);
    relayOnOff(10);
  }
  else if (z > 500 && z < 550) {
    delay(100);
    relayOnOff(11);
  }
  else if (z > 450 && z < 500) {
    delay(100);
    relayOnOff(12);
  }

  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0x14EB58A7:
        relayOnOff(1);
        break;

      case 0x14EB8877:
        relayOnOff(2);
        break;

      case 0x14EB906F:
        relayOnOff(3);
        break;

      case 0x14EBD827:
        relayOnOff(4);
        break;

      case 0x14EB58f7:
        relayOnOff(5);
        break;

      case 0x14EB887567:
        relayOnOff(6);
        break;

      case 0x14EB90666F:
        relayOnOff(7);
        break;

      case 0x14EBD8267:
        relayOnOff(8);
        break;

      case 0x14EB5867:
        relayOnOff(9);
        break;

      case 0x14EB8875:
        relayOnOff(10);
        break;

      case 0x14EB905F:
        relayOnOff(11);
        break;

      case 0x14EBD830:
        relayOnOff(12);
        break;

      case 0x14EB655F:
        volUp();
        break;

      case 0x14EBD85530:
        volDown;
        break;

      default : break;
    }
    irrecv.resume();
  }
}
