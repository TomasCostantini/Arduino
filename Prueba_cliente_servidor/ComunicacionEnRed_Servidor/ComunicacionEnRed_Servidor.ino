#include <SPI.h>
#include <Ethernet.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


#define RST_PIN 9  // Configurable, see typical pin layout above
#define SS_PIN 10  // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 10, 10, 2);
EthernetServer server(80);

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
  Serial.println("Servidor iniciado...");
  SPI.Begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') {
          Serial.print("Mensaje recibido: ");
          Serial.println(request);
          client.stop();
          break;
        }
      }
    }
  }

  // Enviar mensaje desde el monitor serie al cliente
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    if (client.connect(ip, 80)) {
      client.println(message);
      client.stop();
    }
  }
}
