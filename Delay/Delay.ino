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
   Serial.print("Pintando-->"); 
   Serial.println(Actual); 
}
void Funcion_B(){
   Actual=0;
   Actual=millis()-Inicio;
   Serial.print("Nivel de pintura-->"); 
   Serial.println(Actual); 
}
void loop() {
  Funcion_A();
  delay(1500);
  Funcion_B();
  delay(500);
}
