#define echoPin 6
#define trigPin 7
#define buzzerPin 5
#define led1 11
#define led2 10
#define led3 9
#define led4 8
int maximumRange = 50;
int minimumRange = 0;
int deger;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{
  int olcum = distance(maximumRange, minimumRange);
  sound(olcum * 10);
  light(olcum);
}
int light(int olcum){
    if(olcum>=100){
    deger =4;
    }
    else if(olcum>=75){
    deger =3;
    }
    else if(olcum>=50){
    deger =2;
    }
    else if(olcum>=25){
    deger =1;
    }
  switch(deger){
    case 4:
      digitalWrite(led1,HIGH);
      delay(olcum-100);
      digitalWrite(led1,HIGH);
    case 3:
      digitalWrite(led2,HIGH);
      delay(olcum-75);
      digitalWrite(led2,HIGH);
    case 2:
      digitalWrite(led3,HIGH);
      delay(olcum-50);
      digitalWrite(led3,HIGH);
    case 1:
      digitalWrite(led4,HIGH);
      delay(olcum-25);
      digitalWrite(led4,HIGH);
  }
}
int distance(int maxrange, int minrange){
  
  long duration, distancev;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distancev = duration / 58.2;
  delay(50);
  if (distancev >= maxrange || distancev <= minrange)
    return 0;
  return distancev;
}

int sound(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
