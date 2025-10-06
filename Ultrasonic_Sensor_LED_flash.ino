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
  // Turn off all output pins initially
  digitalWrite(led_pin, LOW);
  digitalWrite(trig, LOW);
  delay(2);

  // Send a trigger pulse to the ultrasonic sensor
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  // Record the pulse from the echo pin and convert it to centimeters
  time_from_echo = pulseIn(echo, HIGH);
  distance_in_cm = time_from_echo * 0.017;

  // Print the distance if connected to a computer
  Serial.print("Distance: ");
  Serial.print(distance_in_cm);
  Serial.print("cm");

  // Keeps the LED on or off for 88ms
  delay(88);

  // Checks the distance, and turns the LED on if it is less than 30cm
  if (distance_in_cm <= 30){
    digitalWrite(led_pin, HIGH);
  }
  // Otherwise it ensures the LED off
  else{
    digitalWrite(led_pin, LOW);
  }

  // Waits 100ms before repeating the loop
  delay(100);
}
