# Arduino Mega Wifi

![](images/arduino-small.jpg)

## Funcionamiento 🚀

Placa madre que incorpora un Arduino Mega 2560 + módulo WIFI ESP8266. Incluye un switch de conexión que permite la utilización de los modulos de la placa de forma conjunta o independiente. La incorporación de 62 Entradas/salidas digitales nos permite realizar proyectos que incorporen mayor cantidad de sensores.



### Características 📋

* **Dos CPU:** ATmega2560 (8 bits) y ESP8266 (32 bits)
* **Memoria Flash:** 8mb ESP8266
* **Velocidad del reloj:** 16MHz (ATmega2560) y 80MHz / 160MHz (ESP8266)
* **Voltaje de funcionamiento:** 5V (ATmega2560) y 3.3V (ESP8266)
* **Pines  E/S digitales:** 54 (ATmega2560) + 8 (ESP8266)
* **Pines de entrada analógica:** 16 (ATMEGA328P) + 1 (ESP8266)
* **Conexión:** Micro USB
* **Entrada de alimentación:**  7-12V

```
Proyectos para realizar:

- Estación metereológica, con envío de datos a un servidor.  
- Carro controlado mediante aplicación movil.
```

### A Trabajar ! 🔧

_Para introducirnos en el uso de esta placa realizaremos tres proyectos, uno para cada modulo de forma independiente y uno para el conjunto de integrado de ambos. Pero antes de comenzar debemos configurar el entorno de desarrollo._



## Composición de la placa 🤖

_Como mencionamos anteriormente la placa se compone de dos modulos que pueden ser utilizados mediante la activaciòn de los jumper ubicados en la placa tal como se muestra en la imagen._



_La variación en el estado del jumper definirà el estado de la placa,  en la siguiente tabla se especifica la configuracion  para cada uso:_


<table role="table">
<thead>
<tr>
<th align="left"></th>
<th align="center">1</th>
<th align="center">2</th>
<th align="center">3</th>
<th align="center">4</th>
<th align="center">5</th>
<th align="center">6</th>
<th align="center">7</th>
<th align="center">8</th>
<th align="center">TXD0/TXD3</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left"><strong>ATmega2560&lt;-&gt;ESP8266</strong></td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">TXD0</td>
</tr>
<tr>
<td align="left"><strong>USB &lt;-&gt;ATmega2560</strong></td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">TXD0</td>
</tr>
<tr>
<td align="left">
<strong>USB&lt;-&gt;ESP8266</strong> <em>(upload sketch)</em>
</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">OFF</td>
<td align="center">TXD0</td>
</tr>
<tr>
<td align="left">
<strong>USB&lt;-&gt;ESP8266</strong> <em>(communication)</em>
</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">TXD0</td>
</tr>
<tr>
<td align="left"><strong>USB &lt;-&gt;ATmega2560&lt;-&gt;ESP8266</strong></td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">ON</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">TXD0</td>
</tr>
<tr>
<td align="left"><strong>Modulos independientes</strong></td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">OFF</td>
<td align="center">TXD3</td>
</tr>
</tbody>
</table>


## Configuración IDE Arduino para utilizar  ESP8266

Antes de programar debemos veríficar  que el entorno de desarrollo esté configurado de manera acorde al proyecto. En este caso trabajaremos con la placa NodeMCU y con librerías que debemos instalar, a continuación te explico como hacerlo.

### Instalamos la placa que utilizaremos

En este caso el ide de arduino no incluye la placa que utilizaremos así que primero debemos realizar la instalación de ella.

Primero nos dirigimos a las preferencias de arduino (archivo>preferencias) y se nos abrirá una ventana como la que vé a continuación. aquí debemos pegar el siguiente link en la sección "Additional Boards manager URLs" :


Le damos a "OK" y ahora podemos seleccionar la placa que utilizaremos en el proyecto


## Configuración IDE Arduino para utilizar Arduino Mega 2560

En este caso trabajaremos con la placa arduino mega 2560, debemos conectar la placa arduino mediante usb.

### Seleccionamos la placa que utilizaremos

En este caso utilizaremos la placa arduino mega

Ademas debemos seleccionar el puerto en el que trabajará la placa, para esto debemos conectar el arduino uno mediante usb y seleccionarlo de la siguiente manera:

## Agregar librería Memory Free

Descargar la librería Memory free

Copiamos la carpeta memoy free y debemos pegarla en la siguiente ruta Documents\Arduino\libraries.
Luego corroboramos de la siguiente manera si quedó instalado.

Ahora que terminamos la configuración del entorno arduino podemos desarrollar el proyecto.
