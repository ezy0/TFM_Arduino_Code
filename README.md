# TFM Arduino Code

Este repositorio contiene los distintos códigos de Arduino desarrollados para el TFM - Evaluación de ciberseguridad de un sistema IoT basado en Arduino. 
Cada carpeta incluye el código del sketch y los archivos que necesita para su ejecución.

A continuación encontrarás:
- Una visión general del proyecto.
- Requisitos y materiales.
- Guía de uso.
- Un apartado para cada carpeta con espacio para que añadas tú la descripción específica, dependencias y pasos de ejecución.

## Índice
- [Descripción general](#descripción-general)
- [Objetivos del TFM](#objetivos-del-tfm)
- [Placas y materiales](#placas-y-materiales)
- [Dependencias y librerías comunes](#dependencias-y-librerías-comunes)
- [Configuración y compilación](#configuración-y-compilación)
- [Estructura del repositorio](#estructura-del-repositorio)
- [ap](#ap)
- [ddos_http](#ddos_http)
- [ftp](#ftp)
- [mqtt](#mqtt)
- [mqtt_mtls](#mqtt_mtls)
- [replay_attack](#replay_attack)
- [replay_attack_https](#replay_attack_https)
- [sta](#sta)


## Placas y materiales
- Placa(s) Arduino/ESP: especifica el modelo (ej. ESP32, ESP8266, Arduino Uno, etc.)
- Módulos de comunicación: WiFi, Ethernet, LoRa, etc. (si aplica)
- Sensores/actuadores: …
- Otros: cables, protoboard, alimentación, etc.

## Dependencias y librerías comunes
Indica las librerías que se usan de forma transversal y versiones recomendadas:
- Arduino Core: versión …
- Librerías de WiFi/Ethernet: …
- Librerías de MQTT: …
- Certificados/credenciales: dónde colocarlos y formato (si aplica)
- Nota: especifica cómo instalar librerías desde el Library Manager del Arduino IDE o vía `arduino-cli`.

## Configuración y compilación
1. Instala Arduino IDE (o `arduino-cli`).
2. Configura el soporte de la placa (Boards Manager).
3. Clona el repositorio o descarga el ZIP.
4. Abre la carpeta del sketch correspondiente en el IDE.
5. Ajusta parámetros en `config.h` o variables al inicio del sketch (SSID, claves, host, puertos, etc.).
6. Selecciona la placa y el puerto serie.
7. Compila y sube el programa.

## Estructura del repositorio

### ap
- Descripción: [Escribe aquí qué hace el código de la carpeta `ap` (por ejemplo, modo punto de acceso, autenticación, pruebas de conectividad, etc.)]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Resultados esperados: …

### ddos_http
- Descripción: [Explica el objetivo de `ddos_http` (por ejemplo, simulación/estudio de patrones de tráfico, pruebas de resiliencia, etc.)]
- Advertencias éticas/legales: [Asegúrate de remarcar que cualquier prueba debe hacerse en entornos controlados y con permiso]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Métricas/observaciones: …

### ftp
- Descripción: [Indica si se realiza conexión FTP, subida/descarga de archivos, autenticación, etc.]
- Dependencias específicas: …
- Configuración necesaria: [Servidor FTP, credenciales, puertos]
- Pasos de ejecución: …
- Resultados esperados: …

### mqtt
- Descripción: [Publicación/suscripción MQTT, tópicos, QoS, broker utilizado]
- Dependencias específicas: [Librería MQTT, por ejemplo PubSubClient]
- Configuración necesaria: [Host, puerto, topics, credenciales si aplica]
- Pasos de ejecución: …
- Resultados esperados: …

### mqtt_mtls
- Descripción: [Conexión MQTT con mTLS (mutual TLS), intercambio de certificados, autenticación de cliente]
- Dependencias específicas: [Soporte TLS, ubicación de certificados CA, cliente y clave privada]
- Configuración necesaria: [Ruta/almacenamiento de certs, host seguro, puerto TLS]
- Pasos de ejecución: …
- Verificación: [Cómo comprobar el establecimiento mTLS y logs]
- Resultados esperados: …

### replay_attack
- Descripción: [Escenario de ataque de repetición en protocolos sin cifrado/nonce]
- Consideraciones: [Entorno de pruebas controlado, finalidad académica]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Mitigaciones estudiadas: …

### replay_attack_https
- Descripción: [Estudio de ataques de repetición en HTTPS/TLS y por qué/como están mitigados]
- Dependencias específicas: …
- Configuración necesaria: …
- Pasos de ejecución: …
- Observaciones: [Uso de TLS, timestamps, nonces, sequence numbers]

### sta
- Descripción: [Modo estación (STA): conexión a AP, obtención de IP, pruebas de latencia/throughput]
- Dependencias específicas: …
- Configuración necesaria: [SSID, contraseña, parámetros de red]
- Pasos de ejecución: …
- Resultados esperados: …
