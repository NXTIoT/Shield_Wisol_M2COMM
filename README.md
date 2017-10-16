Shield_Wisol_M2COMM
===================

Proyecto donde se describe el uso del shield para Arduino/Raspberry con conectividad Sigfox (Wisol/M2COMM)

-	[Introducción](#introducción)

Introducción
------------

En este proyecto se explicarán las caracteristicas de los Shields para Arduino con conectividad sigfox (Wisol o M2COMM), asi tambien se mostraran programas de ejemplo sencillos, para mostrar como interactuar con los módulos de conectividad. 

Ambos módulos se comunican con el microcontrolador por el puerto serial (Pines Tx y Rx de la placa Arduino) por lo que el shield DEBE RETIRARSE CADA VEZ QUE SE DESEE CARGAR UN PROGRAMA A LA PLACA DE ARDUINO. Asi mismo, para activar los modulos y poder mandar mensajes por medio de la red Sigfox, los pines del 2 al 5 deben ponerse en alto antes de enviar un mensaje.

