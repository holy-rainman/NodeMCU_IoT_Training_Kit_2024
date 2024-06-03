int led[4]={D0,D1,D2,D3},in=D5;
int pb,cnt=0,an;

void setup() 
{ Serial.begin(9600);
}

void loop() 
{ an = analogRead(A0);
  an = map(an,30,900,0,11);
  Serial.println(an); 
}
