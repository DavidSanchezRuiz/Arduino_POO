#include <LiquidCrystal.h>}
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
LiquidCrystal liquidCrystal(8, 9, 4, 5, 6, 7);
class Pantalla {
  private:
    int lcd_key     = 0;
    int adc_key_in  = 0;
    boolean estadoLuzLCD = true;
  public:
    Pantalla();
    void mensajeLCDA(String mensaje);
    void mensajeLCDB(String mensaje);
    void luzLCD();
    int getButton();
    void botonesAcciones();
    void botones();
    
};
Pantalla::Pantalla() {
  liquidCrystal.begin(16, 2);
  pinMode(10, OUTPUT);
  luzLCD();
  luzLCD();
}
void Pantalla::mensajeLCDA(String mensaje) {
  liquidCrystal.setCursor(0, 0);
  liquidCrystal.print("                ");
  liquidCrystal.setCursor(0, 0);
  liquidCrystal.print(mensaje);
}
void Pantalla::mensajeLCDB(String mensaje) {
  liquidCrystal.setCursor(0, 1);
  liquidCrystal.print("                ");
  liquidCrystal.setCursor(0, 1);
  liquidCrystal.print(mensaje);
}
void Pantalla::luzLCD() {
  if (estadoLuzLCD) {
    digitalWrite(10, LOW);
    estadoLuzLCD = !estadoLuzLCD;
  } else {
    digitalWrite(10, HIGH);
    estadoLuzLCD = !estadoLuzLCD;
  }
}
int Pantalla::getButton() { //Determinar botones.
  adc_key_in = analogRead(0);// Leemos A0
  // Mis botones dan:  0, 145, 329,507,743
  if (adc_key_in > 900) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 150)  return btnUP;
  if (adc_key_in < 300)  return btnDOWN;
  if (adc_key_in < 450)  return btnLEFT;
  if (adc_key_in < 650)  return btnSELECT;
  return btnNONE;
}
void Pantalla::botonesAcciones() {
  lcd_key = getButton();
  botones();
}
//Metodo de ejemplo
void Pantalla::botones() {
  if ( lcd_key == btnRIGHT) {

  }
  else if ( lcd_key == btnLEFT ) {

  }
  else if ( lcd_key == btnUP) {

  }
  else if ( lcd_key == btnDOWN) {
    
  }
  else if ( lcd_key == btnSELECT) {
    
  }
  else if ( lcd_key == btnNONE) {

  }
}
