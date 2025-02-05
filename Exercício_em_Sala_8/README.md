# Tomada de decisão com entradas digitais piano com led

## Descrição
Este projeto utiliza um Arduino para implementar uma "tomada de decisão" através de botões, onde cada botão aciona um LED e toca uma nota musical correspondente via buzzer. Quando um dos botões (conectados aos pinos digitais) é pressionado, o LED associado se acende e o buzzer emite o som da nota definida para aquele botão. Ao soltar o botão, o LED se apaga e o buzzer para de tocar.

## Objetivo
O objetivo deste projeto é demonstrar como ler entradas digitais e tomar decisões no Arduino. Através desse circuito, aprende-se a:
- Configurar botões com resistores pull-up internos;
- Acionar LEDs e buzzer com base na leitura dos botões;
- Utilizar arrays para organizar múltiplos pinos e notas;
- Integrar controle de som e iluminação para simular um piano básico.

## Materiais Necessários
- **1 Arduino Uno (ou placa compatível)**
- **3 LEDs**
- **3 Resistores de 220 Ω a 330 Ω** (para limitar a corrente dos LEDs)
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
   - Verifique se os botões estão corretamente configurados para uso com o pull-up interno, garantindo que, quando não pressionados, o pino fique em estado **HIGH** e, ao serem pressionados, em **LOW**.

> **Diagrama do Circuito:**  
> Você pode adicionar um diagrama do circuito abaixo, caso possua um link ou imagem ilustrativa.  
>  
> ![Diagrama do Circuito](#)

---

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
  
  // Configura os pinos dos botões como entrada com resistor pull-up interno
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  // Configura o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Percorre os botões e LEDs correspondentes
  for (int i = 0; i < 3; i++) {
    // Se o botão estiver pressionado (estado LOW)
    if (digitalRead(buttonPins[i]) == LOW) { 
      digitalWrite(ledPins[i], HIGH); // Liga o LED correspondente
      tone(buzzerPin, notes[i]);       // Toca a nota correspondente no buzzer
    } else {
      digitalWrite(ledPins[i], LOW);   // Desliga o LED correspondente
      noTone(buzzerPin);               // Para de tocar o buzzer
    }
  }
}
```

<details>
<summary> :cyclone: Código desenvolvido pelo aluno </summary>

```cpp
// Declaração dos pinos dos LEDs
const int ledPins[] = {11, 12, 13}; // Pinos dos LEDs

// Declaração dos pinos dos botões
const int buttonPins[] = {2, 3, 4}; // Pinos dos botões

// Declaração do pino do buzzer
const int buzzerPin = 9; // Pino do buzzer

// Declaração das notas (frequências em Hz)
const int notes[] = {261, 329, 392}; // Notas: C4, E4, G4

void setup() {
  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura os pinos dos botões como entrada com resistor pull-up interno
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  // Configura o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Verifica o estado de cada botão e atua de acordo
  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Se o botão estiver pressionado
      digitalWrite(ledPins[i], HIGH);        // Liga o LED correspondente
      tone(buzzerPin, notes[i]);              // Toca a nota correspondente
    } else {
      digitalWrite(ledPins[i], LOW);          // Desliga o LED correspondente
      noTone(buzzerPin);                      // Para de tocar o buzzer
    }
  }
}
```
</details>

---

## Funcionamento
> O projeto consiste em ler a entrada de três botões e, para cada botão pressionado, acionar um LED e tocar uma nota musical no buzzer.
1. **Declaração de Variáveis:**
   - `ledPins[]`: Armazena os números dos pinos onde os LEDs estão conectados (11, 12 e 13).
   - `buttonPins[]`: Armazena os números dos pinos onde os botões estão conectados (2, 3 e 4).
   - `buzzerPin`: Define o pino do Arduino conectado ao buzzer (9).
   - `notes[]`: Armazena as frequências (em Hz) das notas que o buzzer tocará (261 Hz para C4, 329 Hz para E4 e 392 Hz para G4).

2. **Configuração Inicial (setup):**
   - Os pinos dos LEDs são configurados como saídas.
   - Os pinos dos botões são configurados como entradas utilizando o `INPUT_PULLUP`, que ativa o resistor pull-up interno. Assim, quando os botões não estão pressionados, o estado dos pinos é HIGH, e ao serem pressionados, o estado muda para LOW.
   - O pino do buzzer é configurado como saída.

3. **Laço Principal (loop):**
   - O código percorre todos os botões e, se um botão estiver pressionado (digitalRead retorna LOW), o LED correspondente é aceso e o buzzer toca a nota associada.
   - Se o botão não estiver pressionado, o LED é apagado e o buzzer para de emitir som.

---

## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, que colaborou com orientações e sugestões durante o desenvolvimento e elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: [ChatGPT - OpenAI](https://www.openai.com/chatgpt). Acesso em: 05/02/2025.)*

---

### Aviso de Direitos Autorais
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais, se aplicável. Verifique os termos de uso dos componentes e, se necessário, consulte o arquivo [DISCLAIMER.md](./DISCLAIMER.md) para mais detalhes.

---

Este repositório está pronto para ser utilizado como base para o seu projeto "Tomada de decisão com entradas digitais piano com led". Basta copiar os arquivos e seguir as instruções para compilar e carregar o código no seu Arduino.
