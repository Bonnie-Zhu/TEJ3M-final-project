// Created on: Jan 2024
// Created by: Bonnie Zhu
// Copyright: Mr.Coxall
// Created for: This is the code for a 1/2 adder

const int DIGIT_A1 = 13;
const int DIGIT_B1 = 12;
const int DIGIT_Cin = 11;
const int DIGIT_A2 = 10;
const int DIGIT_B2 = 9;

void setup()
{
  // setup serial output
  Serial.begin(9600);
  // set pin mode to output
  pinMode(DIGIT_A1, OUTPUT);
  pinMode(DIGIT_B1, OUTPUT);
  pinMode(DIGIT_A2, OUTPUT);
  pinMode(DIGIT_B2, OUTPUT);
  pinMode(DIGIT_Cin, OUTPUT);
  
  
  // set all pins to "0)
  digitalWrite(DIGIT_A1, LOW); //LOW and HIGH just reference 0 & 1
  digitalWrite(DIGIT_B1, LOW);
  digitalWrite(DIGIT_Cin, LOW);
  digitalWrite(DIGIT_A2, LOW);
  digitalWrite(DIGIT_B2, LOW);
  
  
  // loop over the inputs
  Serial.print("Starting ... \n\n");
  delay(1000); // Wait for 1000 millisecond(s)
}
void loop()
{
  for (int onesA = 0; onesA <= 1; ++onesA) {
    digitalWrite(DIGIT_A1, onesA);
    
    for (int onesB = 0; onesB <= 1; ++onesB) {
      digitalWrite(DIGIT_B1, onesB);
      
      for (int carryIn = 0; carryIn <= 1; ++carryIn) {
       digitalWrite(DIGIT_Cin, carryIn);

       for (int twosA = 0; twosA <= 1; ++twosA) {
        digitalWrite(DIGIT_A2, twosA);
    
        for (int twosB = 0; twosB <= 1; ++twosB) {
         digitalWrite(DIGIT_B2, twosB);
      
        
        int sum = onesA + onesB + twosA + twosB + carryIn;
        int carryOut = sum /2;
        sum %= 2;
      
      Serial.print("A1 = " + String(onesA) + "\n");
      Serial.print("B1 = " + String(onesB) + "\n");
      Serial.print("A2 = " + String(twosA) + "\n");
      Serial.print("B2 = " + String(twosB) + "\n");
      Serial.print("Cin = " + String(carryIn) + "\n");
      Serial.print(String(twosA) + String(onesA) + " + " + String(twosB) + String(onesB) +  " + " + String(carryIn) +
                   " = " + String(sum) + " with Carry Out = " + String(carryOut) + "\n\n");
      delay(1000); // Wait for 2000 millisecond(s)
           }
         }
       } 
     }
   }

  //Done
  Serial.print("\n Done. \n");
  delay(5000);
}
  
