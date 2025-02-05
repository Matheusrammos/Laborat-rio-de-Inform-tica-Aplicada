# Piano com LEDs: tomada de decisão com entradas digitais 


## Descrição
Este projeto utiliza um Arduino para implementar uma "tomada de decisão" através de botões, onde cada botão aciona um LED e toca uma nota musical correspondente via buzzer. Quando um dos botões (conectados aos pinos digitais) é pressionado, o LED associado se acende e o buzzer emite o som da nota definida para aquele botão. Ao soltar o botão, o LED se apaga e o buzzer para de tocar.


## Objetivo
O objetivo deste projeto é demonstrar como ler entradas digitais e tomar decisões no Arduino. Através desse circuito, aprende-se a:
- Configurar botões com resistores pull-up ou pull-dow (pull-dow neste caso);
- Acionar LEDs e buzzer com base na leitura dos botões;
- Utilizar arrays para organizar múltiplos pinos e notas;
- Integrar controle de som e iluminação para simular um piano básico.


## Materiais Necessários
- **1 Arduino Uno (ou placa compatível)**
- **3 LEDs**
- **3 Resistores de 220 Ω a 330 Ω** (para limitar a corrente dos LEDs)
- **3 Resistores de 10 KΩ (pull-dow)**
- **3 Botões**
- **1 Buzzer**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **LEDs:**
   - Conecte os LEDs aos pinos **11, 12 e 13** do Arduino, cada um em série com um resistor (220Ω a 330Ω) para limitar a corrente e proteger os LEDs.
   
2. **Botões:**
   - Conecte os botões aos pinos **2, 3 e 4** do Arduino.
   - Utilize os resistores pull-up internos configurados com `INPUT_PULLUP` no código, eliminando a necessidade de resistores externos.
   
3. **Buzzer:**
   - Conecte o buzzer ao pino **9** do Arduino.

4. **Observações:**
   - Certifique-se de conectar os LEDs com os resistores em série para evitar queima por corrente excessiva.
   - Verifique se os botões estão corretamente configurados para uso dos resistores pull-dow, garantindo que, quando não pressionados, o pino fique em estado **LOW** e, ao serem pressionados, em **HIGH**.

5. **Diagrama do Circuito:**  
![Diagrama do Circuito](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_8/Diagrama_Aula_8.png)



## Código Comentado

```cpp
// Declaração dos pinos dos LEDs
const int ledPins[] = {11, 12, 13}; // Pinos dos LEDs

// Declaração dos pinos dos botões
const int buttonPins[] = {2, 3, 4}; // Pinos dos botões

// Declaração do pino do buzzer
const int buzzerPin = 9; // Pino do buzzer

// Declaração das notas a serem tocadas (frequências em Hz)
const int notes[] = {261, 329, 392}; // Notas: C4, E4, G4

void setup() {
  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura os pinos dos botões como entrada com resistor pull-dow externo
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  
  // Configura o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Percorre os botões e LEDs correspondentes
  for (int i = 0; i < 3; i++) {
    // Se o botão estiver pressionado (estado HIGH)
    if (digitalRead(buttonPins[i]) == HIGH) { 
      digitalWrite(ledPins[i], HIGH); // Liga o LED correspondente
      tone(buzzerPin, notes[i]);       // Toca a nota correspondente no buzzer
    } else {
      digitalWrite(ledPins[i], LOW);   // Desliga o LED correspondente
      noTone(buzzerPin);               // Para de tocar o buzzer
    }
  }
}
```


## Funcionamento
> O projeto consiste em ler a entrada de três botões e, para cada botão pressionado, acionar um LED e tocar uma nota musical no buzzer.
1. **Declaração de Variáveis:**
   - `ledPins[]`: Armazena os números dos pinos onde os LEDs estão conectados (11, 12 e 13).
   - `buttonPins[]`: Armazena os números dos pinos onde os botões estão conectados (2, 3 e 4).
   - `buzzerPin`: Define o pino do Arduino conectado ao buzzer (9).
   - `notes[]`: Armazena as frequências (em Hz) das notas que o buzzer tocará (261 Hz para C4, 329 Hz para E4 e 392 Hz para G4).

2. **Configuração Inicial (setup):**
   - Os pinos dos LEDs são configurados como saídas.
   - Os pinos dos botões são configurados como entradas utilizando o `INPUT` e também um resistor pull-dow externo. Assim, quando os botões não estão pressionados, o estado dos pinos é LOW, e ao serem pressionados, o estado muda para HIGH.
   - O pino do buzzer é configurado como saída.

3. **Laço Principal (loop):**
   - O código percorre todos os botões e, se um botão estiver pressionado (digitalRead retorna HIGH), o LED correspondente é aceso e o buzzer toca a nota associada.
   - Se o botão não estiver pressionado, o LED é apagado e o buzzer para de emitir som.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, que colaborou com orientações e sugestões durante o desenvolvimento e elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: [ChatGPT - OpenAI](https://www.openai.com/chatgpt). Acesso em: 05/02/2025.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.
