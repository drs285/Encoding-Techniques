int  prevbit=0;
void setup() {
  Serial.begin(9600); // initialize serial communication
}

int nrzmdecoder(int byte)
{
  
  int nrzm=byte ^ prevbit;
  prevbit=byte;
  return nrzm;


}

int nrzSdecoder(int byte)
{
  
  int nrzS=byte ^ prevbit;
  prevbit=byte;
  return 1-nrzS;


}


int nrzLdecoder(int byte)
{
  
  return byte;


}

int bioLdecoder(int byte)
{
  
  return byte;


}

int bioMdecoder(int even, int odd)
{
  return (even==odd) ? 0 : 1;
}

int bioSdecoder(int even, int odd)
{
  return (even==odd) ? 1 : 0;
}



String mytext="";
String temp="";
// void loop() {
//   if (Serial.available() > 0) { 
//     char receivedChar = Serial.read(); 
//     if (receivedChar == '0' || receivedChar=='1') { 
//       int x=nrzSdecoder((receivedChar-'0'));
// //      Serial.print(x);
//       temp+=(x);
      
      
//       if(temp.length()==8)
//       {
//         byte myByte = strtol(temp.c_str(), NULL, 2); // Convert the binary string to a byte
//         char myChar = (char) myByte; // Convert the byte to a character
//         Serial.print(myChar); // Print the character to the serial monitor
//         temp="";
        
//       }
//       }
      
//     }
// //    Serial.println(mytext);
  
//   }

int evenhalf;
int oddhalf;
int index=0;
void loop() {
  if (Serial.available() > 0) { 
    index+=1;
    // Serial.print(index);
    char receivedChar = Serial.read();
    if (index % 2 == 0){
    if (receivedChar == '0' || receivedChar=='1') { 
      int x=bioLdecoder((receivedChar-'0'));
    //  Serial.print(x);
      temp+=(x);
      
      
      if(temp.length()==8)
      {
        byte myByte = strtol(temp.c_str(), NULL, 2); // Convert the binary string to a byte
        char myChar = (char) myByte; // Convert the byte to a character
        Serial.print(myChar); // Print the character to the serial monitor
        temp="";
        
      }
      }
    }
    }
//    Serial.println(mytext);
  }



// void loop() {
//   if (Serial.available() > 0) { 
//     index+=1;
//     // Serial.print(index);
//     char receivedChar = Serial.read();
//     if (index % 2 == 0){
//       evenhalf=(receivedChar-'0');
//       // Serial.print(evenhalf);
//     }
//     if (index % 2 == 1){
//       oddhalf=(receivedChar-'0');
//       // Serial.print(" ");
//     if (receivedChar == '0' || receivedChar=='1') { 
//       int x=bioMdecoder(evenhalf,oddhalf);
//     //  Serial.print(x);
//       temp+=(x);
      
      
//       if(temp.length()==8)
//       {
//         byte myByte = strtol(temp.c_str(), NULL, 2); // Convert the binary string to a byte
//         char myChar = (char) myByte; // Convert the byte to a character
//         Serial.print(myChar); // Print the character to the serial monitor
//         temp="";
        
//       }
//       }
//     }
//     }
// //    Serial.println(mytext);
//   }

// void loop() {
//   if (Serial.available() > 0) { 
//     index+=1;
//     // Serial.print(index);
//     char receivedChar = Serial.read();
//     if (index % 2 == 0){
//       evenhalf=(receivedChar-'0');
//       // Serial.print(evenhalf);
//     }
//     if (index % 2 == 1){
//       oddhalf=(receivedChar-'0');
//       // Serial.print(" ");
//     if (receivedChar == '0' || receivedChar=='1') { 
//       int x=bioSdecoder(evenhalf,oddhalf);
//     //  Serial.print(x);
//       temp+=(x);
      
      
//       if(temp.length()==8)
//       {
//         byte myByte = strtol(temp.c_str(), NULL, 2); // Convert the binary string to a byte
//         char myChar = (char) myByte; // Convert the byte to a character
//         Serial.print(myChar); // Print the character to the serial monitor
//         temp="";
        
//       }
//       }
//     }
//     }
// //    Serial.println(mytext);
//   }