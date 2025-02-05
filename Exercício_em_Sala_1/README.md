# Programa BLINK


## Descrição do Projeto: Blink
O programa Blink é um dos exemplos mais fundamentais e tradicionais para iniciantes que trabalham com microcontroladores, como o Arduino. Ele faz com que um LED pisque repetidamente, ligando e desligando em intervalos regulares. Este exemplo é especialmente útil para verificar se o ambiente de desenvolvimento e o hardware estão funcionando corretamente.

### Sobre os Resistores:
- Os resistores são componentes passivos fundamentais na eletrônica, utilizados para limitar e regular a corrente elétrica em um circuito. Eles funcionam de acordo com a lei de Ohm, dissipando energia em forma de calor e garantindo que outros componentes, como LEDs e microcontroladores, operem dentro de suas faixas seguras de corrente e tensão citeturn0search0.

#### Aplicações no Arduino:

No universo do Arduino, os resistores desempenham papéis essenciais para a segurança e o desempenho dos circuitos. Alguns exemplos de aplicações incluem:

- **Divisores de Tensão:** Permitem reduzir a tensão de um sinal para níveis compatíveis com as entradas analógicas do Arduino, facilitando a leitura precisa de sensores e outros dispositivos.
- **Proteção de LEDs e Outros Componentes:** Em circuitos com LEDs, resistores limitam a corrente que flui pelo diodo, evitando sobrecorrente e prolongando a vida útil do componente.
- **Pull-up e Pull-down:** Utilizados para definir estados lógicos estáveis em entradas digitais, prevenindo leituras erráticas devido a flutuações de sinal em pinos não conectados.
- **Circuitos RC (Resistor-Capacitor):** Junto com capacitores, os resistores formam circuitos temporizadores e filtros que ajudam em funções como o debouncing de botões e a criação de atrasos precisos em sinais.

     > <img height="254.3" width="363" align="right" alt="Diagrama de Resistor" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/RESISTORES_IMG_2.png">
     >
     > <img height="255" width="430" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/RESISTORES_IMG_1.png">
     > 
     > Essas aplicações demonstram como os resistores são indispensáveis para o funcionamento seguro e estável de circuitos com Arduino, servindo tanto para proteção quanto para o controle preciso de sinais elétricos.

<details>
<summary> :bangbang: Funcionamento e Características </summary>

- **Lei de Ohm:** A relação entre tensão (V), corrente (I) e resistência (R) é definida pela lei de Ohm, expressa pela fórmula V = I × R. Esse princípio básico orienta a utilização dos resistores em circuitos eletrônicos.
  
- **Dissipação de Potência:** Ao limitar a corrente, os resistores convertem parte da energia elétrica em calor. É fundamental escolher resistores com a capacidade de dissipação de potência adequada para evitar superaquecimento e danos ao componente.
  
- **Precisão e Tolerância:** Resistores são fabricados com diferentes níveis de tolerância (por exemplo, 1%, 5% ou 10%), o que influencia a precisão dos circuitos onde são aplicados. A escolha correta garante medições mais exatas e desempenho consistente.
  
- **Diversidade de Tipos:** Existem várias tecnologias de resistores, como os de carbono, metal film e wirewound, cada um oferecendo características específicas em termos de estabilidade, ruído e dissipação de calor.
  
> <img height="234.3" width="413" align="right" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/RESISTORES_IMG_3.png">

> <img height="235" width="413" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/RESISTORES_Tabela%3ARESIST%C3%8ANCIA.png">
</details>






## Objetivo
O objetivo do projeto é demonstrar como controlar um pino de saída digital no Arduino para acionar um LED. O código alterna o estado do LED, ligando-o e desligando-o a cada segundo, permitindo que os usuários compreendam os conceitos básicos de controle digital.


## Materiais Necessários
- **1 Arduino Uno (ou qualquer outra placa Arduino)**
- **1 LED (se não usar o embutido)**
- **1 Resistor de 220 Ω (para o LED externo)**
- **Fios de conexão (jumpers)**
- **Protoboard (opcional, para montagem do circuito)**

## Montagem do Circuito
#### Organização do Circuito:
   - Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
   - Use fios de conexão (jumpers) para ligar os componentes ao Arduino.

1. **Conexões do LED:**
   - Insira o LED no protoboard, conectando o terminal mais longo (ânodo) ao pino digital 13 do Arduino.
   - Conecte o terminal mais curto (catodo) a uma extremidade do resistor de 220 Ω.
     
2. **Conexão do Resistor:**
   - Conecte a outra extremidade do resistor ao GND (terra) do protoboard. Isso limita a corrente que passa pelo LED, evitando que ele queime.

3. **Conexões ao Arduino:**
   - Use um jumper para conectar o pino digital 13 do Arduino ao protoboard onde o LED está conectado.
   - Conecte o GND do Arduino a uma linha de terra no protoboard.

4. **Diagrama do Circuito:**
![foto](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/Diagrama_Aula_1.png)
<details>
<summary> :dvd: Teste Prático: Circuito BLINK </summary>

[Circuito BLINK](https://github.com/user-attachments/assets/0fd8602f-0a26-4570-a3aa-290ff9b52ce1)
</details>


## Código Comentado
```cpp
// Define o pino onde o LED está conectado
const int ledPin = 13; // O LED embutido geralmente está no pino 13

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Liga o LED
  digitalWrite(ledPin, HIGH); // Acende o LED
  delay(1000);                // Aguarda 1 segundo (1000 milissegundos)

  // Desliga o LED
  digitalWrite(ledPin, LOW);  // Apaga o LED
  delay(1000);                // Aguarda mais 1 segundo
}
````


### Funcionamento do Projeto: Programa Blink  
> O programa **Blink** é um exemplo básico para aprender como controlar um pino digital no Arduino. Ele alterna o estado de um LED (liga e desliga) a cada segundo, repetidamente.  
1. **Definição do Pino:**
   - O LED está configurado no **pino 13**, que é definido como constante (`ledPin`).

2. **Configuração Inicial (setup):**
   - O pino do LED é configurado como **saída** (`OUTPUT`), permitindo que o Arduino controle o estado (ligado/desligado).

3. **Laço Infinito (loop):**
   - O programa entra em um ciclo que:
     1. Liga o LED (`HIGH`) e aguarda 1 segundo (`delay(1000)`).
     2. Desliga o LED (`LOW`) e aguarda mais 1 segundo.
   - Esse padrão de ligar e desligar se repete indefinidamente.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 26/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar o conteúdo deste projeto.

### Aviso de Direitos Autorais 
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "Story Time, Story Time Link" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).
