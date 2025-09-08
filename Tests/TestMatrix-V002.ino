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
  for(int i = 0; i < 16; i++){
    for(int frame = 0; frame < 4; frame++){
      digitalWrite(GND[frame], 1);
      
      digitalWrite(R[i], 1);
      digitalWrite(G[i], 0);
      digitalWrite(B[i], 1);
      delay(frequency);
      digitalWrite(R[i], 0);
      digitalWrite(B[i], 0);
      
      digitalWrite(B[i], 1);
      delay(frequency);
      digitalWrite(B[i], 0);
      
      digitalWrite(G[i], 1);
      digitalWrite(B[i], 1);
      delay(frequency);
      digitalWrite(G[i], 0);
      digitalWrite(B[i], 0);
      
      digitalWrite(G[i], 1);
      delay(frequency);
      digitalWrite(G[i], 0);
      
      digitalWrite(R[i], 1);
      digitalWrite(G[i], 1);
      delay(frequency);
      digitalWrite(R[i], 0);
      digitalWrite(G[i], 0);
      
      digitalWrite(R[i], 1);
      delay(frequency);
      digitalWrite(R[i], 0);
      
      digitalWrite(R[i], 1);
      digitalWrite(G[i], 1);
      digitalWrite(B[i], 1);
      delay(frequency);
      digitalWrite(R[i], 0);
      digitalWrite(G[i], 0);
      digitalWrite(B[i], 0);

      digitalWrite(GND[frame], 0);
    }
  }
}
