#define BLYNK_TEMPLATE_ID       "TMPL6XTP0YTC1"
#define BLYNK_TEMPLATE_NAME     "First IoT Program"
#define BLYNK_FIRMWARE_VERSION  "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"

void setup()
{ Serial.begin(9600);
  delay(100);
  BlynkEdgent.begin();
}

void loop() 
{ BlynkEdgent.run();
}

