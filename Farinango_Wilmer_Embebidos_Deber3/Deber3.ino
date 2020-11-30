/*
 *Deber N: 3
 *Farinango Tallana Wilmer David
 
 *Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas 
 *que deben observarse en orden aleatorio. La forma de visualización es por medio 
 *de comunicación serial. Su respuesta solo debe ser "SI" y "NO" ingresadas de la 
 *misma forma por comunicación serial.
 *Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje 
 *(respuestas acertadas) en un display.
 */

String respuesta;
String Guardar_Respuesta;
String datos[8]={"1: tienes un nombre?","2: tener dos mujeres es bueno?","3: 1 mas 1 es 4?","4: 3+3=8?","5: Estas bien?","6: te llamas david?","7: tu perro se llama boby?","8: tienes una casa?"};
int Npregunta;
int contadorRincorectas=0;
int contadorRcorectas=0;
void prender_luces(int d,int c,int b,int a){
  digitalWrite(8,a);
  digitalWrite(9,b);
  digitalWrite(10,c);
  digitalWrite(11,d);
//  delay(300);
  }
void borrar_luces(){
  prender_luces(1,1,1,1);
  }

void numero_de_pregunta(){
// for(int J=0;J<5;J++){
  Npregunta=random(1,8);
  Serial.println();
  Serial.print(datos[Npregunta]);
  delay(4000);
//  }
  }

  
void setup() {
  Serial.begin(9600);
  for(int i=8;i<12;i++){ //habilita los pines del 8 al 11 como puertos de salida digital
    pinMode(i,OUTPUT);
    } 
    borrar_luces();
}

void loop() {
 // entra la pregunta y el numero de pregunta
 for(int J=0;J<5;J++){ // recorre 5 preguntas aleatorias.
 numero_de_pregunta(); // llama al metodo que elije las perguntas
 // lee la respuesta
  
  if(Serial.available()){ //lee el serial
  respuesta=Serial.readString();
  Serial.println();
  Guardar_Respuesta=Serial.print(respuesta);// se almasena en otra variable 
  
  // prende el numero de la respuesta

  // if anillados, para las perguntas
 if(respuesta=="SI" && Npregunta==1){
  prender_luces(0,0,0,1);//1
  }else if(respuesta=="SI" && Npregunta==2){
    prender_luces(0,0,1,0);//2
    }else if(respuesta=="SI" && Npregunta==3){
      prender_luces(0,0,1,1);//3
      }else if(respuesta=="SI" && Npregunta==4){
        prender_luces(0,1,0,0);//4
        }else if(respuesta=="SI" && Npregunta==5){
          prender_luces(0,1,0,1);//5
          }else if(respuesta=="SI" && Npregunta==6){
            prender_luces(0,1,1,0);//6
            }else if(respuesta=="SI" && Npregunta==7){
              prender_luces(0,1,1,1);//7
              }else if(respuesta=="SI" && Npregunta==8){
                prender_luces(1,0,0,0);//8
                }else {
                   borrar_luces();
                  }
                  }
                  }
                  }
       
 
