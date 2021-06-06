//F تشغيل الكونتاك
//f اطفاء الكونتاك
//G تشغيل التامين
//g اطفاء التامين
// S......s الفتح
//A.......a لقفل
// D......d المحرك
 
char a;
String z = "";
unsigned long T1 = 0 , T2 = 0 ;
void setup() {
//  Serial . begin (9600 ) ;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
}
void loop() {
  T2 = millis();
  if (digitalRead(A5) == 1) {
    if (T2 > T1 + 17000) {
      T1 = T2;
      Serial.print ("d");
    }
  }
  if (Serial .available ()) {
    while (Serial .available ()) {
      char d = (char)Serial.read ();
      z += d;
    }
    while (Serial .available () > 0) {
      a = Serial .read();
    }

    if  (z == "D") {
      digitalWrite(6, 1);
    }
    else  if  (z == "d") {
      digitalWrite(6, 0);
    }
    else  if  (z == "S") {
      digitalWrite(2, 1);
    }
    else  if  (z == "s") {
      digitalWrite(2, 0);
    }
    else if  (z == "F") {
      digitalWrite(3, 1);
    }
    else  if  (z == "f") {
      digitalWrite(3, 0);
    }
    else if  (z == "G") {
      digitalWrite(4, 1);
    }
    else  if  (z == "g") {
      digitalWrite(4, 0);
    }
    else if  (z == "A") {
      digitalWrite(5, 1);
    }
    else  if  (z == "a") {
      digitalWrite(5, 0);
    }
  }
  Serial.print (z);
  z = "";
  
}
