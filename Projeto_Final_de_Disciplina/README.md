# Roleta com LEDs

## Descrição
Este projeto simula uma roleta luminosa utilizando seis LEDs e um botão, com controle de velocidade e parada gradual. A roleta é acionada ao pressionar o botão, e os LEDs piscam sequencialmente, desacelerando até que um LED final seja destacado como o "vencedor". A interface com o Serial Monitor permite acompanhar o número gerado aleatoriamente.


## Materiais Necessários
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **6 LED (integrado aos pinos de 3 a 8)**
- **1 Botão (integrado no pino 13)**
- **6 Resistor de 220 Ω**
- **1 Resistor de 10 kΩ (pull-dow)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conexão dos LEDs:**
   - Conecte o ânodo (lado maior) no respéctivo pino de forma horária.
   - Conecte o cátodo (lado menor) ao GND.
     
2. **Conectar o Botão:** 
   - Um terminal do botão deve ser conectado ao pino digital 13 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

3. **Configuração do Resistor pull-dow**:
   - Conecte um resistor de 10 kΩ entre o pino 13 (onde o botão está conectado) e o GND (terra). Isso garantirá que o pino 13 esteja em um estado baixo quando o botão não estiver pressionado.

4. **Diagrama de montagem:**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Projeto_Final_de_Disciplina/Diagrama_TRFinal.png)
![sh](https://github.com/Matheusrammos/LIA-Docs/blob/main/Projeto_Final_de_Disciplina/Circuito_Digital.png)


## :cyclone: Código Comentado
```cpp
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
````


### Funcionamento

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
   - Os LEDs acendem e apagam sequencialmente em um ciclo controlado pelo valor de `x`. A velocidade é ajustada dinamicamente com base no cálculo `p = 1000 / x`.
   - O número `x` diminui gradualmente a cada ciclo, fazendo com que a roleta desacelere.

5. **Finalização:**
   - Quando `x` atinge 0, a roleta para, e o LED atual pisca algumas vezes para indicar o resultado final.
   - Após o LED piscar, a roleta aguarda 3 segundos antes de ser desativada completamente.

6. **Reinício:**
   - O processo pode ser reiniciado pressionando o botão novamente.
