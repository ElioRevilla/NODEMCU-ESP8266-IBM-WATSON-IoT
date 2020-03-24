#include <OneWire.h>
#include <DallasTemperature.h>

OneWire pin(D4);
DallasTemperature sensor(&pin);

void setup()
{
   Serial.begin(115200);
   sensor.begin(); 
}

void loop()
{
  sensor.requestTemperatures();
  Serial.println(sensor.getTempCByIndex(0));
}
