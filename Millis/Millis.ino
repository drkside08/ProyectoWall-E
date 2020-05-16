/**/
unsigned long InicioP=0;
unsigned long Pintando=0;
unsigned long InicioS=0;
unsigned long Lecturas=0;

void setup() {
  Serial.begin(9600);
  InicioP=millis();
  InicioS=millis();
  

}
void Funcion_A(){
   InicioP=millis();
   Serial.print("Pintando-->"); 
   Serial.println(millis()); 
}
void Funcion_B(){
   InicioS=millis();
   Serial.print("Nivel de pintura-->"); 
   Serial.println(InicioS); 
}
void loop() {
  Pintando=millis();
  Lecturas=millis();
  if((unsigned long)(Pintando-InicioP)>=1500){
  Funcion_A();
  }
  if((unsigned long)(Lecturas-InicioS)>=500){
  Funcion_B();
  }
}
