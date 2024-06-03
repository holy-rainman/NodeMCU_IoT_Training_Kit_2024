int led[4]={D0, D1, D2, D3};

void setup() 
{ for(int i=0;i<=3;i++)
  pinMode(led[i],OUTPUT);
}

void loop() 
{ for(int i=0;i<=3;i++) digitalWrite(led[i],HIGH); 
  delay(1000); 
  for(int i=0;i<=3;i++) digitalWrite(led[i],LOW); 
  delay(1000); 
}
