// set all moisture sensors PIN ID
int moisture1 = A0;
int moisture2 = A1;
int moisture3 = A2;
int moisture4 = A3;

// declare moisture values
int moisture1_value = 0;
int moisture2_value = 0;
int moisture3_value = 0;
int moisture4_value = 0;

// set water relays
int relay1 = 3;
int relay2 = 4;
int relay3 = 5;
int relay4 = 6;

// set water pump
int pump = 2;

void setup() {
  // declare relay as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  // declare pump as output
  pinMode(pump, OUTPUT);
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);  
}

void loop() {
  
 // read the value from the moisture sensors:
 moisture1_value = analogRead(moisture1);
 moisture2_value = analogRead(moisture2);
 moisture3_value = analogRead(moisture3);
 moisture4_value = analogRead(moisture4);
 
 // check which plant need water
 // and open the switch for that specific plant

  Serial.print("1번 수치 : "); Serial.print(moisture1); Serial.print("  ");
  Serial.print("습도 수치 : "); Serial.print(moisture2); Serial.print("  ");
  Serial.print("3번 수치 : "); Serial.print(moisture3); Serial.print("  ");
  Serial.print("4번 수치 : "); Serial.println(moisture4);
 
 if(moisture1_value<=20){
  digitalWrite(relay1, HIGH);
 }


 if(moisture2<=16){
    digitalWrite(relay2, HIGH);
    digitalWrite(pump, HIGH);
    Serial.println("2 펌프 작동 중");
     if(moisture3<=16){
        digitalWrite(relay3, HIGH);
        digitalWrite(pump, HIGH);
        Serial.println("3 펌프 작동 중");
     }
     else if(moisture4<=16){
       digitalWrite(relay4, HIGH);
       digitalWrite(pump, HIGH);
       Serial.println("4 펌프 작동 중");
     }
 }

  if(moisture3<=16){
    digitalWrite(relay3, HIGH);
    digitalWrite(pump, HIGH);
    Serial.println("3 펌프 작동 중");
     if(moisture2<=16){
        digitalWrite(relay2, HIGH);
        digitalWrite(pump, HIGH);
        Serial.println("2 펌프 작동 중");
     }
     else if(moisture4<=16){
       digitalWrite(relay4, HIGH);
       digitalWrite(pump, HIGH);
       Serial.println("4 펌프 작동 중");
     }
 }

   if(moisture4<=16){
    digitalWrite(relay4, HIGH);
    digitalWrite(pump, HIGH);
    Serial.println("4 펌프 작동 중");
     if(moisture2<=16){
        digitalWrite(relay2, HIGH);
        digitalWrite(pump, HIGH);
        Serial.println("2 펌프 작동 중");
     }
     else if(moisture3<=16){
       digitalWrite(relay3, HIGH);
       digitalWrite(pump, HIGH);
       Serial.println("3 펌프 작동 중");
     }
 }
 if(moisture3<=16){
    digitalWrite(relay3, HIGH);
    digitalWrite(pump, HIGH);
    Serial.println("3 펌프 작동 중");
 }
 if(moisture4<=16){
    digitalWrite(relay4, HIGH);
    digitalWrite(pump, HIGH);
    Serial.println("4 펌프 작동 중");
 }
 
 // make sure there is at least one plant that needs water
// if there is, open the motor
 if(moisture2_value<=20 || moisture3_value<=20 || moisture4_value<=20){
   digitalWrite(pump, HIGH);
   Serial.println("펌프 작동 중");
 }
if(moisture1<=20){
  digitalWrite(relay1, HIGH);
  digitalWrite(pump, HIGH);     Serial.print("1 펌프 작동 중");
  delay(2000);
  digitalWrite(relay1, LOW);
  digitalWrite(pump, LOW);  Serial.println("     작동 끝");
  delay(2000);
 }
 
 if(moisture2 <=20){
  digitalWrite(relay2, HIGH);     Serial.print(" 펌프 작동 중");
  digitalWrite(pump, HIGH);
  delay(10000);
  digitalWrite(relay2, LOW);
  digitalWrite(pump, LOW);      Serial.println("     작동 끝");
  delay(2000);
 }
 if(moisture3 <=20){
  digitalWrite(relay3, HIGH);
 digitalWrite(pump, HIGH);    Serial.print("3 펌프 작동 중");
  delay(2000);
  digitalWrite(relay3, LOW);
  digitalWrite(pump, LOW);  Serial.println("     작동 끝");
  delay(2000);
}
 if(moisture4 <=20){
  digitalWrite(relay4, HIGH);
  digitalWrite(pump, HIGH);     Serial.print("4 펌프 작동 중");
  delay(2000);
  digitalWrite(relay4, LOW);
  digitalWrite(pump, LOW);  Serial.println("     작동 끝");
  delay(2000);
 }
 
 // let it water the plant for 5 seconds
 delay(2000);
 
 // turn the pump off
 digitalWrite(pump, LOW);
 
 // go each switch and turn them off
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);
 digitalWrite(relay4, LOW);
 
 delay(2000);
 
}
