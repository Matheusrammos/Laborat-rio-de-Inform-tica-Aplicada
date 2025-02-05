# Display Sete Segmentos: Hexadecimal


## Descrição
O projeto utiliza um display de 7 segmentos para exibir caracteres no formato hexadecimal (0–9 e A–F). O Arduino controla quais segmentos do display serão ativados para formar cada número ou letra. A exibição de caracteres ocorre de forma sequencial, alternando a cada segundo.

### Sobre o Display de Sete Segmentos:
- Um display de sete segmentos é um componente eletrônico usado para exibir números e algumas letras. Ele é composto por sete LEDs organizados em forma de "8", identificados como A, B, C, D, E, F e G, além de um ponto decimal (DP) opcional. É amplamente utilizado em dispositivos como relógios digitais, calculadoras e termômetros, sendo fácil de controlar e econômico. Apesar de sua simplicidade, é limitado à exibição de caracteres básicos.

- Ponderações:
    - O display de sete segmentos continua sendo uma escolha popular para aplicações que exigem exibição básica, devido à sua simplicidade e custo-benefício.
      
    - Nesse caso, os pinos 3 e 8 (comuns) foram ligados ao terra. 

    <img height="300em" align="right" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Displ_Sete_Seg2.png">

    > <img height="300" width="583" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Displ_Sete_Seg.png">
    > 
    > <img height="505" width="803" alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/ffbac0dc-0306-4d23-ae06-9b521a51fa61"> 
    >
    > 
    >
    > Aplicações: Dispositivos portáteis: relógios e calculadoras; Medidores: termômetros digitais, multímetros e balanças eletrônicas; Eletrodomésticos: micro-ondas e máquinas de lavar.

<details>
<summary> :bangbang: Tipos de Configuração  </summary>

1. **Anodo Comum (CA):**  
   - Todos os ânodos (terminais positivos) dos LEDs estão conectados juntos e precisam ser ligados a uma fonte de tensão positiva.  
   - Os segmentos são ativados ao conectar seus cátodos (terminais negativos) ao GND.  

2. **Cátodo Comum (CC):**  
   - Todos os cátodos (terminais negativos) dos LEDs estão conectados ao GND, e os segmentos são ativados ao aplicar tensão positiva nos ânodos (terminais positivos).  
</details>


## Objetivo  
O objetivo deste projeto é construir um circuito eletrônico utilizando um Arduino e um display de sete segmentos para exibir caracteres do sistema hexadecimal (0–9 e A–F). Além de explorar o funcionamento e o controle de um display de sete segmentos, o projeto visa:

1. **Aprendizado Prático:**  
   - Demonstrar como os displays de sete segmentos podem ser utilizados em aplicações básicas, como contadores ou interfaces visuais simples.
   - Ensinar conceitos fundamentais de eletrônica, como controle de LEDs, mapeamento de pinos e gerenciamento de saídas digitais.

2. **Automação Sequencial:**  
   - Criar um sistema automatizado que altera os caracteres exibidos no display de forma sequencial e em intervalos regulares, simulando o funcionamento de contadores ou indicadores digitais.

3. **Exploração de Matrizes:**  
   - Utilizar uma matriz para simplificar o controle dos segmentos e exibir diferentes caracteres, reforçando a lógica de programação e a organização do código.

4. **Prototipagem e Integração:**  
   - Proporcionar experiência na montagem de circuitos em protoboard, conexões com resistores e jumpers, e a integração entre hardware e software no desenvolvimento de projetos eletrônicos.  

> O resultado final será um display funcional que alterna entre os caracteres do sistema hexadecimal, com ampla aplicabilidade em dispositivos digitais básicos, como cronômetros, relógios, ou sistemas de medição.


## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **1 Display Sete Segmentos**
- **7 resistores de 220 Ω**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito

1. **Diagrama de montagem:**
![fotgfjsdo](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Diagrama_Aula_7.png)
<details>
<summary> :dvd: Teste Prático: Display Sete Segmentos: Hexadecimal </summary>

[Display Sete Segmentos: Hexadecimal](https://github.com/user-attachments/assets/03fdbf51-9697-49a2-9bf1-2c41e625b01d)
</details>

## Código Comentado
```cpp
// Definindo os pinos para cada segmento do display de 7 segmentos
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;

// Mapeamento dos números (0-9) e (A-F) para os segmentos do display
const int digit[16][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1},  // 9
  {1, 1, 1, 0, 1, 1, 1}, // A
  {0, 0, 1, 1, 1, 1, 1}, // B
  {1, 0, 0, 1, 1, 1, 0}, // C
  {0, 1, 1, 1, 1, 0, 1}, // D
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1} // F
};


void setup() {
  // Configurando os pinos dos segmentos como saída
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}


void loop() {
  // Loop para exibir números de 0 a F no display
  for (int i = 0; i < 16; i++) {
    displayDigit(i);  // Exibe o número no display
    delay(1000);      // Espera 1 segundo antes de mudar para o próximo número
  }
}


// Função para exibir um dígito no display
void displayDigit(int num) {
  digitalWrite(segA, digit[num][0]);
  digitalWrite(segB, digit[num][1]);
  digitalWrite(segC, digit[num][2]);
  digitalWrite(segD, digit[num][3]);
  digitalWrite(segE, digit[num][4]);
  digitalWrite(segF, digit[num][5]);
  digitalWrite(segG, digit[num][6]);
}
````


## Funcionamento  
> O projeto utiliza um display de sete segmentos para exibir os números de 0 a F (sistema hexadecimal). Cada segmento do display é controlado individualmente por pinos digitais do Arduino, que recebem valores para acender ou apagar os LEDs correspondentes.
1. **Configuração dos Pinos:**  
   - Cada segmento do display é conectado a um pino digital do Arduino (`segA` a `segG`), configurado como saída no `setup()`.  

2. **Mapeamento de Dígitos:**  
   - Uma matriz (`digit`) armazena os estados necessários (ligado ou desligado) para cada segmento, mapeando caracteres de 0 a F.  
     > Exemplo: Para exibir o número "0", os segmentos A, B, C, D, E e F são ativados, enquanto o segmento G é desligado.  
3. **Exibição de Caracteres:**  
   - A função `displayDigit()` recebe o número ou letra como entrada e ativa os segmentos correspondentes com base no mapeamento da matriz.  

4. **Laço Principal:**  
   - No `loop()`, um laço `for` percorre todos os caracteres de 0 a F.  
   - A cada iteração, o número ou letra é exibido no display por 1 segundo antes de mudar para o próximo caractere.  


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 27/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.

### Aviso de Direitos Autorais
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "Boys" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).


