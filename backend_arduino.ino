#include <ESP8266WiFi.h>
const char* ssid = "INSERTAR WIFI_SSID";
const char* password = "INSERTAR PASSWORD";
int led =D0;
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode (led,OUTPUT);
  digitalWrite (led,LOW);
  WiFi.begin (ssid,password);
  while (WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi conectado");

 server.begin();
 Serial.println("servidor iniciado");
  Serial.print ("usa esta URL para conectar al servidor: "); 
  Serial.print ("http://");
  Serial.print (WiFi.localIP());
  Serial.println("/");
 
}

void loop() {
  WiFiClient client = server.available();
  if (!client){
  return;
  }
  Serial.println ("¡nuevo cliente!");
  while (!client.available()){
    delay(1);
  }
String request = client.readStringUntil('\r');
Serial.println (request);
client.flush();

}
