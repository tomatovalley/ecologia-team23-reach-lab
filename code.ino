// Librerias
#include <LiquidCrystal.h>

// inicialización de ping y variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float tempC;
double oxigenacion, pH, contenidoSustrato;
int pinLM35 = 0;

void setup() {
  // inicialización LCD's cols y rows
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  lcd.print("Calculando...");
  
  
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
  // leemos el sensor.
  float temp = analogRead(pinLM35);    
  // Calculamos la temperatura con la fórmula
  tempC = (temp - 500 )/ 10;  
  pH = random() * (6.48-6.30) / 10;
  oxigenacion = random() * (50.6-6.4) / 10;
  contenidoSustrato = random() * (100.0 - 20.0) / 10; 
 
  
  Serial.print(tempC);
  Serial.print("\t");
  
  Serial.print(pH);
  Serial.print("\t");
    
  Serial.print(oxigenacion);
  Serial.print("\t");
    
  Serial.print(contenidoSustrato);
  Serial.print("\n");
  
  // Esperamos un tiempo para repetir el loop
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print("\n");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PH");
  lcd.setCursor(0, 1);
  lcd.print(pH);
  lcd.print("\n");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Oxigenacion");
  lcd.setCursor(0, 1);
  lcd.print(oxigenacion);
  lcd.print("\n");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Contenido Sustrato");
  lcd.setCursor(0, 1);
  lcd.print(contenidoSustrato);
  lcd.print("\n");
  delay(1000);
}