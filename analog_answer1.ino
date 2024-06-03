int led[4]={D0,D1,D2,D3};
int in=D5;

void setup() 
{ for(int i=0;i<=3;i++) pinMode(led[i],OUTPUT);
  pinMode(in,INPUT);
  Serial.begin(9600);
}

void loop() 
{ int an = analogRead(A0);
  an = map(an,6,1024,1,10);
  Serial.println(an);
  digitalWrite(D0,HIGH);

  int pb = digitalRead(in);
  if(pb==1)
  { digitalWrite(D0,LOW);
    for(int i=0;i<an;i++)
    { digitalWrite(D1,HIGH);  delay(200);
      digitalWrite(D1,LOW);   delay(200);
    }
    delay(200);
  }
}
