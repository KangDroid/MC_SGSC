#include "usb_hid_keys.h"

uint8_t buf[8] = {
0 }; /* Keyboard report buffer */

#define PIN_ONE     2
#define PIN_TWO     3
#define PIN_THREE   4
#define PIN_FOUR    5
#define PIN_FIVE    6
#define PIN_SIX     7

int state = 1;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(200);

  pinMode(PIN_ONE, INPUT);
  pinMode(PIN_TWO, INPUT);
  pinMode(PIN_THREE, INPUT);
  pinMode(PIN_FOUR, INPUT);
  pinMode(PIN_FIVE, INPUT);
  pinMode(PIN_SIX, INPUT);

  digitalWrite(PIN_ONE, 1);
  digitalWrite(PIN_TWO, 1);
  digitalWrite(PIN_THREE, 1);
  digitalWrite(PIN_FOUR, 1);
  digitalWrite(PIN_FIVE, 1);
  digitalWrite(PIN_SIX, 1);
}

void loop()
{
  state = digitalRead(PIN_ONE);
  if (state != 1) { //0381
    buf[0] = 0;

    buf[2] = KEY_0;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_3;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_8;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_1;
    Serial.write(buf, 8);

    releaseKey();
    delay(200);
  }

  state = digitalRead(PIN_TWO);
  if (state != 1) { //0039
    buf[0] = 0;

    buf[2] = KEY_0;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_0;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_3;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_9;
    Serial.write(buf, 8);

    releaseKey();
    delay(200);
  }


  state = digitalRead(PIN_THREE);
  if (state != 1) { //0040
    buf[0] = 0;

    buf[2] = KEY_0;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_0;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_4;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_0;
    Serial.write(buf, 8);

    releaseKey();
    delay(200);
  }

  state = digitalRead(PIN_FOUR);
  if (state != 1) { //3444
    buf[0] = 0;
    
    buf[2] = KEY_3;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_4;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_4;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_4;
    Serial.write(buf, 8);
    releaseKey();
    delay(200);
  }

  state = digitalRead(PIN_FIVE);
  if (state != 1) {
    buf[0] = 0;

    buf[2] = KEY_1;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_3;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_4;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_7;
    Serial.write(buf, 8);
    releaseKey();
    delay(200);
  }

  state = digitalRead(PIN_SIX);
  if (state != 1) {
    buf[0] = 0;

    buf[2] = KEY_1;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_7;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_1;
    Serial.write(buf, 8);
    releaseKey();
    buf[2] = KEY_9;
    Serial.write(buf, 8);
    releaseKey();
    delay(200);
  }

}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
}
