#include <IRremote.h>
#include <IRremoteInt.h>

#define Button_0 0xFF6897
#define Button_1 0xFF30CF
#define Button_2 0xFF18E7
#define Button_3 0xFF7A85
#define Button_4 0xFF10EF
#define Button_5 0xFF38C7
#define Button_6 0xFF5AA5
#define Button_7 0xFF42BD
#define Button_8 0xFF4AB5
#define Button_9 0xFF52AD

IRrecv irrecv(13);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {

    switch(results.value){
      case Button_1: digitalWrite(12, HIGH); break;
     case Button_2: digitalWrite(11, HIGH); break;
     case Button_3: digitalWrite(10, HIGH); break;

      case Button_4: digitalWrite(12, LOW); break;
      case Button_5: digitalWrite(11, LOW); break;
      case Button_6: digitalWrite(10, LOW); break;

      }
    Serial.print(results.value, HEX);
    Serial.print('\n');
    irrecv.resume();
  }
  // put your main code here, to run repeatedly:

}
