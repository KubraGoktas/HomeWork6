// pin tanımlamaları
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 2;

// değişken tanımları
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); 
  
  
   attachInterrupt(0, InterruptMethod, RISING);
  
}


void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);

// mesafe hesaplama
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 200){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else {
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  
  Serial.println("guvenli mesafe");
}
}

void InterruptMethod()
{ 
  Serial.print("lutfen sosyal mesafeyi koruyun");
}
