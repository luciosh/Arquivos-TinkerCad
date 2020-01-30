#include <LiquidCrystal.h>

#define pGas A5
#define pPir 7
#define pTemp A4

#define gVermelho 8
#define gAzul 9
#define gVerde 10

#define tVerde A0
#define tAzul A1
#define tVermelho A2

#define pLED A3


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Monitoramento: ");
  pinMode(pPir,INPUT);
  pinMode(gVermelho,OUTPUT);
  pinMode(gVerde,OUTPUT);
  pinMode(gAzul,OUTPUT);
}

void loop() {
  //leitura sensor gas
  limpa_tela();
  lcd.print("GAS: ");
  gas();
  
  //Leitura de presenca
  limpa_tela();
  lcd.print("Estado: ");
  presenca();
  
  //Leitura temperatura
  limpa_tela();
  lcd.print("Temp: ");
  temperatura();
  
  delay(100);
  
}

void limpa_tela(){
 delay(500);
 lcd.setCursor(0,1);
 lcd.print("                ");
 lcd.setCursor(0,1); 
}
 
void presenca(){
  int sinalPir=digitalRead(pPir);
  if(sinalPir==1){
    lcd.print("Em uso");
    analogWrite(pLED,255);
  }
  else{
    lcd.print("Vazio");
    analogWrite(pLED,0);
    
  }
}

void temperatura(){
  float sinalTemp=analogRead(pTemp)*5;
  float tempC=((sinalTemp/1023)-0.5)*100;
  if(tempC>=15 && tempC<=20){
    analogWrite(tVermelho,0);
    analogWrite(tVerde,255);
    analogWrite(tAzul,0);
  }else if(tempC>20 && tempC<=25){
  	analogWrite(tVermelho,255);
    analogWrite(tVerde,255);
    analogWrite(tAzul,0);
  }else{
    analogWrite(tVermelho,255);
    analogWrite(tVerde,0);
    analogWrite(tAzul,0);
  }
  lcd.print(tempC);
}

void gas(){
  int sinalGas=analogRead(pGas);
  sinalGas=map(sinalGas,300,750,0,100);
  if(sinalGas>=0 && sinalGas<=10){
    digitalWrite(gVermelho,LOW);
    digitalWrite(gVerde,HIGH);
    digitalWrite(gAzul,LOW);
  }else if(sinalGas>10 && sinalGas<=15){
   	digitalWrite(gVermelho,HIGH);
    digitalWrite(gVerde,HIGH);
    digitalWrite(gAzul,LOW);
  }else {
    digitalWrite(gVermelho,HIGH);
    digitalWrite(gVerde,LOW);
    digitalWrite(gAzul,LOW);
  }
  lcd.print(sinalGas);
}