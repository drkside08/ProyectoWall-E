/*Variables para guardar el tiempo*/
unsigned long InicioP=0;
unsigned long Pintando=0;
unsigned long InicioS=0;
unsigned long Lecturas=0;
/*SIEMPRE TIENENS QUE SER UNSIGNED LONG */

La funcion MILLIS te da el millisegundo en el que se invoco la funcion
 
void setup() { 
  Serial.begin(9600);
  InicioP=millis(); <--- Aqui pido el tiempo de inicio y lo guardo en InicioP  en este caso va a ser "0s" el valor 
  delay(100); <--- bloquea la siguiente instruccion por 100 millisegundos
  InicioS=millis(); InicioS= 100
  print(InicioP);<-- para ver el "0"
  print(InicioS);
  

}
void Funcion_A(){
   InicioP=millis(); InicioP=3060ms 
   Serial.print("Pintando-->"); 
   Serial.println(millis()); 1560 en la pantalla 
}
void Funcion_B(){
   InicioS=millis(); InicioS=1100 
   Serial.print("Nivel de pintura-->"); 
   Serial.println(InicioS); 1100 en la pantalla
}
void loop() {  << esta es la funcion de encoder  
  ya se inicio el porceso de pintado
  y se puso l maquina  a pintar 
  
  Pintando=millis(); x
  Lecturas=millis(); x
                       3060  -   1560 = 1500
  if((unsigned long)(Pintando-InicioP)   >=1500){
  Funcion_A();
  }
                        1100  -   600 = 500
  if((unsigned long)(Lecturas-InicioS)>=500){
  Funcion_B();
  }

  funcion C 
}



cuadrado  = A
circulo  = B
operacion casta
A+(cuadrado)B =C




PastillaA 8 
PastillaB 16

PastillaA-PastillaB = 8 = 8horas te tomas la pastilla
PastillaA 8
PastillaB 17
PastillaA-PastillaB = 8 = 9 horas te tomas la pastilla

cada 8 horas una pastilla 

PastillaA 8 
PastillaB 16

PastillaA-PastillaB = 8 = 8horas te tomas la pastilla
PastillaA =16
PastillaB =24
PastillaA-PastillaB = 8  horas  te tomas la pastilla
