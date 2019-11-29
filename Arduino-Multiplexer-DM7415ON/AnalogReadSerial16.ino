int totalChannels = 16;

int addressA = 7;
int addressB = 6;
int addressC = 5;
int addressD = 4;

int A = 0;      //Address pin A
int B = 0;      //Address pin B
int C = 0;      //Address pin C
int D = 0;      //Address pin D

int time = 0;

void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(addressA, OUTPUT);
  pinMode(addressB, OUTPUT);
  pinMode(addressC, OUTPUT);
  pinMode(addressD, OUTPUT);
  // Prepare read pin 
  pinMode(A0, INPUT);
}


void loop() {
  //Select each pin and read value
  char firstRow[] = "0000";
  char secondRow[] = "0000";
  for(int i=0; i<totalChannels; i++){
    A = bitRead(i,0); //Take first bit from binary value of i channel.
    B = bitRead(i,1); //Take second bit from binary value of i channel.
    C = bitRead(i,2); //Take third bit from value of i channel.
    D = bitRead(i,3); //Take fourth bit from value of i channel.

    //Write address to mux
    digitalWrite(addressA, A);
    digitalWrite(addressB, B);
    digitalWrite(addressC, C);
    digitalWrite(addressD, D);
    bool isON = analogRead(A0) >= 700;

    //Currently reversed
    if(isON){
      if(i <= 3){
        firstRow[i] = '1';
      }
      else{
        secondRow[i-4] = '1';
      }
    }

  //    //Read and print value
  //    Serial.print("Channel ");
  //    Serial.print(i);
  //    Serial.print(" value: ");
  //    
  //    if(analogRead(A0) >= 700){
  //      Serial.print("ON");
  //    }
  //    else{
  //      Serial.print("OFF");
  //    }
  //    Serial.println();
  }
    Serial.print("time: ");
    Serial.println(time);
    Serial.println(firstRow);
    Serial.println(secondRow);
    Serial.println();
  time = time + 2;
  
  delay(2000);
}
