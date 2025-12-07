# TFM Arduino Code

Este repositorio contiene los distintos códigos de Arduino desarrollados para el TFM - Evaluación de ciberseguridad de un sistema IoT basado en Arduino. 
Cada carpeta incluye el código del sketch y los archivos que necesita para su ejecución.

## Índice
- [Configuración y compilación](#configuración-y-compilación)
- [sta](#sta)
- [ddos_http](#ddos_http)
- [ftp](#ftp)
- [mqtt](#mqtt)
- [mqtt_mtls](#mqtt_mtls)
- [replay_attack](#replay_attack)
- [replay_attack_https](#replay_attack_https)

## Configuración y compilación
1. Instala Arduino IDE (o `arduino-cli`).
2. Configura la placa de Arduino dentro del IDE, en este caso se ha utilizado un Arduino Nano ESP32
4. Abre la carpeta del sketch correspondiente en el IDE.
5. Decarga las dependencias y librerías que encesite el código.
6. Ajusta los parámetros que hagan falta, como las credenciales del WiFi en `config.h`, variables, etc.
8. Compila y sube el código para ejecutarlo.

## sta
- Descripción: Código del escenario de ejemplo en el que Arduino funciona en modo Station. En este código, Arduino se conectará a un punto de acceso WiFi y realizará pings al host que se le indique.
- Dependencias específicas: `WiFi.h` y `ESPping.h`
- Configuración necesaria: Modificar las credenciales de acceso del punto WiFi en el archivo `config.h`

## ddos_http
- Descripción: Servidor HTTP que levanta Arduino, en el que permite al usuario encender y apagar un LED conectado a la placa mediante un frontal web. Además, el código hace un recuento de conexiones activas para limitarlas y cerrar conexiones que intenten denegar los servicios atacando a la capa de aplicación.
- Dependencias específicas: `WiFi.h`
- Configuración necesaria: Modificar las credenciales de acceso en `config.h` y el valor del pin al que se conecte el LED.

## ftp
- Descripción: Con este código, Arduino se conecta al servidor FTP y se descarga el archivo indicado. A lo largo de la ejecución se muestra por el serial el estado de la conexión y el contenido del archivo.
- Dependencias específicas: `WiFi.h` y `FTPduino.h`
- Configuración necesaria: Modificar las credenciales de acceso en `config.h` y el valor de todas las variables del FTP como usuario, contraseña, puerto, archivo, etc.

## mqtt
- Descripción: En este código Arduino manda cada 3 segundos la información que recibe de un fotoresistor a un servidor MQTT.
- Dependencias específicas: `WiFi.h` y `PubSubClient.h`
- Configuración necesaria: Modificar las credenciales de acceso en `config.h`, el valor del pin del fotoresistor y las variables MQTT.

## mqtt_mtls
- Descripción: En este código Arduino manda cada 3 segundos la información que recibe de un fotoresistor a un servidor MQTT en el que se ha autenticado mediante MTLS.
- Dependencias específicas: `WiFi.h`, `PubSubClient.h` y `WiFiClientSecure.h`
- Configuración necesaria: Modificar las credenciales de acceso en `config.h`, el valor del pin del fotoresistor, las variables MQTT y los certificados de la CA (`ca_cert.h`) y cliente (`cert.h`), junto con su clave privada (`private_key.h`).

## replay_attack
- Descripción: [Escenario de ataque de repetición en protocolos sin cifrado/nonce]
- Consideraciones: [Entorno de pruebas controlado, finalidad académica]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Mitigaciones estudiadas: …

## replay_attack_https
- Descripción: [Estudio de ataques de repetición en HTTPS/TLS y por qué/como están mitigados]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Observaciones: [Uso de TLS, timestamps, nonces, sequence numbers]
