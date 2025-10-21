#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

// Crea el objeto display (0x3C es la dirección I2C más común)
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Inicializa la pantalla
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("No se encontró pantalla OLED"));
    while(true); // se queda trabado si no la detecta
  }

  display.clearDisplay();
  display.setTextSize(1);      // Tamaño de texto (1 a 3 aprox.)
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,10);
  display.println("Hola Mundo!");
  display.display(); // Refresca la pantalla
}

void loop() {
}