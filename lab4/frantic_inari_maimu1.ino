// C++ code
//
const int dry_threshold = 800;
const int wet_threshold = 300;
int moisture_sensor = 0;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  moisture_sensor = analogRead(A0);
  Serial.println(moisture_sensor);
  //moisture_sensor <= wet_threshold
  if(moisture_sensor >= dry_threshold){
    digitalWrite(13,HIGH);
  }
  else{
        digitalWrite(13,LOW);
  }
}