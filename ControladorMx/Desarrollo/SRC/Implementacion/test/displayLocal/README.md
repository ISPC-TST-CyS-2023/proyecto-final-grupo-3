# Comunicacion I2C

## Descripcion

La conexion con el ESP32 sera a travez comunicacion I2C, para ello se debe tener en cuenta que el ESP32 tiene dos puertos I2C, los cuales son:

SDA: GPIO 21
SCL: GPIO 22

## Direccion de los dispositivos

Direcion del LCD 4200: 0x23
Direccion del teclado Matricial: 0x3F

## Librerias

Para la comunicacion I2C se utilizara la libreria Wire.h, la cual viene por defecto en el frame de Arduino. 
Tambien se utilizara la libreria LiquidCrystal_I2C.h, la cual se puede descargar desde el gestor de librerias de platformio.

## Hardware

La comunicacion entre el panel se realiza a travez de un cable de 4 hilos, los cuales son:

- VCC: 5V
- GND: GND
- SDA: GPIO 21
- SCL: GPIO 22
  
## Ejemplo de uso

- Desde el display se puede configurar las caracteristicas del controladorMx, para ello debe navegar en el menu del mismo con las teclas 0, * y # segun se indica: 

**0:** Para ingresar al menu de configuracion del controladorMx sostenga presionada la tecla 0 por 3 segundos, luego de esto se mostrara en el display el menu de configuracion. El 0 tambien sirve para confirmar seleccion de opciones en el menu de configuracion.

**#:** Para navegar en el menu de configuracion del controladorMx se debe presionar la tecla #, la cual permite avanzar en el menu.

***:** Para salir del menu de configuracion del controladorMx se debe presionar la tecla *, la cual permite retroceder en el menu.

