const int baudRate = 9600;
const int dt = 200;
const int buttonPin = 9;
const int ledPin = 11;

// Stores the button state from the PREVIOUS loop iteration
// Initialized to 0 (button not pressed) for proper rising-edge detection
// QUESTION: What if initialized to 1?
// ANSWER: First button press would be missed! The condition (oldButtonValue==0 && currentButtonValue==1)
// requires oldButtonValue to be 0, so if it starts at 1, the first press won't trigger.
// Result: User must press twice to see first toggle.
int oldButtonValue = 0;

// Tracks whether LED is ON (1) or OFF (0)
int ledState = 0;

void turnOnLED() {
  digitalWrite(ledPin, HIGH);
  ledState = 1;
}

void turnOffLED() {
  digitalWrite(ledPin, LOW);
  ledState = 0;
}


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  ledState = digitalRead(ledPin);
  oldButtonValue = digitalRead(buttonPin);
  Serial.begin(baudRate);
}

void loop() {
  // Read current button state this iteration
  int currentButtonValue = digitalRead(buttonPin);
  
  // Detect rising edge (0→1): button transitions from NOT pressed to pressed
  // This ensures toggle happens exactly once per button press
  if (oldButtonValue == 0 && currentButtonValue == 1) {
    // Button was just pressed - toggle the LED
    if (ledState == 0) {
      turnOnLED();      // LED OFF → ON
    } else if (ledState == 1) {
      turnOffLED();     // LED ON → OFF
    }
  }

  Serial.println(ledState);
  
  // Save current state to compare next loop iteration
  oldButtonValue = currentButtonValue;
  
  // Debounce: prevent multiple false triggers from button contact bounce
  delay(dt);
}

/*
================================================================================
QUESTION: What would happen if oldButtonValue was initialized to 1?
================================================================================

ANSWER: The first button press would be completely ignored/missed!

EXPLANATION of why:
  - Our rising-edge detection requires: (oldButtonValue == 0 && currentButtonValue == 1)
  - If oldButtonValue starts at 1, this condition is NEVER true on first press
  - Scenario:
    * Initialization: oldButtonValue = 1, ledState = 0 (LED OFF)
    * Loop 1 (user presses button):
      - currentButtonValue = 1 (button pressed)
      - Check: (1 == 0 && 1 == 1)? NO! ← Condition fails!
      - No toggle occurs, LED stays OFF
      - oldButtonValue = 1
    * Loop 2 (user releases button):
      - currentButtonValue = 0 (button released)
      - Check: (1 == 0 && 0 == 1)? NO
      - oldButtonValue = 0
    * Loop 3 (user presses button AGAIN):
      - currentButtonValue = 1 (button pressed)
      - Check: (0 == 0 && 1 == 1)? YES ← NOW it works!
      - Toggle happens on SECOND press
      
  RESULT: Users wonder why their first click does nothing!
  That's why initialization to 0 is critical - it matches hardware default.

================================================================================
DRY RUN EXAMPLE: Complete sequence with CORRECT initialization (oldButtonValue=0)
================================================================================

HARDWARE: Button defaults to unpressed (reads 0), LED starts OFF

INITIALIZATION:
  - oldButtonValue = 0 (button not pressed)
  - ledState = 0 (LED OFF)

─────────────────────────────────────────────────────────────────────────────
LOOP 1-3: User NOT pressing button
─────────────────────────────────────────────────────────────────────────────
  Loop 1:
    currentButtonValue = digitalRead(9) = 0 (not pressed)
    Check: (0 == 0 && 0 == 1)? NO
    → No action, LED stays OFF
    oldButtonValue = 0
    Serial: 0

  Loop 2-3: Identical to Loop 1
    Serial: 0, 0 (LED OFF)

─────────────────────────────────────────────────────────────────────────────
LOOP 4: USER PRESSES BUTTON (RISING EDGE!)
─────────────────────────────────────────────────────────────────────────────
  Loop 4:
    currentButtonValue = digitalRead(9) = 1 (button pressed/HIGH)
    Check: (0 == 0 && 1 == 1)? YES ✓ RISING EDGE DETECTED!
    → Enter if block:
      if (ledState == 0): TRUE
      turnOnLED()
        digitalWrite(11, HIGH)
        ledState = 1
    delay(200) → debounce wait
    oldButtonValue = 1
    Serial: 1 (LED ON)

─────────────────────────────────────────────────────────────────────────────
LOOP 5-7: User STILL holding button
─────────────────────────────────────────────────────────────────────────────
  Loop 5:
    currentButtonValue = 1 (still pressed)
    Check: (1 == 0 && 1 == 1)? NO ← oldButtonValue is NOW 1!
    → No toggle (critical: we only act on 0→1 transition)
    oldButtonValue = 1
    Serial: 1 (LED stays ON)

  Loop 6-7: Same as Loop 5
    Serial: 1, 1

─────────────────────────────────────────────────────────────────────────────
LOOP 8: User RELEASES button (falling edge - we ignore this)
─────────────────────────────────────────────────────────────────────────────
  Loop 8:
    currentButtonValue = 0 (released/LOW)
    Check: (1 == 0 && 0 == 1)? NO
    → No action (we don't care about falling edge, only rising)
    oldButtonValue = 0
    Serial: 1 (LED stays ON - correct!)

─────────────────────────────────────────────────────────────────────────────
LOOP 9-11: User NOT pressing again
─────────────────────────────────────────────────────────────────────────────
  Loop 9-11:
    currentButtonValue = 0
    Check: (0 == 0 && 0 == 1)? NO
    oldButtonValue = 0
    Serial: 1 (LED stays ON)

─────────────────────────────────────────────────────────────────────────────
LOOP 12: USER PRESSES BUTTON AGAIN (SECOND RISING EDGE!)
─────────────────────────────────────────────────────────────────────────────
  Loop 12:
    currentButtonValue = 1 (pressed)
    Check: (0 == 0 && 1 == 1)? YES ✓ RISING EDGE DETECTED!
    → Enter if block:
      if (ledState == 0): FALSE (ledState is 1)
      else if (ledState == 1): TRUE
      turnOffLED()
        digitalWrite(11, LOW)
        ledState = 0
    delay(200)
    oldButtonValue = 1
    Serial: 0 (LED OFF)

─────────────────────────────────────────────────────────────────────────────
SUMMARY
─────────────────────────────────────────────────────────────────────────────
Press #1 at Loop 4: LED toggles OFF→ON ✓
Press #2 at Loop 12: LED toggles ON→OFF ✓

KEY INSIGHTS:
  1. The condition detects only RISING edges (0→1), not falling edges (1→0)
  2. While button is held, condition is false (oldButtonValue becomes 1)
  3. This prevents multiple toggles from a single press ✓
  4. Delay prevents electronic bounce noise from triggering false edges
  5. Perfect toggle behavior!

*/
