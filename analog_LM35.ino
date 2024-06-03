int led[4]={D0,D1,D2,D3},in=D5;
int pb,cnt=0;
float an,volt,temp;

void setup() 
{ Serial.begin(9600);
}

void loop() 
{ an = analogRead(A0);
  an = map(an,22,930,0,1023);
  volt = an * 3.3 / 1023;
  temp = volt * 100;
  Serial.print(an,0); 
  Serial.print("  Volt:"); Serial.print(volt); Serial.print("V");
  Serial.print("  Temp:"); Serial.print(temp); Serial.println("C");
  delay(20);
}
