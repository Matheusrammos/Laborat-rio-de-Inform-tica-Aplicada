# Montagem Básica com LEDs e Botão

## Descrição do Projeto: Controle de LED com Botão usando Arduino
Este projeto demonstra como controlar um LED integrado no pino 13 de uma placa Arduino por meio de um botão. Ao pressionar o botão, o LED acende, proporcionando uma interação simples e eficaz com o microcontrolador. A configuração utiliza um resistor pull-up de 10 kΩ para garantir que a entrada digital do Arduino seja lida corretamente, evitando flutuações indesejadas no sinal.

## Componentes Utilizados
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão**
- **1 Resistor de 10 kΩ (pull-up)**
- **Fios de conexão (jumpers)**
- **Protoboard (opcional)**

## Diagrama de Conexões (MONTAGEM)
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 2 do Arduino.
   - O outro terminal do botão deve ser conectado ao GND da placa.

2. **Configuração do Resistor Pull-up**:
   - Conecte um resistor de 10 kΩ entre o pino 2 (onde o botão está conectado) e o VCC (5V). Isso garantirá que o pino 2 esteja em um estado alto quando o botão não estiver pressionado.

3. **Código Comentado**

```const int buttonPin = 2; // Pino onde o botão está conectado
const int ledPin = 13;   // Pino do LED integrado

void setup() {
  pinMode(ledPin, OUTPUT);      // Define o pino do LED como saída
  pinMode(buttonPin, INPUT);    // Define o pino do botão como entrada
  digitalWrite(buttonPin, HIGH); // Ativa o resistor pull-up
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Se o botão for pressionado
    digitalWrite(ledPin, HIGH);        // Liga o LED
  } else {
    digitalWrite(ledPin, LOW);         // Desliga o LED
  }
}
Funcionamento do Código
setup(): Inicializa os pinos do LED como saída e do botão como entrada, ativando o resistor pull-up.
loop(): Verifica constantemente o estado do botão. Se o botão estiver pressionado (estado baixo), o LED é aceso. Caso contrário, o LED é desligado.  
```

## Participações

### Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
- OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.
### [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) responsável por disponibilizar a imagem do diagrama.
