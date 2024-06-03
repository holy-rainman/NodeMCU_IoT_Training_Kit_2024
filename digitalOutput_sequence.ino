int led1=D0, led2=D1, led3=D2, led4=D3;
void setup() 
{ pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);  
}
void loop() 
{ digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led4, HIGH); delay(1000); 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  digitalWrite(led4, LOW);  delay(1000); 
}
