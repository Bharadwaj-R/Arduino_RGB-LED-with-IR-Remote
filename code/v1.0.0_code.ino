/*
!! Caution before Proceeding further !!
The values written in the if cases change based on the IR Remote used. To re-calibrate the IR receiver, run the program first only with the first if case. 
Note down the values for various buttons pressed from the serial monitor, and replace the numbers used in program with the new numbers obtained.
*/

#include <IRremote.h>

IRrecv irrecv(2);           
decode_results results;     

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);       
  irrecv.enableIRIn();      
}

void loop()
{
  long int val;            
  if (irrecv.decode(&results))
  {
    val=results.value;
    Serial.println(val);
    irrecv.resume();        
  }
  
  if(val==16593103)    
  {
    analogWrite(A0,256);
    analogWrite(A1,256);
    analogWrite(A2,256);
  }
  
  if(val==16582903)
  {
    analogWrite(A0,256);
    analogWrite(A1,0);
    analogWrite(A2,0);
  }
  
  if(val==16615543)
  {
    analogWrite(A0,0);
    analogWrite(A1,256);
    analogWrite(A2,0);
  }
  
  if(val==16599223)
  {
    analogWrite(A0,0);
    analogWrite(A1,0);
    analogWrite(A2,256);
  }
  
  if(val==16580863)
  {
    analogWrite(A0,0);
    analogWrite(A1,0);
    analogWrite(A2,0);
  }
  delay(100);
}
