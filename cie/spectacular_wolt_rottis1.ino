const int dry_threshold = 800;
const int wet_threshold = 300;
int moisture_sensor = 0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  moisture_sensor = analogRead(A0);

  Serial.print("Moisture Level: ");
  Serial.print(moisture_sensor);
  Serial.print(" - Status: ");

  if (moisture_sensor >= dry_threshold) {
    Serial.println("Dry - Needs Water");
    digitalWrite(13, HIGH); 
    digitalWrite(11, HIGH); 
    digitalWrite(10, LOW); 
    digitalWrite(9, LOW); 
  } else if (moisture_sensor <= wet_threshold) {
    Serial.println("Wet - No Water Needed");
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);     
    digitalWrite(10, LOW);     
    digitalWrite(9, HIGH);     
  } else {
    Serial.println("Moderate - Monitor Closely");
    digitalWrite(13, LOW); 
    digitalWrite(11, LOW);     
    digitalWrite(10, HIGH);     
    digitalWrite(9, LOW);     
  }

  delay(1000);
}
