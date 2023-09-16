#include <ESP8266WiFi.h> 
#include "DHT.h" 
#include <SPI.h>
#include <Wire.h>
#include "MQ135.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
String apiKey = "MHQK34KJYWS1RXZ2"; 
const char *ssid =  "HUAWEI Y8s"; 
const char *pass =  "HM876543211"; 
const char* server = "api.thingspeak.com"; 
 
DHT dht(D5, DHT11); 
WiFiClient client; 
 
void setup() { 
  Serial.begin(115200); 
  delay(10); 
  dht.begin(); 
  WiFi.begin(ssid, pass); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
  delay(10);
 
  Serial.println("Connecting to ");
  Serial.println(ssid);
  
  display.clearDisplay();
  display.setCursor(0,0);  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Connecting to ");
  display.setTextSize(2);
  display.print(ssid);
  display.display();
  
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected");
    
    display.clearDisplay();
    display.setCursor(0,0);  
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("WiFi connected");
    display.display();
    delay(4000);
} 
 
void loop() { 
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
 
  if (isnan(h) || isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!"); 
    return; 
  } 
 
  if (client.connect(server, 80)) { 
    String postStr = apiKey; 
    postStr += "&field1="; 
    postStr += String(t); 
    postStr += "&field2="; 
    postStr += String(h); 
    postStr += "\r\n\r\n"; 
 
    client.print("POST /update HTTP/1.1\n"); 
    client.print("Host: api.thingspeak.com\n"); 
    client.print("Connection: close\n"); 
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n"); 
    client.print("Content-Type: application/x-www-form-urlencoded\n"); 
    client.print("Content-Length: "); 
    client.print(postStr.length()); 
    client.print("\n\n"); 
    client.print(postStr); 
 
    Serial.print("Temperature: "); 
    Serial.print(t); 
    Serial.print("\t"); 
    Serial.print("Humidity: "); 
    Serial.println(h); 
 
  } 
  client.stop(); 
  delay(1000); 
     MQ135 gasSensor = MQ135(A0);
    float air_quality = gasSensor.getPPM();
    Serial.print("Air Quality: ");  
    Serial.print(air_quality);
    Serial.println("  PPM");   
    Serial.println();
 
    display.clearDisplay();
    display.setCursor(0,0);  //oled display
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Air Quality Index");
    
  
    display.setCursor(0,20);  //oled display
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print(air_quality);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(" PPM");
    display.display();
 
 
    if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(air_quality);
    postStr += "r\n";
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    
    Serial.println("Data Send to Thingspeak");
  }
    client.stop();
    Serial.println("Waiting...");
 
    delay(2000);      // thingspeak needs minimum 15 sec delay between updates.
}
