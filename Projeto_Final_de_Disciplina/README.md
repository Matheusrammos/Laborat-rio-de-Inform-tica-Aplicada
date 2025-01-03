# Roleta com LEDs




```cpp
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
````


### Funcionamento do Projeto: Roleta com LEDs

> Este projeto utiliza seis LEDs conectados a um Arduino que acendem de forma sequencial, simulando uma roleta. A velocidade da roleta é determinada por um número gerado aleatoriamente, e o ciclo é interrompido gradualmente até que um LED final permaneça piscando. O botão controla o início e o fim da roleta. 
1. **Configuração Inicial:**
   - Os LEDs são conectados aos pinos digitais 3 a 8 e configurados como saídas.
   - O botão é conectado ao pino 13 e configurado como entrada.
   - O gerador de números aleatórios é inicializado usando `randomSeed(analogRead(0))` para criar a semente baseada em ruído analógico.
   - A comunicação serial é iniciada para monitoramento no Serial Monitor.

2. **Controle do Botão:**
   - O estado do botão é monitorado com `digitalRead(buttonPin)`.
   - Quando o botão é pressionado, a variável `a` é alternada entre verdadeiro (`true`) e falso (`false`), ativando ou desativando o funcionamento da roleta.

3. **Início da Roleta:**
   - Quando `a` é verdadeiro, um número aleatório `x` entre 41 e 590 é gerado.
   - Esse número controla a velocidade e o tempo total da roleta.

4. **Sequência dos LEDs:**
   - Os LEDs acendem e apagam sequencialmente em um ciclo controlado pelo valor de `x`. A velocidade é ajustada dinamicamente com base no cálculo `parado = 1000 / x`.
   - O número `x` diminui gradualmente a cada ciclo, fazendo com que a roleta desacelere.

5. **Finalização:**
   - Quando `x` atinge 0, a roleta para, e o LED atual pisca algumas vezes para indicar o resultado final.
   - Após o LED piscar, a roleta aguarda 3 segundos antes de ser desativada completamente.

6. **Reinício:**
   - O processo pode ser reiniciado pressionando o botão novamente.
