//Set current state
int triggerPin = 9;
int statusLedPin = 6;
int triggerLedPin = 13;
int currentRecState = LOW;
const int STARTUP_DELAY = 1000;
int recStateType;
int isRecording = LOW;
int debug = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(statusLedPin, OUTPUT);
  pinMode(triggerLedPin, OUTPUT);
  
  if (debug) {
    Serial.begin(9600);
  }

  // Delay start before reading state of remote pin
  delay(STARTUP_DELAY);
  recStateType = (digitalRead(A0) == HIGH) ? LOW : HIGH;
  currentRecState = digitalRead(A0);
  //Serial.println(recStateType);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the raw data coming in on analog pin 0:
  int voltage = analogRead(0);
  int recState = digitalRead(A0);

  // If state has changed send a pulse
  if (recState != currentRecState) {

    // Set rec state
    currentRecState = recState;
    isRecording = (currentRecState == recStateType) ? HIGH : LOW; 

    // Set rec status led
    digitalWrite(statusLedPin, isRecording);

    if (debug) {
      Serial.println("Pulse");
    }

    //Pulse trigger and led
    digitalWrite(triggerPin, HIGH);
    digitalWrite(triggerLedPin, HIGH);
    delay(250);
    digitalWrite(triggerPin,LOW);
    digitalWrite(triggerLedPin,LOW);
  }
  
  if (debug) {
    Serial.println(voltage);
    Serial.println(recState);
  }
}
