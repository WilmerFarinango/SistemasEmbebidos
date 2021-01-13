#include <avr/wdt.h>
int conversor = 0; //variable de lectura CAD
int tiempo = 0; //variable de conversion y rango del CAD
int on = 0; //variable de estado
void setup() {
  Serial.begin(9600);   //inicia comunicacion Serial
  attachInterrupt(0, encender, FALLING);  //configura interrupcion
  Serial.println("BIENVENIDO");   //Mensaje de reincio del sistema
  wdt_disable();  //desactiva WatchDog
}

void loop() {
  conversor = analogRead(A0); //lee el CAD
  tiempo = map(conversor, 0, 1023, 0, 9); //realiza la conversion
  Serial.println(tiempo); //imprime el mensaje
  delay(2000);  //limita tiempo de lectura del cad
}

void encender() {
  on = 1 - on;
  if (on == 1) {  //comprueba si se cumple el cambio de estado
    Serial.println("WatchDog Configurado de Manera Correcta");  //mensaje de configuracion
    switch (tiempo) {   //comprueba la variable de conversion
      case 0:
        wdt_enable(WDTO_15MS);  //configura WatchDog
        Serial.println("Tiempo: 15MS" );  //Imprime mensaje
        break;
      case 1:
        wdt_enable(WDTO_30MS);//configura WatchDog
        Serial.println("Tiempo: 30MS" );//Imprime mensaje
        break;
      case 2:
        wdt_enable(WDTO_60MS);//configura WatchDog
        Serial.println("Tiempo: 60MS" );//Imprime mensaje
        break;
      case 3:
        wdt_enable(WDTO_120MS);//configura WatchDog
        Serial.println("Tiempo: 120MS" );//Imprime mensaje
        break;
      case 4:
        wdt_enable(WDTO_250MS);//configura WatchDog
        Serial.println("Tiempo: 250MS" );//Imprime mensaje
        break;
      case 5:
        wdt_enable(WDTO_500MS);//configura WatchDog
        Serial.println("Tiempo: 500MS" );//Imprime mensaje
        break;
      case 6:
        wdt_enable(WDTO_1S);//configura WatchDog
        Serial.println("Tiempo: 1S" );//Imprime mensaje
        break;
      case 7:
        wdt_enable(WDTO_2S);//configura WatchDog
        Serial.println("Tiempo: 2S" );//Imprime mensaje
        break;
      case 8:
        wdt_enable(WDTO_4S);//configura WatchDog
        Serial.println("Tiempo: 4S" );//Imprime mensaje
        break;
      case 9:
        wdt_enable(WDTO_8S);//configura WatchDog
        Serial.println("Tiempo: 8S" );//Imprime mensaje
        break;
    }
  }
}
