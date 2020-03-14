#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Nextion.h>

// pulsos mínimos de cada servo
#define SERVOMIN 102
#define SERVOMAX 512

// inicializacion servos
Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();

// inicializacion pantalla

//decalracion de variables de la pantalla
//NexButton (pagina, componente, "nombre")
NexButton b0 =NexButton(0, 1, "b0");
NexButton b1 =NexButton(0, 2, "b1");
NexButton b2 =NexButton(0, 3, "b2");
NexButton b3 =NexButton(0, 4, "b3");
NexButton b4 =NexButton(0, 5, "b4");
NexButton b5 =NexButton(0, 6, "b5");
NexButton b6 =NexButton(0, 7, "b6");
NexButton b7 =NexButton(0, 8, "b7");
NexButton b8 =NexButton(0, 9, "b8");
NexButton b9 =NexButton(0, 10, "b9");

char buffer[100]={0}; //buffer para leer los mensajes de la pantalla

NexTouch *nex_listen_list[]= //Registra un objeto boton en la lista de eventos
{
&b0,
&b1,
&b2,
&b3,
&b4,
&b5,
&b6,
&b7,
&b8,
&b9,
NULL
};

void setPosition(int angulo, int servonum){
  double pulselenght;
  pulselenght = map(angulo, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servonum, 0, pulselenght);

}

void setup() {
  //inicializacion pantalla
  nexInit();
  b0.attachPush(b0PushCallback, &b0);
  b1.attachPush(b1PushCallback, &b1);
  b2.attachPush(b2PushCallback, &b2);
  b3.attachPush(b3PushCallback, &b3);
  b4.attachPush(b4PushCallback, &b4);
  b5.attachPush(b5PushCallback, &b5);
  b6.attachPush(b6PushCallback, &b6);
  b7.attachPush(b7PushCallback, &b7);
  b8.attachPush(b8PushCallback, &b8);
  b9.attachPush(b9PushCallback, &b9);

  //inicializacion servos
  pwm.begin();
  pwm.setPWMFreq(50);
  //Inicializacion OK
  Serial.begin(9600);
  Serial.println("Inicio del programa");
}

void loop() {
  // bucle lectura pantalla
  nexLoop(nex_listen_list);
}

//Respuesta al evento boton pulsado
void b0PushCallback(void *ptr){

}
