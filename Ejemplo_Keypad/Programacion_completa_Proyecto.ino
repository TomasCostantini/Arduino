#include <Wire.h>  // Libreria para utilizar el puerto I2C
#include <LiquidCrystal_I2C.h> // Libreria para utilizar el Display Lcd
#include <Keypad.h> //Libreria para utilizar el teclado matricial
LiquidCrystal_I2C lcd(0x27, 20, 4);

int alarm;

//teclado
const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";   // almacena en un array la contraseña maestra
byte INDICE = 0;      // indice del array
char clave1[7] = "449264"; // Ejemplos de claves
char clave2[7] = "261753";
char clave3[7] = "654514";
char clave4[7] = "696211";
char clave5[7] = "104123";

byte pinesFilas[FILAS] = {30, 32, 34, 36}; // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {22, 24, 26, 28}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto



void setup() {
  lcd.init();         // Iniciar Display
  lcd.setCursor(0, 0);
  lcd.backlight();

  for (int x = 0; x <= 50; x++) {
    lcd.print("Buenos Dias,");       // Saludo inicial
    lcd.setCursor(0, 1);
    lcd.print("tardes o noches.");
  }
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Ingrese su Pin");
  digitalWrite(14, HIGH);
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable

  if (TECLA)        // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA;    // almacena en array la tecla presionada
    lcd.setCursor(INDICE, 1);

    lcd.print(TECLA);    // envia a monitor serial la tecla presionada
    INDICE++;       // incrementa indice en uno
  }

  if (INDICE == 6) {
    if (!strcmp(CLAVE, CLAVE_MAESTRA) or !strcmp(CLAVE, clave1) or !strcmp(CLAVE, clave2) or !strcmp(CLAVE, clave3) or !strcmp(CLAVE, clave4) or !strcmp(CLAVE, clave5)) { // compara clave ingresada con el resto de claves
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Acceso Permitido");  // imprime en el display que es correcta la clave
      apertura();

    }
    else {
      alarm++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Accseso Denegado");
      lcd.setCursor(0, 1);               // Si la clave ingresada no coincide con ninguna clave se imprime la negacion del acceso y se le suma un intento a la alarma
      lcd.print (" Intento n°:");
      lcd.println (alarm);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      delay(500);
      digitalWrite(15, LOW);
      alarma();
    }
    delay(500);
    lcd.clear(); // Limpia el display y resetea el valor del indice 
    INDICE = 0; 
  }



}