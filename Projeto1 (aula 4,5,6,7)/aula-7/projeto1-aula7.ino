#include <LiquidCrystal.h>

#define pGas A5
#define pPir 7
#define pTemp A4

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Monitoramento: ");
  pinMode(pPir,INPUT);
}

void loop() {
  int sinalGas=analogRead(pGas);
  sinalGas=map(sinalGas,300,750,0,100);
  limpa_tela();
  //leitura sensor gas
  lcd.print("GAS: ");
  lcd.print(sinalGas);
  
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
 delay(1500);
 lcd.setCursor(0,1);
 lcd.print("                ");
 lcd.setCursor(0,1); 
}
 
void presenca(){
  int sinalPir=digitalRead(pPir);
  if(sinalPir==1)
    lcd.print("Em uso");
  else
    lcd.print("Vazio");
}

void temperatura(){
  float sinalTemp=analogRead(pTemp)*5;
  float TempC=((sinalTemp/1023)-0.5)*100;
  lcd.print(TempC);
}