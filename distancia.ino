#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
#define RED 4
#define GREEN 5
#define BLUE 6

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance = distance/58;                         // Calculate distance from time of pulse
  if (distance >= 100){
     Serial.println("eniende RED");
     digitalWrite(GREEN,LOW);
     digitalWrite(BLUE,LOW);
     digitalWrite(RED, HIGH);
  }   
  else if(distance < 100 && distance >= 60){
     Serial.println("eniende GREEN");
     digitalWrite(BLUE,LOW);
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, HIGH);
  }
  else if (distance < 60 && distance >= 30){
     Serial.println("eniende BLUE");
     digitalWrite(RED, LOW);
     digitalWrite(GREEN, LOW);
     digitalWrite(BLUE, HIGH);     
  }
  else if (distance <= 30){
     Serial.println("enienden Todos");
     digitalWrite(GREEN, HIGH);
     digitalWrite(BLUE, HIGH);
     digitalWrite(RED, HIGH);    
  }
  Serial.println(distance);                     
  delay(100);                                    // Wait 50mS before next ranging
}
