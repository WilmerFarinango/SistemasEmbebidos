/*
Farinango Wilmer - deber 5
link de la simulacion tikercad:
https://www.tinkercad.com/things/cwNLhyf8pEQ-farinangowilmer-deber5

Realizar un programa que mediante interrupciones tenga
3 modos: Inicio del sistema, giro de motor y fin de programa.
El giro debe ser ingresado por comunicación serial. 
*/
#include <Servo.h>//incluimos la libreria del servo
int ltr;// igresamos una variable que guarde los datos del serial
int grados = 0;//iniciacilazmos grados en 0
Servo servo;
void setup()
{
  Serial.begin(9600);//ingresamos el modo de comunicacion
  servo.attach(9);//pin de salida para mover el servo
  pinMode(2,INPUT);//pin de interrupcion en 0
  pinMode(3,INPUT);//pin de interrupcion en 1
  attachInterrupt(0, aumentar, RISING);//interrupcion bajo a alto
  attachInterrupt(1, disminuir, RISING);//interrupcion bajo a alto
}
void loop()
{
servo.write(grados);// agregamos un funcion en la cual el servo iniciara en 0 grados
}
void aumentar(){
 if(Serial.available()>0){// si la entrada es 0 no hace nada
ltr = Serial.read();// leemos el dato ingresado por el serial y la asignamos al la variable
Serial.print("Recibi un: "); //imprime el mensaje con los datos en grados
Serial.println(ltr);
}
if (grados<180) grados=ltr; //gira los grados que ingrasamos por el puerto serial 
ltr =0;
}
void disminuir(){
if (grados>0) grados=grados-100;//regresamos el servo a la posicion original
}
