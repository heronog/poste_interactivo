#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
#define RED 5
#define GREEN 6
#define BLUE 9
//Step for RGB light output
#define STEP 25
// Max PWD output
#define TOP 255

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(RED,LOW);
  analogWrite(GREEN,LOW);
  analogWrite(BLUE,LOW);
}

void loop() {                   
  int i = 0, red = 0, green = 0, blue = 0;
  // Set the trigger pin to low for 2uS
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  // Send a 10uS high to trigger ranging
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  // Send pin low again
  digitalWrite(TRIGPIN, LOW);
  // Read in times pulse
  int distance = pulseIn(ECHOPIN, HIGH);
  // Calculate distance from time of pulse
  distance = distance/58;
  Serial.print("Distance: ");
  Serial.println(distance);                     
  for (i = 0; i <= distance; i++) {
    red += STEP;

    if (red > TOP) {
      red = 0;
      green += STEP;
    }

    if (green > TOP) {
      green = 0;
      blue += STEP;
    }

    if (blue > TOP) {
      blue = TOP;
    }

  }

  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
  
  delay(100); 
}
