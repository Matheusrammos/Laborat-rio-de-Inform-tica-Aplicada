# Montagem Básica com LEDs e Botão

## Descrição do Projeto: Controle de LED com Botão usando Arduino
Este projeto demonstra como controlar um LED integrado no pino 13 de uma placa Arduino por meio de um botão. Ao pressionar o botão, o LED acende, proporcionando uma interação simples e eficaz com o microcontrolador. A configuração utiliza um resistor pull-up (ou pull-dow) de 10 kΩ para garantir que a entrada digital do Arduino seja lida corretamente, evitando flutuações indesejadas no sinal.

### O que são resistores pull-up e pull-dow?
- Resistores pull-down e pull-up são usados para garantir que um pino de entrada digital tenha um estado lógico definido (LOW ou HIGH) quando nenhum sinal está sendo enviado.

   - **Pull-down:** Conecta o pino ao GND (0V) através de um resistor, forçando o estado LOW quando o botão ou outro dispositivo está aberto.

   - **Pull-up:** Conecta o pino ao 5V (ou VCC) através de um resistor, forçando o estado HIGH quando o botão ou dispositivo está aberto.
Eles evitam estados flutuantes que podem causar leituras instáveis ou interferências.

   > ![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull_resistors.jpg)



## Componentes Utilizados
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão (integrado no pino 5)**
- **1 Resistor de 10 kΩ (pull-up ou pull-dow)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
### Ultilizando um resistor pull-up:
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 5 do Arduino.
   - O outro terminal do botão deve ser conectado ao GND (terra) da placa.

2. **Configuração do Resistor pull-up**:
   - Conecte um resistor de 10 kΩ entre o pino 5 (onde o botão está conectado) e o VCC (5V). Isso garantirá que o pino 2 esteja em um estado alto quando o botão não estiver pressionado.

3. **Diagrama de montagem**
   - *Ultilizando um resistor pull-up:*
      > ![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-up.png)


### Ultilizando um resistor pull-dow:
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 5 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

2. **Configuração do Resistor pull-dow**:
   - Conecte um resistor de 10 kΩ entre o pino 5 (onde o botão está conectado) e o GND (terra). Isso garantirá que o pino 5 esteja em um estado baixo quando o botão não estiver pressionado.


3. **Diagrama de montagem**
   - *Ultilizando um resistor pull-dow:*
      > ![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-dow.png)


## Código Comentado
### Ultilizando um resistor pull-up:
```cpp
// Definindo os pinos
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Se o botão for precionado*********************
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
  }
}
````

### Ultilizando um resistor pull-dow:
```cpp
// Definindo os pinos
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Se o botão for precionado*********************
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
  }
}
````

## Funcionamento
Aqui está uma explicação no formato solicitado, adaptada para o seu código:

## Funcionamento
###  Ultilizando um resistor Pull-up:
> O projeto de controle de LED com botão, utilizando o **pull-up** interno, opera de maneira simples e eficaz. Abaixo estão os principais passos que descrevem seu funcionamento:
1. **Configuração Inicial:**  
   O Arduino é configurado para monitorar o pino digital 5, onde o botão está conectado. O pino 13 é configurado como a saída para controlar o LED. O estado inicial do LED é **LOW** (apagado). O pino do botão é configurado como **entrada com pull-up** usando a configuração **`pinMode(buttonPin, INPUT)`**, e o resistor pull-up interno é ativado automaticamente.
2. **Leitura do Estado do Botão:**  
   A cada iteração do loop principal, o Arduino lê o estado atual do botão com o comando **`digitalRead(buttonPin)`**. O estado do botão pode ser "HIGH" (botão não pressionado, devido ao pull-up) ou "LOW" (botão pressionado, puxando para o GND).
3. **Comparação de Estados:**  
   O código verifica se o botão está em **LOW** (pressionado). Isso ocorre porque, com o **pull-up interno** ativado, o pino do botão fica em **HIGH** quando não pressionado e vai para **LOW** quando pressionado.
4. **Detecção de Pressionamento:**  
   Quando o botão é pressionado, o estado do pino do botão será **LOW**, indicando que há uma conexão com o GND. Nesse momento, o código acende o LED com o comando **`digitalWrite(ledPin, HIGH)`**.
5. **Exibição do Estado do LED:**  
   Se o botão estiver pressionado (**LOW**), o LED será aceso. Caso contrário, quando o botão não estiver pressionado (**HIGH**), o LED será apagado.
6. **Atualização do Estado Anterior:**  
   Não há necessidade de uma variável para comparar o estado anterior, pois o código apenas verifica continuamente o estado atual do botão. Se o botão for pressionado, o LED acende, e se não for pressionado, o LED apaga.

###  Ultilizando um resistor Pull-dow:
> O projeto de controle de LED com um botão opera de forma simples e eficaz. Abaixo estão os principais passos que descrevem seu funcionamento:
1. **Configuração Inicial:** 
   O Arduino é configurado para monitorar o pino digital 5, onde o botão está conectado. O pino do LED (pino 13) é configurado como saída. O estado inicial do LED é **LOW** (desligado).
2. **Leitura do Estado do Botão:** 
   A cada iteração do loop principal, o Arduino lê o estado atual do botão com o comando **`digitalRead(buttonPin)`**. O estado do botão pode ser "HIGH" (botão pressionado) ou "LOW" (botão não pressionado).
3. **Comparação de Estados:** 
   O estado do botão é comparado a **HIGH** ou **LOW**. Quando o botão é pressionado, o pino de entrada do botão recebe **HIGH**. Caso contrário, ele está em **LOW**.
4. **Detecção de Pressionamento:** 
   Quando o botão está pressionado, o estado do pino do botão será **HIGH**, e o código entra no bloco do `if`. Nesse momento, o LED é aceso, com o comando **`digitalWrite(ledPin, HIGH)`**.
5. **Exibição do Estado do LED:** 
   Se o botão estiver pressionado, o LED acende. Caso o botão não esteja pressionado, o LED apaga, com o comando **`digitalWrite(ledPin, LOW)`**.
6. **Atualização do Estado Anterior:** 
   Não há um armazenamento explícito de estados anteriores do botão nesse código, pois ele apenas verifica o estado atual do botão a cada iteração do loop. O comportamento do LED depende diretamente do estado atual do botão, sem a necessidade de variáveis de comparação.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.


