#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID 	"TMPL6XTP0YTC1"
#define BLYNK_TEMPLATE_NAME "First IoT Program"
#define BLYNK_AUTH_TOKEN 	  "Xx9Xjre2Stv3E2sG2FwJL7H6ke5ZbaLk"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHTesp.h"
DHTesp dht;

char ssid[] = "UTHM@wifi";
char pass[] = "123456abc";
BlynkTimer timer;

int status=0;
void kelip()
{ digitalWrite(D1,status);
  status =! status;
}

BLYNK_WRITE(V0)
{ int pb = param.asInt();
  digitalWrite(D0,pb);
}

void getPB()
{ int pbD5 = digitalRead(D5);
  if(pbD5==1) Blynk.virtualWrite(V1,"ON");
  if(pbD5==0) Blynk.virtualWrite(V1,"OFF");
}

char dhtData[100];
void getDHT11()
{ float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  sprintf(dhtData,"Humid: %.1f%\tTemp:%.1f",humidity,temperature);
  Serial.println(dhtData);
  Blynk.virtualWrite(V2,humidity);
  Blynk.virtualWrite(V3,temperature);
}

void setup()
{ Serial.begin(9600);
  dht.setup(D7, DHTesp::DHT11);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L,kelip);
  timer.setInterval(10L,getPB);
  timer.setInterval(2000L,getDHT11);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D5,INPUT);
}

void loop()
{ Blynk.run();
  timer.run();
}
