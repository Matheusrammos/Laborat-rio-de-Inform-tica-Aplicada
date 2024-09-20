# Montagem Básica de Contagem de Pressionamentos de Botão

## Descrição
Este projeto demonstra como contar o número de vezes que um botão é pressionado utilizando um Arduino. O objetivo é detectar as transições do estado do botão de desligado (LOW) para ligado (HIGH) e contabilizar cada pressionamento. Os resultados são exibidos no Serial Monitor, permitindo monitorar a contagem em tempo real.

## Funcionamento
O programa opera da seguinte maneira:
1. **Leitura do Estado do Botão:** A cada iteração do loop principal, o Arduino lê o estado atual do botão.
2. **Comparação de Estados:** O estado atual do botão é comparado com o estado anterior, que é armazenado em uma variável.
3. **Detecção de Pressionamento:** Se o estado atual for diferente do estado anterior e for igual a HIGH, o contador de pressionamentos é incrementado.
4. **Exibição no Serial Monitor:** A cada incremento, o valor da contagem é enviado ao Serial Monitor, permitindo a visualização imediata do número de pressões.

## Materiais Necessários
- 1 Arduino Uno
- 1 Botão de pressão
- 1 Resistor de 10 kΩ (pull-up)
- Fios de conexão (jumpers)
- Protoboard (opcional)

## Montagem do Circuito
1. **Conexões do Botão:**
   - Conecte um terminal do botão ao pino digital 2 do Arduino.
   - Conecte o outro terminal do botão a uma fonte de 5V.
   - Conecte um resistor de 10 kΩ entre o pino 2 e o GND para configurar o resistor pull-up.

2. **Organização do Circuito:**
   - Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
   - Use fios de conexão (jumpers) para ligar os componentes ao Arduino.

## Código
````const int buttonPin = 2; // Pino onde o botão está conectado
int buttonState;          // Estado atual do botão
int lastButtonState = LOW; // Estado anterior do botão
int pressCount = 0;      // Contador de pressionamentos

void setup() {
  pinMode(buttonPin, INPUT); // Define o pino do botão como entrada
  Serial.begin(9600);        // Inicia a comunicação serial
}

void loop() {
  buttonState = digitalRead(buttonPin); // Lê o estado atual do botão

  // Detecta a transição de LOW para HIGH
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount++; // Incrementa o contador
    Serial.print("Contador de Pressionamentos: ");
    Serial.println(pressCount); // Exibe a contagem no Serial Monitor
  }

  lastButtonState = buttonState; // Atualiza o estado anterior
}
````
