# Montagem Básica de Contagem de Pressionamentos de Botão


## Descrição
Este projeto demonstra como contar o número de vezes que um botão é pressionado utilizando um Arduino. O objetivo é detectar as transições do estado do botão de desligado (LOW) para ligado (HIGH) e contabilizar cada pressionamento. Os resultados são exibidos no Serial Monitor, permitindo monitorar a contagem em tempo real.


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
const int buttonPin = 2;      // Pino onde o botão está conectado
int buttonState;               // Estado atual do botão
int lastButtonState = LOW;     // Estado anterior do botão
int pressCount = 0;            // Contador de pressionamentos

void setup() {
  pinMode(buttonPin, INPUT);   // Define o pino do botão como entrada
}

void loop() {
  buttonState = digitalRead(buttonPin); // Lê o estado atual do botão

  // Detecta a transição de LOW para HIGH
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount++; // Incrementa o contador
    // Aqui você pode adicionar algum código para usar a contagem
    // Exemplo: acender um LED, acionar um motor, etc.
  }

  lastButtonState = buttonState; // Atualiza o estado anterior
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
