#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int p1 = 4;
const int p2 = 5;

int player_1_points = 0;
int player_2_points = 0;

bool p1_state;
bool p2_state;

bool last_p1_state = false;
bool last_p2_state = false;

unsigned long p1_lastDebounceTime = 0;
unsigned long p2_lastDebounceTime = 0;  
unsigned long debounceDelay = 50;

const int orange_r = 255;
const int orange_g = 165;
const int orange_b = 0;

const int blue_r = 0;
const int blue_g = 100;
const int blue_b = 150;


void setup() {
  // put your setup code here, to run once:
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.setRGB(255, 255, 255);

  lcd.setCursor(0, 0);
  lcd.print("      Air");
  lcd.setCursor(0, 1);
  lcd.print("     Hockey");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" P1          P2 ");
}

void update_screen(){
  if (player_1_points > player_2_points){
    lcd.setRGB(blue_r, blue_g, blue_b);
  }
  else if (player_2_points > player_1_points){
    lcd.setRGB(orange_r, orange_g, orange_b);
  }
  else{
    lcd.setRGB(120, 255, 160);
  }
  
  lcd.setCursor(1, 1);
  lcd.print(player_1_points);
  lcd.setCursor(13, 1);
  lcd.print(player_2_points);

}

void loop() {
  // put your main code here, to run repeatedly:

  int p1_reading = digitalRead(p1);
  int p2_reading = digitalRead(p2);
  
  if (p1_reading != last_p1_state) {
    p1_lastDebounceTime = millis();
  }

  if (p2_reading != last_p2_state) {
    p2_lastDebounceTime = millis();
  }

  if ((millis() - p1_lastDebounceTime) > debounceDelay) {
    
    if (p1_reading != p1_state) {
      
      p1_state = p1_reading;
      
      if (p1_state == HIGH) {
        player_1_points ++;
      }
    }
  }

  if ((millis() - p2_lastDebounceTime) > debounceDelay) {
    
    if (p2_reading != p2_state) {
      
      p2_state = p2_reading;
      
      if (p2_state == HIGH) {
        player_2_points ++;
      }
    }
  }
   last_p1_state = p1_reading;
   last_p2_state = p2_reading;

   update_screen();


}
