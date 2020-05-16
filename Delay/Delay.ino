/**/
unsigned long Inicio=0;
unsigned long Actual=0;
void setup() {
  Serial.begin(9600);
  Inicio=millis();

}
void Funcion_A(){
   Actual=0;
   Actual=millis()-Inicio;
   Serial.print("Accion A-->"); 
   Serial.println(Actual); 
}
void Funcion_B(){
   Actual=0;
   Actual=millis()-Inicio;
   Serial.print("Accion B-->"); 
   Serial.println(Actual); 
}
void loop() {
  Funcion_A();
  delay(1500);
  Funcion_B();
  delay(500);
  
  

}
