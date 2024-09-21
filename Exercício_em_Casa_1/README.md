# Montagem Básica com LEDs e Botão

## Descrição do Projeto: Controle de LED com Botão usando Arduino
Este projeto demonstra como controlar um LED integrado no pino 13 de uma placa Arduino por meio de um botão. Ao pressionar o botão, o LED acende, proporcionando uma interação simples e eficaz com o microcontrolador. A configuração utiliza um resistor pull-up de 10 kΩ para garantir que a entrada digital do Arduino seja lida corretamente, evitando flutuações indesejadas no sinal.

## Componentes Utilizados
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão (integrado no pino 2)**
- **1 Resistor de 10 kΩ (pull-up)**
- **Fios de conexão (jumpers)**
- **Protoboard**


## Montagem do Circuito
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 2 do Arduino.
   - O outro terminal do botão deve ser conectado ao GND da placa.

2. **Configuração do Resistor Pull-up**:
   - Conecte um resistor de 10 kΩ entre o pino 2 (onde o botão está conectado) e o VCC (5V). Isso garantirá que o pino 2 esteja em um estado alto quando o botão não estiver pressionado.
     
3. **Diagrama de montagem**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1.jpeg)

## Código Comentado
```cpp
const int buttonPin = 2; // Pino onde o botão está conectado
const int ledPin = 13;   // Pino do LED integrado

void setup() {
  pinMode(ledPin, OUTPUT);      // Define o pino do LED como saída
  pinMode(buttonPin, INPUT_PULLUP); // Define o pino do botão como entrada com pull-up interno
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Se o botão for pressionado
    digitalWrite(ledPin, HIGH);        // Liga o LED
  } else {
    digitalWrite(ledPin, LOW);         // Desliga o LED
  }
}
```

## Funcionamento
O projeto de contagem de pressionamentos de botão opera de forma simples e eficaz. Abaixo estão os principais passos que descrevem seu funcionamento:
1. **Configuração Inicial:** O Arduino é configurado para monitorar o pino digital 2, onde o botão está conectado. A comunicação serial é iniciada para permitir a exibição de informações no Serial Monitor.
2. **Leitura do Estado do Botão:** A cada iteração do loop principal, o Arduino lê o estado atual do botão. Este estado pode ser "HIGH" (botão pressionado) ou "LOW" (botão não pressionado).
3. **Comparação de Estados:** O estado atual do botão é comparado com o estado anterior, armazenado em uma variável. Essa comparação permite detectar mudanças no estado do botão.
4. **Detecção de Pressionamento:** Quando o estado atual é "HIGH" e o estado anterior é "LOW", isso indica que o botão foi pressionado. Nesse momento, o contador de pressionamentos é incrementado.
5. **Exibição no Serial Monitor:** Após cada pressionamento, o novo valor do contador é enviado ao Serial Monitor. Isso permite ao usuário visualizar a contagem em tempo real, facilitando o acompanhamento das interações com o botão.
6. **Atualização do Estado Anterior:** Ao final de cada iteração, o estado anterior do botão é atualizado para o estado atual, preparando o sistema para a próxima leitura.

## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.


