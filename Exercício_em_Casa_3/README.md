# Enviando Dados para a Porta Serial

## Descrição
Este diretório contém o terceiro exercício de casa, onde demonstramos como enviar dados para a porta serial. Neste código, ao pressionar o botão, o LED integrado no pino 13 da placa Arduino é acionado e imediatamente é transmitido um sinal à Porta Serial.
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

3. **Diagrama de montagem**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Casa_1/Diagrama_Casa_1%3A%20pull-dow.png)
<details>
<summary> :dvd: Teste Prático: Enviando Dados para a Porta Serial </summary>

[Enviando Dados para a Porta Serial](https://github.com/user-attachments/assets/5c721e95-d484-4fbe-aead-86e4e88b54a2)
</details>


## Código Comentado
```cpp
// Definindo os pinos e algumas variáveis
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão
int Estbutton = 0; // Estado atual

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}

void loop() {
Estbutton = digitalRead(buttonPin); // O estado do botão recebe a leitura atual do botão
 if (Estbutton == HIGH) { // Se o botão estiver pressionado
    digitalWrite(ledPin, HIGH); // Liga o LED
  } else { // Se não
    digitalWrite(ledPin, LOW); // Desliga o LED
  }
Serial.println(Estbutton); // Mostre o estado do botão no Serial Monitor
delay(50); // Debouncing
}
````

## Funcionamento
1. **Configuração Inicial:** O Arduino é configurado para monitorar o botão no pino digital 5 e controlar o LED no pino digital 13. Inicialmente, o LED é configurado como apagado (**LOW**) e a comunicação serial é iniciada para enviar informações ao **Serial Monitor**.
2. **Leitura do Estado do Botão:** A cada ciclo do programa, o estado do botão é lido utilizando o comando **`digitalRead(buttonPin)`** e armazenado na variável **`Estbutton`**.  
3. **Controle do LED:** Se o botão estiver pressionado (**HIGH**), o LED é aceso com **`digitalWrite(ledPin, HIGH)`**. Caso contrário, o LED é apagado com **`digitalWrite(ledPin, LOW)`**.
4. **Exibição no Serial Monitor:** O estado atual do botão é exibido no **Serial Monitor** por meio de **`Serial.println(Estbutton)`**, permitindo que o usuário veja se o botão está pressionado ou não.
5. **Debouncing:** Para evitar múltiplas leituras causadas por ruídos no botão, é aplicado um atraso de 50ms ao final de cada iteração do loop principal.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 14/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.

