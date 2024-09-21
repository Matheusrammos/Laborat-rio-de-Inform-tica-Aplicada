# Montagem Básica com LEDs


## Descrição
Este projeto utiliza um Arduino Uno para acender três LEDs conectados aos pinos 4, 5 e 6 de forma sequencial. Cada LED permanece aceso por 1 segundo antes que o próximo seja ativado. Após o terceiro LED acender, o ciclo se reinicia, repetindo indefinidamente.


## Objetivo
O objetivo deste projeto é aprender a controlar múltiplos LEDs com um Arduino Uno, acendendo-os sequencialmente. Isso ajuda a entender o controle digital, praticar a programação e a montagem de circuitos, além de familiarizar-se com o uso de resistores.


## Materiais Necessários
- **1 Arduino Uno**
- **3 LEDs**
- **3 Resistores de 220 Ω (para limitar a corrente dos LEDs)**
- **Fios de conexão (jumpers)**
- **1 Protoboard**


## Montagem do Circuito
#### Organização do Circuito:
   - Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
   - Use fios de conexão (jumpers) para ligar os componentes ao Arduino.

1. **Conexões dos LEDs:**

   **Primeiro LED:**
    - Conecte o ânodo (terminal positivo) ao pino digital 4 do Arduino através de um resistor de 220 Ω.
    - Conecte o cátodo (terminal negativo) a um resistor.
   
   **Segundo LED:**
   - Conecte o ânodo ao pino digital 5 do Arduino através de um resistor de 220 Ω.
   - Conecte o cátodo a outro resistor.
     
   **Terceiro LED:**
   - Conecte o ânodo ao pino digital 6 do Arduino através de um resistor de 220 Ω.
   - Conecte o cátodo ao terceiro resistor.

2. **Conexões dos Resistores:**
   - Os resistores  de 220 Ω, separadamente, devem ser conectados a extremidade de cada ânodo de cada LED. A extremidade restante do resistor deve ser conectada ao GND do Arduino.

3. **Diagrama do Circuito:**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_3/Diagrama_Aula_3.jpeg)

## Código Comentado
```cpp
// Define os pinos dos LEDs
const int led1Pin = 4; // Pino do primeiro LED
const int led2Pin = 5; // Pino do segundo LED
const int led3Pin = 6; // Pino do terceiro LED

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  // Acende o primeiro LED
  digitalWrite(led1Pin, HIGH);
  delay(1000); // Aguarda 1 segundo
  digitalWrite(led1Pin, LOW); // Apaga o primeiro LED

  // Acende o segundo LED
  digitalWrite(led2Pin, HIGH);
  delay(1000); // Aguarda 1 segundo
  digitalWrite(led2Pin, LOW); // Apaga o segundo LED

  // Acende o terceiro LED
  digitalWrite(led3Pin, HIGH);
  delay(1000); // Aguarda 1 segundo
  digitalWrite(led3Pin, LOW); // Apaga o terceiro LED
}
````

## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar o conteúdo deste projeto.


