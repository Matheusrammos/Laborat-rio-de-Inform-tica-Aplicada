// Definindo os pinos e algumas variáveis
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão
int Estbutton = 0; // Estado atual

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}

void loop() {
Estbutton = digitalRead(buttonPin); // O estado do botão recebe a leitura atual do botão
 if (Estbutton == HIGH) { // Se o botão estiver pressionado
    digitalWrite(ledPin, HIGH); // Liga o LED
  } else { // Se não
    digitalWrite(ledPin, LOW); // Desliga o LED
  }
Serial.println(Estbutton); // Mostre o estado do botão no Serial Monitor
delay(50); // Debouncing
}
