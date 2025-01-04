// Define o pino onde o LED está conectado
const int ledPin = 13; // O LED embutido geralmente está no pino 13

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Liga o LED
  digitalWrite(ledPin, HIGH); // Acende o LED
  delay(1000);                // Aguarda 1 segundo (1000 milissegundos)

  // Desliga o LED
  digitalWrite(ledPin, LOW);  // Apaga o LED
  delay(1000);                // Aguarda mais 1 segundo
}
