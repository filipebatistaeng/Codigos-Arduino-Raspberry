#define  ADDO  7  //DOUT
#define  ADSK  6  //SCK

#define motor 13


float lerCelula();
void alimentaPeixes(float); 

unsigned long convert;

void setup()
{
  Serial.begin(9600);
  pinMode(ADDO, INPUT_PULLUP);   
  pinMode(ADSK, OUTPUT);        
  pinMode(motor, OUTPUT);
   

} 

void loop()
{
  
  float quantidadeRacao = 10.0;

  alimentaPeixes(quantidadeRacao);

  delay(2000);
} 


float lerCelula()
{
  unsigned long Count = 0;
  unsigned char i;
  
  digitalWrite(ADSK, LOW);
  
  while(digitalRead(ADDO));
  
  for(i=0;i<24;i++)
  {
     digitalWrite(ADSK, HIGH);
     Count = Count << 1;
     digitalWrite(ADSK, LOW);
     if(digitalRead(ADDO)) Count++;
  
  } //end for
  
  digitalWrite(ADSK, HIGH);
  Count = Count^0x800000;
  digitalWrite(ADSK, LOW);

  float massa = -0.0016312*float(Count)+13984.113;
  
  return(massa);
  
}

void alimentaPeixes(float valorAlimento)
{
  
  digitalWrite(motor, HIGH);
  while(lerCelula()<=valorAlimento);
  digitalWrite(motor, LOW);
  
}









