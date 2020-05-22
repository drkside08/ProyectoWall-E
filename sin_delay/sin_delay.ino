int BISR1=2; //<--aun no usados
int BISR2=3; //<--aun no usados
int BArranque=4;
int BParo=5;
int B4=6;
int BTest=7;
int LVerde=8;//<--Etapa de Pintar
int LAmarillo=10;//<--Etapa de Programacion
int LRojo=9;//<--Etapa de Paro
int LAnaranjado=11;//<--Etapa de Test
int LRojo2=12;//<--Led aux;
//------------------------------------------
unsigned long Actual=0;
unsigned long Inicio1=0;
unsigned long Inicio2=0;
unsigned long Intervalo=100;
unsigned long Intervalo2=100;
//------------------------------------
float Distancia;
int flag=1;
bool Pro=false;


void setup(){
  Serial.begin(9600);
  pinMode(BArranque,INPUT);
  pinMode(BParo,INPUT);
  pinMode(B4,INPUT);
  pinMode(BTest,INPUT);
  pinMode(LVerde,OUTPUT);
  pinMode(LAmarillo,OUTPUT);
  pinMode(LRojo,OUTPUT);
  pinMode(LAnaranjado,OUTPUT);
  pinMode(LRojo2,OUTPUT);
  pinMode(LVerde,OUTPUT);
  pinMode(LAmarillo,OUTPUT);
  pinMode(13,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), Paro, RISING);
  Inicio1=millis();
}
void CambiarLed1(int A){
   bool estado=!digitalRead(A);
   if (estado) digitalWrite(A,HIGH);
   if (!estado)digitalWrite(A,LOW);
}
void CambiarLed2(int LedAux){
   bool estado=!digitalRead(LedAux);
   if (estado) digitalWrite(LedAux,HIGH);
   if (!estado)digitalWrite(LedAux,LOW);
}
void Test(){
  float Valor=0;
  int Aux=-1;
  unsigned long InicioP=millis();
  unsigned long Punto=0;
  unsigned long Tiempo=0;
  digitalWrite(LAnaranjado,HIGH);
  do{
   Valor=analogRead(A3);
    Valor=((Valor*5)/1024);
    Serial.println(Valor);
    if(Valor>=3.75){
      if(Valor>=4.80){
        Aux=5;   
      }
      else{
        Aux=4; 
      }
    }
    else{
      if(Valor>=2.5){
        Aux=3; 
      }
      else{
        if(Valor>=1.25){
          Aux=2;
        }
        else{
          if(Valor>=.50){
            Aux=1;
          }
          else{
            Aux=0;
          }
        }
      }
    }
    switch(Aux){
      case 5:
      digitalWrite(LRojo2,HIGH);
      break;
      case 4:
        //digitalWrite(LRojo2,LOW);
        Tiempo=500;
        Punto=millis(); 
        if((unsigned long)(Punto-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Punto;
        }
      break;
      case 3:
        Tiempo=400;
        Punto=millis();
        if((unsigned long)(Punto-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Punto;
        }
      break;
      case 2:
        Tiempo=300;
        Punto=millis();
        if((unsigned long)(Punto-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Punto;
        }
      break;
      case 1:
        Tiempo=200;
        Punto=millis();
        if((unsigned long)(Punto-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Punto;
        }
      break;
      case 0:
        Tiempo=100;
        Punto=millis();
        if((unsigned long)(Punto-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Punto;
        }
      break;
    }
   }while(digitalRead(BParo)!=HIGH);
   digitalWrite(LAnaranjado,LOW);
   digitalWrite(LRojo2,LOW);
}
void Programar(){
  int Opc=0;
  unsigned long InicioP=millis();
  unsigned long Actual=0;
  unsigned long Tiempo=0;
  digitalWrite(LAmarillo,HIGH);
  delay(500);
  do{
     if(digitalRead(B4)==HIGH){
        Opc=1;Distancia=2.5;
     }
     if(digitalRead(BTest)==HIGH){
        Opc=2;Distancia=4;
     }
     switch(Opc){
      case 2:
        digitalWrite(LAnaranjado,LOW);
        Tiempo=500;
        Actual=millis();
        if((unsigned long)(Actual-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Actual;
        }
      break;
      case 1:
        digitalWrite(LRojo2,LOW);
        Tiempo=500;
        Actual=millis();
        if((unsigned long)(Actual-InicioP)>=Tiempo){
        CambiarLed2(LAnaranjado);
        InicioP=Actual;
        }
      break;
      case 0:
      digitalWrite(LAmarillo,HIGH);
      break;
      }
      }while(digitalRead(BParo)!=HIGH);
      digitalWrite(LAnaranjado,LOW);
      digitalWrite(LRojo2,LOW);
  
}
void Pintar(){
  digitalWrite(LVerde,HIGH);
  unsigned long InicioP=millis();
  unsigned long Actual=0;
  unsigned long Tiempo=0;
  Serial.write("\xa0\x01\x01\xa2");
  
}
void Paro(){
  digitalWrite(LRojo,HIGH);
  unsigned long InicioP=millis();
  unsigned long Actual=0;
  unsigned long Tiempo=500;
  Serial.write("\xa0\x01");
  Serial.write(0x00);
  Serial.write(0xa1);
  if((unsigned long)(Actual-InicioP)>=Tiempo){
        CambiarLed2(LRojo2);
        InicioP=Actual;
  }
}
void loop(){
  
  if((digitalRead(BArranque)==HIGH) && (Pro==true)){
   Pintar();
  }
  if(digitalRead(B4)==HIGH){
   Programar();
   if(Distancia != 0 ){
    Pro=true;
   }
  }
  if(digitalRead(BTest)==HIGH){
   Test(); 
  }
  //-----------------------------------//
  Actual=millis();
  if((unsigned long)(Actual-Inicio1)>=Intervalo){
    CambiarLed1(13);
    Inicio1=Actual;
    }
}
