# Montagem Básica com LEDs e Botão

## Descrição do Projeto: Controle de LED com Botão usando Arduino
Este projeto demonstra como controlar um LED integrado no pino 13 de uma placa Arduino por meio de um botão. Ao pressionar o botão, o LED acende, proporcionando uma interação simples e eficaz com o microcontrolador. A configuração utiliza um resistor pull-up (ou pull-dow) de 10 kΩ para garantir que a entrada digital do Arduino seja lida corretamente, evitando flutuações indesejadas no sinal.

### O que são resistores pull-up e pull-dow?
- Resistores pull-down e pull-up são usados para garantir que um pino de entrada digital tenha um estado lógico definido (LOW ou HIGH) quando nenhum sinal está sendo enviado.

**Pull-down:** Conecta o pino ao GND (0V) através de um resistor, forçando o estado LOW quando o botão ou outro dispositivo está aberto.

**Pull-up:** Conecta o pino ao 5V (ou VCC) através de um resistor, forçando o estado HIGH quando o botão ou dispositivo está aberto.
Eles evitam estados flutuantes que podem causar leituras instáveis ou interferências.


## Componentes Utilizados
### Ultilizando um resistor Pull-up:
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão (integrado no pino 5)**
- **1 Resistor de 10 kΩ (pull-up)**
- **Fios de conexão (jumpers)**
- **Protoboard**

### Ultilizando um resistor Pull-dow:
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão (integrado no pino 5)**
- **1 Resistor de 10 kΩ (pull-dow)**
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
// Definindo os pinos
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, HIGH);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Se o botão for precionado
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
  }
}
````

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


