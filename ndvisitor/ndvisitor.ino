#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

WiFiClient wifiClient;

SoftwareSerial node(5,4);
 
const char* ssid     = ".....";
const char* password = "basecamp04"; 

void setup() 
{
  node.begin(9600);
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);   
  delay(1000);
  WiFi.mode(WIFI_STA);     
  
  WiFi.begin(ssid, password);    
  Serial.println("");

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  }

}


int data;
void loop() 
{
  data = 0;
  if(node.available()>0){
    data = int(node.read());

    HTTPClient http; 
    String postData = "jumlah=1&data=";
    postData += data;
    Serial.println(postData);
    
    http.begin(wifiClient,"http://192.168.1.3/test/simpan.php");        
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");  
  
    int httpCode = http.POST(postData); 
    String payload = http.getString();   
  
    Serial.println(httpCode); 
    Serial.println(payload);  
  
    http.end(); 
  }

  Serial.println(data);
    
  delay(2000); 
}
