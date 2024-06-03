int led[4]={D0,D1,D2,D3},in=D5;
int pb,cnt=0;
float an,volt;

void setup() 
{ Serial.begin(9600);
}

void loop() 
{ an = analogRead(A0);
  an = map(an,22,900,0,1023);
  volt = an * 3.3 / 1023;
  Serial.print(an,0); 
  Serial.print("  Volt:");
  Serial.print(volt);
  Serial.println("V");
}
