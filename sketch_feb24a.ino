#include <IRremote.h>

const int ir = 2;
long deger;
int ileri=0x46;
int geri=0x15;
int sag=0x43;
int sol=0x44;
int dur=0x40;
int etrafindasag=0x41;
int etrafindasol=0x42;
int animasyon1=0x47;
int animasyon2=0x48;

#define pwm2 9
#define pwm 3
#define in1 4
#define in2 5
#define in3 6
#define in4 7



void setup() {

  Serial.begin(9600);
  IrReceiver.begin(ir);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(pwm2, OUTPUT);
  
}

void loop() {

  if(IrReceiver.decode());
  {
    deger=IrReceiver.decodedIRData.command;
    Serial.println(deger, HEX);
    IrReceiver.resume();
  }
  
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 255);

    

  if(deger==ileri)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 255);
  }
  if(deger==geri)
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 0);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 255);
  }
  if(deger==sag)
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 50);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 50);
  }
  if(deger==sol)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 50);
    digitalWrite(in4, 0);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 50);
  }
  if(deger==dur)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 0);
    digitalWrite(in4, 1);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 0);
  }
  if(deger==animasyon1)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 10);
    digitalWrite(in4, 0);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 10);

    delay(1500);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 10);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 10);

    delay(1500);
  }
  if(deger==animasyon2)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 10);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 10);

    delay(1500);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 255);

    delay(3000);

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 10);
    digitalWrite(in4, 0);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 10);

    delay(1500);

    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 0);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 255);

    delay(3000);
  }
  if(deger==etrafindasag)
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 1);
    digitalWrite(in3, 0);
    digitalWrite(pwm2, 255);
  }
  if(deger==etrafindasol)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(pwm, 255);
    digitalWrite(in4, 0);
    digitalWrite(in3, 1);
    digitalWrite(pwm2, 255);
  }

}
