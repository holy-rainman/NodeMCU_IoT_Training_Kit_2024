int led[4]={D0, D1, D2, D3}, in=D5;
int pb,cnt=0;

void setup() 
{ for(int i=0;i<=3;i++) pinMode(led[i],OUTPUT);
  pinMode(in,INPUT);
}

void loop() 
{ pb = digitalRead(in);
  if(pb==1) { cnt++; while(digitalRead(in)==1); delay(200); }
  if(cnt==1) digitalWrite(led[0],HIGH);
  if(cnt==2) digitalWrite(led[1],HIGH);
  if(cnt==3) digitalWrite(led[2],HIGH);
  if(cnt==4) digitalWrite(led[3],HIGH);
  if(cnt==5) 
  { for(int i=0;i<=3;i++) digitalWrite(led[i],LOW);
    cnt=0;
  }
}
