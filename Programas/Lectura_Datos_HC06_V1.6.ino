/*
   Autor : Victor Cubedo Hernández

   Fecha : 12/12/2019

   Versión 1.6 * Añadida la librería SoftwareSerial por problemas de comunicación.

   Versión 1.5 * Añadido Pin digital para alimentasr el HC06 (evita tener que estar pendiente de
   conectarlo y desconectarlo cada vez ques ser cargue el programa en la placa).

   Este programa recibe los datos de la app, que dependiendo del numero que sea hace una cosa u otra.
   Para ampliar las posibilidades del programa habría que añadir mas botones en la app y los "if" en
   el programa. Actualmente se está usando la app "Arduino bluetooth Terminal".
*/

#include <SoftwareSerial.h>

#define led 13  //Led con el que vamos a trabajar
#define Rx 2  //Pin recepción de datos arduino
#define Tx 3  //Pin transmision de datos arduino

int opcion = 0; //Valores que recibirá de la app

SoftwareSerial QBBT =  SoftwareSerial(Rx, Tx); // Creamos el modulo BT y le asginamos los pines

void setup() {
  QBBT.begin(9600);   //Iniciamos el módulo BT
  Serial.begin(9600);   //Iniciamos el monitor serial
  pinMode(led, OUTPUT);   //LED declarado como salida

}

void loop () {

  bluetooth();

}


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
