/*
* Ejemplo para conectar blynk a NodeMCU
* Basado en NodeMCU: https://github.com/blynkkk/blynklibrary/tree/master/examples/Boards_WiFi/NodeMCU
* Requiere:
* - Blynk: https://github.com/blynkkk/blynk-library
*/

#include <ESP8266WiFi.h>

char ssid[] = "XXXX"; //nombre wifi
char pass[] = "XXXX"; // contraseña

void setup()
{

Serial.begin(9600);
Serial.print("Conectando a "); 
Serial.print(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    } 
Serial.println("");
Serial.print("WiFi conectado, direccion IP: "); 
Serial.println(WiFi.localIP());

}
void loop()
{

}
