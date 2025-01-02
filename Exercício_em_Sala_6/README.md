# Pisca-Pisca Led aleatório de 4 canais


## Descrição
O projeto consiste em um circuito com quatro LEDs e um botão conectado a um Arduino. O código controla os LEDs para que pisquem de forma aleatória enquanto o botão estiver pressionado. Quando o botão é solto, todos os LEDs são apagados. A função `random()` é usada para selecionar qual LED acender, e a lógica monitora o estado do botão para alternar entre piscar os LEDs e apagá-los.


## Objetivo
Este projeto faz com que quatro LEDs pisquem aleatoriamente sempre que o botão for pressionado. A função random(min, max) é usada para gerar aleatoriamente os pinos dos LEDs, e a contagem de tempo entre o acendimento e apagamento é controlada com delay(). O código utiliza a variável a para armazenar o pino do LED que será acionado a cada iteração.


## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **4 LEDs**
- **4 resistores de 220 Ω**
- **1 resistor de 10 KΩ (pull-dow)**
- **1 botão**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 3 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

2. **Configuração do Resistor pull-dow**:
   - Conecte um resistor de 10 kΩ entre o pino 3 (onde o botão está conectado) e o GND (terra). Isso garantirá que o pino 5 esteja em um estado baixo quando o botão não estiver pressionado.

3. **Conexão dos LEDs:**
   - Conecte os ânodos (terminais positivos) dos LEDs aos pinos digitais 8, 9, 10 e 11 do Arduino.
   - Conecte os cátodos (terminais negativos) dos LEDs ao GND (terra) do Arduino através de resistores de 220 Ω.

4. **Diagrama de montagem:**
![fotoddfd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_6/Diagrama_Aula_6.png)
<details>
<summary> :dvd: Teste Prático: Pisca-Pisca Led aleatório de 4 canais </summary>

[Pisca-Pisca Led aleatório de 4 canais](https://github.com/user-attachments/assets/a67398cb-376a-404c-8098-02cf144e1a35)
</details>



## Código Comentado

```cpp
// Definição dos pinos dos LEDs
const int led1 = 8; // Pino do LED 1
const int led2 = 9; // Pino do LED 2
const int led3 = 10; // Pino do LED 3
const int led4 = 11; // Pino do LED 4

// Definição do pino do botão
const int buttonPin = 3; // Pino do botão

// Variável para armazenar o valor aleatório
long a; // Variável para o pino do LED a ser acionado


void setup() {
  // Inicializa o pino do botão como entrada
  pinMode(buttonPin, INPUT); 
  
  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios

  // Inicializa os pinos dos LEDs como saídas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}


void loop() {
  // Usando um loop for para repetir indefinidamente enquanto o botão estiver pressionado
  for (; digitalRead(buttonPin) == HIGH;) { //Também poderia ser o seguinte comando:    while (digitalRead(buttonPin) == LOW) {   
    a = random(8, 12); // Gera um número aleatório entre 8 e 11 (pinos dos LEDs)
    digitalWrite(a, HIGH); // Acende o LED correspondente
    delay(500); // Aguarda por um período de tempo
    digitalWrite(a, LOW); // Apaga o LED
    delay(500); // Aguarda por um período de tempo antes de repetir 
  }
  
  // Apaga todos os LEDs quando o botão não estiver pressionado
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
```
<details>
<summary> :cyclone: Código desenvolvido pelo aluno </summary>

```cpp
// Definição dos pinos dos LEDs
const int ledPins[] = {8, 9, 10, 11}; // Pino do LED 1, 2, 3 e 4.

// Definição do pino do botão
const int buttonPin = 3; // Pino do botão

long i; // Variável para o pino do LED a ser acionado


void setup() {
  // Inicializa o pino do botão como entrada
  pinMode(buttonPin, INPUT);

  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios

  // Inicializa os pinos dos LEDs como saídas
  for (; i < 4; i++) { 
    pinMode(ledPins[i], OUTPUT); 
  }
}


void loop() {
  // Usando um loop for para repetir indefinidamente enquanto o botão for pressionado
  while (digitalRead(buttonPin) == LOW) { //Também poderia ser o seguinte comando:   for (;digitalRead(buttonPin) == HIGH;) {
    i = random(0, 4); // Gera um número aleatório de 0 a 3 (4 números)
    digitalWrite(ledPins[i], HIGH); // Acende o LED correspondente
    delay(500); // Aguarda por um período de tempo
    digitalWrite(ledPins[i], LOW); // Apaga o LED
    delay(500); // Aguarda por um período de tempo antes de repetir
  }
}
````
</details>






## Funcionamento
> O código faz com que quatro LEDs pisquem aleatoriamente enquanto o botão está pressionado. Quando o botão é pressionado, um número aleatório entre 8 e 11 é gerado, determinando qual LED acender. O LED acende por 500 milissegundos, apaga, e depois repete o processo. Esse ciclo continua até o botão ser liberado, momento em que todos os LEDs são apagados. O gerador de números aleatórios é inicializado com a leitura do pino analógico 0 para garantir aleatoriedade. O controle do LED e a leitura do botão são feitos com as funções `digitalWrite()` e `digitalRead()`.
1. **Definição de Pinos e Variáveis**
   - `led1`, `led2`, `led3`, `led4`: Representam os pinos digitais onde os LEDs estão conectados (8, 9, 10, 11).
   - `buttonPin`: Pino digital 3, que é usado para o botão.
   - `a`: Variável do tipo `long` que armazenará o valor aleatório gerado pela função `random()`, determinando qual LED acender.
   
2. **Configuração Inicial (Setup)**
   - Os pinos dos LEDs são configurados como **saídas** (`pinMode(led1, OUTPUT)` e os outros LEDs).
   - O pino do botão é configurado como **entrada** (`pinMode(buttonPin, INPUT)`).
   - A função `randomSeed(analogRead(0))` inicializa o gerador de números aleatórios.

3. **Geração Aleatória de LED**
   - A função `random(8, 12)` gera um número aleatório entre 8 e 11, correspondendo aos pinos dos LEDs. Em Arduino, a função `random(min, max)` retorna um número inteiro aleatório no intervalo de `[min, max-1]`. Ou seja, o valor gerado começa no valor de `min` (inclusive) e vai até **um a menos que o valor de `max`** (exclusivo).
   - O LED correspondente ao número gerado é aceso com `digitalWrite(a, HIGH)` e apagado após 500 milissegundos com `digitalWrite(a, LOW)`.

4. **Controle do Botão**
   - Enquanto o botão estiver **pressionado** (o pino de leitura digital do botão for **HIGH**), o loop executará a sequência de LEDs piscando aleatoriamente.
   - Quando o botão é liberado (o pino de leitura digital do botão for **LOW**), todos os LEDs são apagados com `digitalWrite(led1, LOW)` e assim por diante.

5. **Uso de `delay()`**
   - O comando `delay(500)` é usado para criar uma pausa de 500 milissegundos entre o acendimento e apagamento de cada LED, e outra pausa entre as repetições do loop.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 27/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.

### Aviso de Direitos Autorais
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "Walkin' the Dog" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).

