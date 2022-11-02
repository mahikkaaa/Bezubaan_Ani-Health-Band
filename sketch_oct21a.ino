#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
int ledl=7;

void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();

  pinMode(7,OUTPUT);
}

void loop() 
{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  float f = dht.readTemperature(true);

  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C   ");
  Serial.print(f);
  Serial.println(" *F");

  digitalWrite(ledl,HIGH);
  delay(110);
  digitalWrite(ledl,LOW);
  delay(20);
}
