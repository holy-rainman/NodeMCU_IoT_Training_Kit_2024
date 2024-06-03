int led[4]={D0,D1,D2,D3};

void setup() 
{ for(int i=0;i<=3;i++) pinMode(led[i],OUTPUT);
}

void loop() 
{ for(int i=0;i<255;i++)
  { analogWrite(D0,i);
    delay(5);
  }
  for(int i=255;i>0;i--)
  { analogWrite(D0,i);
    delay(5);
  } 
}
