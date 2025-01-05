#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "REPLACE_WITH_YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "REPLACE_WITH_YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "REPLACE_WITH_YOUR_AUTH_TOKEN"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

#include "DHTesp.h"
DHTesp dht;

String phoneNumber = "REPLACE_WITH_YOUR_PHONE_NUMBER"; //+60177002044
String apiKey = "REPLACE_WITH_YOUR_WHATSAPP_API_KEY";

char ssid[] = "REPLACE_WITH _YOUR_SSID";
char pass[] = "REPLACE_WITH_YOUR_PASSWORD";
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
  if(pbD5==1) { Blynk.virtualWrite(V1,"ON"); sendMessage("PB pushed!"); }
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

void sendMessage(String message)
{ // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200)
  { Serial.print("Message sent successfully");
  }
  else
  { Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
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
