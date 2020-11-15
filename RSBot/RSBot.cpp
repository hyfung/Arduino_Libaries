#include "RSBot.h"
#include "Arduino.h"

const char bdb[] = "black dragonhide body";
const char nats[] = "nature rune";
const char herb[] =  "\ngreen:wave:Herb here\n";
char password[] = "rS52446v27bZ";
volatile int count = 5000;
String inString = "";

void ClickMode() {
  while (1) {
    Mouse.press();//Left Down
    drandom(45, 100); //Delay
    Mouse.release();//Left Up
    drandom(5000, 7500);
  }
}

void humidify() {
  while (count > 0) {
    Mouse.press();//Left Down
    drandom(800, 1050); //Delay
    Mouse.release();//Left Up
    drandom(500, 650); //Delay
    Keyboard.press('1');//S Down
    drandom(20, 70); //Delay
    Keyboard.releaseAll();//S Up
    drandom(1800, 2350); //Delay
    Keyboard.press('d');//S Down
    drandom(20, 70); //Delay
    Keyboard.releaseAll();//S Up
    drandom(3000, 4500); //Delay

  }
}

void Alch_sequence() {
  while (count > 0) {
    count--;
    segout;
    Keyboard.press('s');//S Down
    led_on(0);
    segout;
    drandom(5, 10);
    drandom(20, 70); //Delay
    segout;
    Keyboard.releaseAll();//S Up
    led_on(1);
    drandom(5, 10);
    drandom(50, 300); //Delay
    segout;
    drandom(5, 10);
    segout;
    Mouse.press();//Left Down
    led_on(2);
    segout;
    drandom(45, 100); //Delay
    Mouse.release();//Left Up
    led_on(3);
    drandom(5, 10);
    segout;
    drandom(200, 450); //Delay
    segout;
    drandom(2500, 3000);
    segout;
    all_off();
    Serial.println("Count left: " + count);
    float time_left = count * 3 / 3600;
    segout;
    Serial.println("Time left(hrs): " + (time_left, 2) );
  }
}

void GetCount() {
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      inString += (char)inChar;
    }
    if (inChar == '\n') {
      Serial.print("Count received:");
      Serial.println(inString.toInt());
      count = inString.toInt();
      inString = "";
    }
  }
}

void send_password() {
  if (pw_ok) {
    for (int i = 0; i < strlen(password); i++ ) {
      Keyboard.write(password[i]);
      delay(40);
    }
    Keyboard.write('\n');
    pw_ok = false;
  }
}

void slow_keyboard(const char* string) {
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    Keyboard.press(string[i]);
    delay(40);
    Keyboard.releaseAll();
  }
}

void say_herb() {
  slow_keyboard(herb);
}
