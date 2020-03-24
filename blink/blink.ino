/*
* Ejemplo para encender LEDs incoporados
* Basado en ESP8266 Blink by Simon Peter:
* https://github.com/esp8266/Arduino/blob/master/libraries/esp8266/examples/Blink/Blink.ino
*/

#define LED_BUILTIN D4

void setup() {
pinMode(LED_BUILTIN, OUTPUT); // Inicializa el LED_BUILTIN pin como salida

}
// la funcion se ejecuta permanentemente
void loop() {
digitalWrite(LED_BUILTIN, LOW); // Enciende el LED
delay(1000); // Espera un segundo
digitalWrite(LED_BUILTIN, HIGH); // Apaga el LED
delay(2000); // Espera dos segundos

}
