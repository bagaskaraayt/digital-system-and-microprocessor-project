#define PB 3
#define buzzer 4
#define LEDg 5
#define LEDr 6
#define magsens 7
#define trigPin 8
#define echoPin 9

int pushbutton=0;
int sinyal;
int distance;
long duration;

void readsensor(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PB,INPUT);
  pinMode(magsens, INPUT_PULLUP);
  pinMode(LEDg, OUTPUT);
  pinMode(LEDr, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //setting 
  readsensor();

  sinyal=digitalRead(magsens);
  while(sinyal==HIGH){
    pushbutton=digitalRead(PB);
    noTone(buzzer);
    while(pushbutton==LOW){
      digitalWrite(LEDg,LOW);
      digitalWrite(LEDr, HIGH);
      digitalWrite(buzzer, HIGH);
      delay (300);
      digitalWrite(LEDr, LOW);
      delay(300);
      readsensor();
      pushbutton=digitalRead(PB);
      Serial.print("Loop3");
    } f
    sinyal=digitalRead(magsens);
  }

  while(distance<=6 && sinyal==LOW){
    digitalWrite(LEDg, LOW);
    digitalWrite(LEDr, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(LEDr,LOW);
    digitalWrite(buzzer, LOW);
    delay(300);
    readsensor();
    sinyal=digitalRead(magsens);
    Serial.print("Loop2");
  }

  while(distance>6 && sinyal==LOW){
    digitalWrite(LEDg, HIGH);
    digitalWrite(LEDr, LOW);
    digitalWrite(buzzer, LOW);
    readsensor();
    sinyal=digitalRead(magsens);
    Serial.print("Loop1");
  }
}
