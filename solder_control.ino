#define BUTTON 2
#define RELAY 11
#define POT A1 

bool is_button_pressed = false;
int pulse_duration = 0;

void pulse_solder () {
  is_button_pressed = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RELAY, OUTPUT);
  pinMode(POT, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), pulse_solder, FALLING);
}

void loop() {
  pulse_duration = map(analogRead(POT), 0, 1024, 10, 30);
  
  if (is_button_pressed) {
    digitalWrite(RELAY, HIGH);
    delay(pulse_duration);
    Serial.println(pulse_duration);
    digitalWrite(RELAY, LOW);
    delay(1000);
    is_button_pressed = false;
  }
}
