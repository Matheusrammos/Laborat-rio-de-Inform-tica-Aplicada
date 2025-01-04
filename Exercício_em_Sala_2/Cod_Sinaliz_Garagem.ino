// Definindo os pinos dos LEDs
const int led1Pin = 9; // Pino do primeiro LED
const int led2Pin = 13; // Pino do segundo LED

void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  digitalWrite(led1Pin, HIGH); // Acende o primeiro LED
  digitalWrite(led2Pin, LOW); // Apaga o segundo LED
  delay(1000); // Aguarda 1 segundo

  digitalWrite(led1Pin, LOW); // Apaga o primeiro LED
  digitalWrite(led2Pin, HIGH); // Acende o segundo LED
  delay(1000); // Aguarda 1 segundo
}
