#include <SoftwareSerial.h>
#define rxPin 10
#define txPin 11
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
// matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};
int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //sumatoria x
int Ey=0; //sumatoria y
long int Exy=0; //sumatoria x*y
long int Ex2=0; //sumatoria x^2
long int Ex_2=0; //sumatoria Ex^2
int n= 14; //tama;o de muestras
float Bo; //ordenada en el origen
float m; //pendiente
String dato; //recibir estatura
int estatura; //convertir dato
float peso;
int m1; //aux

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  Bo=(float(Ex2*Ey)-float(Ex*Exy))/(float(n*Ex2-Ex_2));
  m1=(n*Exy)-(Ex*Ey); //aux de desborde
  m=(float(m1))/(float(n*Ex2-Ex_2));
  Serial.println("El modelo es: ");
  Serial.println(String("y= ")+String(Bo)+String("+")+String(m)+String("x"));
  Serial.println("Ingrese su estatura: ");
}
void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=m*estatura+Bo;
    Serial.println("");
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    //Serial.println("Ingrese su estatura: ");
    mySerial.write(estatura);
    Serial.println(estatura);
  }
}
