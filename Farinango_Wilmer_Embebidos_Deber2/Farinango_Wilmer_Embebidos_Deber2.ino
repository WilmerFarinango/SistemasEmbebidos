/*
 *Deber N: 2
 *Farinango Tallana Wilmer David
 *Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99. 
 */
const int D=11;
const int C=10;
const int B=9;
const int A=8;
const int decenas=13;
const int unidades=12;
const int btn=7;
int contador=0;
int decenas1;
int unidades1;

void setup() {
pinMode(D,OUTPUT);
pinMode(C,OUTPUT);
pinMode(B,OUTPUT);
pinMode(A,OUTPUT);
pinMode(decenas,OUTPUT);
pinMode(unidades,OUTPUT);

pinMode(btn,INPUT);
}

void loop() {
   
  if(digitalRead(btn)==LOW ){
    delay(100);
    if(contador<98)  
    contador=contador+3; 
    else
    contador=0;
    decenas1=contador/10;
    unidades1=contador-(decenas1*10);
    }contador++;
    digitalWrite(decenas,HIGH);
    digitalWrite(unidades,LOW);
    primo(decenas1);
    segmentos(decenas1);
    delay(200);
    digitalWrite(decenas,LOW);
    digitalWrite(unidades,HIGH);
    primo(unidades1);
    segmentos(unidades1);
    delay(200);
    }
    bool primo (int contador){
      bool condicion;
      for(int i=2; 1<contador;i++){
      if(contador % i==0){
      if(contador==1){
            condicion= true;
            }
            else {
              condicion= false;
              }
          }
        } 
        condicion=false;
        return condicion;
      }
  void segmentos(int i){//no retorna nada
    switch(i){
      case 0:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break ;
      case 1:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break ;
      case 2:
    digitalWrite(D,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break ;
      case 3:
    digitalWrite(D,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(A,LOW);
    break ;
      case 4:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break ;
      case 5:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break ;
      case 6:
    digitalWrite(D,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break ;
      case 7:
    digitalWrite(D,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break ;
      case 8:
    digitalWrite(D,LOW);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,HIGH);
    break ;
      case 9:
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(B,LOW);
    digitalWrite(A,HIGH);
    break ;
      }
    }
