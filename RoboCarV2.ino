int left_sen= A0;   
int center_sen= A1; 
int right_sen= A2;  
int dis_center= A3;
const int AIN1= 12;
const int AIN2= 13;
const int PWMA= 11;
const int BIN1= 8;
const int BIN2= 9;
const int PWMB= 10;

int motorSpeed = 115;
int exitCount = 0;
int requiredExit = 0;
int lineStandard = 800;
int disStandard = 600;


void setup()
{ 
  pinMode(left_sen, INPUT);
  pinMode(right_sen, INPUT);
  pinMode(center_sen, INPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter number of exit...");
  delay(1000);
}

void forward() {
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void right() {
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void left() {
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void Stop() {
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void back(){
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void turnAround(){
  analogWrite(PWMA, abs(motorSpeed));
  analogWrite(PWMB, abs(motorSpeed));
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void loop(){

  Serial.println(motorSpeed);
  Serial.println(analogRead(left_sen));
  Serial.println(analogRead(right_sen));
  Serial.println(analogRead(center_sen));
  Serial.println(analogRead(dis_center));
  Serial.println("\n");
  
  if(analogRead(center_sen) > lineStandard){

   if (analogRead(left_sen) < lineStandard && analogRead(right_sen) < lineStandard){
    motorSpeed = 110;
    forward();
    delay(100);
   }
   else if ((analogRead(left_sen) > lineStandard) && (analogRead(right_sen) < lineStandard)){
    motorSpeed = 110;
    left();
    delay(100);
   }
   else if ((analogRead(right_sen) > lineStandard)&& (analogRead(left_sen) < lineStandard)){
    motorSpeed = 110;
    right();
    delay(100);
   }
   else if ((analogRead(right_sen) > lineStandard)&& (analogRead(left_sen) > lineStandard)){
      delay(100);
      motorSpeed = 150;
      forward();
      delay(100);
   }
  }
  else if (analogRead(right_sen) > lineStandard){
    motorSpeed = 110;
    right();
    delay(100);
  }
  else if (analogRead(left_sen) > lineStandard){
    motorSpeed = 110;
    left(); 
    delay(100);
  }
  else {
    Stop();
    }
  delay(200);
}
