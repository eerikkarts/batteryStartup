const int toggleSwitchPin = 25;
const int relayAPin = 33;
const int relayBPin = 5;
const int relayCPin = 32;

bool toggleSwitchState = false;

void setup() {
  pinMode(toggleSwitchPin, INPUT_PULLUP);
  pinMode(relayAPin, OUTPUT);
  pinMode(relayBPin, OUTPUT);
  pinMode(relayCPin, OUTPUT);
}

void loop() {
  // Read the toggle switch state
  bool newToggleSwitchState = digitalRead(toggleSwitchPin);

  if (newToggleSwitchState != toggleSwitchState) {
    // Toggle switch state has changed
    toggleSwitchState = newToggleSwitchState;

    if (toggleSwitchState == LOW) {
      // Toggle switch turned ON
      digitalWrite(relayAPin, LOW);
      delay(180);
      digitalWrite(relayBPin, LOW);
      digitalWrite(relayCPin, LOW);
      delay(500);
      digitalWrite(relayAPin, HIGH);
    } else {
      // Toggle switch turned OFF
      digitalWrite(relayCPin, HIGH);
      delay(230);
      digitalWrite(relayBPin, HIGH);
      delay(2030);
      digitalWrite(relayAPin, LOW);
      delay(20);
      digitalWrite(relayAPin, HIGH);
    }
  }
}