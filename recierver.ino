const int dataPin = 8;
const int clockPin = 3;
const int bitPeriod = 100; // time in ms for each bit
bool lastBitValue = false;

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  // read a series of 8 bits and decode them (in this case, decoding ASCII code to character)
  byte decodedByte = 0;
  Serial.println("hi");
  for (int i = 0; i < 1; i++) {

    bool signalLevel = waitForClockEdge(); // wait for the clock edge and get the signal level
    if (signalLevel == lastBitValue) { // if signal level is the same as the last bit, it's a 0
      bitClear(decodedByte, i); // clear the i-th bit in the decoded byte
    } else { // if signal level is different from the last bit, it's a 1
      bitSet(decodedByte, i); // set the i-th bit in the decoded byte
    }
    lastBitValue = signalLevel; // update the last bit value for the next iteration
    Serial.write(signalLevel);
  }
  Serial.write(decodedByte); // send the decoded byte over serial communication
  delay(1000);

}

bool waitForClockEdge() {
  bool signalLevel = digitalRead(dataPin);
  int values = AnalogRead(dataPin);
  Serial.print(signalLevel);
  while (signalLevel == lastBitValue) {
    Serial.print(signalLevel);
    signalLevel = digitalRead(dataPin);
    delay(100);
  } // wait for the clock edge
  delay(bitPeriod / 2); // wait half the bit period
  digitalWrite(clockPin, HIGH); // toggle the clock pin
  delay(bitPeriod / 2); // wait the other half of the bit period
  digitalWrite(clockPin, LOW); // toggle the clock pin back to its original state
  return signalLevel; // return the signal level for the current bit
}
