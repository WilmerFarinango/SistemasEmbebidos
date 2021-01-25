#include "datos.h"

float datosPrueba [5]={5.8,2.7,5.1,1.9,3.0}
;
int Resp;
int knn (int k, int etiquetas, int tam_col, int col_fil); // definir la func
void setup() {
Serial.begin(9600);
Resp=knn(3,3,5,87);
switch(Resp){
  case 1:
    Serial.println("setosa");
  break;
  case 2:
    Serial.println("versicolor");
  break;
   case 3:
    Serial.println("verginica");
  break;
  }
}

void loop() {
}

int knn (int k, int etiquetas, int tam_col, int tam_fil){
int col;
int fil=0;
int i=0;
int j;
float aux;
float aux_etiqueta;
float potencia;
float raiz;
int label;
String salida="";
 float matriz_k [3][k];
 for(;i<k;i++){
  matriz_k[0][i]=i+1.00;
  matriz_k[1][i]=0; 
  matriz_k[2][i]=2500.0+i;
  }
  i=0;
 
  float matriz_eti[2][etiquetas];
  for(;i<etiquetas;i++){
      matriz_eti[0][i]=i+1.0; 
      matriz_eti[1][i]=0.0;   
    }

   for(;fil<tam_fil;fil++){
      for(col=0;col<tam_col-1;col++){ // menos la ultima columna que corresponde a la etiqueta
          potencia=potencia+pow(matriz[fil][col]-datosPrueba[col],2);
        }
        raiz=sqrt(potencia);
        potencia=0;
        if(raiz<matriz_k[2][k-1]){
          matriz_k[2][k-1]=raiz;
          matriz_k[1][k-1]=matriz[fil][tam_col-1]; 
          // ordenar matriz por metodo de burbuja
          for(i=0;i<k;i++){
             for(j=i+1;j<k;j++){
               if(matriz_k[2][i]>matriz_k[2][j]){
                 // distancia
                  aux=matriz_k[2][i];
                  matriz_k[2][i]=matriz_k[2][j];
                  matriz_k[2][j]=aux;
                  //etiqueta
                  aux_etiqueta=matriz_k[1][i];
                  matriz_k[1][i]=matriz_k[1][j];
                  matriz_k[1][j]=aux_etiqueta;
                }
              }
            }
        }
    }
    for(i=0;i<etiquetas;i++){
      for(j=0;j<k;j++){
          if(matriz_eti[0][i]==matriz_k[1][j]){
            matriz_eti[1][i]++;
          }
        }
      }

    for(i=0;i<etiquetas-1;i++){
       if(matriz_eti[1][i]<matriz_eti[1][i+1])
        label=(int)matriz_eti[0][i+1];
        else 
        label=(int)matriz_eti[0][i];
      }  
 return label;
};
