const int sensorPin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void leer_sensor()
{
  String bufer="AT$SF=";
  String bufer2="\r\n";
  delay(1000);
  int sensorVal=analogRead(sensorPin);
  float voltaje=(sensorVal/1024.0)*5.0;
  Serial.print("Grados Cº: ");
  float temp=((voltaje)*100)+1;
  Serial.println(temp);
  //convierte el dato a bytes y lo agrega a nuestro mensaje a enviar
  byte* a1 = (byte*) &temp;  
  String str1,str2,str3,str4;
  str1=  String(a1[0], HEX);  
  str2=  String(a1[1], HEX);
  str3=  String(a1[2], HEX);
  str4=  String(a1[3], HEX);
  bufer+=0+str1+str2+str3+str4+bufer2;
  Serial.print("AT$RC\r\n");
  delay(500);
  Serial.print(bufer);
  delay(3000);
  
}

void loop()
{
  //manda la temperatura cada minuto
  enable_module();
  leer_sensor();
  disable_module();
  delay(60000);
}
void enable_module()
{
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
}
void disable_module()
{
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
}


