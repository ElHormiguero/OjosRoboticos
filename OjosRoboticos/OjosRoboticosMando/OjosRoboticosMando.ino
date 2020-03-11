/* Robot que controla las pupilas y los parpados de dos ojos roboticos mediante servos con un control a distancia por radiofrecuencia.
 * Autor: Victor Carrillo Garrido 
 * Basado en proyecto de Nilheim Mechatronics: http://www.nilheim.co.uk/latest-projects-and-blog/simplified-3d-printed-animatronic-dual-eye-mechanism 
 * https://creativecommons.org/licenses/by/4.0/
  */

//CONTROL MANDO A DISTANCIA
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>


//PINES DE COMUNICACION NRF24L01
#define CE_PIN   9
#define CSN_PIN 10

//DEFINIMOS LOS BOTONES Y POTENCIOMETROS DEL JOYSTICK
#define x_axis A0 // x axis
#define y_axis A1 //y axis
#define button1 8 // joystick button
#define button2 2 // A button
#define button3 3 // B button
#define button4 4 // C button
#define button5 5 // D button
#define button6 6 // E button
#define button7 7 // F button



//CANAL POR EL CUAL SE COMUNICA CON EL ARDUINO MEGA
const byte address[6] = "00001";
RF24 radio(CE_PIN, CSN_PIN); 
int data[9]; 


void setup() 
{
  Serial.begin(9600);

  //CONTROL MANDO A DISTANCIA
  radio.begin();
  radio.openWritingPipe(address); 
  radio.stopListening();

  //CONTROL BOTONES
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);

}

void loop()   
{

//LECTURA DE VALORES
  data[0] = analogRead(x_axis);
  data[1] = analogRead(y_axis);
  data[2] = digitalRead(button1);
  data[3] = digitalRead(button2);
  data[4] = digitalRead(button3);
  data[5] = digitalRead(button4);
  data[6] = digitalRead(button5);
  data[7] = digitalRead(button6);
  data[8] = digitalRead(button7);
  radio.write( data, sizeof(data) ); 
 
//MOSTRAMOS LOS VALORES POR EL MONITOR SERIAL
Serial.print(analogRead(x_axis));
  Serial.print(" ");
  Serial.print(analogRead(y_axis));
  Serial.println(" ");
  Serial.print(digitalRead(button1));
  Serial.print(" ");
    Serial.print(digitalRead(button2));
  Serial.print(" ");
    Serial.print(digitalRead(button3));
  Serial.print(" ");
    Serial.print(digitalRead(button4));
  Serial.print(" ");
    Serial.print(digitalRead(button5));
  Serial.print(" ");
    Serial.print(digitalRead(button6));
  Serial.print(" ");
    Serial.print(digitalRead(button7));
  Serial.println(" ");

delay(100);

}
