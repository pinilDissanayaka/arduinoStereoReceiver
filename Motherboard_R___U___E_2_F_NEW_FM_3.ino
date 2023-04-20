#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <IRremote.h>
#include <DHT.h> //DHT sensor Library
#include <Button.h>
#include <TEA5767.h>
LiquidCrystal_I2C lcd(0x27, 16, 4); //defines the base address of the LCD
#define eeprom 0x50 //defines the base address of the EEPROM
#define DHTPIN 53 //Define sensor pin(pin 12)
#define DHTTYPE DHT22 //What sensor use
DHT dht(DHTPIN, DHTTYPE);//Create sensor object

int fan = 13; // pwm pin for fan
int tempMin = 37;   // the tempurature to start the fan
int tempMax = 47;   // the maximum tempurature when fan is at 100%
int fanSpeed; //variable for fan speed
int count = 1;

uint8_t bPLAY[8] = {0x00, 0x00, 0x08, 0x0C, 0x0E, 0x0C, 0x08, 0x00};
uint8_t bPAUSE[8] = {0x00, 0x00, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x00};
uint8_t bNEXT[8] = {0x00, 0x00, 0x11, 0x19, 0x1D, 0x19, 0x11, 0x00};
uint8_t bPREVIOUS[8] = {0x00, 0x00, 0x11, 0x13, 0x17, 0x13, 0x11, 0x00};
uint8_t bUPVOLUME[8] = {0x00, 0x00, 0x04, 0x04, 0x0E, 0x04, 0x04, 0x00};
uint8_t bDOWNVOLUME[8] = {0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00};

// Set the LCD address to 0x27 for a 16 chars and 2 line display


SoftwareSerial dfpSerial(16, 17);

/*************************
  DF Player Serial Format：
  1. START_BYTE     0x7E
  2. VERSION        0xFF
  3. LENGTH         0x06
  4. COMMAND        CMD / operation
  5. FEEDBACK       1: with Feedback, 0: no feedback
  6. PARAMETER_1    Parameter of Command (High data byte)
  7. PARAMETER_2    Parameter of Command (Low data byte)
  8. CHECKSUM
  9. CHECKSUM
  10. END_BYTE      0xEF

*/
# define START_BYTE 0x7E
# define VERSION    0xFF
# define LENGTH     0x06
# define FEEDBACK   0x00
# define END_BYTE   0xEF


# define ACTIVATED LOW

const byte buttonPin = 22;

int buttonNext = 59;
int buttonPause = 60;
int buttonPrevious = 61;
boolean isPlaying = false;

unsigned long buttonTimerL = 0;
unsigned long longPressTimeL = 250;
boolean buttonActiveL = false;
boolean longPressActiveL = false;

unsigned long buttonTimerR = 0;
unsigned long longPressTimeR = 250;
boolean buttonActiveR = false;
boolean longPressActiveR = false;

byte currVolume = 25;

const int relay_1 =  1; //SP A
const int relay_2 =  2; //SP B
const int relay_3 =  3; //USB MP3
const int relay_4 =  4; //FM
const int relay_5 =  5; //BT
const int relay_6 =  6; //LINE 1
const int relay_7 =  7; //LINE 2
const int relay_8 =  8; //LINE 3
const int relay_9 =  9; //CD
const int relay_10 = 10; //DIGITAL
const int relay_11 = 11; //MUTE
const int relay_12 = 12; //POWER

/*const int mswitch_1 = 23;
  const int mswitch_2 = 25;
  const int mswitch_3 = 27;
  const int mswitch_4 = 29;
  const int mswitch_5 = 31;
  const int mswitch_6 = 33;
  const int mswitch_7 = 35;
  const int mswitch_8 = 37;
  const int mswitch_9 = 39;
  const int mswitch_10 = 41;
  const int mswitch_11 = 43;
  const int mswitch_12 = 45;*/

const int RECV_PIN = 54; //IR sensor pin

IRrecv irrecv(RECV_PIN);
decode_results results;


int toggleState_1 = 0;
int toggleState_2 = 0;
int toggleState_3 = 0;
int toggleState_4 = 0;
int toggleState_5 = 0;
int toggleState_6 = 0;
int toggleState_7 = 0;
int toggleState_8 = 0;
int toggleState_9 = 0;
int toggleState_10 = 0;
int toggleState_11 = 0;
int toggleState_12 = 0;

TEA5767 Radio;
int search_mode = 1;
int search_direction;

unsigned long last_pressed = 0;
unsigned long now;
unsigned long timegap = 3200;
byte scan_mode; // 0:auto, 1:manual
int mem_index; //0 to 9,
int default_index = 10;
unsigned char buf[5];
int stereo;
int signal_level;
double current_freq;

//SPECIAL CHARACTERS
byte HPEAK[8] = {B00000, B00100, B11100, B11100, B11100, B11100, B00100, B00000}; // Half peak character
byte PEAK[8] = {B00000, B00001, B11111, B11111, B11111, B11111, B00001, B00000}; // Peak character
byte LED[8] = {B00000, B00000, B11111, B11111, B11111, B11111, B00000, B00000}; // LED like character

Button btn_forward(56, PULLUP);
Button btn_backward(55, PULLUP);
Button btn_mode(57, PULLUP, 3000);
Button btn_enter(58, PULLUP, 3000);

void bar(int signal_lev); // Prints signal level in a bar graph

void setup() {

  Wire.begin();
  dht.begin();//Start DHT22 sensor
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  pinMode(relay_5, OUTPUT);
  pinMode(relay_6, OUTPUT);
  pinMode(relay_7, OUTPUT);
  pinMode(relay_8, OUTPUT);
  pinMode(relay_9, OUTPUT);
  pinMode(relay_10, OUTPUT);
  pinMode(relay_11, OUTPUT);
  pinMode(relay_12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);

  /*pinMode(mswitch_1, INPUT_PULLUP);
    pinMode(mswitch_2, INPUT_PULLUP);
    pinMode(mswitch_3, INPUT_PULLUP);
    pinMode(mswitch_4, INPUT_PULLUP);
    pinMode(mswitch_5, INPUT_PULLUP);
    pinMode(mswitch_6, INPUT_PULLUP);
    pinMode(mswitch_7, INPUT_PULLUP);
    pinMode(mswitch_8, INPUT_PULLUP);
    pinMode(mswitch_9, INPUT_PULLUP);
    pinMode(mswitch_10, INPUT_PULLUP);
    pinMode(mswitch_11, INPUT_PULLUP);
    pinMode(mswitch_12, INPUT_PULLUP);*/
  pinMode(A0, INPUT);

  //lcd.begin(16,2);
  pinMode(buttonPause, INPUT_PULLUP);
  pinMode(buttonNext, INPUT_PULLUP);
  pinMode(buttonPrevious, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.createChar(0, bPLAY);
  lcd.createChar(1, bPAUSE);
  lcd.createChar(2, bNEXT);
  lcd.createChar(3, bPREVIOUS);
  lcd.createChar(4, bUPVOLUME);
  lcd.createChar(5, bDOWNVOLUME);

  /*lcd.home();
    lcd.setCursor(3,0);
    lcd.print("MP3 PLAYER");*/
}

void loop() {

  temp();
  input();
}
