// C++ code
//

const int pins[] = {2,3,4,5,6,7};
const int delayVal = 200;
const int n =6;
void setup()
{
  for(int i=0;i<6;i++)
  pinMode(pins[i], OUTPUT);
  
}

void loop()
{

  for(int i=0;i<n;i++){
    if(i%2==0){
      digitalWrite(pins[i], HIGH);
      delay(delayVal); // Wait for 1000 millisecond(s)
      digitalWrite(pins[i], LOW);
      delay(delayVal); // Wait for 1000 millisecond(s)
  	}
  }
  for(int i=0;i<n;i++){
    if(i%2!=0){
      digitalWrite(pins[i], HIGH);
      delay(delayVal); // Wait for 1000 millisecond(s)
      digitalWrite(pins[i], LOW);
      delay(delayVal); // Wait for 1000 millisecond(s)
  	}
  }
  /*
  for(int i=0;i<n;i++){
    digitalWrite(pins[i], HIGH);
    delay(delayVal); // Wait for 1000 millisecond(s)
    digitalWrite(pins[i], LOW);
    delay(delayVal); // Wait for 1000 millisecond(s)
  }
  for(int i=n-1;i>=0;i--){
    digitalWrite(pins[i], HIGH);
    delay(delayVal); // Wait for 1000 millisecond(s)
    digitalWrite(pins[i], LOW);
    delay(delayVal); // Wait for 1000 millisecond(s)
  }*/
}