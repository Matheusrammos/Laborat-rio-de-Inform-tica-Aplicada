// Definindo os pinos dos LEDs
const int led1Pin = 13; // Pino do primeiro LED
const int led2Pin = 9; // Pino do segundo LED
const int led3Pin = 6; // Pino do terceiro LED

void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  digitalWrite(led1Pin, HIGH); // Acende o primeiro LED
  delay(1000); // Aguarda 1 segundo

  digitalWrite(led1Pin, LOW); // Apaga o primeiro LED  
  digitalWrite(led2Pin, HIGH); // Acende o segundo LED
  delay(1000); // Aguarda 1 segundo

  digitalWrite(led2Pin, LOW); // Apaga o segundo LED
  digitalWrite(led3Pin, HIGH); // Acende o terceiro LED
  delay(1000); // Aguarda 1 segundo

  digitalWrite(led3Pin, LOW); // Apaga o terceiro LED
}
