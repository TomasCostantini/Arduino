void alarma(){

for (int b = 0; b <= 5; b++) {
          digitalWrite(16, HIGH);
          delay (50);
          digitalWrite(16, LOW);
          delay (50);
          lcd.clear();
        }
if (alarm>=4){
  alarm=0;
   for (int b = 0; b <= 200; b++) {
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("ALERTA");          // Cuando el contador la alarma llega a 4 intentos fallidos se activa una alerta sonora
          digitalWrite(16, HIGH);
          delay (50);
          digitalWrite(16, LOW);
          delay (50);
    
        }
}
}