//---------------------------------------
// arduino shift register 8 LED demo
// dan@marginallyclever.com
// see also https://www.marginallyclever.com/2017/02/daisy-chain-shift-registers/
//---------------------------------------

//---------------------------------------
// CONSTANTS
//---------------------------------------

// name of SR pin -> Arduino pin # connected to SR pin
#define SER    6  // data in
#define SRCLK  5  // shift register clock
#define SRCLR  4  // clear shift register
#define RCLK   3  // storage register (sometimes called the latch pin)
#define OE     2  // enable output

#define TOTAL_SHIFT_PINS  64

bool Done = false;

//---------------------------------------
// METHODS
//---------------------------------------

void setup() {
  // put your setup code here, to run once:  
  pinMode(SER,OUTPUT);
  pinMode(SRCLK,OUTPUT);
  pinMode(SRCLR,OUTPUT);
  pinMode(RCLK,OUTPUT);
  pinMode(OE,OUTPUT);
  clearShiftRegisters();
  turnOutputsOn();
  Done = false;
}


void loop() {
  // put your main code here, to run repeatedly:
  //lightFirst();
  //lightAll(); 
  /*blinkA();
  blinkB();
  blinkC();
  oneAtATime();
  pingPong();
  pingPongSine();
  bouncingLevelA();
  bouncingLevelB();
  marqueeA();
  marqueeB();*/
  //FirstRow();
  //FirstPink(0);
  //SecondPink();
  //midDiagonal(0);
  //fullDiagonal(0);
  //Y3Diag();
  //GND1();
  //WSnake();
  //PSnake();
  //TSnake();
  if (!Done) {
    YSnake(50); // Run this function if Done is false
    Done = true; // Set Done to true after the function runs
  }

  if (Done) {
    ColorFull1(); // Run this function once Done is true
  }
}

void Row1(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || B43(i) || B42(i) || G42(i) || B41(i) || G41(i) ||GND13(i) || 
    B34(i) || B33(i) || G33(i) || B32(i) || G32(i) || G31(i) ||GND9(i) || 
    Blue11(i) || R11(i) || B12(i) || R12(i) || R13(i) || R14(i) || GND4(i) || 
    GND8(i) || R24(i) || R23(i) || R22(i) || R21(i) || B21(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void Row2(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || R43(i) || B42(i) || B41(i) || G41(i) ||GND14(i) || 
    R34(i) || B33(i) || B32(i) || G32(i) || G31(i) || B31(i) ||GND10(i) || 
    Blue11(i) || B12(i) || R12(i) || B13(i) || R13(i) || R14(i) || GND3(i) || 
    R24(i) || R23(i) || R22(i) || B22(i) || B21(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void Row3(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || R43(i) || G43(i) || R42(i) || B41(i) ||GND15(i) || 
    R34(i) || G34(i) || R33(i) || B32(i) || G31(i) || B31(i) ||GND11(i) || 
    G11(i) || B12(i) || B13(i) || R13(i) || B14(i) || R14(i) || GND2(i) || 
    R24(i) || R23(i) || B23(i) || R22(i) || B22(i) || B21(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void Row4(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || R43(i) || G43(i) || R42(i) || G42(i) || R41(i) ||GND16(i) || 
    R34(i) || G34(i) || R33(i) || G33(i) || R32(i) || B31(i) ||GND12(i) || 
    G11(i) || R11(i) || G12(i) || B13(i) || B14(i) || R14(i) || GND1(i) || 
    R24(i) || B24(i) || R23(i) || B23(i) || R22(i) || B22(i) || G21(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void ColorFull1(){
  Row1();
  Row2();
  Row3();
  Row4();
}

void lightAll() {
  shiftDataIn(HIGH);
  copyShiftToStorage();
  delay(200);
}

void TSnake(){
  T111();
  T121();
  T131();
  T141();
  T142();
  T132();
  T122();
  T112();
  T113();
  T123();
  T133();
  T143();
  T144();
  T134();
  T124();
  T114();
  T214();
  T224();
  T234();
  T244();
  T243();
  T233();
  T223();
  T213();
  T212();
  T222();
  T232();
  T242();
  T241();
  T231();
  T221();
  T211();
  T311();
  T321();
  T331();
  T341();
  T342();
  T332();
  T322();
  T312();
  T313();
  T323();
  T333();
  T343();
  T344();
  T334();
  T324();
  T314();
  T414();
  T424();
  T434();
  T444();
  T443();
  T433();
  T423();
  T413();
  T412();
  T422();
  T432();
  T442();
  T441();
  T431();
  T421();
  T411();
}

void YSnake(int d){
  Y211(d);
  Y221(d);
  Y231(d);
  Y241(d);
  Y242(d);
  Y232(d);
  Y222(d);
  Y212(d);
  Y213(d);
  Y223(d);
  Y233(d);
  Y243(d);
  Y244(d);
  Y234(d);
  Y224(d);
  Y214(d);
  Y114(d);
  Y124(d);
  Y134(d);
  Y144(d);
  Y143(d);
  Y133(d);
  Y123(d);
  Y113(d);
  Y112(d);
  Y122(d);
  Y132(d);
  Y142(d);
  Y141(d);
  Y131(d);
  Y121(d);
  Y111(d);
  Y344(d);
  Y334(d);
  Y324(d);
  Y314(d);
  Y313(d);
  Y323(d);
  Y333(d);
  Y343(d);
  Y342(d);
  Y332(d);
  Y322(d);
  Y312(d);
  Y311(d);
  Y321(d);
  Y331(d);
  Y341(d);
  Y441(d);
  Y431(d);
  Y421(d);
  Y411(d);
  Y412(d);
  Y422(d);
  Y432(d);
  Y442(d);
  Y443(d);
  Y433(d);
  Y423(d);
  Y413(d);
  Y414(d);
  Y424(d);
  Y434(d);
  Y444(d);
}

void WSnake(){
  W111();
  W121();
  W131();
  W141();
  W142();
  W132();
  W122();
  W112();
  W113();
  W123();
  W133();
  W143();
  W144();
  W134();
  W124();
  W114();
  W214();
  W224();
  W234();
  W244();
  W243();
  W233();
  W223();
  W213();
  W212();
  W222();
  W232();
  W242();
  W241();
  W231();
  W221();
  W211();
  W311();
  W321();
  W331();
  W341();
  W342();
  W332();
  W322();
  W312();
  W313();
  W323();
  W333();
  W343();
  W344();
  W334();
  W324();
  W314();
  W414();
  W424();
  W434();
  W444();
  W443();
  W433();
  W423();
  W413();
  W412();
  W422();
  W432();
  W442();
  W441();
  W431();
  W421();
  W411();
}

void RR444(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR443(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR442(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR432(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR441(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR431(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG424(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G42(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();  
}

void GG413(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();  
}

void GG412(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();  
}

void BB414(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B41(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();  
}

void RR342(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR341(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
} 

void RR331(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG334(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G33(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG323(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G32(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG312(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G31(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB324(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B32(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB313(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B31(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void RR241(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG244(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G24(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG233(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G23(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG222(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G22(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG211(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G21(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB234(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B23(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB223(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B22(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB212(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B21(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG144(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || GND4(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG143(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || GND3(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG132(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G13(i) || GND2(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void GG121(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G12(i) || GND1(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB134(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B13(i) || GND4(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB133(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B13(i) || GND3(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB122(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (B12(i) || GND2(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}

void BB111(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (Blue11(i) || GND1(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
}
void FirstRow(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (GND16(i) || i == 5 || i == 7 || i == 8 || i == 10 || i == 11 || i == 13 || i == 14 || i == 16) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void Y3Diag(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (i == 0 || i == 4 || i == 6 || i == 17 || i == 23 || i == 25 || i == 34 || i == 42 || i == 44|| i == 51 || i == 61 || i == 63) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

// This doesn't change the value stored in the storage registers.
void turnOutputsOn() {
  digitalWrite(OE,LOW);
}

// This doesn't change the value stored in the storage registers.
void turnOutputsOff() {
  digitalWrite(OE,HIGH);
}

// clear the shift registers without affecting the storage registers.
void clearShiftRegisters() {
  digitalWrite(SRCLR,LOW);
  digitalWrite(SRCLR,HIGH);
}

// All the data in the shift registers moves over 1 unit and the new data goes in at shift register 0.
// The data that was in the shift register 7 goes to the next register (if any).
void shiftDataIn(int data) {
  digitalWrite(SER,data);
  digitalWrite(SRCLK,HIGH);
  digitalWrite(SRCLK,LOW);
}

// copy the 8 shift registers into the shift registers,
// which changes the output voltage of the pins.
void copyShiftToStorage() {
  digitalWrite(RCLK,HIGH);
  digitalWrite(RCLK,LOW);
}

void W111(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND1(i) || Blue11(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void W121(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND1(i) || B12(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void W131(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND1(i) || B13(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void W141(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND1(i) || B14(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void W142(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND2(i) || B14(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W132(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND2(i) || B13(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void W122(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND2(i) || B12(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W112(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND2(i) || Blue11(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W113(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND3(i) || Blue11(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W123(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND3(i) || B12(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W133(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND3(i) || B13(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W143(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND3(i) || B14(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W144(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND4(i) || B14(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W134(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND4(i) || B13(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W124(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND4(i) || B12(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W114(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND4(i) || Blue11(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W214(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND8(i) || B21(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W224(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND8(i) || B22(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W234(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND8(i) || B23(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W244(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND8(i) || B24(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W243(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND7(i) || B24(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W233(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND7(i) || B23(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W223(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND7(i) || B22(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W213(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND7(i) || B21(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W212(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND6(i) || B21(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W222(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND6(i) || B22(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W232(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND6(i) || B23(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W242(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND6(i) || B24(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W241(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND5(i) || B24(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W231(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND5(i) || B23(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W221(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND5(i) || B22(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W211(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND5(i) || B21(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W311(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || B31(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W321(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || B32(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W331(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || B33(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W341(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || B34(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W342(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || B34(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W332(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || B33(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W322(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || B32(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W312(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || B31(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W313(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || B31(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W323(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || B32(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W333(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || B33(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W343(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || B34(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W344(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || B34(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W334(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || B33(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W324(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || B32(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W314(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || B31(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W414(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || B41(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W424(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || B42(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W434(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || B43(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W444(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || B44(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W443(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || B44(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W433(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || B43(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W423(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || B42(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W413(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || B41(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W412(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || B41(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W422(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || B42(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W432(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || B43(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W442(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || B44(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W441(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || B44(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W431(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || B43(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W421(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || B42(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void W411(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || B41(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void Y111(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
} 

void Y121(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
} 

void Y131(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
} 

void Y141(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
} 

void Y142(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y132(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
} 

void Y122(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y112(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y113(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y123(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y133(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y143(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y144(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || G14(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y134(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || G13(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y124(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || G12(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y114(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || G11(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y214(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y224(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y234(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y244(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y243(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y233(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y223(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y213(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y212(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y222(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y232(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y242(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y241(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || G24(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y231(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || G23(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y221(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || G22(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y211(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || G21(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y311(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y321(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y331(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y341(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y342(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y332(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y322(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y312(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y313(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y323(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y333(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y343(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y344(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || G34(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y334(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || G33(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y324(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || G32(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y314(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || G31(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y414(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y424(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y434(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y444(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y443(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y433(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y423(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y413(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y412(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y422(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y432(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y442(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y441(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || G44(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y431(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || G43(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y421(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || G42(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void Y411(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || G41(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P111(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i)||Blue11(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void P121(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i)||B12(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void P131(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || B13(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void P141(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || B14(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void P142(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || B14(i)|| GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P132(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || B13(i)|| GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
} 

void P122(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || B12(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P112(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || Blue11(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P113(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || Blue11(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P123(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || B12(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P133(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || B13(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P143(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || B14(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P144(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R14(i) || B14(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P134(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R13(i) || B13(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P124(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R12(i) || B12(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P114(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R11(i) || Blue11(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P214(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || B21(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P224(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || B22(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P234(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || B23(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P244(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || B24(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P243(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || B24(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P233(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || B23(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P223(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || B22(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P213(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || B21(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P212(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || B21(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P222(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || B22(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P232(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || B23(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P242(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || B24(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P241(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R24(i) || B24(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P231(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R23(i) || B23(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P221(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R22(i) || B22(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P211(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R21(i) || B21(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P311(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || B31(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P321(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || B32(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P331(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || B33(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P341(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || B34(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P342(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || B34(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P332(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || B33(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P322(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || B32(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P312(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || B31(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P313(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || B31(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P323(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || B32(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P333(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || B33(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P343(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || B34(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P344(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R34(i) || B34(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P334(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R33(i) || B33(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P324(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R32(i) || B32(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P314(int d){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R31(i) || B31(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(d);
}

void P414(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || B41(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P424(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || B42(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P434(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || B43(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P444(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || B44(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P443(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || B44(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P433(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || B43(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P423(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || B42(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P413(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || B41(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P412(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || B41(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P422(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || B42(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P432(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || B43(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P442(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || B44(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P441(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R44(i) || B44(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P431(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R43(i) || B43(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P421(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R42(i) || B42(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void P411(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (R41(i) || B41(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T111(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G11(i)||Blue11(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T121(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G12(i)||B12(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T131(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G13(i) || B13(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T141(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || B14(i)||GND1(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T142(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || B14(i)|| GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T132(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G13(i) || B13(i)|| GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T122(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G12(i) || B12(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T112(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G11(i) || Blue11(i) || GND2(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T113(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G11(i) || Blue11(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T123(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G12(i) || B12(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T133(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G13(i) || B13(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T143(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || B14(i) || GND3(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T144(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G14(i) || B14(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T134(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G13(i) || B13(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T124(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G12(i) || B12(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T114(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G11(i) || Blue11(i) || GND4(i)){
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T214(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G21(i) || B21(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T224(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G22(i) || B22(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T234(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G23(i) || B23(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T244(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G24(i) || B24(i) || GND8(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T243(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G24(i) || B24(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T233(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G23(i) || B23(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T223(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G22(i) || B22(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T213(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G21(i) || B21(i) || GND7(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T212(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G21(i) || B21(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T222(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G22(i) || B22(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T232(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G23(i) || B23(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T242(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G24(i) || B24(i) || GND6(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T241(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G24(i) || B24(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T231(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G23(i) || B23(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T221(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G22(i) || B22(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T211(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G21(i) || B21(i) || GND5(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

// Functions for T311 to T344

void T311(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G31(i) || B31(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T321(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G32(i) || B32(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T331(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G33(i) || B33(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T341(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G34(i) || B34(i) || GND9(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T342(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G34(i) || B34(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T332(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G33(i) || B33(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T322(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G32(i) || B32(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T312(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G31(i) || B31(i) || GND10(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T313(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G31(i) || B31(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T323(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G32(i) || B32(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T333(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G33(i) || B33(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T343(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G34(i) || B34(i) || GND11(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T344(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G34(i) || B34(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T334(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G33(i) || B33(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T324(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G32(i) || B32(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T314(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G31(i) || B31(i) || GND12(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T414(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || B41(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T424(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G42(i) || B42(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T434(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G43(i) || B43(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T444(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G44(i) || B44(i) || GND16(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T443(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G44(i) || B44(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T433(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G43(i) || B43(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T423(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G42(i) || B42(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T413(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || B41(i) || GND15(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T412(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || B41(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T422(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G42(i) || B42(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T432(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G43(i) || B43(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T442(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G44(i) || B44(i) || GND14(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T441(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G44(i) || B44(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T431(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G43(i) || B43(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T421(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G42(i) || B42(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

void T411(){
  clearShiftRegisters();
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    if (G41(i) || B41(i) || GND13(i)) {
      shiftDataIn(HIGH);
    } else {
      shiftDataIn(LOW);
    }
  }
  copyShiftToStorage();
  delay(200);
}

bool GND16(int i) {
  return i == 0;
}

bool GND15(int i) {
  return i == 1;
}

bool GND14(int i) {
  return i == 2;
}

bool GND13(int i) {
  return i == 3;
}

bool G44(int i) {
  return i == 4;
}

bool B44(int i) {
  return i == 5;
}

bool R44(int i) {
  return i == 6;
}

bool G43(int i) {
  return i == 7;
}

bool B43(int i) {
  return i == 8;
}

bool R43(int i) {
  return i == 9;
}

bool G42(int i) {
  return i == 10;
}

bool B42(int i) {
  return i == 11;
}

bool R42(int i) {
  return i == 12;
}

bool G41(int i) {
  return i == 13;
}

bool B41(int i) {
  return i == 14;
}

bool R41(int i) {
  return i == 15;
}

bool GND12(int i) {
  return i == 16;
}

bool GND11(int i) {
  return i == 17;
}

bool GND10(int i) {
  return i == 18;
}

bool GND9(int i) {
  return i == 19;
}

bool G34(int i) {
  return i == 20;
}

bool B34(int i) {
  return i == 21;
}

bool R34(int i) {
  return i == 22;
}

bool G33(int i) {
  return i == 23;
}

bool B33(int i) {
  return i == 24;
}

bool R33(int i) {
  return i == 25;
}

bool G32(int i) {
  return i == 26;
}

bool B32(int i) {
  return i == 27;
}

bool R32(int i) {
  return i == 28;
}

bool G31(int i) {
  return i == 29;
}

bool B31(int i) {
  return i == 30;
}

bool R31(int i) {
  return i == 31;
}

bool GND8(int i) {
  return i == 32;
}

bool GND7(int i) {
  return i == 33;
}

bool GND6(int i) {
  return i == 34;
}

bool GND5(int i) {
  return i == 35;
}

bool G24(int i) {
  return i == 36;
}

bool B24(int i) {
  return i == 37;
}

bool R24(int i) {
  return i == 38;
}

bool G23(int i) {
  return i == 39;
}

bool B23(int i) {
  return i == 40;
}

bool R23(int i) {
  return i == 41;
}

bool G22(int i) {
  return i == 42;
}

bool B22(int i) {
  return i == 43;
}

bool R22(int i) {
  return i == 44;
}

bool G21(int i) {
  return i == 45;
}

bool B21(int i) {
  return i == 46;
}

bool R21(int i) {
  return i == 47;
}

bool GND4(int i) {
  return i == 48;
}

bool GND3(int i) {
  return i == 49;
}

bool GND2(int i) {
  return i == 50;
}

bool GND1(int i) {
  return i == 51;
}

bool G14(int i) {
  return i == 52;
}

bool B14(int i) {
  return i == 53;
}

bool R14(int i) {
  return i == 54;
}

bool G13(int i) {
  return i == 55;
}

bool B13(int i) {
  return i == 56;
}

bool R13(int i) {
  return i == 57;
}

bool G12(int i) {
  return i == 58;
}

bool B12(int i) {
  return i == 59;
}

bool R12(int i) {
  return i == 60;
}

bool G11(int i) {
  return i == 61;
}

bool Blue11(int i) {
  return i == 62;
}

bool R11(int i) {
  return i == 63;
}