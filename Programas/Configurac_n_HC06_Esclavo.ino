const int LED = 13;
const int BTPWR = 12;

char nombreBT[6] = "QB2BT";
int velocidad = 4;

//char velocidad ='4';//9600
char pin [5]= "1234";

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPWR, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BTPWR, HIGH);

  Serial.begin(9600);

  Serial.print("AT");
  delay(1000);

  Serial.print("AT+NAME = ");
  Serial.println(nombreBT);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.println(velocidad);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.println(pin);
  delay(1000);

  digitalWrite(LED, HIGH);
}

void loop(){
  
}
