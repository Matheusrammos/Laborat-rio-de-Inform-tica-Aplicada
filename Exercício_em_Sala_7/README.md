# Display Sete Segmentos: Hexadecimal

## Descrição
O projeto utiliza um display de 7 segmentos para exibir caracteres no formato hexadecimal (0–9 e A–F). O Arduino controla quais segmentos do display serão ativados para formar cada número ou letra. A exibição de caracteres ocorre de forma sequencial, alternando a cada segundo.

### Sobre o Display de Sete Segmentos:
- Um display de sete segmentos é um componente eletrônico usado para exibir números e algumas letras. Ele é composto por sete LEDs organizados em forma de "8", identificados como A, B, C, D, E, F e G, além de um ponto decimal (DP) opcional. É amplamente utilizado em dispositivos como relógios digitais, calculadoras e termômetros, sendo fácil de controlar e econômico. Apesar de sua simplicidade, é limitado à exibição de caracteres básicos.

    - O display de sete segmentos continua sendo uma escolha popular para aplicações que exigem exibição básica, devido à sua simplicidade e custo-benefício.
      
    - Nesse caso, os pinos 3 e 8 (comuns) foram ligados ao terra. 


<details>
<summary> :bangbang: Tipos de Configuração  </summary>


1. **Anodo Comum (CA):**  
   - Todos os ânodos (terminais positivos) dos LEDs estão conectados juntos e precisam ser ligados a uma fonte de tensão positiva.  
   - Os segmentos são ativados ao conectar seus cátodos (terminais negativos) ao GND.  

2. **Cátodo Comum (CC):**  
   - Todos os cátodos (terminais negativos) dos LEDs estão conectados ao GND, e os segmentos são ativados ao aplicar tensão positiva nos ânodos (terminais positivos).  
</details>

> <img alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Displ_Sete_Seg2.png">

> <img alt="WhileDIAGRAMA" height="400" width="773" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Displ_Sete_Seg.png">


## Objetivo  

## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **1 Display Sete Segmentos**
- **7 resistores de 220 Ω**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conectar o Botão:**
   - Um terminal do botão deve ser conectado ao pino digital 3 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

1. **Diagrama de montagem:**
![fotgfjsdo](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_7/Diagrama_Aula_7.png)


## Código
```cpp
// Definindo os pinos para cada segmento do display de 7 segmentos
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;



// Mapeamento dos números (0-9) para os segmentos do display
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
  // Loop para exibir números de 0 a 9 no display
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
1. **Configuração dos Pinos:**  
   - Cada segmento do display é conectado a um pino digital do Arduino (`segA` a `segG`), configurado como saída no `setup()`.  

2. **Mapeamento de Dígitos:**  
   - Uma matriz (`digit`) armazena os estados necessários (ligado ou desligado) para cada segmento, mapeando caracteres de 0 a F.  
   - Exemplo: Para exibir o número "0", os segmentos A, B, C, D, E e F são ativados, enquanto o segmento G é desligado.  

3. **Exibição de Caracteres:**  
   - A função `displayDigit()` recebe o número ou letra como entrada e ativa os segmentos correspondentes com base no mapeamento da matriz.  

4. **Laço Principal:**  
   - No `loop()`, um laço `for` percorre todos os caracteres de 0 a F.  
   - A cada iteração, o número ou letra é exibido no display por 1 segundo antes de mudar para o próximo caractere.  

## Aplicações  
Este projeto é útil para aprender o funcionamento de displays de 7 segmentos e pode ser aplicado em:  
- Sistemas de contagem ou cronômetros.  
- Interfaces simples para microcontroladores.  
- Exibição de informações numéricas ou alfanuméricas em sistemas embarcados.  

O projeto exemplifica o controle básico de um display, oferecendo uma introdução prática ao uso de matrizes e controle de hardware no Arduino.  
