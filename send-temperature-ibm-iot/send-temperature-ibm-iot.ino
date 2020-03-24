#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h> 

char* ssid = "XXXX";
char* password = "XXXX";

#define ORG "XXXX" 
#define DEVICE_TYPE "XXXX" 
#define DEVICE_ID "XXXX" 
#define TOKEN "XXXXXXXXXXXXXX" 

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char pubTopic[] = "iot-2/evt/XXXX/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;

WiFiClient wifiClient;
PubSubClient client(server, 1883, NULL, wifiClient);


//SENSOR DE TEMPERATURA
#include <OneWire.h>                
#include <DallasTemperature.h>
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire D4
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor


void setup() {
    Serial.begin(115200);  
    sensors.begin();   //Se inicia el sensor
    Serial.println();
    Serial.print("Connecting to "); 
    Serial.print(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    } 
    Serial.println("");
    
    Serial.print("WiFi connected, IP address: "); 
    Serial.println(WiFi.localIP());

    if (!client.connected()) {
        Serial.print("Reconnecting client to ");
        Serial.println(server);
        while (!client.connect(clientId, authMethod, token)) {
            Serial.print(".");
            delay(500);
        }
        Serial.println("Bluemix connected");
    }
}

long lastMsg = 0;

void loop() {
    client.loop();
    long now = millis();
    
    sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
   
    
    if (now - lastMsg > 3000) {
        lastMsg = now;            
        float temperatura= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC 
        String payload = "{\"d\":{\"Name\":\"" DEVICE_ID "\"";
              payload += ",\"temperatura\":";
              payload += temperatura;
              payload += "}}";
       
        Serial.print("Sending payload: ");
        Serial.println(payload);

        if (client.publish(pubTopic, (char*) payload.c_str())) {
            Serial.println("Publish ok");
        } else {
            Serial.println("Publish failed");
        }
       
    }
}
 
