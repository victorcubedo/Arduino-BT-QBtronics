/*
   Autor : Victor Cubedo Hernández
   Fecha : 12/12/2019
   Versión 1.0
   Este programa recibe los datos de la app, que dependiendo del numero que sea hace una cosa u otra.
   Para ampliar las posibilidades del programa habría que añadir mas botones en la app y los "if" en
   el programa. Actualmente se está usando la app "Arduino bluetooth Terminal".
*/

int led13 = 13;  //Led con el que vamos a trabajar
int opcion = 0; //Valores que recibirá de la app

void setup() {

  Serial.begin(9600);
  pinMode(led13, OUTPUT);

}

void loop () {

  if (Serial.available() > 0) {  //Si el valor recibido es mayor a 0
    opcion = Serial.read(); //Guardamos el valor recibido en opcion
  }

  if (opcion == '1') { //Cuando mandemos 1
    digitalWrite(led13, HIGH);  //Se enciende
  }
  if (opcion == '2') {  //Cuando mandemos 2
    digitalWrite(led13, LOW); //Se apaga
  }
}
