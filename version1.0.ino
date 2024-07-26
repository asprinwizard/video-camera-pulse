//Set current state
int triggerPin = 9;
int currentRecState = LOW;
int debug = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  if (debug) {
    Serial.begin(9600);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the raw data coming in on analog pin 0:
  int voltage = analogRead(0);
  int recState = digitalRead(A0);

  // If state has changed send a pulse
  if (recState != currentRecState) {
    if (debug) {
      Serial.println("Pulse");
    }
    currentRecState = recState;
    digitalWrite(triggerPin, HIGH);
    delay(250);
    digitalWrite(triggerPin,LOW);
  }
  if (debug) {
    Serial.println(voltage);
    Serial.println(recState);
  }
}
