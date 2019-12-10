//Output pins
int NAND_B3 = 8;    //B3
int NAND_A3 = 9;    //A3

void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(NAND_B3, OUTPUT);
  pinMode(NAND_A3, OUTPUT);
}

void loop() {
  Serial.println();
  Serial.println("NAND_B3 = High");
  Serial.println("NAND_A3 = High");
  digitalWrite(NAND_B3, HIGH);
  digitalWrite(NAND_A3, HIGH);
  delay(1000);


  Serial.println("NAND_B3 = High");
  Serial.println("NAND_A3 = LOW");
  digitalWrite(NAND_B3, HIGH);
  digitalWrite(NAND_A3, LOW);
  delay(1000);

  Serial.println("NAND_B3 = LOW");
  Serial.println("NAND_A3 = HIGH");
  digitalWrite(NAND_B3, LOW);
  digitalWrite(NAND_A3, HIGH);
  delay(1000);

  Serial.println("NAND_B3 = LOW");
  Serial.println("NAND_A3 = LOW");
  digitalWrite(NAND_B3, LOW);
  digitalWrite(NAND_A3, LOW);
  delay(1000);
}
