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
  String str1;
  for(int i=0;i<4;i++)
  {
    str1=String(a1[i], HEX);
    if(str1.length()<2)
    {
      bufer+=0+str1;
    }
    else
    {
      bufer+=str1;
    }
  }
  bufer+=bufer2;
  enable_module();
  Serial.print("AT$RC\r\n");
  delay(500);
  Serial.print(bufer);
  delay(3000);
}

void loop()
{
  //manda la temperatura cada 5 minutos
  leer_sensor();
  disable_module();
  delay(30000);
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

