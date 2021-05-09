#include <IRremote.h> // 적외선 송수신을 하기 위해서 IRremot 라이브러리를 사용한다.


IRsend irsend;
int i = 0;
long inputInt;
void setup(){
Serial.begin(9600);
}
void loop(){

 inputInt = Serial.parseInt();
 switch(inputInt){
 case 0:
 Serial.print(" ");
 break;
 case 1: //커튼올려
 for(i = 0; i < 3; i++){
 irsend.sendSony(0xFF5AA5,32);
 delay(40);
 Serial.print("1");
 }
 break; case 2: //커튼내려
 for(i = 0; i < 3; i++){
 irsend.sendSony(0xFF10EF,32);
 delay(40);
 Serial.print("2");
 }
 break;
