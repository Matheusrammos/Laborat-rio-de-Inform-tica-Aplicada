#include <TimerOne.h>  // Biblioteca para usar Timer

// Definindo pinos e algumas variáveis
const int ledPins[] = { 3, 4, 5, 6, 7, 8, 9, 10 };  // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13;                           // Pino do botão
const int buzzerPin = 12;                           // Pino do buzzer
bool a = false;                                     // Variável iterruptora
long x;                                             // Número de piscadas
int p;                                              // Tempo de cada piscada
int c = 0;                                          // LED excolhido
int som[] = { 58, 108 };

bool z = false;  // Modo Tigrgrinho
int counter = 0;
bool estadoLEDs = false;
int vitorias = 0;
int chance;
int sorte;



void setup() {

  pinMode(buttonPin, INPUT);   // Inicializando o pino do botão como entrada
  pinMode(buzzerPin, OUTPUT);  // Configura o pino do buzzer como saída

  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);  // Configura os pinos dos LEDs como saída
  }

  randomSeed(analogRead(0));  // Inicializando o gerador de números aleatórios
  Serial.begin(9600);         // Inicializando a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}



// Alterna os LEDs no modo Tigrinho
void piscarLEDs() {
  if (z && !a) {
    estadoLEDs = !estadoLEDs;  // Inverte estado dos LEDs
    for (int i = 0; (i < 6); i++) {
      if (i == c) {  // Pula o LED atualmente escolhido
        i++;
      }
      digitalWrite(ledPins[i], estadoLEDs);
    }
  }
}



// Função para girar a roleta
void giraRoleta() {

  if (a) {                          // Se o "interrruptor" marcar "true"
    if (z) {                        // Se o modo Tigrinho estiver ativo
      Serial.println((x % 6) - 1);  // Esse número representa extamente o LED que será excolhido após o giro da roleta

      // Ajusta as chances de vitória conforme histórico de ganhos
      if (vitorias < 2) {
        chance = 80;
      } else if (vitorias < 5) {
        chance = 50;
        vitorias = vitorias--;
      } else {
        chance = 30;
        vitorias -= 2;  // vitorias = vitorias - 2;
      }

      sorte = random(0, 101);
      Serial.println(sorte);  // Mostrar esse número no Serial Monitor

      // Determina se o jogador vence ou perde
      if (sorte <= chance) {
        while (x <= 10) {
          x = ((c % 6) + 6 * sorte + 1);
        }
        vitorias++;
      } else {
        do {
          x = random(41, 591);
        } while (((x % 6) - 1) == c);
      }
      Serial.println(vitorias);  // Mostrar esse número no Serial Monitor


    } else {
      x = random(41, 591);  // Gerar um número aleatório de 41 a 590
      Serial.println(x);    // Mostrar esse número no Serial Monitor
    }



    // Percorre os LEDs simulando o giro da roleta
    for (int i = 0; i < 7; i++) {
      // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
      if (i == 6) {  // Estado temporário
        i = 0;       // Resetado para o pino 3
      }

      p = 1000 / x;                    // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição
      digitalWrite(ledPins[i], HIGH);  // Acende o respectivo LED

      if (digitalRead(ledPins[i]) == HIGH) {
        tone(buzzerPin, som[z]);  // Toca a nota correspondente
        delay(p / 2);             // Espera metade do tempo de piscada
        noTone(buzzerPin);        // Deixa de tocar a nota
      }
      delay(p / 2);                   // Espera metade do tempo de piscada
      digitalWrite(ledPins[i], LOW);  // Apaga o mesmo
      x--;                            // O valor de "x" diminui em 1

      // Indicando o LED escolhido
      if (x == 0) {
        if (c == i) {
          digitalWrite(ledPins[7], HIGH);
          delay(70);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 120);  // Toca a nota correspondente
          delay(60);             // Espera 60 mili segundos
          noTone(buzzerPin);     // Deixa de tocar a nota

          delay(40);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 350);  // Toca a nota correspondente
          delay(60);             // Espera 60 mili segundos
          noTone(buzzerPin);     // Deixa de tocar a nota

        } else {
          digitalWrite(ledPins[6], HIGH);
          delay(70);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 500);  // Toca a nota correspondente
          delay(60);             // Espera 60 mili segundos
          noTone(buzzerPin);     // Deixa de tocar a nota

          delay(40);
          digitalWrite(ledPins[i], LOW);
          delay(100);
          digitalWrite(ledPins[i], HIGH);

          tone(buzzerPin, 300);  // Toca a nota correspondente
          delay(60);             // Espera 60 mili segundos
          noTone(buzzerPin);     // Deixa de tocar a nota
        }


        if (digitalRead(buttonPin) == HIGH) {
          // Ativa modo Tigrinho
          z = !z;
          vitorias = 0;
          digitalWrite(ledPins[6], HIGH);
          digitalWrite(ledPins[7], HIGH);

          c = 0;  // Reseta o índice de LEDs
          if (z == true) {
            digitalWrite(ledPins[i], LOW);

            introModoTigrin();
            a = false;  // Desativa o modo de roleta
            loop();
          }
        }
        delay(4940);
        digitalWrite(ledPins[i], LOW);


        // Finaliza a roleta
        digitalWrite(ledPins[6], LOW);
        digitalWrite(ledPins[7], LOW);
        a = false;  // Desativa o modo de roleta
        c = 0;      // Reseta o índice de LEDs
        i = 7;      // Força a saída do comando for
      }
    }
  }
}



// Transição entre o Modo Padrão e o Modo do Trigrinho
void introModoTigrin() {
  // Acende e apaga os LEDs sequencialmente
  for (int i = 0; (i < 7) && (z == true); i++) {
    p = 130;  // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição

    // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
    if (i == 6) {  // Estado temporário
      i = 0;       // Resetado para o pino 3
      c++;
    }

    if ((c == 2) && (i == 1)) {
      digitalWrite(ledPins[5], LOW);  // Apaga o mesmo
    } else if (c == 3) {
      if (i == 1) {
        digitalWrite(ledPins[4], LOW);  // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[5], LOW);  // Apaga o mesmo
      }

    } else if (c == 4) {
      if (i == 1) {
        digitalWrite(ledPins[3], LOW);  // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[4], LOW);  // Apaga o mesmo
      } else if (i == 3) {
        digitalWrite(ledPins[5], LOW);  // Apaga o mesmo
      }

    } else if (c == 5) {
      if (i == 1) {
        digitalWrite(ledPins[2], LOW);  // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[3], LOW);  // Apaga o mesmo
      } else if (i == 3) {
        digitalWrite(ledPins[4], LOW);  // Apaga o mesmo
      } else if (i == 4) {
        digitalWrite(ledPins[5], LOW);  // Apaga o mesmo
      } else if (i == 5) {
        digitalWrite(ledPins[0], LOW);  // Apaga o mesmo
      }

    } else if (c == 6) {
      c = 0;

      vitorias++;
      if (vitorias == 2) {
        counter = 0;
        vitorias = 0;
        digitalWrite(ledPins[6], LOW);
        digitalWrite(ledPins[7], LOW);
        delay(500);
        return;
      }
    }

    digitalWrite(ledPins[i], HIGH);  // Acende o respectivo LED
    if (digitalRead(ledPins[i]) == HIGH) {
      tone(buzzerPin, som[z]);  // Toca a nota correspondente
      delay(p / 2);             // Espera metade do tempo de piscada
      noTone(buzzerPin);        // Deixa de tocar a nota
    }
    delay((p / 2) + (p / 2) * c);       // Espera metade do tempo de piscada
    digitalWrite(ledPins[i - c], LOW);  // Apaga o mesmo
  }
}



void loop() {
  for (int counter = 0; counter <= 6;) {
    digitalWrite(ledPins[6], LOW);
    digitalWrite(ledPins[7], LOW);
    if (z == true) {
      Timer1.initialize(1200000);          // Configura Timer para 1200ms (1.200.000 microssegundos)
      Timer1.attachInterrupt(piscarLEDs);  // Ativa interrupção a cada 500ms
      Serial.println(counter);             // Mostrar esse número no Serial Monitor

      if (estadoLEDs == true) {
        digitalWrite(ledPins[c], LOW);  // Acende o respectivo LED
      } else {
        digitalWrite(ledPins[c], HIGH);  // Acende o respectivo LED
      }
      if (estadoLEDs == true) {
        digitalWrite(ledPins[c - 1], HIGH);  // Acende o respectivo LED
      } else {
        digitalWrite(ledPins[c - 1], LOW);  // Acende o respectivo LED
      }

      if (digitalRead(buttonPin) == HIGH) {  // Se o botão for pressionado
        counter++;
        delay(80);
      }

      if ((digitalRead(buttonPin) == LOW) && (counter >= 1 && counter <= 4)) {
        if (estadoLEDs == true) {
          digitalWrite(ledPins[c], HIGH);  // Acende o respectivo LED
        } else {
          digitalWrite(ledPins[c], LOW);  // Acende o respectivo LED
        }

        c++;
        if (c == 6) {
          c = 0;
        }

        tone(buzzerPin, 108);
        delay(60);          // Espera 60 mili segundos
        noTone(buzzerPin);  // Deixa de tocar a nota
        counter = 0;

      } else if ((counter > 4) && ((digitalRead(buttonPin) == LOW) || (digitalRead(buttonPin) == HIGH))) {
        a = !a;
        counter = 0;
        Timer1.stop();
        giraRoleta();
      }


    } else {
      Serial.println(counter);         // Mostrar esse número no Serial Monitor
      digitalWrite(ledPins[c], HIGH);  // Acende o respectivo LED

      if (digitalRead(buttonPin) == HIGH) {  // Se o botão for pressionado
        counter++;
        delay(80);
      }

      if ((digitalRead(buttonPin) == LOW) && (counter >= 1 && counter <= 4)) {
        digitalWrite(ledPins[c], LOW);  // Apaga o mesmo
        c++;                            // O "interruptor" marcará 'true'
        tone(buzzerPin, som[z]);        // Toca a nota correspondente
        delay(60);                      // Espera 60 mili segundos
        noTone(buzzerPin);              // Deixa de tocar a nota

        if (c == 6) {
          c = 0;
        }
        counter = 0;

      } else if ((counter > 4) && ((digitalRead(buttonPin) == LOW) or (digitalRead(buttonPin) == HIGH))) {
        a = !a;
        counter = 0;
        Timer1.stop();
        giraRoleta();
      }
    }
  }
}
