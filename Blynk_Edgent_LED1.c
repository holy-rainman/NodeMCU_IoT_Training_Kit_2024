#define BLYNK_TEMPLATE_ID "Insert Template ID"
#define BLYNK_DEVICE_NAME "Insert Device Name"
#define BLYNK_FIRMWARE_VERSION  "0.1.0"
#define BLYNK_PRINT Serial

#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"
BlynkTimer timer;

int status=0;
void kelip()
{ digitalWrite(D0,status);
  status=!status;
}

void setup()
{ pinMode(D0,OUTPUT);
  Serial.begin(9600);
  BlynkEdgent.begin();
  timer.setInterval(500L,kelip);
}

void loop() 
{ BlynkEdgent.run();
  timer.run();
}

