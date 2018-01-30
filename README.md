Shield_Wisol_M2COMM
===================

-	[Introducción](#introducción)

-	[Ejemplo](#ejemplo)

	-	[Sensor de Temperatura](#sensor-de-temperatura)

Introducción
------------

En este proyecto se explicarán las características de los Shields para Arduino con conectividad sigfox (Wisol o M2COMM), así como también se mostrarán programas de ejemplo sencillos, para mostrar como interactuar con los módulos de conectividad. 

A continuación se muestran los dos tipos de shields con los módulos de conectividad Wisol (Izquierda) y M2COMM (Derecha). Los dos shields tienen el mismo funcionamiento, la única diferencia es el modulo que utilizan para la comunicación. El módulo Wisol acepta la comunicación bidireccional, es decir permite uplinks y downlinks, mientras que el módulo M2COMM únicamente uplinks. Ademas, algunas instrucciones difieren entre los módulos, sin embargo la instrucción para enviar mensajes por sigfox es la misma para ambos casos (AT$SF=“PAYLOAD”).

![shield_mod](https://github.com/Iotnet/Shield_Wisol_M2COMM/blob/master/%20imagenes/shield_mod.png?raw=true)

![shield_mod](https://github.com/NXTIoT/Shield_Wisol_M2COMM/blob/master/imagenes/pinout_shield(1).jpg)

Ambos módulos se comunican con el microcontrolador por el puerto serial (Pines Tx y Rx de la placa Arduino) por lo que el shield DEBE RETIRARSE CADA VEZ QUE SE DESEE CARGAR UN PROGRAMA A LA PLACA DE ARDUINO. Asi mismo, para activar los módulos y poder mandar mensajes por medio de la red Sigfox, los pines del 2 al 5 deben ponerse en alto para abilitar los modulos antes de enviar un mensaje.

Ejemplo
-------

El siguiente ejemplo tiene como finalidad el conocer como mandar un dato por medio de Sigfox.

### Sensor de Temperatura

En este ejemplo se utilizará el sensor LM35 para mandar la información de la temperatura por medio de Sigfox. Descargar el código para el modulo [Wisol](https://github.com/Iotnet/Shield_Wisol_M2COMM/blob/master/ejemplos/temp_shield_wisol/temp_shield_wisol.ino) o [M2COMM](https://github.com/Iotnet/Shield_Wisol_M2COMM/blob/master/ejemplos/temp_shield_m2comm/temp_shield_m2comm.ino) según sea el caso. 

Después de que se obtiene el valor de la temperatura, se transforma el dato en flotante a Hexadecimal de 4 bytes en formato little Endian, es decir, el byte menos significante se encuentra a la izquierda.



