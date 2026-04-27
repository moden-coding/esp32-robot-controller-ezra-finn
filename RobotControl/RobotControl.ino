int triggerleft = 9;
int echoleft = 8;
int triggerfront = 13;
int echofront = 12;
int triggerright = 9;
int echoright = 8;

void setup() {
  Serial.begin(115200);
  setupOTA();
  setupWebServer();
pinMode(triggerleft, OUTPUT);
  pinMode(echoleft, INPUT);
  pinMode(triggerfront, OUTPUT);
  pinMode(echofront, INPUT);
  pinMode(triggerright, OUTPUT);
  pinMode(echoright, INPUT);
  
}

void loop() {
  handleOTA();
  handleWebServer();

  
}
float getDistancefront() {
  digitalWrite(triggerfront, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerfront, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerfront, LOW);
  long duration = pulseIn(echofront, HIGH);
  float distanceCMfront = duration * 0.0343 / 2.0;

  return distanceCMfront;
}
float getDistanceleft() {
  digitalWrite(triggerleft, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerleft, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerleft, LOW);
  long duration = pulseIn(echoleft, HIGH);
  float distanceCMleft = duration * 0.0343 / 2.0;

  return distanceCMleft;
}

float getDistanceright() {
  digitalWrite(triggerright, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerright, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerright, LOW);
  long duration = pulseIn(echoright, HIGH);
  float distanceCMright = duration * 0.0343 / 2.0;

  return distanceCMright;
}