Fuente: https://www.taloselectronics.com/blogs/tutoriales/como-usar-dfplayer-modulo-reproductor-mp3-con-arduino
Ejemplos: https://www.youtube.com/watch?v=Hoot1hKMlR0

¿Como usar DFPlayer Modulo reproductor mp3 con arduino? - Tutorial
El modulo DFPlayer Mini es un reproductor de audio económico que podemos conectar fácilmente con a un microcontrolador y tarjetas Arduino para reproducir audio en formato MP3.

El modulo DFPlayer es capaz de reproducir no solo formatos MP3 además puede reproducir WMA y WAV. Incluye un lector micro SD compatible con FAT16 y FAT32, con una capacidad máxima de 32GB. 

Soporta hasta 100 carpetas y puede acceder hasta 255 canciones.

El DFPlayer Mini proporciona velocidades de muestreo de 8, 11.025 12 16 22.05 24 32 44.1 y 48 kHz, y salida con DAC de 24 bits.

Tiene 30 niveles de volumen ajustable, ecualizador de 6 niveles, y una relación señal ruido (SNR) de 85dB

La comunicación entre arduino y el modulo DFPlayer es mediante el puerto Serial. Dispone de funciones para reproducir, detener, pausar, avanzar, retroceder entre canciones.

La salida se realiza directamente al altavoz, a través de los pines correspondientes además se puede conectar a un amplificador para aumentar la potencia de salida.

Pinout


Especificaciones
Tensión de funcionamiento: 3.3 ~ 5 V
Capacidad de almacenamiento y reproducción de audio
Ranura para almacenamiento de tarjetas Micro SD
Compatible con Tarjeta de hasta 32GB (no incluida)
Funciona incluso sin la presencia del microcontrolador
Compatible con los formatos MP3, WAV, WMA
Trabaja con formato FAT16 y FAT32
Soporta hasta 100 carpetas en la tarjeta SD
Máximo 255 canciones en carpeta
Funcionalidad extremadamente amplia
30 niveles de volumen ajustables
6 niveles de ecualización ajustables
Desarrollo
Material
Arduino nano
protoboard 400 puntos
cables dupont 10cm macho a macho
bocina 1w 8ohms
Libreria DFPlayer
Para agilizar el desarrollo usaremos la libreria DFPlayer de DFRobot la cual estara disponible en el siguiente enlace.

https://github.com/DFRobot/DFRobotDFPlayerMini

O directamente dando click en aqui Descargar libreria

Para instalar la libreria solo debemos descomprimir el archivo y copiar todo el contenido en:

documentos/arduino/libreries/

Conexiones
 

Diagrama de conexión 



Preparando memoria micro sd
Para este tutorial usaremos una herramienta online para convertir el texto en audio.

Nota:

Todos los archivos se encuentran el repositorio de github.

https://www.texttomp3.online/index-es.html

Copiaremos los archivos en la raiz de la memoria micro sd

