#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Wi-Fi credentials
// Replace these placeholders with your own credentials locally.
// Do not commit real credentials to a public repository.
const char* ssid = "YOUR_WIFI_NAME";
const char* pwd = "YOUR_WIFI_PASSWORD";

// Server configuration
const char* host = "http://tsm.ecssofttech.com";
String get_host = "http://tsm.ecssofttech.com/";

WiFiServer server(80);

// Pin configuration
int trig1 = 26;
int echo1 = 27;
int trig2 = 33;
int echo2 = 25;
int buz = 16;
int rain = 34;
int pump = 4;

int state1 = 0;
long duration1, cm1, duration2, cm2;

// Function declaration
void sensor1();
void sensor2();
void get_device_status();

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("IoT Based Flood");

  lcd.setCursor(0, 1);
  lcd.print("Detect & DamCtrl");

  delay(5000);
  lcd.clear();

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(pump, OUTPUT);

  digitalWrite(pump, HIGH);

  Serial.begin(9600);

  WiFi.begin(ssid, pwd);
  server.begin();
}

void loop() {
  sensor1();
  sensor2();
}

void sensor1() {
  digitalWrite(trig1, LOW);
  delayMicroseconds(5);

  digitalWrite(trig1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1, LOW);

  duration1 = pulseIn(echo1, HIGH);
  cm1 = (duration1 / 2) / 20.9;

  Serial.print("distance1 ");
  Serial.println(cm1);

  if (cm1 > 20 && cm1 < 400) {
    digitalWrite(pump, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print("Less Than 50%");

    delay(2000);
    lcd.clear();

    state1 = 0;
  }
  else if (cm1 <= 20 && cm1 > 5) {
    state1 = 0;

    float per = cm2 * (100 / 35);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print(100 - per);

    lcd.setCursor(6, 1);
    lcd.print("% Full");

    digitalWrite(pump, HIGH);

    delay(2000);
    lcd.clear();
  }
  else if (cm1 <= 5 && cm1 >= 0) {
    state1 = 1;
    digitalWrite(pump, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print("almost full");

    get_device_status();

    delay(2000);
    lcd.clear();
  }
}

void sensor2() {
  digitalWrite(trig2, LOW);
  delayMicroseconds(5);

  digitalWrite(trig2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2, LOW);

  duration2 = pulseIn(echo2, HIGH);
  cm2 = (duration2 / 2) / 20.9;

  Serial.print("distance2 ");
  Serial.println(cm2);

  delay(1000);

  if (cm2 > 20 && cm2 < 400) {
    digitalWrite(pump, HIGH);
    digitalWrite(buz, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print("Less Than 50%");

    delay(2000);
    lcd.clear();

    state1 = 0;
  }
  else if (cm2 <= 20 && cm2 > 5) {
    digitalWrite(pump, HIGH);

    float per = cm2 * (100 / 35);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print(100 - per);

    lcd.setCursor(6, 1);
    lcd.print("% Full");

    delay(2000);

    digitalWrite(buz, LOW);
    lcd.clear();

    state1 = 0;
  }
  else if (cm2 <= 5 && cm2 >= 0) {
    digitalWrite(pump, LOW);
    digitalWrite(buz, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("Dam Level is");

    lcd.setCursor(0, 1);
    lcd.print("almost full");

    delay(2000);
    lcd.clear();

    state1 = 1;

    get_device_status();
  }
}

