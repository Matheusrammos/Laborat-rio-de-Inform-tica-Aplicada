# Luzes de Sinalização de Garagem


## Descrição
Este projeto demonstra uma montagem básica utilizando um Arduino Uno e dois LEDs. O objetivo é aprender como controlar LEDs através do Arduino, ligando e desligando-os de forma sequencial. Essa prática ajuda a compreender conceitos fundamentais de programação e eletrônica.

### Sobre os LEDs:
- O LED (diodo emissor de luz) é um componente semicondutor que, ao ser polarizado diretamente, emite luz através do fenômeno da eletroluminescência. Em vez de utilizar filamentos como nas lâmpadas incandescentes, os LEDs convertem energia elétrica em luz por meio da recombinação de elétrons e lacunas no material semicondutor citeturn0search0.

#### Aplicações no Arduino:

 Os LEDs são componentes essenciais para muitos projetos com Arduino, pois permitem que os iniciantes experimentem conceitos básicos de eletrônica e programação. Alguns exemplos de aplicações incluem:

   - **Programa Blink:** É o primeiro projeto tradicionalmente feito com Arduino, onde um LED é ligado e desligado periodicamente. Esse exercício ajuda a entender o funcionamento dos pinos digitais e o uso da função delay() na programação citeturn0search3.
   - **Controle de Intensidade e Cores:** Com a utilização de PWM (modulação por largura de pulso), é possível ajustar o brilho de um LED ou controlar LEDs RGB para criar efeitos de cor. Essa técnica é bastante utilizada em projetos de iluminação e displays interativos.
   - **Sequências e Animações:** Projetos mais avançados podem envolver a criação de sequências de LEDs (como em uma matriz ou em tiras de LED endereçáveis WS2812B) para construir efeitos visuais, animações e até interfaces de usuário interativas.
   - **Interação com Sensores:** Os LEDs podem ser integrados a sensores para indicar estados ou eventos, como em sistemas de monitoramento, alarmes ou jogos interativos.

     > <img height="254.3" width="325" align="right" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_2/LED_IMG_2.png">
     >
     >
     > <img height="255" width="463" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_2/LED_IMG_1.png">
     >
     > Essas aplicações facilitam o aprendizado de circuitos e programação, além de servirem como base para projetos mais avançados em comunicação, redes de sensores e automação. Assim, a integração de LEDs com Arduino proporciona amplas possibilidades de experimentação e desenvolvimento na eletrônica.
     
<details>
<summary> :bangbang: Funcionamento e Características </summary>

- **Baixo Consumo e Longa Vida:** Os LEDs consomem pouca energia e têm uma vida útil muito maior que as lâmpadas tradicionais, o que os torna ideais para aplicações em dispositivos portáteis e sistemas de iluminação de longa duração.

- **Diversidade de Cores:** A cor emitida pelo LED depende dos materiais semicondutores utilizados. Com técnicas de dopagem, é possível obter luz vermelha, verde, azul e até combiná-las para formar luz branca ou LEDs RGB.

- **Compactos e Eficientes:** Devido ao seu tamanho reduzido e alta eficiência energética, os LEDs são amplamente utilizados em displays, indicadores e iluminação decorativa ou funcional.

> <img height="254.3" width="413" align="right" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/D%C3%ADodo_Emissor_de_Luz_3.png">

> <img height="255" width="413" alt="WhileDIAGRAMA" src="https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_1/D%C3%ADodo_Emissor_de_Luz_TABELA%3ATENSAO.png">
</details>


## Objetivo
O objetivo deste projeto é aprender a controlar LEDs com um Arduino Uno, ligando e desligando-os sequencialmente. Isso permite entender o controle digital, praticar a programação básica e a montagem de circuitos em protoboard, além de compreender a função dos resistores na limitação de corrente. Essas atividades contribuem para construir uma base sólida para projetos eletrônicos futuros.


## Materiais Necessários
- **1 Arduino Uno (ou qualquer outra placa Arduino)**
- **2 LEDs**
- **2 Resistores de 220 Ω (para limitar a corrente dos LEDs)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
### Organização do Circuito:
- Utilize a protoboard para montar o circuito e organizar as conexões de forma limpa.
- Use fios de conexão (jumpers) para ligar os componentes ao Arduino.

1. **Conexões dos LEDs:**

   **Primeiro LED:**
   - Conecte o ânodo (terminal positivo) do primeiro LED ao pino digital 9 do Arduino.
   - Conecte o cátodo (terminal negativo) do primeiro LED a um resistor de 220 Ω.

   **Segundo LED:**
   - Conecte o ânodo do segundo LED ao pino digital 13 do Arduino.
   - Conecte o cátodo do segundo LED a outro resistor de 220 Ω.
   
3. **Conexões dos Resistores**
   - Os resistores  de 220 Ω, separadamente, devem ser conectados a extremidade de cada ânodo de cada LED. A extremidade restante do resistor deve ser conectada ao GND do Arduino.
  
4. **Diagrama do Circuito:**
![fotoi](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_2/Diagrama_Aula_2.png)
<details>
<summary> :dvd: Teste Prático: Luzes de Sinalização de Garagem </summary>

[Luzes de Sinalização de Garagem](https://github.com/user-attachments/assets/2bb3d1d8-f805-40ad-b18f-218ab6cd244a)
</details>


# Código Comentado
```cpp
// Definindo os pinos dos LEDs
const int led1Pin = 9; // Pino do primeiro LED
const int led2Pin = 13; // Pino do segundo LED


void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}


void loop() {
  digitalWrite(led1Pin, HIGH); // Acende o primeiro LED
  digitalWrite(led2Pin, LOW); // Apaga o segundo LED
  delay(1000); // Aguarda 1 segundo

  digitalWrite(led1Pin, LOW); // Apaga o primeiro LED
  digitalWrite(led2Pin, HIGH); // Acende o segundo LED
  delay(1000); // Aguarda 1 segundo
}
````

<details>
<summary> :cyclone: Código desenvolvido pelo aluno </summary>

```cpp
// Definindo os pinos dos LEDs
const int ledPins[] = {9, 13};  // Pinos onde os LEDs estão conectados


void setup() {
  // Configurando os pinos dos LEDs como saída
  for (int i = 0; i < 2; i++) {
  pinMode(ledPins[i], OUTPUT);
  }
}


void loop() {
  // Acende e apaga os LEDs sequencialmente
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPins[i], HIGH); // Acende o LED correspondente ao número "i"
    delay(1000); // Aguarda 1 segundo
    digitalWrite(ledPins[i], LOW); // Apaga o LED correspondente ao número "i"
  }
}

````
</details>


## Funcionamento
1. **Configuração Inicial:** O código configura os pinos 2 e 3 como saídas no Arduino.
2. **Sequência de Ação:** O primeiro LED é aceso, aguarda 1 segundo e é apagado. Em seguida, o segundo LED é aceso, aguarda 1 segundo e é apagado.
3. **Repetição:** Essa sequência se repete indefinidamente enquanto o programa estiver em execução, permitindo observar o controle sequencial dos LEDs.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 26/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordenar o conteúdo deste projeto.

### Aviso de Direitos Autorais
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "On the Go, On the Go Link" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).
