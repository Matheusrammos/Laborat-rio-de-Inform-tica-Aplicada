# Alarme com senha.

// Definição dos pinos dos LEDs e do botão
const int ledPins[] = {3, 4, 5, 6, 7, 8}; // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13; // Pino do botão

//Definindo variáveis
bool a = false;
long x;
int parado;


void setup() {
  // Inicializando o pino do botão como entrada
  pinMode(buttonPin, INPUT); 

  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }
  // Inicializando o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}


void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Se o botão estiver pressionado
    a = !a;
  }

  if (a == true) {
    x = random(41, 591);
    Serial.println(x); // Mostre o estado do botão no Serial Monitor

    // Acende e apaga os LEDs sequencialmente
    for (int i = 0; i < 7; i++) {
      if (i == 6) {
        i = 0;
      }

      parado = 1000/x;
      digitalWrite(ledPins[i], HIGH); // Acende o LED
      delay(parado);
      digitalWrite(ledPins[i], LOW); // Apaga o LED
      x--;

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
