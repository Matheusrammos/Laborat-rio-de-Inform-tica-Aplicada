# Controle de Pisca-Pisca de LED com Variáveis Configuráveis

## Descrição
Este projeto utiliza um Arduino para controlar um LED conectado ao pino 10, fazendo-o piscar 3 vezes a cada 0,1 segundo (100ms) através do `while` e, em seguida, apagar por 1,5 segundos (1500ms). O número de piscadas, a duração de cada piscada e a duração do apagamento são variáveis configuráveis no código, permitindo ajustes para testar diferentes comportamentos do sistema.

### O que é, e o que faz a estrutura `while`?

- O `while` em C++ é uma estrutura de repetição que executa um bloco de código enquanto uma condição for verdadeira.

    - **Primeira etapa:** A condição do loop é avaliada antes de cada execução. Essa condição é geralmente uma expressão booleana (como i < 10), que determina se o loop continuará ou será encerrado. Se a condição for avaliada como falsa desde o início, o bloco de código dentro do loop nem será executado uma única vez.
      
    - **Segunda etapa:** Se a condição for avaliada como verdadeira, o bloco de código dentro do loop será executado. Após a execução, o controle retorna para a verificação da condição. Se, em algum ponto, a condição se tornar falsa, o loop será encerrado, e o programa continuará com o código após o loop.
      
    - **Terceira etapa:** É fundamental que a condição do loop seja atualizada dentro do corpo do loop ou como parte da própria estrutura de controle. Isso evita loops infinitos, que ocorrem quando a condição nunca se torna falsa. Por exemplo, incrementar uma variável de controle (i++) ou modificar os valores avaliados na condição garante que o loop progrida e termine corretamente.
    <br>
    
    > <img alt="WhileDIAGRAMA" height="480" width="733" src="https://i.pinimg.com/originals/b9/b9/48/b9b948ec034a0c5474e2d82ecf41c9b1.gif">
<details>
<summary>: :file_folder: Sintaxe  </summary>
    
```cpp
while (condição) {
    // Código a ser repetido
}
```````
</details>


## Objetivo
O objetivo deste projeto é aprender a manipular o comportamento de um LED através de variáveis configuráveis em um sketch Arduino. Este exercício permite a prática de controle de tempo (com o comando `delay()`e `while`), manipulação de pinos digitais e a modificação de variáveis para alterar o comportamento do sistema.

## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **1 LED**
- **1 Resistor de 220 Ω (para limitar a corrente do LED)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**

## Montagem do Circuito
1. **Conexões do LED:**
   - Conecte o ânodo (terminal positivo) do LED ao pino digital 10 do Arduino através de um resistor de 220 Ω.
   - Conecte o cátodo (terminal negativo) do LED ao GND (terra) do Arduino.

2. **Diagrama do Circuito:**
 ![fotodud](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_4/Diagrama_Aula_4.png)

## Código Comentado

```cpp
// Definição das variáveis configuráveis
const int ledPin = 10; // Pino onde o LED está conectado
int blinkCount = 3; // Número de piscadas
int blinkDuration = 100; // Duração de cada piscada em milissegundos (0.1 segundo)
int offDuration = 1500; // Duração de apagar o LED em milissegundos (1.5 segundos)

void setup() {
   pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
}

void loop() {
   int count = 0; // Inicializa o contador para o número de piscadas
   // Loop para piscar o LED
   while (count < blinkCount) {
      digitalWrite(ledPin, HIGH); // Acende o LED
      delay(blinkDuration); // Mantém o LED aceso pelo tempo especificado
      digitalWrite(ledPin, LOW); // Apaga o LED
      delay(blinkDuration); // Pausa antes de piscar novamente
      count++; // Incrementa o contador
   }
   // Aguarda com o LED apagado
   delay(offDuration); // Mantém o LED apagado pelo tempo de apagamento especificado
}
```

## Funcionamento

1. **Configuração Inicial:**
   O código começa definindo o pino de saída para o LED (pino 10) e as variáveis configuráveis `blinkCount`, `blinkDuration` e `offDuration`, que controlam o número de piscadas, o tempo de cada piscada e o tempo de apagamento do LED, respectivamente.

2. **Loop de Piscar o LED:**
   O código entra no loop principal (`loop()`) e começa a contar até o número de piscadas especificado pela variável `blinkCount`. Para cada piscada, o LED é aceso por um tempo definido pela variável `blinkDuration` e, em seguida, apagado pelo mesmo tempo. O contador de piscadas (`count`) é incrementado após cada piscada.

3. **Aguardar com LED apagado:**
   Após a quantidade de piscadas definida, o LED fica apagado por um tempo especificado pela variável `offDuration`. Esse ciclo se repete indefinidamente.

4. **Modificando as Variáveis:**
   Você pode alterar os valores das variáveis `blinkCount`, `blinkDuration` e `offDuration` para observar como o comportamento do LED muda. Por exemplo, pode-se aumentar o número de piscadas ou alterar o tempo de apagamento para ver diferentes efeitos no LED.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 14/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.
- Fonte do [gif](https://i.pinimg.com/originals/b9/b9/48/b9b948ec034a0c5474e2d82ecf41c9b1.gif) utilizado para explicar o funcionamento do `while`.
