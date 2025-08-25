// C++ code
//
int smoke_sensor=0;
void setup()
{
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop()
{
 smoke_sensor = analogRead(A0);
  Serial.println(smoke_sensor);
  if(smoke_sensor >=20){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  if(smoke_sensor >=25){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  delay(10);
}