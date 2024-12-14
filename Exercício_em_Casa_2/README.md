# Montagem Básica de Contagem de Pressionamentos de Botão


## Descrição
Este projeto demonstra como contar o número de vezes que um botão é pressionado utilizando um Arduino. O objetivo é detectar as transições do estado do botão de desligado (LOW) para ligado (HIGH) e contabilizar cada pressionamento. Os resultados são exibidos no Serial Monitor, permitindo monitorar a contagem em tempo real.
> *A montagem do circuito é coincidente ao [Exercício_em_Casa_1](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Casa_1). Porém, nesse projeto, optei por usar o modelo [pull-dow](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-dow.png).*

## Materiais Necessários
- **1 Arduino Uno**
- **1 Botão de pressão**
- **1 Resistor de 10 kΩ (pull-up)**
- **Fios de conexão (jumpers)**
- **Protoboard (opcional)**


## Montagem do Circuito
#### Organização do Circuito:
   - Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
   - Use fios de conexão (jumpers) para ligar os componentes ao Arduino.
     
1. **Conexões do Botão:**
   - Conecte um terminal do botão ao pino digital 2 do Arduino.
   - Conecte o outro terminal do botão a uma fonte de 5V.

2. **Conexões do Resistor:**
   - Conecte um resistor de 10 kΩ entre o pino 2 e o GND para configurar o resistor pull-up.

3. **Diagrama do Circuito:**
   
![fotodbid](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_2/Diagrama_Casa_2.jpeg)

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
O programa opera da seguinte maneira:
1. **Leitura do Estado do Botão:** A cada iteração do loop principal, o Arduino lê o estado atual do botão.
2. **Comparação de Estados:** O estado atual do botão é comparado com o estado anterior, que é armazenado em uma variável.
3. **Detecção de Pressionamento:** Se o estado atual for diferente do estado anterior e for igual a HIGH, o contador de pressionamentos é incrementado.
4. **Exibição no Serial Monitor:** A cada incremento, o valor da contagem é enviado ao Serial Monitor, permitindo a visualização imediata do número de pressões.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 19/09/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.
