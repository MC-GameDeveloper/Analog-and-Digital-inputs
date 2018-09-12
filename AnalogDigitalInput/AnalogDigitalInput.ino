
int sensorPinX = A0;
int sensorPinY = A1;
int digitalButton = 2;
int led = 9;
int brightness = 0;
int buttonStage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensorPinX,INPUT);
  pinMode(sensorPinY,INPUT);
  pinMode(digitalButton, INPUT);
  digitalWrite(digitalButton, HIGH);
  
}

void loop() {
  buttonStage = digitalRead(digitalButton);
  int sensorValue = analogRead(sensorPinX);
  
  if(buttonStage == LOW){
    digitalWrite(led,HIGH);
    brightness = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(led, brightness);
  }else{digitalWrite(led, LOW);}
    
    Serial.println(sensorValue);
    Serial.println(buttonStage);
}
