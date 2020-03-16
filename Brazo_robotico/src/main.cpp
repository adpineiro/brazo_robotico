#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Nextion.h>

// pulsos mínimos de cada servo
#define SERVOMIN 102
#define SERVOMAX 512

//declaracion angulos
int angulo0=90; //rotacion base
int angulo1=90; //subir-bajar
int angulo2=90; //subir-bajar codo
int angulo3=90; //rotacion mano
int angulo4=90; //abrir-cerrar mano

//variables para el control
int servo=0; //numero de servo a controlar

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
  //delay(500); //para dar tiempo a los servos

}


//Respuesta al evento boton pulsado
void b0PushCallback(void *ptr){
  servo = 0;
  angulo0=angulo0+20;
  setPosition(angulo0, servo);
  digitalWrite(13, HIGH);
}
void b1PushCallback(void *ptr){
  servo = 0;
  angulo0= angulo0-20;
  setPosition(angulo0, servo);
  digitalWrite(13, LOW);

}
void b2PushCallback(void *ptr){
  servo = 1;
  angulo1 = angulo1+5;
  setPosition(angulo1, servo);

}

void b3PushCallback(void *ptr){
  servo = 1;
  angulo1 = angulo1-5;
  setPosition(angulo1, servo);

}
void b4PushCallback(void *ptr){
  servo = 2;
  angulo2=angulo2+5;
  setPosition(angulo2, servo);

}
void b5PushCallback(void *ptr){
  servo = 2;
  angulo2=angulo2-5;
  setPosition(angulo2, servo);

}
void b6PushCallback(void *ptr){
  servo = 3;
  angulo3 = angulo3+5;
  setPosition(angulo3, servo);

}
void b7PushCallback(void *ptr){
  servo = 3;
  angulo3=angulo3-5;
  setPosition(angulo3, servo);

}
void b8PushCallback(void *ptr){
  servo = 4;
  angulo4 = angulo4+5;
  setPosition(angulo4, servo);

}
void b9PushCallback(void *ptr){
  servo = 4;
  angulo4=angulo4-5;
  setPosition(angulo4, servo);

}

void setup() {

  pinMode(13, OUTPUT);
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
  setPosition(angulo0, 0);
  setPosition(angulo1, 1);
  setPosition(angulo2, 2);
  setPosition(angulo3, 3);
  setPosition(angulo4, 4);


}

void loop() {
  // bucle lectura pantalla
  nexLoop(nex_listen_list);
}
