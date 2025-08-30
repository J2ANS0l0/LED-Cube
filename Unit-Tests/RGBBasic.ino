#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Crear objeto para controlar el módulo PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {

  Serial.begin(9600);  
  pwm.begin();
  pwm.setPWMFreq(1000); // General Frecuency

}

void loop() {

  RGB("111111");
  delay(1000);

  //pwm.setPWM(0, 0, 1000);
  //pwm.setPWM(1, 0, 900);
  //pwm.setPWM(2, 0, 1000);

}

void RGB(char color[6]){

  char Red[3];
  char Green[3];
  char Blue[3];

  Red[0] = color[0];
  Red[1] = color[1];
  Red[2] = "\0";
    
  Green[0] = color[2];
  Green[1] = color[3];
  Green[2] = "\0";

  Blue[0] = color[4];
  Blue[1] = color[5];
  Blue[2] = "\0";

  int R = (strtol(Red, NULL, 16) * 1000)/255;
  int G = (strtol(Green, NULL, 16) * 1000)/255;
  int B = (strtol(Blue, NULL, 16) * 1000)/255;
  
  pwm.setPWM(0, 0, R);
  pwm.setPWM(1, 0, G);
  pwm.setPWM(2, 0, B);

}
