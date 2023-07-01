# Panel con WS2812

## Descripcion

Este panel esta construido con una configuracion de reloj  88 : 88
El mismo consta de 4 display, cada uno de 10x15 cm y 3 ws2812 por segmento, es decir 21 leds por display. 

## Hardware
Cada display esta construido con 3 tiras de 7 leds ws2812, las cuales estan conectadas en serie.
La conexion serie entre los segmentos es la siguiente: e-d-c-b-a-f-g 
Ademas en el recorrido de la informacion para el panel completo quedaria de la siguiente manera: 
```
e1-d1-c1-b1-a1-f1-g1 -- e2-d2-c2-b2-a2-f2-g2 -- p1 -- p2 -- e3-d3-c3-b3-a3-f3-g3 -- e4-d4-c4-b4-a4-f4-g4
```  
Donde p1 y p2 son los puntos del reloj y corresponden a 1 solo ws2812, mientras que los segmentos como ya se dijo estan compuestos por 3 ws2812. Haciendo un total de 86 ws2812 por panel.

## Software

Para el control de los ws2812 se utiliza la libreria FastLed.h, la cual se puede descargar desde el gestor de librerias de platformio.