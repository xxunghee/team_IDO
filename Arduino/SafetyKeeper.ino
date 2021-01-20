#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo;

int Relaypin = 12;
int motor_pin = 2;
int water_pin = A0;
int flame_pin = 7;
int gas_pin = A2;
int dust_sensor = A1;

SoftwareSerial mySerial(3,4);

int water = 0;
int gas = 0;
int angle = 90;
int flame_state = 0;
int sensor_led = 8;  
int sampling = 280;    // 미세먼지를 측정하는 샘플링 시간
int waiting = 40;    
float stop_time = 9680;   // 센서를 구동하지 않는 시간
float dust_value = 0;  // 센서에서 입력 받은 미세먼지 값
float dustDensityug=0;  // ug/m^3 값을 계산

void setup() {
  servo.attach(motor_pin);
  pinMode(water_pin,INPUT);
  pinMode(flame_pin,INPUT);
  pinMode(gas_pin,INPUT);
  pinMode(sensor_led,OUTPUT); // 미세먼지 적외선 led를 출력으로 설정
  pinMode(Relaypin,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  flame_check();
  water_check();
  dust_check();
}

void flame_check() {
  flame_state = digitalRead(flame_pin);
  if(flame_state == 1) {  // 화염 감지가 된 경우
    mySerial.println("1");
    Serial.println("1");
  }
  else if(flame_state != 1) { // 화염 감지가 안 된 경우
    mySerial.println("5");
    Serial.println("5");
  }
  delay(150);
}

void water_check() {
  if(analogRead(water_pin)>=200){ // 물이 찬 경우
    mySerial.println("2");
    Serial.println("2") ;
  }
  else if(analogRead(water_pin) < 200) { // 물이 안 찬 경우
    mySerial.println("6");
    Serial.println("6");
  }
  delay(200);
}



void dust_check() {
  digitalWrite(sensor_led, LOW);    // LED 켜기
  delayMicroseconds(sampling);   // 샘플링해주는 시간. 
 
  dust_value = analogRead(dust_sensor); // 센서 값 읽어오기
  
  delayMicroseconds(waiting);  // 너무 많은 데이터 입력을 피해주기 위해 잠시 멈춰주는 시간. 

  digitalWrite(sensor_led, HIGH); // LED 끄기
  delayMicroseconds(stop_time);   // LED 끄고 대기  
 
  dustDensityug = (0.17 * (dust_value * (5.0 / 1024)) - 0.1) * 1000;    // 미세먼지 값 계산
  
  if(dustDensityug >= 15) { // 미세먼지가 기준치보다 높은 경우
    mySerial.println("3");
    Serial.println("3");
  }
  else if(dustDensityug < 15) { // 미세먼지가 기준치보다 작은 경우
    mySerial.println("7");
    Serial.println("7");
  }
  
  if(analogRead(gas_pin) >= 200) { // 가스를 감지한 경우
    mySerial.println("4");
    Serial.println("4");
  }
  else if(analogRead(gas_pin) < 200) { // 가스를 감지하지 않은 경우
    mySerial.println("8");
    Serial.println("8");
  }
  
  if(dustDensityug >= 15 || analogRead(gas_pin) >= 200) {
    digitalWrite(Relaypin,HIGH);
    servo.write(0);
    delay(5000);
  }
  else {
    digitalWrite(Relaypin,LOW);
    servo.write(90);
  }
  
  delay(150);
}
