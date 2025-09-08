#define GND_01 47
#define GND_02 45
#define GND_03 46
#define GND_04 44

const int GND[] = {GND_01, GND_02, GND_03, GND_04};

const int R[] = {7,6,59,58,13,12,65,64,19,18,33,32,25,24,39,38};
const int G[] = {5,4,57,56,11,10,63,62,17,16,69,68,23,22,37,36};
const int B[] = {3,2,55,54,9,8,61,60,15,14,67,66,21,20,35,34};

int frequency = 500;

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
}

void loop() {

    digitalWrite(R[0], 1);
    digitalWrite(B[0], 1);
    digitalWrite(GND[0], 1);
    delay(frequency);
    digitalWrite(GND[0], 0);
    digitalWrite(R[0], 0);
    digitalWrite(B[0], 0);

    digitalWrite(R[1], 1);
    digitalWrite(B[1], 1);
    digitalWrite(GND[1], 1);
    delay(frequency);
    digitalWrite(GND[1], 0);
    digitalWrite(R[1], 0);
    digitalWrite(B[1], 0);


    digitalWrite(R[2], 1);
    digitalWrite(B[2], 1);
    digitalWrite(GND[2], 1);
    delay(frequency);
    digitalWrite(GND[2], 0);
    digitalWrite(R[2], 0);
    digitalWrite(B[2], 0);

    digitalWrite(R[3], 1);
    digitalWrite(B[3], 1);
    digitalWrite(GND[3], 1);
    delay(frequency);
    digitalWrite(GND[3], 0);
    digitalWrite(R[3], 0);
    digitalWrite(B[3], 0);
}
