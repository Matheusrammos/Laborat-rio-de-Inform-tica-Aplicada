// Definindo os pinos
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Se o botão for precionado*********************
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
  }
}
