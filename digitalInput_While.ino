int led[4]={D0,D1,D2,D3},in=D5;
int pb,cnt=0;

void setup() 
{ pinMode(in,INPUT);
  Serial.begin(9600);
}

void loop() 
{ pb = digitalRead(in);
  if(pb==1) 
  { cnt++; 
    Serial.println(cnt);
    while(digitalRead(in)==1);
    delay(200); 
  } 
}
