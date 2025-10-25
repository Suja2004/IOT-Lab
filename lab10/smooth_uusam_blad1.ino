#include <Adafruit_LiquidCrystal.h>
int pinTemp = 14;
int analogVal ;
int seconds = 0;
float lastVoltage = 0;
Adafruit_LiquidCrystal lcd(0);

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 0);
  analogVal = analogRead(pinTemp);
  float voltage = (analogVal / 1023.0) * 5.0; // Convert to voltage
  float temperatureC = (voltage - 0.5) * 100.0; // Convert to degrees Celsius
  
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  if(lastVoltage - voltage != 0 ){
  lastVoltage = voltage ;
    lcd.clear();
  }
  lcd.print(temperatureC);
  lcd.print(" C");
  delay(500);
}

/*#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>

#define DHT11PIN 4
dht11 DHT11;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(7, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;); // Infinite loop if display init fails
  }

  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(5000);

  int chk = DHT11.read(DHT11PIN);
  digitalWrite(7, HIGH);

  float t = DHT11.temperature;
  float h = DHT11.humidity;

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temperature");

  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(t);
  display.write(167);
  display.print("C");

  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity");

  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print("%");

  display.display();
}
*/