/*
   Autor : Victor Cubedo Hernández

   Fecha creación : 12/12/2019

   Este programa depende de una App (en creación) que enciende los leds que nosotros indiquemos. 

   Versión 1.8 * 19/12/19 * Añadidos 2 LED mas.

   Versión 1.7 * 18/12/19 * Creado el rpograma mediante funciones.

   Versión 1.6 * 18/12/19 * Añadida la librería SoftwareSerial por problemas de comunicación.

   Versión 1.5 * Añadido Pin digital para alimentasr el HC06 (evita tener que estar pendiente de
   conectarlo y desconectarlo cada vez ques ser cargue el programa en la placa).
   
*/

#include <SoftwareSerial.h>

#define led1 4  //Led con el que vamos a trabajar
#define led2 5  //Led con el que vamos a trabajar
#define led3 6  //Led con el que vamos a trabajar
#define Rx 2  //Pin recepción de datos arduino
#define Tx 3  //Pin transmision de datos arduino

int opcion = 0; //Valores que recibirá de la app

SoftwareSerial QBBT =  SoftwareSerial(Rx, Tx); // Creamos el modulo BT y le asginamos los pines

//-------------------------------------------------------------------------------------------------------

void setup() {
  QBBT.begin(9600);   //Iniciamos el módulo BT
  Serial.begin(9600);   //Iniciamos el monitor serial
  pinMode(led1, OUTPUT);   //LED declarado como salida
  pinMode(led2, OUTPUT);   //LED declarado como salida
  pinMode(led3, OUTPUT);   //LED declarado como salida

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
    digitalWrite(led1, HIGH);  //Se enciende
    Serial.println("El LED 1 se ha encendido");
    Serial.println();
  }
  if (opcion == '2') {  //Cuando mandemos 2
    digitalWrite(led1, LOW); //Se apaga
    Serial.println("El LED 1 se ha apagado");
    Serial.println();
  }
    if (opcion == '3') { //Cuando mandemos 3
    digitalWrite(led2, HIGH);  //Se enciende
    Serial.println("El LED 2 se ha encendido");
    Serial.println();
  }
    if (opcion == '4') { //Cuando mandemos 4
    digitalWrite(led2, LOW);  //Se enciende
    Serial.println("El LED 2 se ha apagado");
    Serial.println();
  }
    if (opcion == '5') { //Cuando mandemos 5
    digitalWrite(led3, HIGH);  //Se enciende
    Serial.println("El LED 3 se ha encendido");
    Serial.println();
  }
    if (opcion == '6') { //Cuando mandemos 6
    digitalWrite(led3, LOW);  //Se enciende
    Serial.println("El LED 3 se ha apagado");
    Serial.println();
  }
}
