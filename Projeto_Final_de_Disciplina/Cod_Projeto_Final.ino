// Definindo pinos e algumas variáveis
const int ledPins[] = { 3, 4, 5, 6, 7, 8, 9, 10 };  // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13;                           // Pino do botão
const int buzzerPin = 12;                           // Pino do buzzer
bool a = false;                                     // Variável iterruptora
long x;                                             // Número de piscadas
int p;                                              // Tempo de cada piscada
int c = 0;                                          // LED excolhido


void setup() {
  // Inicializando o pino do botão como entrada
  pinMode(buttonPin, INPUT);

  // Configura o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT); 

  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Inicializando o gerador de números aleatórios
  randomSeed(analogRead(0));  // Gera a semente para números aleatórios

  // Inicializando a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
  Serial.begin(9600);
}


void loop() {
  for (int counter = 0; counter <= 6;) {
    Serial.println(counter);         // Mostrar esse número no Serial Monitor
    digitalWrite(ledPins[c], HIGH);  // Acende o respectivo LED

    if (digitalRead(buttonPin) == HIGH) {  // Se o botão for pressionado
      counter++;
      delay(80);
    }

    if ((digitalRead(buttonPin) == LOW) && (counter >= 1 && counter <= 4)) {
      digitalWrite(ledPins[c], LOW);   // Apaga o mesmo
      c++;                             // O "interruptor" marcará 'true'
      tone(buzzerPin, 58);             // Toca a nota correspondente
      delay(60);                       // Espera 60 mili segundos 
      noTone(buzzerPin);               // Deixa de tocar a nota

      if (c == 6) {
        c = 0;
      }
      counter = 0;
    } else if ((counter > 4) && ((digitalRead(buttonPin) == LOW) or (digitalRead(buttonPin) == HIGH))) {
      a = !a;
    }
  }

  // Se o "interrruptor" marcar "true"
  if (a == true) {
    x = random(41, 591);       // Gerar um número aleatório de 41 a 590
    Serial.println(x);         // Mostrar esse número no Serial Monitor

    // Acende e apaga os LEDs sequencialmente
    for (int i = 0; i < 7; i++) {
      // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
      if (i == 6) {            // Estado temporário
        i = 0;                 // Resetado para o pino 3
      }

      p = 1000 / x;                    // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição
      digitalWrite(ledPins[i], HIGH);  // Acende o respectivo LED

      if (digitalRead(ledPins[i]) == HIGH) {
        tone(buzzerPin, 58);   // Toca a nota correspondente
        delay(p/2);            // Espera metade do tempo de piscada         
        noTone(buzzerPin);     // Deixa de tocar a nota
      }   
      delay(p/2);                      // Espera metade do tempo de piscada                 
      digitalWrite(ledPins[i], LOW);   // Apaga o mesmo
      x--;                             // O valor de "x" diminui em 1

      // Indicando o LED escolhido
      if (x == 0) {
        if (c == i) {
          digitalWrite(ledPins[7], HIGH);
          delay(70);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 120);            // Toca a nota correspondente
          delay(60);                       // Espera 60 mili segundos 
          noTone(buzzerPin);               // Deixa de tocar a nota

          delay(40);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 350);            // Toca a nota correspondente
          delay(60);                       // Espera 60 mili segundos 
          noTone(buzzerPin);               // Deixa de tocar a nota

        } else {
          digitalWrite(ledPins[6], HIGH);
          delay(70);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 500);            // Toca a nota correspondente
          delay(60);                       // Espera 60 mili segundos 
          noTone(buzzerPin);               // Deixa de tocar a nota

          delay(40);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 300);            // Toca a nota correspondente
          delay(60);                       // Espera 60 mili segundos 
          noTone(buzzerPin);               // Deixa de tocar a nota
        }

        delay(4940);
        digitalWrite(ledPins[i], LOW);

        // Finaliza a roleta
        digitalWrite(ledPins[6], LOW);
        digitalWrite(ledPins[7], LOW);
        a = false;                     // Desativa o modo de roleta
        c = 0;                         // Reseta o índice de LEDs
        i = 7;                         // Força a saída do comando for
      }
    }
  }
}
