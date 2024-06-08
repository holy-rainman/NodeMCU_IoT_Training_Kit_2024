#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID 	"TMPL6XTP0YTC1"
#define BLYNK_TEMPLATE_NAME "First IoT Program"
#define BLYNK_AUTH_TOKEN 	  "Xx9Xjre2Stv3E2sG2FwJL7H6ke5ZbaLk"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

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
  Blynk.virtualWrite(V1,pbD5);
}

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L,kelip);
  timer.setInterval(10L,getPB);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D5,INPUT);
}

void loop()
{ Blynk.run();
  timer.run();
}
