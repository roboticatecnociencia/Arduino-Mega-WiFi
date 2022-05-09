#define ENA   8          // GPIO14(D5)
#define ENB   13          // GPIO12(D6)
#define IN_1  9          // GPIO15(D8)
#define IN_2  10          // GPIO13(D7)
#define IN_3  11           // GPIO2(D4)
#define IN_4  12           // GPIO0(D3)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String boton;             // Almacena la petición del botón.
int Velocidad = 800;      
int speed_Coeff = 3;

const char* ssid = "NodeMCU Car";
ESP8266WebServer server(80);

void setup() {
 
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
  
  Serial.begin(115200);
  
// Conectar a WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid); 

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP Dirección IP es: ");
  Serial.println(myIP);
 
 // Iniciando servidor web 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void Avanza(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, Velocidad);
  }

void Retrocede(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, Velocidad);
  }

void Derecha(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, Velocidad);
  }

void Izquierda(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, Velocidad);
  }

void DiagonalDerecha(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, Velocidad/speed_Coeff);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, Velocidad);
   }

void DiagonalIzquierda(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, Velocidad/speed_Coeff);
  }

void DiagonalDerechaAbajo(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, Velocidad/speed_Coeff);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, Velocidad);
  }

void DiagonalIzquierdaAbajo(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, Velocidad/speed_Coeff);
  }

void Detener(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, Velocidad);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, Velocidad);
 }

void loop() {
    server.handleClient();
    
      boton = server.arg("State");
      if (boton == "F") Avanza();
      else if (boton == "B") Retrocede();
      else if (boton == "L") Izquierda();
      else if (boton == "R") Derecha();
      else if (boton == "I") DiagonalDerecha();
      else if (boton == "G") DiagonalIzquierda();
      else if (boton == "J") DiagonalDerechaAbajo();
      else if (boton == "H") DiagonalIzquierdaAbajo();
      else if (boton == "0") Velocidad = 400;
      else if (boton == "1") Velocidad = 470;
      else if (boton == "2") Velocidad = 540;
      else if (boton == "3") Velocidad = 610;
      else if (boton == "4") Velocidad = 680;
      else if (boton == "5") Velocidad = 750;
      else if (boton == "6") Velocidad = 820;
      else if (boton == "7") Velocidad = 890;
      else if (boton == "8") Velocidad = 960;
      else if (boton == "9") Velocidad = 1023;
      else if (boton == "S") Detener();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
