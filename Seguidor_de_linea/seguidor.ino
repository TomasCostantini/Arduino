/*//sensor
int SensorIzquierdo = 6;//8;
int SensorMedioIzquierda =5 ;//2;
int SensorMedio = 3;//7;
int SensorMedioDerecha = 4;//4;
int SensorDerecha = 2;//13;

//L298N
int enAPin = 11;//3;
int in1Pin = 12;//10;
int in2Pin = 13;//9;
int in3Pin = 9;//6;
int in4Pin = 8;//11;
int enBPin = 10;//5;
*/
#define SensorIzquierda 6
#define SensorMedioIzquierda 5
#define SensorCentro 3
#define SensorMedioDerecha 4
#define SensorDerecha 2

#define numsensores 5 
#define numSalidasMotores 6

//Control motor 1
int ENA = 11;
int IN1 = 12;  
int IN2 = 13;  

//Control motor 2
int ENB = 10;
int IN3 = 9;   
int IN4 = 8;   

const int sensores[]={SensorIzquierda, SensorMedioIzquierda, SensorCentro, SensorMedioDerecha, SensorDerecha};
const int salidas_motores[]={ENA, IN1, IN2, ENB, IN3, IN4};

  boolean ValorSensorIzquierdo;
  boolean ValorSensorMedioIzquierda; 
  boolean ValorSensorCentro;
  boolean ValorSensorMedioDerecha; 
  boolean ValorSensorDerecho; 

void setup() {
 /* pinMode(SensorIzquierdo, INPUT);
  pinMode(SensorMedioIzquierda, INPUT);
  pinMode(SensorMedio, INPUT);
  pinMode(SensorMedioDerecha, INPUT);
  pinMode(SensorDerecha, INPUT);
  //L298N salidas*/

  Serial.begin(9600);
  
   for(int i = 0; i <= numsensores; i++ ){
    pinMode(sensores[i], INPUT);
    delay(10);}
    
   for(int i = 0; i <= numSalidasMotores; i++ ){
    pinMode(salidas_motores[i], OUTPUT);
    delay(10);}
  
   delay(1000);

 
 /* pinMode(enAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enBPin, OUTPUT);
*/
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
   ValorSensorIzquierdo = digitalRead(SensorIzquierda);
   ValorSensorMedioIzquierda = digitalRead(SensorMedioIzquierda);
   ValorSensorMedio = digitalRead(SensorCentro);
   ValorSensorMedioDerecha = digitalRead(SensorMedioDerecha);
   ValorSensorDerecho = digitalRead(SensorDerecha);


  if (ValorSensorMedio == HIGH and ValorSensorIzquierdo == LOW and ValorSensorMedioIzquierda == LOW and ValorSensorDerecho == LOW and ValorSensorMedioDerecha == LOW) {
  avanzar();
  }
  if (ValorSensorMedio == LOW and ValorSensorIzquierdo == LOW and ValorSensorMedioIzquierda == HIGH and ValorSensorDerecho == LOW and ValorSensorMedioDerecha == LOW) {
  doizq();
  }
  if (ValorSensorMedio == LOW and ValorSensorIzquierdo == LOW and ValorSensorMedioIzquierda == LOW and ValorSensorDerecho == LOW and ValorSensorMedioDerecha == HIGH) {
  doder();
  }
   if (ValorSensorMedio == LOW and ValorSensorIzquierdo == HIGH and ValorSensorMedioIzquierda == LOW and ValorSensorDerecho == LOW and ValorSensorMedioDerecha == LOW) {
  correcizq();
  }
    if (ValorSensorMedio == LOW and ValorSensorIzquierdo == LOW and ValorSensorMedioIzquierda == LOW and ValorSensorDerecho == HIGH and ValorSensorMedioDerecha == LOW) {
  correcder();
  }
  
  /*if (ValorSensorMedio == LOW and ValorSensorIzquierdo == LOW and ValorSensorMedioIzquierda == LOW and ValorSensorDerecho == LOW and ValorSensorMedioDerecha == LOW) {

    analogWrite(enAPin, 70);
    analogWrite(enBPin, 0);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, LOW);
  }*/
}