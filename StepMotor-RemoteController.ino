#include <Stepper.h>
#include <IRremote.h>


const int stepsPerRevolution = 1024;
Stepper myStepper(stepsPerRevolution,11,9,10,8);
int RECV_PIN=12;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
 myStepper.setSpeed(30);
 Serial.begin(9600);
 irrecv.enableIRIn();
}
void loop(){
 if(irrecv.decode(&results)){
 Serial.println(results.value, HEX);

 irrecv.resume();
 switch(results.value){
 case 0xFF10EF:
myStepper.step(stepsPerRevolution);; break;

 } }
 if(irrecv.decode(&results)){
 Serial.println(results.value, HEX);

 irrecv.resume();
 switch(results.value){

 case 0xFF5AA5:
myStepper.step(-stepsPerRevolution);; break;
 }
 } }
