#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Nextion.h>

// pulsos mínimos de cada servo
#define SERVOMIN 102
#define SERVOMAX 512

// inicializacion servos
Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();
int ang_giro=90;
int ang_1 = 90;
int ang_2 = 90;
int giro_mano = 90;
int ang_apert = 90;

// inicializacion pantalla

NexButton b0=NexButton(0, 1, "b0");

NexTouch *nex_listen_list[]=
{
  &b0,
  NULL
};

void setPosition(int angulo, int servonum){
  double pulselenght;
  pulselenght = map(angulo, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servonum, 0, pulselenght);

}

//Acciones a los botones de la pantalla
void b0PopCallback(void *ptr){
// boton1

}

void update_nextion(){
  // actualizar los datos de la pantalla
}

void setup() {
  //inicializacion servos
  Serial.begin(9600);
  Serial.println("Inicio del programa");
  pwm.begin();
  pwm.setPWMFreq(50);

// inicializacion pantalla
  nexInit();
  b0.attachPop(b0PopCallback, &b0);


  delay(10);

}

void loop() {
  // bucle lectura pantalla
  nexLoop(nex_listen_list);
}
