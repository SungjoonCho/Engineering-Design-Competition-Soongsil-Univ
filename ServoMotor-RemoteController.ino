
#include <IRremote.h>
#include <Servo.h>
Servo servo;
int RECV_PIN=11; //11번 핀에 적외선 리모콘 수신
부 연결
IRrecv irrecv(RECV_PIN);
decode_results results;
//
void setup(){
 Serial.begin(9600);
 irrecv.enableIRIn();
 servo.attach(9); // 서보모터 9번에 연결
}
//
void loop(){
 if(irrecv.decode(&results)){
 Serial.println(results.value, HEX);
 irrecv.resume();
 switch(results.value){
 case 0xFFA25D: servo.write(70); break;
// 버튼 1
 case 0xFF629D: servo.write(145); break;
// 버튼 2 //80, 135
 }
 }

 }
