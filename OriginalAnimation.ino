
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

  /*

  //SNAKE

  // 01

  led(1,2,violet); frame(4);
  led(1,3,violet); frame(4);
  led(1,1,violet); frame(4);
  led(1,4,violet); frame(4);

  led(1,4,violet); frame(3);
  led(1,3,violet); frame(3);
  led(1,2,violet); frame(3);
  led(1,1,violet); frame(3);

  led(1,1,violet); frame(2);
  led(1,2,violet); frame(2);
  led(1,3,violet); frame(2);
  led(1,4,violet); frame(2);

  led(1,4,violet); frame(1);
  led(1,3,violet); frame(1);
  led(1,2,violet); frame(1);
  led(1,1,violet); frame(1);
  frame(1);

  // 02

  led(2,1,violet);
  led(2,2,violet);
  led(2,3,violet);
  led(2,4,violet);

  led(2,4,violet);
  led(2,3,violet);
  led(2,2,violet);
  led(2,1,violet);

  led(2,1,violet);
  led(2,2,violet);
  led(2,3,violet);
  led(2,4,violet);

  led(2,4,violet);
  led(2,3,violet);
  led(2,2,violet);
  led(2,1,violet);
  
  // 03

  led(3,1,violet);
  led(3,2,violet);
  led(3,3,violet);
  led(3,4,violet);

  led(3,4,violet);
  led(3,3,violet);
  led(3,2,violet);
  led(3,1,violet);

  led(3,1,violet);
  led(3,2,violet);
  led(3,3,violet);
  led(3,4,violet);

  led(3,4,violet);
  led(3,3,violet);
  led(3,2,violet);
  led(3,1,violet);

  // 04

  led(4,1,violet);
  led(4,2,violet);
  led(4,3,violet);
  led(4,4,violet);

  led(4,4,violet);
  led(4,3,violet);
  led(4,2,violet);
  led(4,1,violet);

  led(4,1,violet);
  led(4,2,violet);
  led(4,3,violet);
  led(4,4,violet);

  led(4,4,violet);
  led(4,3,violet);
  led(4,2,violet);
  led(4,1,violet);
*/

}

void frame(int z_row){

  digitalWrite(GND[z_row-1], 1);
  delay(200);
  digitalWrite(GND[z_row-1], 0);

  for(int n = 0; n <16; n++){
    digitalWrite(R[n], 0);  
    digitalWrite(G[n], 0);
    digitalWrite(B[n], 0);
  }

}

void led(int x_matrix, int y_column, uint8_t color){

  int led = 4*(x_matrix-1) + (y_column-1);
  
  digitalWrite(R[led], color & 0b001);
  digitalWrite(G[led], color & 0b010);
  digitalWrite(B[led], color & 0b100);

}

void loop() {

  led(1,1,violet);
  led(2,2,violet);
  led(3,3,violet);
  led(4,4,violet);
  frame(1);

  led(1,4,violet);
  led(2,3,violet);
  led(3,2,violet);
  led(4,1,violet);
  frame(2);

  led(1,1,violet);
  led(2,2,violet);
  led(3,3,violet);
  led(4,4,violet);
  frame(3);

  led(1,4,violet);
  led(2,3,violet);
  led(3,2,violet);
  led(4,1,violet);
  frame(4);
}
