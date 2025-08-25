#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 };
IPAddress ip(10, 10, 10, 3); // Cambiar para cada cliente
IPAddress server(10, 10, 10, 2); // IP del servidor

EthernetClient client;

void setup() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  delay(1000);
  Serial.println("Cliente iniciado...");
}

void loop() {
  // Enviar mensaje desde el monitor serie al servidor
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    if (client.connect(server, 80)) {
      client.println(message);
      client.stop();
    }
  }
  
  // Recibir mensaje del servidor
  if (client.available()) {
    String response = "";
    while (client.available()) {
      char c = client.read();
      response += c;
    }
    Serial.print("Mensaje del servidor: ");
    Serial.println(response);
  }
}
