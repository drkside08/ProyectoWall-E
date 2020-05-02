int BArranque=2;
int BParo=3;
int B25m=4;
int B40m=5;
int BTest=6;
int Baux=7;
int LVerde=8;//<--Etapa de Pintar
int LAmarillo=9;//<--Etapa de Programacion
int LRojo=10;//<--Etapa de Paro
int LAnaranjado=11;//<--Etapa de Test
int LRojo2=12;//<--Led aux;
void setup2() {
  Serial.begin(9600);
  pinMode(BArranque,INPUT);
  pinMode(BParo,INPUT);
  pinMode(B25m,INPUT);
  pinMode(B40m,INPUT);
  pinMode(BTest,INPUT);
  pinMode(Baux,INPUT);
  pinMode(LVerde,OUTPUT);
  pinMode(LAmarillo,OUTPUT);
  pinMode(LRojo,OUTPUT);
  pinMode(LAnaranjado,OUTPUT);
  pinMode(LRojo2,OUTPUT);

}
void Test(){
  float Valor=0;
  int Aux=-1;
  int Eboton=0;
  digitalWrite(LAnaranjado,HIGH);
  while(Eboton==0){
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
        digitalWrite(LRojo2,HIGH);
        delay(1000);
        digitalWrite(LRojo2,LOW);
        delay(1000);
       break;
      case 3:
        digitalWrite(LRojo2,HIGH);
        delay(750);
        digitalWrite(LRojo2,LOW);
        delay(750);
       break;
      case 2:
        digitalWrite(LRojo2,HIGH);
        delay(500);
        digitalWrite(LRojo2,LOW);
        delay(500);
       break;
      case 1:
         digitalWrite(LAnaranjado,HIGH);
        digitalWrite(LRojo2,HIGH);
        delay(100);
        digitalWrite(LRojo2,LOW);
        delay(100);
       break;
      case 0:
        digitalWrite(LRojo2,HIGH);
        digitalWrite(LAnaranjado,HIGH);
        delay(100);
        digitalWrite(LRojo2,LOW);
        digitalWrite(LAnaranjado,LOW);
        delay(100);
       break;
    }
    if(digitalRead(BTest)==HIGH){Eboton=1; digitalWrite(LAnaranjado,LOW); digitalWrite(LRojo2,LOW);}
    else{Eboton=0;}
  }
}
void Selector(){
   
}

void loop2()
{
  Test();
  delay(1000);     
}
/*while(Valor<1.25){
    Valor=analogRead(A3);
    Valor=((Valor*5)/1024);
    Serial.println(Valor);
    digitalWrite(LRojo2,HIGH);
    delay(100);
    digitalWrite(LRojo2,LOW);
    delay(100);

    */
