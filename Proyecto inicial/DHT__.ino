#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

const char* ssid = "wifi";  // SSID
const char* password = "password";  // Password 

ESP8266WebServer server(80);

// DHT Sensor
uint8_t DHTPin = 2; 
               
// Inicializa elsensor DHT
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;
 
void setup() {
  Serial.begin(9600);
  delay(100);
  
  pinMode(DHTPin, INPUT);

  dht.begin();              

  Serial.println("Conectando a ");
  Serial.println(ssid);

 WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("conectando WiFi..!");
  Serial.print("IP: ");
  Seria…
