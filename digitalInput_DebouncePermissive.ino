int led[4]={D0,D1,D2,D3},in=D5;
int newPB,oldPB,cnt=0;

void setup() 
{ pinMode(in,INPUT);
  Serial.begin(9600);
}

void loop() 
{ oldPB = newPB;
  newPB = digitalRead(in);
  if(newPB==1 && oldPB==0) 
  { cnt++; 
    Serial.println(cnt);
    delay(200); 
  } 
}
