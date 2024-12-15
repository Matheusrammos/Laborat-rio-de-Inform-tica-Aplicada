const int ledPins[] = {13, 9, 6, 3}; // Pinos onde os LEDs estão conectados

void setup() {
   // Configura os pinos dos LEDs como saída
   for (int i = 0; i < 4; i++) {
      pinMode(ledPins[i], OUTPUT); 
   }
}

void loop() {
   // Acende e apaga os LEDs sequencialmente
   for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH); // Acende o LED
      delay(500); // Espera 0,5 segundos
      digitalWrite(ledPins[i], LOW); // Apaga o LED
      delay(500); // Espera 0,5 segundos
   }
}
