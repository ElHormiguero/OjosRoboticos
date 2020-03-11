OJOS ROBOTICOS
------------
El diseño está basado en el proyecto de "Simplified Eye Mechanism" de Nilheim Mechatronics.

Se ejecuta el movimiento de los parpados y las pupilas mediante servomotores. Se compone por dos servos para realizar el movmiento de las pupilas en los ejes X e Y, mientras que los 4 servos restantes se encargan de generar el movimiento del parpado superior e inferior.
Mediante un Arduino MEGA se controlan cada uno de los servomotores y la comunicación por radiofrecuencia del dispositivo electrónico NRF24L01. Para facilitar el control se ha usado un Arduino UNO acompañado de un joystick shield que se comunica con nuestro Arduino MEGA gracias al NRF24L01.
Todas las piezas están impresas en 3D y ensambladas con pequeños tornillos.
