

#include <Servo.h>
Servo pickServo;
Servo dropServo;

#define S0 4 
#define S1 5
#define S2 7
#define S3 6
#define sensorOut 8    
int frequency = 0;
int color=0;

int detectColor() {
  // activating red photodiodes to read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("Red = ");
  Serial.print(frequency);//printing RED color frequency
  Serial.print("   ");
  delay(50);

   // activating green photodiodes to read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("Green = ");
  Serial.print(frequency);
  Serial.print("   ");

   // activating blue photodiodes to read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("Blue = ");
  Serial.print(frequency);
  Serial.println("   ");
  
  delay(50);

  delay(50);


if(R<375 & R>350 & G<360 & G>335 & B<320 & B>290){
    color = 1; // Green
       Serial.print("Detected Color is = ");
    Serial.println("GREEN");
}
    if(R<416 & R>370 & G<380 & G>345 & B<300 & B>270){
    color = 2; // Blue
       Serial.print("Detected Color is = ");
    Serial.println("BLUE");
    }

    if(R<343 & R>301 & G<372 & G>306 & B<326 & B>241){
    color = 3; // Yellow
       Serial.print("Detected Color is = ");
    Serial.println("YELLOW");
    }

    if(R<355 & R>335 & G<390 & G>370 & B<320 & B>300){
    color = 4; // Red
       Serial.print("Detected Color is = ");
    Serial.println("RED");
    }
     
    return color;
    }
/*  if(R<22 & R>20 & G<29 & G>27){
    color = 1; // Red
    Serial.print("Detected Color is = ");
    Serial.println("RED");
  }
  if(G<25 & G>22 & B<22 &B>19){
    color = 2; // Orange
      Serial.println("Orange  ");
  }
  if(R<21 & R>20 & G<28 & G>25){
    color = 3; // Green
      Serial.print("Detected Color is = ");
    Serial.println("GREEN");
  }
  if(R<38 & R>24 & G<44 & G>30){
    color = 4; // Yellow
       Serial.print("Detected Color is = ");
    Serial.println("YELLOW");
  }
  if (G<29 & G>27 & B<22 &B>19){
    color = 5; // Blue
     Serial.print("Detected Color is = ");
    Serial.println("BLUE");
  }*/
  


void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  //frequency-scaling to 20% selected
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);

  pickServo.attach(9);
  dropServo.attach(10);

  Serial.begin(9600);
}

void loop() {
  //initial position of servo motor
  pickServo.write(135);
  delay(600);
  
  for(int i = 115; i > 80; i--) {
    pickServo.write(i);
    delay(2);
  }
  delay(500);
  //read color values by calling function. save the values for conclusion in variable
  color = detectColor();
  delay(1000);  

  switch (color) {
    case 1:
    dropServo.write(70);
    
    break;

    case 2:
    dropServo.write(110);
    break;

    case 3:
    dropServo.write(140);
    break;

    case 4:
    dropServo.write(170);
    break;

    case 5:
    dropServo.write(170);
    break;
    
    case 0:
    break;
  }
  delay(500);
  
  for(int i = 65; i > 29; i--) {
    pickServo.write(i);
    delay(2);
  } 
  delay(300);
  
  for(int i = 29; i < 115; i++) {
    pickServo.write(i);
    delay(2);
  }
  color=0;
}
