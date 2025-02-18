void apertura(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Acceso Permitido");
        digitalWrite(15, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        delay(500);
        digitalWrite(14,HIGH);
        digitalWrite(15,LOW);
        digitalWrite(16, LOW);
        delay(150);
        digitalWrite(17, LOW);
        alarm=0;
        lcd.clear();
}