/* Para utilizar este codigo debemos configurar la placa para el uso de ambos módulos.
Además debemos agregar la libreríá MemoryFree como se especifica en el readme.
Una vez que compilamos y subimos el código en el puerto serial podremos revisar la configuración de red
Recordar configurar la velocidad a 115200 baudios para ver los datos correctamente.
Encontraremos la dirección IP que nos permitirá acceder mediante un navegador a encender y apagar un Led.
 */

#include <MemoryFree.h>
#include <EEPROM.h>

#define PIN_LED 13    // Salida del LED
String inString;


void setup() {
  // Inicialización de puertos y salidas
  Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}


void loop() {
}

// Verificacion de la conectividad entre la Mega y ESP8266
void serialEvent3() {
  while (Serial3.available()) {
    // Lectura de datos del Serial3
    char inChar = Serial3.read();
    // Salida de los datos leídos en el puerto serie
    Serial.write(inChar);
    // Buscamos si recibimos un ON o un OFF desde la Web para actuvar o no el LED de la Mega(debe estar entre corchetes [])
    inString += inChar;
    if (inChar == ']') {
      if (inString.indexOf("[ON]")>0) {
        digitalWrite(PIN_LED, HIGH);
      }
      else if (inString.indexOf("[OFF]")>0) {
        digitalWrite(PIN_LED, LOW);
      }
      else
      {
        Serial.println("Wrong command");
      }
      inString = "";
    }
  }
}
