// Luca Quacquarelli
// 000838997
// 2022-09-19
//I, Luca Quacquarelli, student number 000838997, certify that this material is my original work. 
//No other person's work has been used without due acknowledgment and I have not made my work available to anyone else.

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 


float calculateTemp(int iVal) {
  float temp;
  temp = iVal * 50.0/1023;
  return temp;
}

float calculateVolts(int iVal) {
  float volts;
  volts = iVal * 0.0032226563;
  return volts;
}
 
void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  // print value to the USB port
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage = " + String(calculateVolts(iVal)));


  float temp = calculateTemp(iVal);
  String temptext;
  if(temp <= 15.00)
  {
     temptext = "Cold!";
  }
  else if (temp <= 25.00)
  {
     temptext = "Perfect!";
  }
  else if (temp <= 30.00)
  {
    temptext = "Warm!";
  }
  else if (temp <= 35.00)
  {
    temptext = "Hot!";
  }
  else if (temp >= 35.00)
  {
    temptext = "Too Hot!";
  }

  Serial.println("Digitized output of " + String(iVal) + " is equivalent to an temperature input of " + String(calculateTemp(iVal)) + " deg. C, which is " + temptext);
  // wait 0.5 seconds (500 ms) 
  delay(500); 
} 