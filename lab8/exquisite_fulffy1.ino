// C++ code
//
#define TRIG 9
#define ECHO 10

long du;
float di;
float td = 300.0;
float wl;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

}

float getStableDistance() {
  long sum = 0;
  for (int i = 0; i < 5; i++) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    sum += pulseIn(ECHO, HIGH);
    delay(50);
  }
  return (sum / 5.0) * 0.034 / 2;
}


void loop()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);   
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);   
  digitalWrite(TRIG, LOW);
  
  du = pulseIn(ECHO,HIGH);
  di = du * 0.034/2;
  //di = getStableDistance();
  wl = td - di;
  Serial.println(di);
  
  if(wl < 0) wl = 0;
  if(wl > td) wl = td;
  
  Serial.print("Water Level: ");
  Serial.print(wl);
  Serial.print("cm /Depth: ");
  Serial.print(td);
  Serial.println("cm");
  
  delay(1000); 
}