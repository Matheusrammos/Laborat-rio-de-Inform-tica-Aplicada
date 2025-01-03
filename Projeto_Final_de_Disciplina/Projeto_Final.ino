// Definindo pinos e algumas variáveis
const int ledPins[] = {3, 4, 5, 6, 7, 8}; // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13; // Pino do botão
bool a = false; // Variável iterruptora
long x; // Número de piscadas
int p; // Tempo de cada piscada


void setup() {
  // Inicializando o pino do botão como entrada
  pinMode(buttonPin, INPUT); 

  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }

  // Inicializando o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios

  // Inicializando a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
  Serial.begin(9600); 
}


void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Se o botão for pressionado
    a = !a; // O "interruptor" marcará 'true'
  }

  if (a == true) { // Se o "interrruptor" marcar 'true'
    x = random(41, 591); // Gerar um número aleatório de 41 a 590
    Serial.println(x); // Mostrar esse número no Serial Monitor

    // Acende e apaga os LEDs sequencialmente
    for (int i = 0; i < 7; i++) {
      // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
      if (i == 6) { // Estado temporário
        i = 0; // Resetado para o pino 3
      }

      p = 1000/x; // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição
      digitalWrite(ledPins[i], HIGH); // Acende o respectivo LED
      delay(p); // Espera o tempo de piscada
      digitalWrite(ledPins[i], LOW); // Apaga o mesmo
      x--; // O valor de "x" diminui em 1

      // Indicando o LED escolhido
      if (x == 0) {
        delay(70);
        digitalWrite(ledPins[i], LOW);
        delay(100);
        digitalWrite(ledPins[i], HIGH);
        delay(100);
        digitalWrite(ledPins[i], LOW);
        delay(100);
        digitalWrite(ledPins[i], HIGH);
        delay(3000);
        a = !a;
        i = 7;
      }
    }
  }
}
