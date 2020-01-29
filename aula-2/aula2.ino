int vermelho=12;
int azul=10;
int verde=9;
int potenciometro = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  
}

//Funções responsáveis por executar o brilho selecionado
void vermelhoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}
void azulFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}
void verdeFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void amareloFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 50);
  analogWrite(vermelho, 255);
}
void roxoFuncao(){
  analogWrite(azul, 207);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void brancoFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}
 

void loop()
{
  float sinal;
  sinal = analogRead(potenciometro);
  Serial.println(sinal);
  if(sinal>=0 && sinal<=150)
    brancoFuncao();
  else if(sinal>150 && sinal<=300)
    	azulFuncao();
  	   else if(sinal>300 && sinal<=450)
         		verdeFuncao();
         	else if(sinal>450 && sinal<=600)
              	  amareloFuncao();
  				 else if(sinal>600 && sinal<=750)
                   		vermelhoFuncao();
                      else brancoFuncao();
                 
    
}














