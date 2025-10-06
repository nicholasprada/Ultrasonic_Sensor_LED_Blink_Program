// Define all our pin numbers and variables
const int trig = 9;
const int echo = 10;
const int led_pin = 8;
float time_from_echo, distance_in_cm;



void setup() {
  // Set the pin types for each of our input and output pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_pin, OUTPUT);

  // Set our output pins to be off initially
  digitalWrite(trig, LOW);
  digitalWrite(led_pin, LOW);

  // Begin the serial monitor to print values to the computer
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led_pin, LOW);
  digitalWrite(trig, LOW);
  delay(2);

  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  time_from_echo = pulseIn(echo, HIGH);
  distance_in_cm = time_from_echo * 0.017;

  Serial.print("Distance: ");
  Serial.print(distance_in_cm);
  Serial.print("cm");

  delay(88);
  if (distance_in_cm <= 30){
    digitalWrite(led_pin, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);
  }

  delay(100);
}
