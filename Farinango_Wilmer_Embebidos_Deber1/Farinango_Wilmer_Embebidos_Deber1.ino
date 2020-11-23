/*
 *Deber N: 1
 *Farinango Tallana Wilmer David
 *Realizar un programa que accione mediante 4 switchs a un juego de luces diferente. Es decir.
 *sw3   sw2  sw1  sw0
 *0        0       0        1            Juego 1
 *0        0       1        0            Juego 2
 *0        1       0        0            Juego 3
 *1        0       0        0            Juego 4
 *Juego #1
Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones
Juego #2
Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones
Juego #3
Se encienden secuencialmente cada uno ellos (flexible a su criterio)
Juego #4
Su propio diseño de juego. 
 */
int led1=13;
int led2=12;
int led3=11;
int led4=10;
int led5=9;
int led6=8;
int btn=7;
int cont=0;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);  
  pinMode(btn,INPUT);
  }
void loop() {
  if(digitalRead(btn)==1)
  cont++;
  if(cont=4){
    cont==0;  
        }
  switch (cont){
    case 1:
    digitalWrite(led2,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led6,HIGH);
    break;
    case 2:
    digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led5,HIGH);
    break;
    case 3:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    break;
    case 4:
    digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led5,HIGH);
    break;
    }
}


  

     





  
