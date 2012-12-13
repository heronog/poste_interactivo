#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
#define RED 5
#define GREEN 6
#define BLUE 9
//Step for RGB light output
#define STEP 15
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
  int i = 0, red = 10, green = 1, blue = 1;
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

    if (red < (TOP - STEP)) {
      red += STEP;
    } else if ( green < (TOP - STEP)) {
      green += STEP;
    } else if ( blue < (TOP - STEP)) {
      blue += STEP;
    } else {
      break;
    }
  }

  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
  
  delay(100); 
}
