#include <stdio.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4  // 4 modules
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

long randNumber;
int step_counter = 0;
int button_values[] = {913, 429, 267, 179, 110};
int btn_tol = 20;
int analogValue = 0;
int pin_p1 = A0;
int pin_p2 = A6;
int leds_cnt = 5;
// These refer to the LED terminals of your 4-terminal buttons
int p1_leds[5] = {2,3,4,5,6};
int p2_leds[5] = {A2,A3,A4,A5,A1};
int p1_score = 0;
int p2_score = 0;
int action_speed = 2000;
int action_speed_min = 250;
bool game_over = false;
unsigned long display_toggle_time = 0;
bool showing_p1_score = true;
const int display_toggle_interval = 2000; // Toggle between scores every 2 seconds

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A7));
  
  pinMode(pin_p1, INPUT);
  pinMode(pin_p2, INPUT);
  
  // Initialize all LED terminals of the buttons as outputs
  for (int i = 0; leds_cnt > i; i++) {
    pinMode(p1_leds[i], OUTPUT);
    pinMode(p2_leds[i], OUTPUT);
  }  
  
  // Initialize the LED matrix
  P.begin();
  P.setIntensity(0); // Set brightness (0-15)
  P.displayClear();
  updateScoreDisplay();
  
  // Turn all button LEDs off initially
  for (int i = 0; i < leds_cnt; i++) {
    digitalWrite(p1_leds[i], LOW);
    digitalWrite(p2_leds[i], LOW);
  }
}

void loop()
{
  if (!game_over && p1_score < 100 && p2_score < 100) {
    // Game logic
    step_counter++;
    bool step_action = false;
    if (step_counter > action_speed) {
      step_counter = 0;
      step_action = true;  
      action_speed = action_speed - round(action_speed/50);
      if (action_speed < action_speed_min) {
        action_speed = action_speed_min;
      }
      Serial.println(action_speed);
    }
  
    if (step_action) {
      int pin_light = random(0,5);
      // Light up a random button for each player
      digitalWrite(p1_leds[pin_light], HIGH);
      digitalWrite(p2_leds[pin_light], HIGH);
    }
  
    // Player 1 button handling
    analogValue = analogRead(pin_p1);
    for (int i = 0; leds_cnt > i; i++) {
      if (analogValue < button_values[i] + btn_tol && analogValue > button_values[i] - btn_tol) {
        if(digitalRead(p1_leds[i]) == HIGH) {
          digitalWrite(p1_leds[i], LOW);
          p1_score++;
          updateScoreDisplay();
        }
      }
    }
  
    // Player 2 button handling
    analogValue = analogRead(pin_p2);
    for (int i = 0; leds_cnt > i; i++) {
      if (analogValue < button_values[i] + btn_tol && analogValue > button_values[i] - btn_tol) {
        if(digitalRead(p2_leds[i]) == HIGH) {
          digitalWrite(p2_leds[i], LOW);
          p2_score++;
          updateScoreDisplay();
        }
      }
    }
    
    // Update score display periodically
    if (step_counter % 100 == 0) {
      updateScoreDisplay();
    }
    
  } else {
    // Game over state
    if (!game_over) {
      game_over = true;
      display_toggle_time = millis();
      
      // Turn off all button LEDs at game end
      for (int i = 0; i < leds_cnt; i++) {
        digitalWrite(p1_leds[i], LOW);
        digitalWrite(p2_leds[i], LOW);
      }
    }
    
    // Toggle between winner announcement and scores
    if (millis() - display_toggle_time >= display_toggle_interval) {
      display_toggle_time = millis();
      showing_p1_score = !showing_p1_score;
      
      if (showing_p1_score) {
        // Show scores
        char scoreText[20];
        sprintf(scoreText, "P1:%d P2:%d", p1_score, p2_score);
        P.displayText(scoreText, PA_CENTER, 80, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
      } else {
        // Show winner
        if (p1_score > p2_score) {
          P.displayText("P1 WINS!", PA_CENTER, 80, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        } else if (p2_score > p1_score) {
          P.displayText("P2 WINS!", PA_CENTER, 80, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        } else {
          P.displayText("TIE GAME!", PA_CENTER, 80, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        }
      }
    }
  }
  
  // Always update the animation
  P.displayAnimate();
}

void updateScoreDisplay() {
  // For the smaller 4-module display, we'll use a compact format
  char scoreText[20];
  sprintf(scoreText, "P1:%d P2:%d", p1_score, p2_score);
  
  // Set the text to display
  P.displayText(scoreText, PA_CENTER, 80, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}