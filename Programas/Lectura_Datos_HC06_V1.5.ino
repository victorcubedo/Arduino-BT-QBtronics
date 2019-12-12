/*
   Autor : Victor Cubedo Hernández

   Fecha : 12/12/2019

   Versión 1.5 * Añadido Pin digital para alimentasr el HC06 (evita tener que estar pendiente de
   conectarlo y desconectarlo cada vez ques ser cargue el programa en la placa).

   Este programa recibe los datos de la app, que dependiendo del numero que sea hace una cosa u otra.
   Para ampliar las posibilidades del programa habría que añadir mas botones en la app y los "if" en
   el programa. Actualmente se está usando la app "Arduino bluetooth Terminal".
*/

int led = 13;  //Led con el que vamos a trabajar
int opcion = 0; //Valores que recibirá de la app
int vccBT = 8; //Pin por el que alimentamos al HC06

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(vccBT, OUTPUT); //Pin alimentación HC06
  delay(1000);  //Esperamos 1 segundo.
  digitalWrite(vccBT, HIGH); //Le mandamos voltaje

}

void loop () {

  if (Serial.available() > 0) {  //Si el valor recibido es mayor a 0
    opcion = Serial.read(); //Guardamos el valor recibido en opcion
  }

  if (opcion == '1') { //Cuando mandemos 1
    digitalWrite(led, HIGH);  //Se enciende
  }
  if (opcion == '2') {  //Cuando mandemos 2
    digitalWrite(led, LOW); //Se apaga
  }
}
