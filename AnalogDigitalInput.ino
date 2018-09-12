
int sensorPin = A0;
int digitalButton = 3;
int led = 9;
int brightness = 0;
int buttonStage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(digitalButton, INPUT);
}

void loop() {
  buttonStage = digitalRead(digitalButton);
  int sensorValue = analogRead(sensorPin);
  
  if(buttonStage == HIGH){
    digitalWrite(led,HIGH);
    brightness = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(led, brightness);
  }else{digitalWrite(led, LOW);}
    
    Serial.println(sensorValue);
    Serial.println(buttonStage);
}
