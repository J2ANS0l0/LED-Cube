
#define GND_01 47
#define GND_02 45
#define GND_03 46
#define GND_04 44

#define violet      0b101
#define blue        0b001
#define light_blue  0b011 
#define green       0b010
#define yellow      0b110
#define red         0b100
#define white       0b111
#define off         0b000

const int GND[] = {GND_01, GND_02, GND_03, GND_04};

// Position = 4*(Matrix) + (Column)
const int R[] = {7,6,59,58,13,12,65,64,19,18,33,32,25,24,39,38};
const int G[] = {5,4,57,56,11,10,63,62,17,16,69,68,23,22,37,36};
const int B[] = {3,2,55,54,9,8,61,60,15,14,67,66,21,20,35,34};

int frequency = 5;

void setup() {
  Serial.begin(9600);
  pinMode(GND_01, OUTPUT);
  pinMode(GND_02, OUTPUT);
  pinMode(GND_03, OUTPUT);
  pinMode(GND_04, OUTPUT);

  for(int n = 0; n <16; n++){
    pinMode(R[n], OUTPUT);  
    pinMode(G[n], OUTPUT);
    pinMode(B[n], OUTPUT);
  }

  //SNAKE

  int velocity = 50;

  // 01

  led(1,1,violet); frame(4, velocity);
  led(1,2,violet); frame(4, velocity);
  led(1,3,violet); frame(4, velocity);
  led(1,4,violet); frame(4, velocity);

  led(1,4,violet); frame(3, velocity);
  led(1,3,violet); frame(3, velocity);
  led(1,2,violet); frame(3, velocity);
  led(1,1,violet); frame(3, velocity);

  led(1,1,violet); frame(2, velocity);
  led(1,2,violet); frame(2, velocity);
  led(1,3,violet); frame(2, velocity);
  led(1,4,violet); frame(2, velocity);

  led(1,4,violet); frame(1, velocity);
  led(1,3,violet); frame(1, velocity);
  led(1,2,violet); frame(1, velocity);
  led(1,1,violet); frame(1, velocity);

  // 02

  led(2,1,violet); frame(1, velocity);
  led(2,2,violet); frame(1, velocity);
  led(2,3,violet); frame(1, velocity);
  led(2,4,violet); frame(1, velocity);

  led(2,4,violet); frame(2, velocity);
  led(2,3,violet); frame(2, velocity);
  led(2,2,violet); frame(2, velocity);
  led(2,1,violet); frame(2, velocity);

  led(2,1,violet); frame(3, velocity);
  led(2,2,violet); frame(3, velocity);
  led(2,3,violet); frame(3, velocity);
  led(2,4,violet); frame(3, velocity);

  led(2,4,violet); frame(4, velocity);
  led(2,3,violet); frame(4, velocity);
  led(2,2,violet); frame(4, velocity);
  led(2,1,violet); frame(4, velocity);
  
  // 03

  led(3,1,violet); frame(4, velocity);
  led(3,2,violet); frame(4, velocity);
  led(3,3,violet); frame(4, velocity);
  led(3,4,violet); frame(4, velocity);

  led(3,4,violet); frame(3, velocity);
  led(3,3,violet); frame(3, velocity);
  led(3,2,violet); frame(3, velocity);
  led(3,1,violet); frame(3, velocity);

  led(3,1,violet); frame(2, velocity);
  led(3,2,violet); frame(2, velocity); 
  led(3,3,violet); frame(2, velocity); 
  led(3,4,violet); frame(2, velocity); 

  led(3,4,violet); frame(1, velocity);
  led(3,3,violet); frame(1, velocity);
  led(3,2,violet); frame(1, velocity);
  led(3,1,violet); frame(1, velocity);

  // 04

  led(4,1,violet); frame(1, velocity);
  led(4,2,violet); frame(1, velocity);
  led(4,3,violet); frame(1, velocity);
  led(4,4,violet); frame(1, velocity);

  led(4,4,violet); frame(2, velocity);
  led(4,3,violet); frame(2, velocity);
  led(4,2,violet); frame(2, velocity);
  led(4,1,violet); frame(2, velocity);

  led(4,1,violet); frame(3, velocity);
  led(4,2,violet); frame(3, velocity);
  led(4,3,violet); frame(3, velocity);
  led(4,4,violet); frame(3, velocity);

  led(4,4,violet); frame(4, velocity);
  led(4,3,violet); frame(4, velocity);
  led(4,2,violet); frame(4, velocity);
  led(4,1,violet); frame(4, velocity);

}

void frame(int z_row, int speed){

  digitalWrite(GND[z_row-1], 1);
  delay(speed);
  digitalWrite(GND[z_row-1], 0);

  for(int n = 0; n <16; n++){
    digitalWrite(R[n], 0);  
    digitalWrite(G[n], 0);
    digitalWrite(B[n], 0);
  }

}

void led(int x_matrix, int y_column, uint8_t color){

  int led = 4*(x_matrix-1) + (y_column-1);
  
  digitalWrite(R[led], color & 0b100);
  digitalWrite(G[led], color & 0b010);
  digitalWrite(B[led], color & 0b001);

}

double intensity = 1;

void loop() {

  /*
  violet    
  blue      
  light_blue
  green     
  yellow    
  red       
  white     
  off       
  */

  // 04

  led(4,1,violet);
  led(4,2,violet);  
  led(4,3,violet);  
  led(3,1,violet); 
  led(3,2,violet); 
  led(2,1,violet);

  led(4,4,blue);
  led(3,3,blue);
  led(2,2,blue);
  led(1,1,blue);

  led(3,4,light_blue);
  led(2,3,light_blue);
  led(1,2,light_blue);

  led(2,4,green);
  led(1,3,green);

  led(1,4,yellow);

  frame(4, intensity);

  // 03
  
  led(4,1,violet);
  led(4,2,violet);
  led(3,1,violet);

  led(4,3,blue);
  led(3,2,blue);
  led(2,1,blue);

  led(4,4,light_blue);
  led(3,3,light_blue);
  led(2,2,light_blue);
  led(1,1,light_blue);

  led(3,4,green);
  led(2,3,green);
  led(1,2,green);

  led(2,4,yellow);
  led(1,3,yellow);

  led(1,4,red);

  frame(3, intensity);

  // 02

  led(4,1,violet);

  led(4,2,blue);
  led(3,1,blue);

  led(4,3,light_blue);
  led(3,2,light_blue);
  led(2,1,light_blue);

  led(4,4,green);
  led(3,3,green);
  led(2,2,green);
  led(1,1,green);

  led(3,4,yellow);
  led(2,3,yellow);
  led(1,2,yellow);

  led(2,4,red);
  led(1,3,red);
  led(1,4,red);

  frame(2, intensity);

  // 01

  led(4,1,blue);

  led(4,2,light_blue);
  led(3,1,light_blue);

  led(4,3,green);
  led(3,2,green);
  led(2,1,green);

  led(4,4,yellow);
  led(3,3,yellow);
  led(2,2,yellow);
  led(1,1,yellow);
  
  led(3,4,red);
  led(2,3,red);
  led(1,2,red);
  led(2,4,red);
  led(1,3,red);
  led(1,4,red);

  frame(1, intensity);

}
