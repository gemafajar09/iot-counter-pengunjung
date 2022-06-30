#include <SoftwareSerial.h>

SoftwareSerial arduino(2,3);

#define trig1       6
#define echo1       7
#define trig2       8
#define echo2       9

#define bel1        12
#define bel2        A0
#define led         A1

long durasi1, jarak1;
long durasi2, jarak2;

int data;

void setup() {
  Serial.begin(9600);
  arduino.begin(9600);

  pinMode(bel1, OUTPUT);
  pinMode(bel2, OUTPUT);
  pinMode(led, OUTPUT);
  
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

}

void loop() {
  data = 0;
  digitalWrite(led,HIGH);

  digitalWrite(trig1, LOW);
  delayMicroseconds(10);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  delayMicroseconds(10);
  
  durasi1 = pulseIn(echo1, HIGH);
  jarak1 = (durasi1 / 2) / 29.1;

  if(jarak1 < 10 && jarak1 > 1)
  {
      data = 1;
      arduino.write(data);
      digitalWrite(bel1,HIGH);
  }else{
      digitalWrite(bel1,LOW);
  }

  digitalWrite(trig2, LOW);
  delayMicroseconds(10);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  delayMicroseconds(10);

  durasi2 = pulseIn(echo2, HIGH);
  jarak2 = (durasi2 / 2) / 29.1;

  if(jarak2 < 10 && jarak2 > 1)
  {
      data = 2;
      arduino.write(data);
      digitalWrite(bel2,HIGH);
  }else{
      digitalWrite(bel2,LOW);
  }

  delay(2000);
}
