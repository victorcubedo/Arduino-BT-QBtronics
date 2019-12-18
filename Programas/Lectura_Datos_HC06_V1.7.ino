/*
   Autor : Victor Cubedo Hernández

   Fecha creación : 12/12/2019

   Este programa depende de una App (en creación) que enciende los leds que nosotros indiquemos. 

   Versión 1.7 * 18/12/19 * Creado el rpograma mediante funciones.

   Versión 1.6 * 18/12/19 * Añadida la librería SoftwareSerial por problemas de comunicación.

   Versión 1.5 * Añadido Pin digital para alimentasr el HC06 (evita tener que estar pendiente de
   conectarlo y desconectarlo cada vez ques ser cargue el programa en la placa).
   
*/

#include <SoftwareSerial.h>

#define led 13  //Led con el que vamos a trabajar
#define Rx 2  //Pin recepción de datos arduino
#define Tx 3  //Pin transmision de datos arduino

int opcion = 0; //Valores que recibirá de la app

SoftwareSerial QBBT =  SoftwareSerial(Rx, Tx); // Creamos el modulo BT y le asginamos los pines

//-------------------------------------------------------------------------------------------------------

void setup() {
  QBBT.begin(9600);   //Iniciamos el módulo BT
  Serial.begin(9600);   //Iniciamos el monitor serial
  pinMode(led, OUTPUT);   //LED declarado como salida

}

//-------------------------------------------------------------------------------------------------------

void loop () {

  bluetooth();    //Llamamos a la función bluetooth

}
/*-------------------------------------------------------------------------------------------------------
//--------------------------CREACÓN DE LA FUNCIÓN BLUETOOTH---------------------------------------------
--------------------------------------------------------------------------------------------------------*/
void bluetooth() { 
  if (QBBT.available() > 0) {  //Si el valor recibido es mayor a 0
    opcion = QBBT.read(); //Guardamos el valor recibido en opcion
  }

  if (opcion == '1') { //Cuando mandemos 1
    digitalWrite(led, HIGH);  //Se enciende
    Serial.println("El LED 1 se ha encendido");
    Serial.println();
  }
  if (opcion == '2') {  //Cuando mandemos 2
    digitalWrite(led, LOW); //Se apaga
    Serial.println("El LED 1 se ha apagado");
    Serial.println();

  }
}
