int led[4]={D0,D1,D2,D3};

void setup() 
{ for(int i=0;i<=3;i++) pinMode(led[i],OUTPUT);
}

void loop() 
{ for(int j=0;j<4;j++)
  { for(int i=0;i<255;i++)
    { analogWrite(led[j],i);
      delay(2);
    }
    for(int i=255;i>-1;i--)
    { analogWrite(led[j],i);
      delay(2);
    }
  }
}
