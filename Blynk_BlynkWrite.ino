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

void setup()
{ Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L,kelip);
  pinMode(D1,OUTPUT);
}

void loop()
{ Blynk.run();
  timer.run();
}
