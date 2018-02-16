/*
   Blynk leds when push button
   Button launch action
   16/02/2018
   ©Jacin Montava
*/

byte pinled_1 = 8; // Red led
byte pinled_2 = 7; // White led
byte pinled_3 = 6; // Yellow led
int delayTime = 500;
int pinbutton = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pinled_1, OUTPUT);
  pinMode(pinled_2, OUTPUT);
  pinMode(pinled_3, OUTPUT);
  pinMode(pinbutton, INPUT);
}

void loop() {
  boolean buttonState = digitalRead(pinbutton);

  Serial.print("Button state: ");
  Serial.println(buttonState);

  if(buttonState == 1) {
    launchBlynks();
  }
}

void launchBlynks() {
  sameTime_blynk();
  alternate_blynk();
  blynk_one_to_one();
}

void sameTime_blynk() {
  digitalWrite(pinled_1, HIGH);
  digitalWrite(pinled_2, HIGH);
  digitalWrite(pinled_3, HIGH);
  delay(delayTime);

  digitalWrite(pinled_1, LOW);
  digitalWrite(pinled_2, LOW);
  digitalWrite(pinled_3, LOW);
  delay(delayTime);
}

void alternate_blynk() {
  digitalWrite(pinled_1, HIGH);
  delay(delayTime);
  digitalWrite(pinled_1, LOW);

  digitalWrite(pinled_2, HIGH);
  delay(delayTime);
  digitalWrite(pinled_2, LOW);

  digitalWrite(pinled_3, HIGH);
  delay(delayTime);
  digitalWrite(pinled_3, LOW);
  delay(delayTime);
}

void blynk_one_to_one() {
  digitalWrite(pinled_1, HIGH);
  delay(delayTime);
  digitalWrite(pinled_1, LOW);
  delay(delayTime);

  digitalWrite(pinled_2, HIGH);
  delay(delayTime);
  digitalWrite(pinled_2, LOW);
  delay(delayTime);

  digitalWrite(pinled_3, HIGH);
  delay(delayTime);
  digitalWrite(pinled_3, LOW);
  delay(delayTime);
}

