/*
 * PIR sensor & photoresistor driven relay controller
 * version 1.1
 * Toni Alho 2019
 * 
 * NOTE: Set PIR sensor's delay to minimum, as the delay is executed via the code
 * 
 */

// Pin defining
int photoResPin = A4;         // analog (input) pin for photoresistor
int pirPin = 3;               // digital (input) pin for PIR sensor
int relayPin = 2;             // digital (output) pin for relay

// Photoresistor
int photoResVal = 0;          // variable for photoresistors value
int photoResSwitch = 500;     // ADJUSTABLE photoresistor's treshold value (0 - 1023)

// PIR                              
boolean pirVal = LOW;         // variable for reading the PIR status (LOW / HIGH)
int pirDelay = 20000;         // ADJUSTABLE delay for next conditions check, adjust in milliseconds

 
void setup() {
  pinMode(pirPin, INPUT);       // declare PIR as input
  pinMode(photoResPin, INPUT);  // declare photoresistor as input
  pinMode(relayPin, OUTPUT);    // declare relay as output
 
  Serial.begin(9600);           // Serial monitor
}


void loop(){
  pirVal = digitalRead(pirPin);               // read PIR value
  photoResVal = analogRead(photoResPin);      // read photoresistor value

  // Check if conditions for setting relay on are met
  if (pirVal == HIGH && photoResVal >= photoResSwitch) {
    digitalWrite(relayPin, HIGH);             // turn relay ON
    Serial.println("Motion detected!");       // info to serial
    delay(pirDelay);                          // keep the relay switched on for given time
    }

  else {                                      // if the conditions are not met
    digitalWrite(relayPin, LOW);              // turn relay OFF
  }

  // Info to serial for dubugging 
  Serial.println((String)"PIR state: " + pirVal);
  Serial.println((String)"Light amount: " + photoResVal + " / 1023");
  Serial.println(" ");
  delay (300);
}
