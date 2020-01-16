// https://www.datasheetarchive.com/pdf/download.php?id=143240d741a05b795bfc23691077a7c4a43b10&type=P&term=Display%25205082%25207731
const int pinDP = 8;
const int pinA = 9;
const int pinB = 10;
const int pinC = 11;
const int pinD = 12;
const int pinG = 13;
const int pinE = 2;
const int pinF = 3;

//TODO: Add in all combos
int one[3] = {pinB,pinC,pinDP};
int two[6] = {pinA,pinB,pinG,pinE,pinD,pinDP};
int three[6] = {pinA,pinB,pinG,pinC,pinD,pinDP};
int four[5] = {pinF,pinG,pinB,pinC,pinDP};
int five[6] = {pinA,pinF,pinG,pinC,pinD,pinDP};
int six[6] = {pinA,pinF,pinG,pinC,pinD,pinE};
int seven[6] = {pinA,pinB,pinC,pinDP};
int eight[8] = {pinA,pinB,pinG,pinC,pinD,pinE,pinF,pinDP};
int nine[6] = {pinA,pinB,pinC,pinF,pinDP}; 
int* allnums[] = {one, two, three, four, five, six, seven, eight, nine}; 

int counter;

void applyDigits(int arr[], int sizeOfArray){
  resetDigits();
  for ( int k = 0 ; k < sizeOfArray ; ++k ){
    digitalWrite(arr[k], LOW);
  }
}

void resetDigits(){
  digitalWrite(pinDP, HIGH);
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void allON(){
  digitalWrite(pinDP, LOW);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void setup(){
//  one = {0,1,2,3,4,5};
  pinMode(pinD, OUTPUT);
}

void loop(){
//  resetDigits();
//while(true){
//  digitalWrite(pinG, LOW);
//delay(1000);
//digitalWrite(pinG, HIGH);
//}

//   applyDigits(one, 2);
//   delay(10000);
   
  
//  resetDigits();
  delay(1000);
  allON();
  delay(1000);
  
}
