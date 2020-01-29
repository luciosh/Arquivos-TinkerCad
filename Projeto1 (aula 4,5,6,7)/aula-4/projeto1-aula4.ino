#include <LiquidCrystal.h>

#define pGas A5

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World");
}

void loop() {
  
  limpa_tela();
  //leitura sensor gas
  lcd.print("Arduino Brasil");
  
  delay(100);
  
}

void limpa_tela(){
 delay(1500);
 lcd.setCursor(0,1);
 lcd.print("                ");
 lcd.setCursor(0,1); 
}
 