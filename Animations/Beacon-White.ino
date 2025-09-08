// ========================
// Pin Definitions
// ========================

// Columns X=0..3, Layers Z=0..3
const int R[4][4] = { 
  {7,6,59,58}, 
  {13,12,65,64}, 
  {19,18,33,32}, 
  {25,24,39,38}
};

const int G[4][4] = { 
  {5,4,57,56}, 
  {11,10,63,62}, 
  {17,16,69,68}, 
  {23,22,37,36} 
};

const int B[4][4] = { 
  {3,2,55,54}, 
  {9,8,61,60}, 
  {15,14,67,66}, 
  {21,20,35,34}
};

int de = 1000;

// Rows Y=0..3 (NPN transistor grounds)
const int GND[4] = {44, 46, 45, 47};

// ========================
// Color Enumeration
// ========================
enum Color { OFF, RED, GREEN, BLUE, YELLOW, PURPLE, TEAL, WHITE };

// ========================
// Cube Pattern - Solo Blanco
// ========================
// Cube[Y][X][Z]
Color cube[4][4][4] = {
  {
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE}
  },
  {
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE}
  },
  {
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE}
  },
  {
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE},
    {WHITE, WHITE, WHITE, WHITE}
  }
};

void ColorFull1() {
  // Todo en blanco
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cube[i][j][k] = WHITE;
      }
    }
  }
}

// ========================
// Helper Function
// ========================
void setLED(int Rpin, int Gpin, int Bpin, Color c) {
  // Turn all LOW first
  digitalWrite(Rpin, LOW);
  digitalWrite(Gpin, LOW);
  digitalWrite(Bpin, LOW);

  switch (c) {
    case WHITE:  digitalWrite(Rpin, HIGH); digitalWrite(Gpin, HIGH); digitalWrite(Bpin, HIGH); break;
    case PURPLE: digitalWrite(Rpin, HIGH); digitalWrite(Bpin, HIGH); break;
    case YELLOW: digitalWrite(Rpin, HIGH); digitalWrite(Gpin, HIGH); break;
    case TEAL:   digitalWrite(Gpin, HIGH); digitalWrite(Bpin, HIGH); break;
    case RED:    digitalWrite(Rpin, HIGH); break;
    case GREEN:  digitalWrite(Gpin, HIGH); break;
    case BLUE:   digitalWrite(Bpin, HIGH); break;
    case OFF:    break;
  }
}

// ========================
// Display Function
// ========================
void displayCube(Color c[4][4][4], int d) {
  for (int i = 0; i < 4; i++) {             // Y / row
    digitalWrite(GND[i], HIGH);               // Deactivate row past row

    for (int j = 0; j < 4; j++) {           // X / column
      for (int k = 0; k < 4; k++) {         // Z / layer
        setLED(R[j][k], G[j][k], B[j][k], c[i][j][k]);
      }
    }
    digitalWrite(GND[i], LOW);              // Activate row
    delay(d);
  }
}

// ========================
// Setup
// ========================
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(GND[i], OUTPUT);
    digitalWrite(GND[i], LOW);             // Default OFF

    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        pinMode(R[j][k], OUTPUT);
        pinMode(G[j][k], OUTPUT);
        pinMode(B[j][k], OUTPUT);

        digitalWrite(R[j][k], LOW);
        digitalWrite(G[j][k], LOW);
        digitalWrite(B[j][k], LOW);
      }
    }
  }
  ColorFull1();
}

// ========================
// Loop
// ========================
void loop() {
  displayCube(cube, de);
  de = de/1.3;
}
