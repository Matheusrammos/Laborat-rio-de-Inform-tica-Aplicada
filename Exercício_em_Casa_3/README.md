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
![fotodbid](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_3/Diagrama_Casa_3.jpeg)

## Código Comentado
```cpp
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


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 20/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.

