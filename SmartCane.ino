 //Make a smart stick that helps the Blind
 //Defining pins in Arduino
 #define trigPin 5
 #define echoPin 6
 #define Buzzer 3
 #define Led 2
 //Defining variables for ultrasonic
 long duration;
 int distance;

void setup() 
{
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(Buzzer, OUTPUT);
 pinMode(Led, OUTPUT);
}

void loop() 
{
  //Setup of Ultrasonic
  //Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculating the distance
  distance= duration*0.034/2;
  //Checking with moniter of the IDE if the readings are correct
  Serial.println(distance);
  if (distance <= 25)
  {
    //Dangerously close
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
  }
  
  else if (distance <= 65)
  {
    //Close
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(55);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    delay(55);
  }
  else if (distance <= 100)
  {
    //Near
    digitalWrite(Buzzer,HIGH);
    digitalWrite(Led,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
    delay(100);
  }
  else
  {
    digitalWrite(Buzzer,LOW);
    digitalWrite(Led,LOW);
  }
}
