// Declaração dos pinos dos LEDs
const int ledPins[] = {11, 12, 13}; // Pinos dos LEDs

// Declaração dos pinos dos botões
const int buttonPins[] = {2, 3, 4}; // Pinos dos botões

// Declaração do pino do buzzer
const int buzzerPin = 9; // Pino do buzzer

// Declaração das notas a serem tocadas (frequências em Hz)
const int notes[] = {261, 329, 392}; // Notas: C4, E4, G4

void setup() {
  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura os pinos dos botões como entrada com resistor pull-dow externo
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  
  // Configura o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Percorre os botões e LEDs correspondentes
  for (int i = 0; i < 3; i++) {
    // Se o botão estiver pressionado (estado HIGH)
    if (digitalRead(buttonPins[i]) == HIGH) { 
      digitalWrite(ledPins[i], HIGH); // Liga o LED correspondente
      tone(buzzerPin, notes[i]);       // Toca a nota correspondente no buzzer
    } else {
      digitalWrite(ledPins[i], LOW);   // Desliga o LED correspondente
      noTone(buzzerPin);               // Para de tocar o buzzer
    }
  }
}
