# Luzes de Sinalização de Garagem


## Descrição
Este projeto demonstra uma montagem básica utilizando um Arduino Uno e dois LEDs. O objetivo é aprender como controlar LEDs através do Arduino, ligando e desligando-os de forma sequencial. Essa prática ajuda a compreender conceitos fundamentais de programação e eletrônica.


## Objetivo
O objetivo deste projeto é aprender a controlar LEDs com um Arduino Uno, ligando e desligando-os sequencialmente. Isso permite entender o controle digital, praticar a programação básica e a montagem de circuitos em protoboard, além de compreender a função dos resistores na limitação de corrente. Essas atividades contribuem para construir uma base sólida para projetos eletrônicos futuros.


## Materiais Necessários
- **1 Arduino Uno**
- **2 LEDs**
- **2 Resistores de 220 Ω (para limitar a corrente dos LEDs)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
### Organização do Circuito:
- Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
- Use fios de conexão (jumpers) para ligar os componentes ao Arduino.

1. **Conexões dos LEDs:**
   
   **Primeiro LED:**
      - Conecte o ânodo (terminal positivo) do primeiro LED ao pino digital 2 do Arduino.
      - Conecte o cátodo (terminal negativo) do primeiro LED a um resistor de 220 Ω.

   **Segundo LED:**
      - Conecte o ânodo do segundo LED ao pino digital 3 do Arduino.
      - Conecte o cátodo do segundo LED a outro resistor de 220 Ω.
   
3. **Conexões dos Resistores**

   **Primeiro LED:**
      - Ânodo (terminal positivo): Conecte ao pino digital 2 do Arduino.
      - Cátodo (terminal negativo): Conecte a uma extremidade de um resistor de 220 Ω.
      - Outras extremidades do resistor: Conecte ao GND (terra) do Arduino.
   
   **Segundo LED:**
      - Ânodo (terminal positivo): Conecte ao pino digital 3 do Arduino.
      - Cátodo (terminal negativo): Conecte a uma extremidade de outro resistor de 220 Ω.
      - Outras extremidades do resistor: Conecte ao GND (terra) do Arduino
  
4. **Diagrama do Circuito:**
   
![fotoi](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_2/Diagrama_Aula_2.jpeg)

# Código Comentado
```cpp
// Define os pinos dos LEDs
const int led1Pin = 2; // Pino do primeiro LED
const int led2Pin = 3; // Pino do segundo LED

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  // Acende o primeiro LED
  digitalWrite(led1Pin, HIGH);
  delay(1000); // Aguarda 1 segundo

  // Apaga o primeiro LED
  digitalWrite(led1Pin, LOW);
  
  // Acende o segundo LED
  digitalWrite(led2Pin, HIGH);
  delay(1000); // Aguarda 1 segundo

  // Apaga o segundo LED
  digitalWrite(led2Pin, LOW);
}
````


## Funcionamento
1. **Configuração Inicial:** O código configura os pinos 2 e 3 como saídas no Arduino.
2. **Sequência de Ação:** O primeiro LED é aceso, aguarda 1 segundo e é apagado. Em seguida, o segundo LED é aceso, aguarda 1 segundo e é apagado.
3. **Repetição:** Essa sequência se repete indefinidamente enquanto o programa estiver em execução, permitindo observar o controle sequencial dos LEDs.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordenar o conteúdo deste projeto.

