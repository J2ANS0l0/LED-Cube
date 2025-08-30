#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create object to control the PCA9685 module
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {

  Serial.begin(9600);  
  pwm.begin();
  pwm.setPWMFreq(1000); // General Frecuency

}

void loop() {

  RGB(0,"ffffff");
  delay(1000);

  //pwm.setPWM(0, 0, 1000);
  //pwm.setPWM(1, 0, 1000);
  //pwm.setPWM(2, 0, 1000);

}

void RGB(int LED_number, char HEX_color[6]){

  char Red[3];
  char Green[3];
  char Blue[3];

  Red[0] = HEX_color[0];
  Red[1] = HEX_color[1];
  Red[2] = "\0";
    
  Green[0] = HEX_color[2];
  Green[1] = HEX_color[3];
  Green[2] = "\0";

  Blue[0] = HEX_color[4];
  Blue[1] = HEX_color[5];
  Blue[2] = "\0";

  int R = (strtol(Red, NULL, 16) * 1000)/255;
  int G = (strtol(Green, NULL, 16) * 1000)/255;
  int B = (strtol(Blue, NULL, 16) * 1000)/255;
  
  pwm.setPWM(LED_number, 0, R);
  pwm.setPWM(LED_number + 1, 0, G);
  pwm.setPWM(LED_number + 2, 0, B);

  Serial.println(LED_number * 3);
  Serial.println((LED_number * 3) + 1);
  Serial.println((LED_number * 3) + 2);

}
