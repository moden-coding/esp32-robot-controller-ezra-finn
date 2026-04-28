float p = 0.01;
float d = 0.03;
float target = 8;
float lasterror;
int triggerleft = 7;
int echoleft = 6;
int triggerfront = 18;
int echofront = 17;
int triggerright = 16;
int echoright = 15;
int rightB = 4;
int rightA = 5;
int leftB = 1;
int leftA = 2;

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

  float distancefront = getDistancefront();
  Serial.println(distancefront);

  float distanceleft = getDistanceleft();
  Serial.println(distanceleft);

  float distanceright = getDistanceright();
  Serial.println(distanceright);
  
  float currenterror = distanceleft - distanceright;

float error = distanceleft - distanceright;
  double difference = error * p;
  if (difference > 1) {
    difference = 1;



  } else if (difference < -1) {
    difference = -1;
  }


  leftDrive(0.7 - error * p - (currenterror - lasterror) * d);
 rightDrive(0.7 + error * p + (currenterror - lasterror) * d);

 lasterror = currenterror;
 
 delay(50);
}




float getDistancefront() {
  digitalWrite(triggerfront, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerfront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger