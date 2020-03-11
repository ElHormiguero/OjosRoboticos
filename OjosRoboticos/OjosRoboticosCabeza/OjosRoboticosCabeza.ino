/* Robot que controla las pupilas y los parpados de dos ojos roboticos mediante servos con un control a distancia por radiofrecuencia.
 * Autor: Victor Carrillo Garrido 
 * Basado en proyecto de Nilheim Mechatronics: http://www.nilheim.co.uk/latest-projects-and-blog/simplified-3d-printed-animatronic-dual-eye-mechanism 
 * https://creativecommons.org/licenses/by/4.0/
  */

//CONTROL MANDO A DISTANCIA
#include <nRF24L01.h> //añadimos la librería que nos permite la comunicacion por radiofrecuencia 
#include <RF24.h>

//PINES DE COMUNICACION NRF24L01
#define CE_PIN  11 
#define CSN_PIN 13

//CANAL POR EL CUAL SE COMUNICA CON EL MANDO A DISTANCIA
const byte address[6] = "00001";
RF24 radio(CE_PIN, CSN_PIN); 
int data[9];

//CONTROL SERVOS
#include <Servo.h> 

Servo Servo7;  //creamos un objeto servo
Servo Servo6;  //creamos un objeto servo
Servo Servo5;  //creamos un objeto servo
Servo Servo4;  //creamos un objeto servo
Servo Servo3;  //creamos un objeto servo
Servo Servo2;  //creamos un objeto servo

//POSICION DE LOS SERVOS
#define Servo7MAX 50
#define Servo7MIN 120
#define Servo7INICIO 90
#define Servo6MAX 160
#define Servo6MIN 120
#define Servo5MAX 80
#define Servo5MIN 160
#define Servo4INICIO 30
#define Servo4MAX 00
#define Servo4MIN 70
#define Servo3MAX 60
#define Servo3MIN 90
#define Servo2MAX 60
#define Servo2MIN 90

#define DelayParpadeo 100

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


//CONTROL MANDO A DISTANCIA
radio.begin();
radio.openReadingPipe(0, address);
radio.startListening();

//CONTROL SERVOS
Servo7.attach(7);  // asignamos el pin 7 al servo.
Servo6.attach(6);  // asignamos el pin 6 al servo.
Servo5.attach(5);  // asignamos el pin 5 al servo.
Servo4.attach(4);  // asignamos el pin 4 al servo.
Servo3.attach(3);  // asignamos el pin 3 al servo.
Servo2.attach(2);  // asignamos el pin 2 al servo.

//COLOCAMOS SERVOS EN SU POSICION INICIAL
Servo7.write(Servo7INICIO);  // enviamos el valor escalado al servo. 
Servo6.write(Servo6MIN);  // enviamos el valor escalado al servo.
Servo5.write(Servo5MIN);  // enviamos el valor escalado al servo.
Servo4.write(Servo4INICIO);  // enviamos el valor escalado al servo.
Servo3.write(Servo3MIN);  // enviamos el valor escalado al servo.
Servo2.write(Servo2MIN);  // enviamos el valor escalado al servo.
delay(200); 

}

void loop() {
  // put your main code here, to run repeatedly:


  if ( radio.available() ) 
  {
    radio.read( data, sizeof(data) ); //leemos los datos enviados por el mando a distancia
    
  
Serial.print("data[0]=");
Serial.println(data[0]);
Serial.print("data[1]=");
Serial.println(data[1]);
Serial.print("data[2]=");
Serial.println(data[2]);
Serial.print("data[3]=");
Serial.println(data[3]);
Serial.print("data[4]=");
Serial.println(data[4]);
Serial.print("data[5]=");
Serial.println(data[5]);
Serial.print("data[6]=");
Serial.println(data[6]);
Serial.print("data[7]=");
Serial.println(data[7]);
Serial.print("data[8]=");
Serial.println(data[8]);

hareket(data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8]);

  } else
  Serial.println("fallo comunicacion");
}

void hareket(int x_axis, int y_axis, int button1, int button2, int button3, int button4, int button5, int button6, int button7) {


//movemos las pupilas en el eje X
int Servo7pos = map( x_axis , 0, 679, Servo7MAX, Servo7MIN);
Servo7.write(Servo7pos);
Serial.println(Servo7pos);

//movemos las pupilas en el eje Y acompañado por los parpados
int Servo4pos = map( y_axis , 0, 679, Servo4MAX, Servo4MIN);
Servo4.write(Servo4pos);
Serial.println(Servo4pos);
int Servo5pos = map( Servo4pos ,Servo4MAX, Servo4MIN, Servo5MAX, Servo5MIN);
Servo5.write(Servo5pos);
int Servo6pos = map( Servo4pos ,Servo4MAX, Servo4MIN, Servo6MIN, Servo6MAX);
Servo6.write(Servo6pos);
int Servo2pos = map( Servo4pos ,Servo4MAX, Servo4MIN, Servo2MAX, Servo2MIN);
Servo2.write(Servo2pos);
int Servo3pos = map( Servo4pos ,Servo4MAX, Servo4MIN, Servo3MIN, Servo3MAX);
Servo3.write(Servo3pos);

//Parpadeo ojo izquierdo
if ( button5 == LOW ){
  Servo7.write(Servo7INICIO);  // enviamos el valor escalado al servo. 
Servo4.write(Servo4INICIO);  // enviamos el valor escalado al servo.

for (int i = 0; i<1; i++){
Servo6.write(Servo6MAX);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo5.write(Servo5MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo6.write(Servo6MIN);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo5.write(Servo5MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
}
}

//Parpadeo ojo derecho
if ( button3 == LOW ){
    Servo7.write(Servo7INICIO);  // enviamos el valor escalado al servo. 
Servo4.write(Servo4INICIO);  // enviamos el valor escalado al servo.

for (int i = 0; i<1; i++){
Servo3.write(Servo3MAX);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo2.write(Servo2MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo3.write(Servo3MIN);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo2.write(Servo2MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
}
}

//Parpadeo ambos ojos
if ( button2 == LOW ){
    Servo7.write(Servo7INICIO);  // enviamos el valor escalado al servo. 
Servo4.write(Servo4INICIO);  // enviamos el valor escalado al servo.

for (int i = 0; i<1; i++){
Servo6.write(Servo6MAX);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo5.write(Servo5MAX);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo3.write(Servo3MAX);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo2.write(Servo2MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo6.write(Servo6MIN);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo5.write(Servo5MIN);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo3.write(Servo3MIN);  // enviamos el valor escalado al servo.
//delay(DelayParpadeo);
Servo2.write(Servo2MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
}
}

delay(100);
}


/* PROGRAMA DE EJEMPLO
 *  Para comprobar el funcionamiento de los servos sin control remoto
 *  
//Mirar a izquierda y derecha
for (int pos = Servo7MAX; pos <= Servo7MIN; pos += 2){
Servo7.write(pos);  // enviamos el valor escalado al servo.
delay(50);   
}

for (int pos = Servo7MIN; pos >= Servo7MAX; pos -= 2){
Servo7.write(pos);  // enviamos el valor escalado al servo.
delay(50);   
}

Servo7.write(Servo7INICIO);  // enviamos el valor escalado al servo.
delay(100);   

//Mirar a arriba y abajo
for (int pos = Servo4MAX; pos <= Servo4MIN; pos += 2){
Servo4.write(pos);  // enviamos el valor escalado al servo.
delay(50);   
}

for (int pos = Servo4MIN; pos >= Servo4MAX; pos -= 2){
Servo4.write(pos);  // enviamos el valor escalado al servo.
delay(50);   
}

Servo4.write(Servo4INICIO);  // enviamos el valor escalado al servo.
delay(100);  

//Parpadeo ojo izquierdo
for (int i = 0; i<3; i++){
Servo6.write(Servo6MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo5.write(Servo6MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo6.write(Servo5MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo5.write(Servo5MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
}

//Parpadeo ojo derecho
for (int i = 0; i<3; i++){
Servo3.write(Servo3MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo2.write(Servo2MAX);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo3.write(Servo3MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
Servo2.write(Servo2MIN);  // enviamos el valor escalado al servo.
delay(DelayParpadeo);
}

}*/
