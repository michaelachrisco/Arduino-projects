int addressOneA = 2;

int A = 0;      //Address pin A

int time = 0;

void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(addressOneA, OUTPUT);
  // Prepare read pin 
  pinMode(A0, INPUT);
}


void loop() {
  Serial.println();
  Serial.println(time);
  digitalWrite(addressOneA, HIGH);
  Serial.println("InputA: HIGH");
  Serial.print("OutputY: ");
  Serial.println(analogRead(A0));
  time=time+2;
  
  delay(2000);
  Serial.println("InputA: LOW");
  Serial.print("OutputY: ");
  digitalWrite(addressOneA, LOW);
  Serial.println(analogRead(A0));
  time=time+2;
  delay(2000);
}
