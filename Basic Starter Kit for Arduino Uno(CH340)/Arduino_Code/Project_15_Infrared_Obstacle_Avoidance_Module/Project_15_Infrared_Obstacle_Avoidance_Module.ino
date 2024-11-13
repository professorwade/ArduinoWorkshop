// Interface to IR detection module
int ledPin = 6; // for red indicator
int sensorPin = 7; // gives the sensor pin a name
int buzzerPin = 12;  // gives the buzzer pin a name 
bool flag = false;  // define variables in the global area for all functions to be able to "see"

// setup is called once when the system boots up
void setup() {
  // all I/O pins may be configured as input, input-pullup, and output
  // some pins may be used as communication ports or A-to-D ports as well
  pinMode(buzzerPin, OUTPUT); // configure "buzzer" pin as an output
  pinMode(sensorPin, INPUT); // configure "sensor" pin as input
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

// loop function repeats indefinitely
void loop() {
    if (digitalRead(sensorPin) == 0) { // active low, meaning something is detected
      digitalWrite(buzzerPin, HIGH); // write to make sound
      if (!flag) {
        Serial.println("Obstacle detected");
        flag = true;
      }

    } else {
      digitalWrite(buzzerPin, LOW);
      flag = false;
  }
}
