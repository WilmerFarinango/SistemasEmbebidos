#include <avr/sleep.h>  //importar libreria sleep

#include <avr/wdt.h>
#include <MsTimer2.h> //importar libreria Timer 2
int tiempo = 0;  

int conversor;
void setup() {
  Serial.begin(9600); //incializa Comunicacion Serial
  MsTimer2::set(1000, conteo); //Configura el Timer 2
  MsTimer2::start();  //inicializa Timer 2
  Serial.println("INICIO");
}

void loop() {

}

void conteo() {
  if (tiempo < 59) {
    tiempo++; //incrementa la variable
    Serial.println(tiempo); //imprime el mensaje
    wdt_disable();
    set_sleep_mode(SLEEP_MODE_ADC); //configura el modo sleep
    sleep_enable();
  }
  else{
    
    sleep_disable();  //desactiva el modo sleep
    tiempo = 0; //reinicia la Variable
    conversor = analogRead(A0); //realiza lectura del CAD
    Serial.println("Valor CAD:" + String(conversor)); //Imprime mensaje
    Serial.println(" ");
    Serial.println(tiempo); //imprime el mensaje
    wdt_enable(WDTO_15MS);
  }
}
