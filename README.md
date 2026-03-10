# Arduino Tabanlı IR Kontrollü Robot Araç

Bu proje, Arduino kullanılarak geliştirilen kızılötesi (IR) kumanda kontrollü bir robot araç sistemidir. Araç; ileri, geri, sağ ve sol hareket edebilmekte, dar alanlarda manevra yapabilmektedir, ayrıca dans modlarıda vardır. Proje, motor sürücü ve IR alıcı modül kullanılarak uzaktan kontrol edilecek şekilde tasarlanmıştır.

## Proje Özeti

Bu çalışmada amaç, bir robot aracın IR kumanda ile kablosuz şekilde kontrol edilmesini sağlamaktır. Sistem Arduino tabanlıdır ve motor sürücü üzerinden DC motor kontrol edilmektedir. Araç temel hareket komutlarının yanında kendi ekseni etrafında dönüş yapabilecek şekilde geliştirilmiştir.

## Özellikler

- IR kumanda ile kablosuz kontrol
- İleri hareket
- Geri hareket
- Sağa dönüş
- Sola dönüş
- Kendi ekseni etrafında manevra
- Dans Modları
- Arduino tabanlı kontrol sistemi
- Motor sürücü ile kararlı motor kontrolü

## Kullanılan Malzemeler

- Arduino Uno
- IR alıcı modül
- IR kumanda
- L298N motor sürücü
- DC motor
- Robot araç şasisi
- Tekerlekler
- Batarya
- Jumper kablolar

## Devre Bağlantıları

> Not: Kendi devrenize göre pinleri güncelleyebilirsiniz.

| Arduino Pin | Bağlanan Parça |
|---|---|
| 5V | IR Alıcı VCC , Motor Sürücü 5V|
| GND | IR Alıcı GND, Motor Sürücü GND, Batarya - |
| D2 | IR Alıcı Sinyal Bacağı |
| D4 | Motor Sürücü IN1 |
| D5 | Motor Sürücü IN2 |
| D6 | Motor Sürücü IN3 |
| D7 | Motor Sürücü IN4 |
| Vin | Motor sürücü 12V, Batarya + |
| D3 | Motor Sürücü ENB1 |
| D9 | Motor Sürücü ENB2 |

![Devre Şeması](Aracin_Fotografi.jpg)

## Çalışma Mantığı

IR kumandadan gönderilen sinyaller, IR alıcı modül tarafından okunur ve Arduino’ya aktarılır. Arduino, tanımlanmış komutlara göre motor sürücüyü kontrol eder. Motor sürücü de sağ ve sol motorları uygun şekilde çalıştırarak aracın hareket etmesini sağlar.

## Kodlar

```cpp
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
```
