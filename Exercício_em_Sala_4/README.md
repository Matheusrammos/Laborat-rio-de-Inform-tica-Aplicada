# Controle de Pisca-Pisca de LED com Variáveis Configuráveis

## Descrição
Este projeto utiliza um Arduino para controlar um LED conectado ao pino 10, fazendo-o piscar 3 vezes a cada 0,1 segundo (100ms) e, em seguida, apagar por 1,5 segundos (1500ms). O número de piscadas, a duração de cada piscada e a duração do apagamento são variáveis configuráveis no código, permitindo ajustes para testar diferentes comportamentos do sistema.

## Objetivo
O objetivo deste projeto é aprender a manipular o comportamento de um LED através de variáveis configuráveis em um sketch Arduino. Este exercício permite a prática de controle de tempo (com o comando `delay()`), manipulação de pinos digitais e a modificação de variáveis para alterar o comportamento do sistema.

## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **1 LED**
- **1 Resistor de 220 Ω (para limitar a corrente do LED)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**

## Montagem do Circuito
1. **Conexões do LED:**
   - Conecte o ânodo (terminal positivo) do LED ao pino digital 10 do Arduino através de um resistor de 220 Ω.
   - Conecte o cátodo (terminal negativo) do LED ao GND (terra) do Arduino.

2. **Diagrama do Circuito:**
   (Aqui você pode incluir um diagrama básico mostrando a conexão do LED ao pino 10 e GND)

## Código Comentado

```cpp
// Definição das variáveis configuráveis
const int ledPin = 10; // Pino onde o LED está conectado
int blinkCount = 3; // Número de piscadas
int blinkDuration = 100; // Duração de cada piscada em milissegundos (0.1 segundo)
int offDuration = 1500; // Duração de apagar o LED em milissegundos (1.5 segundos)

void setup() {
   pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
}

void loop() {
   int count = 0; // Inicializa o contador para o número de piscadas
   // Loop para piscar o LED
   while (count < blinkCount) {
      digitalWrite(ledPin, HIGH); // Acende o LED
      delay(blinkDuration); // Mantém o LED aceso pelo tempo especificado
      digitalWrite(ledPin, LOW); // Apaga o LED
      delay(blinkDuration); // Pausa antes de piscar novamente
      count++; // Incrementa o contador
   }
   // Aguarda com o LED apagado
   delay(offDuration); // Mantém o LED apagado pelo tempo de apagamento especificado
}
```

## Funcionamento

1. **Configuração Inicial:**
   O código começa definindo o pino de saída para o LED (pino 10) e as variáveis configuráveis `blinkCount`, `blinkDuration` e `offDuration`, que controlam o número de piscadas, o tempo de cada piscada e o tempo de apagamento do LED, respectivamente.

2. **Loop de Piscar o LED:**
   O código entra no loop principal (`loop()`) e começa a contar até o número de piscadas especificado pela variável `blinkCount`. Para cada piscada, o LED é aceso por um tempo definido pela variável `blinkDuration` e, em seguida, apagado pelo mesmo tempo. O contador de piscadas (`count`) é incrementado após cada piscada.

3. **Aguardar com LED apagado:**
   Após a quantidade de piscadas definida, o LED fica apagado por um tempo especificado pela variável `offDuration`. Esse ciclo se repete indefinidamente.

4. **Modificando as Variáveis:**
   Você pode alterar os valores das variáveis `blinkCount`, `blinkDuration` e `offDuration` para observar como o comportamento do LED muda. Por exemplo, pode-se aumentar o número de piscadas ou alterar o tempo de apagamento para ver diferentes efeitos no LED.

