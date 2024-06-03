int led[4]={D0,D1,D2,D3};
int seq[8]={0,1,3,7,15,14,12,8};

void setup() 
{ for(int i=0;i<=3;i++) pinMode(led[i],OUTPUT);
}

void loop() 
{ for(int i=0;i<8;i++) {LEDs(seq[i]); delay(200); }
}

void LEDs(int no)
{ digitalWrite(led[0], no&(1<<0)); 
  digitalWrite(led[1], no&(1<<1)); 
  digitalWrite(led[2], no&(1<<2)); 
  digitalWrite(led[3], no&(1<<3)); 
}
