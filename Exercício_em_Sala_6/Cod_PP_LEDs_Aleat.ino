// Definição dos pinos dos LEDs
const int led1 = 8; // Pino do LED 1
const int led2 = 9; // Pino do LED 2
const int led3 = 10; // Pino do LED 3
const int led4 = 11; // Pino do LED 4

// Definição do pino do botão
const int buttonPin = 3; // Pino do botão

// Variável para armazenar o valor aleatório
long a; // Variável para o pino do LED a ser acionado

void setup() {
  // Inicializa os pinos dos LEDs como saídas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  // Inicializa o pino do botão como entrada
  pinMode(buttonPin, INPUT);
  
  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios
}

void loop() {
  // Usando um loop for para repetir indefinidamente enquanto o botão não for pressionado
  for (; digitalRead(buttonPin) == HIGH;) {
    // Gera um número aleatório entre 8 e 11 (pinos dos LEDs)
    a = random(8, 12);
    
    // Acende o LED correspondente
    digitalWrite(a, HIGH);
    
    // Aguarda por um período de tempo
    delay(500);
    
    // Apaga o LED
    digitalWrite(a, LOW);
    
    // Aguarda por um período de tempo antes de repetir
    delay(500);
  }
  
  // Apaga todos os LEDs quando o botão for pressionado
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
