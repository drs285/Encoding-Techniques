const int dataPin = 8;
const int clockPin = 3;
const int bitPeriod = 100; // time in ms for each bit
bool lastBitValue = false;
int bioout = 0;


String myText = "";
void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void NRZL(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    digitalWrite(dataPin, bitValue ? HIGH : LOW);
    Serial.print(bitValue);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
   ;
  }
}

void NRZM(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    bool signalLevel = (bitValue == 1) ? !lastBitValue : lastBitValue;
    digitalWrite(dataPin, signalLevel ? HIGH : LOW);
    Serial.print(signalLevel);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
    lastBitValue = signalLevel;
  }
}

void NRZS(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    bool signalLevel = (bitValue == 0) ? !lastBitValue : lastBitValue;
    digitalWrite(dataPin, signalLevel ? HIGH : LOW);
    Serial.print(signalLevel);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
    lastBitValue = signalLevel;
  }
}

void BIOL(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    digitalWrite(dataPin, bitValue ? HIGH : LOW);
    Serial.print(bitValue);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    digitalWrite(dataPin, bitValue ? LOW : HIGH);
    Serial.print(1-bitValue);
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
   ;
  }
}

void BIOM(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    bioout = !bioout;
    digitalWrite(dataPin, bioout ? HIGH : LOW);
    Serial.print(bioout);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    bioout = bitValue ? !bioout : bioout;
    Serial.print(bioout);
    digitalWrite(dataPin, bioout ? HIGH : LOW);
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
   ;
  }
}

void BIOS(char b) {
  
  for (int i = 7; i >= 0; i--) {
    byte bitValue = bitRead(b, i);
    bioout = !bioout;
    digitalWrite(dataPin, bioout ? HIGH : LOW);
    Serial.print(bioout);
    digitalWrite(clockPin, HIGH);
    delay(bitPeriod / 2); // wait half the bit period
    bioout = bitValue ? bioout : !bioout;
    Serial.print(bioout);
    digitalWrite(dataPin, bioout ? HIGH : LOW);
    digitalWrite(clockPin, LOW);
    delay(bitPeriod / 2);
   ;
  }
}

void loop() {
Serial.println(" ");
  while (Serial.available() == 0) {}
  myText = Serial.readString();
  Serial.println(myText);
  Serial.println(" ");
  for (int i = 0; i < myText.length()-1; i++) 
  {
      char myChar = myText.charAt(i);
      NRZL(myChar);
  }
   delay(1000);
       
  }
