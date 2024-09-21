# Enviando Dados para a Porta Serial

## Descrição
Este diretório contém o terceiro exercício de casa, onde demonstramos como enviar dados para a porta serial. Neste código, ao pressionar o botão, o LED integrado no pino 13 da placa Arduino é acionado.

## Materiais Necessários
- **1 Arduino Uno**
- **1 Botão de pressão**
- **1 Resistor de 10 kΩ (pull-up)**
- **Fios de conexão (jumpers)**
- **Protoboard (opcional)**


## Montagem do Circuito

1. **Esquema de Montagem:**

- O botão é conectado ao pino 2 (ou qualquer outra entrada digital) com um resistor de pull-up de 10 kΩ.
- O resistor pull-up está conectado ao GND. O outro pino do botão está conectado a uma fonte de alimentação de 5V.

2. **Diagrama do Circuito:**


Código Comentado
````
const int buttonPin = 2;  // Pino onde o botão está conectado
const int ledPin = 13;    // Pino do LED integrado
int buttonState;           // Estado atual do botão

void setup() {
  Serial.begin(9600);     // Inicializa a porta serial a 9600 bps
  pinMode(buttonPin, INPUT); // Define o pino do botão como entrada
  pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  buttonState = digitalRead(buttonPin); // Lê o estado atual do botão

  if (buttonState == HIGH) { // Se o botão estiver pressionado
    digitalWrite(ledPin, HIGH); // Liga o LED
    Serial.println("Botão pressionado"); // Envia o estado para a porta serial
  } else {
    digitalWrite(ledPin, LOW); // Desliga o LED
  }
}
````

## Funcionamento
1. **Setup:** Inicializa a porta serial a 9600 bps para comunicação entre a placa Arduino e o computador. Também inicializa o pino digital 2 como entrada para ler o estado do botão e o pino 13 como saída para controlar o LED.
2. **Leitura do Botão:** Quando o botão é pressionado, a entrada no pino 2 recebe 5V (sinal HIGH). Caso contrário, o pino é conectado ao GND através do resistor (sinal LOW).
3. **Envio para a Porta Serial:** O estado do botão é enviado para a porta serial sempre que ele é pressionado, permitindo monitorar a contagem em tempo real.
