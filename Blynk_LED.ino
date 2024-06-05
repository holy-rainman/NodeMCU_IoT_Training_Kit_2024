#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID 	"TMPL6XTP0YTC1"
#define BLYNK_TEMPLATE_NAME "First IoT Program"
#define BLYNK_AUTH_TOKEN 	  "Xx9Xjre2Stv3E2sG2FwJL7H6ke5ZbaLk"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "wifi@UTHM";
char pass[] = "123456abc";

BLYNK_WRITE(V0)
{ int pb = param.asInt();
  if(pb==1) digitalWrite(D0,HIGH);
  if(pb==0) digitalWrite(D0,LOW);
}

void setup()
{ pinMode(D0,OUTPUT); 
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{ Blynk.run();
}
