int led1=D0, led2=D1, led3=D2, led4=D3, in=D5;

void setup() 
{ pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(in,INPUT);
}

void loop() 
{ int pb = digitalRead(in);
  if(pb == 1) 
  { digitalWrite(led1,HIGH); 
    digitalWrite(led2,LOW);
  }
  if(pb == 0) 
  { digitalWrite(led1,LOW); 
    digitalWrite(led2,HIGH);
  } 
}
