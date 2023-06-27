// Define pin assignments
const int trigPin = 9;
const int echoPin = 10;
const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;

// Define distance thresholds for traffic light control
const int lowThreshold = 20;   // Low traffic density threshold (in centimeters)
const int highThreshold = 40;  // High traffic density threshold (in centimeters)

// Initialize variables
long duration;
int distance;

void setup() {
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Generate ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;

  // Traffic light control based on distance
  if (distance >= highThreshold) {
    // High traffic density, both lights turn red
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (distance >= lowThreshold) {
    // Medium traffic density, red light on one side, green light on the other
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  } else {
    // Low traffic density, both lights turn green
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
