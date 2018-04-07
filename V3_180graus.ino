#include <Servo.h>

Servo myservo;

int maximo = 0;      //nao mexer nesse
int velocidade = 20; //velocidade da mandibula
int maxAperture = 100; //angulo maximo que a boca abre
int waitOpen = 100;   //tempo em que a boca fica aberta (em milissegundos)
int waitMinClosed = 2000; //tempo minimo em que a boca fica fechada (em milissegundos)
int waitMaxClosed = 5000; //tempo maximo em que a boca fica fechada (em milissegundos)

void setup() {
  myservo.attach(3);
  myservo.write(0);
}

void loop() {
  randomSeed(analogRead(0));
  maximo = random(0, maxAperture);

  for(int i = 0; i <= maximo; i++){
    myservo.write(i);
    delay(velocidade);                                   //laço de abertura da boca
  }
  delay(waitOpen);
  for(int i = maximo; i >= 0; i--){
    myservo.write(i);
    delay(velocidade);                                   //laço de fechamento da boca
  }
  delay(random(waitMinClosed, waitMaxClosed));
}
