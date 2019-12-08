//Output pins
int CLR = 0;    //CLR clear
int LOAD = 13;  //LOAD 
int CLK = 1;    //CLK clock
int ENP = 2;    //ENP (Enable counting)
int ENT = 3;    //Count (If high then it counts)
int inputA = 8; 


int A = 0;      //Address pin A

int time = 0;

void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(CLR, OUTPUT);
  pinMode(LOAD, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(ENP, OUTPUT);
  pinMode(ENT, OUTPUT);
  pinMode(inputA, OUTPUT);
  
  // Prepare read pin 
  pinMode(A0, INPUT);  //RCO
  pinMode(A1, INPUT);  //QA
  pinMode(A2, INPUT);  //QB
  pinMode(A3, INPUT);  //QC
  pinMode(A4, INPUT);  //QD
}

void triggerCLK(){
  digitalWrite(CLK, HIGH);
  digitalWrite(CLK, LOW);
  delay(50); 
  //clock
  digitalWrite(CLK, HIGH);
}

void triggerCLR(){
  digitalWrite(CLR, HIGH);
  digitalWrite(CLR, LOW);
  delay(50); 
  triggerCLK();
  digitalWrite(CLR, HIGH);
}

void triggerLOAD(){
  digitalWrite(LOAD, HIGH);
  delay(1000);
  digitalWrite(LOAD, LOW);
  
  delay(1000);
  triggerCLK();
  digitalWrite(LOAD, HIGH);
}

void readAllValues(){
  Serial.println();
//  Serial.print("Time: ");
//  Serial.println(time);
  Serial.print("RCO: ");
  Serial.println(serial_high_str(analogRead(A0)));
//  Serial.println(analogRead(A0));
  Serial.print("QA: ");
  Serial.println(serial_high_str(analogRead(A1)));
//  Serial.println(analogRead(A1));
  Serial.print("QB: ");
  Serial.println(serial_high_str(analogRead(A2)));
//  Serial.println(analogRead(A2));
  Serial.print("QC: ");
  Serial.println(serial_high_str(analogRead(A3)));
//  Serial.println(analogRead(A3));
  Serial.print("QD: ");
  Serial.println(serial_high_str(analogRead(A4)));

  Serial.println(serial_high_str(analogRead(A1)) + serial_high_str(analogRead(A2)) + serial_high_str(analogRead(A3)) + serial_high_str(analogRead(A4)));
}

String serial_high_str(int value){
  if(value >= 300) return "1";
  return "0";
}


void loop() {

  triggerCLR();
  digitalWrite(ENP, HIGH);
  digitalWrite(inputA, HIGH);
  delay(100);
  triggerLOAD();
  triggerCLK();
  triggerCLK();
  digitalWrite(inputA, LOW);
  triggerCLK();
  
  Serial.println();
  Serial.println("Enable counting");
  digitalWrite(ENP, HIGH);
  readAllValues();
  Serial.println();
  Serial.println("Enable counting 1");
  digitalWrite(ENT, HIGH);
  readAllValues();
  delay(2000);

  while(true){
  triggerCLK();
  readAllValues();
  delay(2000);
  }
}
