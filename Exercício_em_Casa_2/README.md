# Montagem Básica de Contagem de Pressionamentos de Botão


## Descrição
Este projeto demonstra como contar o número de vezes que um botão é pressionado utilizando um Arduino. O objetivo é detectar as transições do estado do botão de desligado (LOW) para ligado (HIGH) e contabilizar cada pressionamento. Os resultados são exibidos no Serial Monitor, permitindo monitorar a contagem em tempo real.
> *A montagem do circuito desse exercício é coincidente à vista em [Exercício_em_Casa_1](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Casa_1). Alem disso, nesse projeto, optei por usar o modelo [pull-dow](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-dow.png), mas não se pode descartar a possibilidade do uso de [pull-up](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-up.png) com algumas alterações na montagem e no código.*


## Componentes Utilizados
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 LED (integrado no pino 13)**
- **1 Botão (integrado no pino 5)**
- **1 Resistor de 10 kΩ (pull-dow)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 5 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

2. **Configuração do Resistor pull-dow**:
   - Conecte um resistor de 10 kΩ entre o pino 5 (onde o botão está conectado) e o GND (terra). Isso garantirá que o pino 5 esteja em um estado baixo quando o botão não estiver pressionado.

3. **Diagrama de montagem:**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-dow.png)
<details>
<summary> :dvd: Teste Prático: Circuito Pull-dow </summary>

https://github.com/user-attachments/assets/957b440d-5a92-4934-900a-3db9f1c8c693


</details>


## Código Comentado
```cpp
// Definindo os pinos e algumas variáveis
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão
int PushCounter = 0; // Contador
int LastState = 0; // Estado anterior
int Estbutton = 0; // Estado atual

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}

void loop() {
Estbutton = digitalRead(buttonPin); // Sincronizando o estado do botão a leitura atual do mesmo
  if ((LastState == LOW) && (Estbutton == HIGH)) { // Se houver uma transição positiva (negativo -> positivo)
    PushCounter++; // Soma 1 à variável "PushCounter"
    digitalWrite(ledPin, HIGH); // Acende o LED
    Serial.print("Número de apertadas no botão:"); // Printa a informação no serial monitor
    Serial.println(PushCounter); 
  }
  if (Estbutton == LOW)  { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
    }
  delay(50);
LastState = Estbutton; //Save State
}
````


## Funcionamento
> Este projeto visa contar o número de pressões de um botão utilizando o Arduino, acendendo e apagando um LED conforme o botão é pressionado. O número de pressões é exibido no **Serial Monitor**. O código utiliza detecção de transições de estado para garantir que cada pressionamento seja contado corretamente.
1. **Configuração Inicial:**
   O pino 13 é configurado como **saída** para controlar o LED, e o pino 5 como **entrada** para o botão. O LED começa apagado (estado **LOW**), e a comunicação serial, que envia enviar dados a 9600bps, é ativada para exibir a contagem de pressionamentos no Serial Monitora.
   
2. **Leitura do Estado do Botão:**
   O estado do botão é lido a cada ciclo do **loop()** e armazenado na variável `Estbutton`. O valor pode ser **HIGH** (botão pressionado) ou **LOW** (botão não pressionado).

3. **Detecção de Transição de Estado (Pressionamento):**
   O código verifica se houve uma **transição de LOW para HIGH**, ou seja, se o botão foi pressionado. Isso é feito com a condição:
     ```cpp
     if ((LastState == LOW) && (Estbutton == HIGH))
     ```
      > Quando essa transição é detectada, a variável `PushCounter` é incrementada em 1, e o LED é aceso. O número de pressões do botão é então impresso no **Serial Monitor**.

4. **Controle do LED:**
   Se o botão estiver pressionado (`Estbutton == HIGH`), o LED é aceso com **`digitalWrite(ledPin, HIGH)`**. Caso contrário, se o botão não estiver pressionado (`Estbutton == LOW`), o LED é apagado com **`digitalWrite(ledPin, LOW)`**.
   
5. **Debouncing:**
   O comando `delay(50)` é usado para criar um pequeno atraso de 50 milissegundos, que ajuda a evitar múltiplas leituras indesejadas do botão (debouncing simples).
   
6. **Atualização do Estado Anterior (save):**
   O estado do botão é armazenado na variável `LastState` para ser comparado na próxima iteração do loop e detectar a próxima transição.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 26/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.


### Aviso de Direitos Autorais 
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "Runnin' Away, Runnin' Away" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).

