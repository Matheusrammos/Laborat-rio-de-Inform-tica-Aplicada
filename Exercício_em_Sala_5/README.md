# Sequencial de 4 Canais com Arduino


## Descrição
Este projeto controla quatro LEDs conectados a diferentes pinos do Arduino, fazendo-os acender e apagar de forma sequencial com um intervalo de 0,5 segundos entre cada ação. O uso do comando `for` torna o código mais compacto e eficiente, pois permite iterar pelos LEDs de forma sistemática.

### Comando `for`
> O comando `for` no Arduino (e em linguagens como C/C++) é uma estrutura de controle de repetição. Ele é usado para executar um conjunto de instruções várias vezes, com base em uma condição.
<details>
<summary> :file_folder: Sintaxe </summary>

 ```cpp
for (inicialização; condição; finalização) {
   // Código a ser executado
}
```
</details>

<details>
<summary> :open_file_folder: Detalhes de Cada Processo </summary>

1. **Inicialização:** 
   - É executada **uma única vez** no início do loop.
   - Geralmente usada para declarar e inicializar a variável de controle. No caso do código:
     ```cpp
     int i = 0;
     ```
     Isso cria uma variável chamada `i` e a inicializa com o valor `0`.

2. **Condição:** 
   - É uma expressão lógica avaliada antes de cada iteração. 
   - Enquanto a condição for verdadeira, o bloco de código entre `{}` será executado. No código:
     ```cpp
     i < 4
     ```
     Isso verifica se o valor de `i` é menor que 4 (o número total de LEDs).

3. **Finalização:** 
   - É executada no final de cada iteração, **antes de reavaliar a condição**.
   - Geralmente usada para atualizar a variável de controle. No código:
     ```cpp
     i++
     ```
     Isso incrementa o valor de `i` em 1 a cada iteração.
</details>

<details>
<summary> :hammer_and_wrench: Comparação com While </summary>

O `for` pode ser reescrito usando `while`, mas isso requer mais linhas de código. Por exemplo:

```cpp
int i = 0;
while (i < 4) {
   digitalWrite(ledPins[i], HIGH);
   delay(500);
   digitalWrite(ledPins[i], LOW);
   delay(500);
   i++;
}
```

O `for` é preferido nesse caso por ser mais compacto e direto.
</details>

<details>
<summary> :jigsaw: Como o For Funciona no Código </summary>

1. **Inicialização:** 
   - Na primeira execução, a variável `i` é inicializada com 0.
2. **Condição:**
   - O programa verifica se `i < 4`. Se verdadeiro, o bloco de código entre `{}` é executado.
3. **Finalização:**
   - Após executar o bloco, o programa incrementa `i` em 1 (`i++`) e reavalia a condição.
4. **Repetição:**
   - Isso continua até que a condição seja falsa, momento em que o programa sai do loop.
</details>


## Objetivo
Controlar quatro LEDs conectados ao Arduino, fazendo-os acender e apagar de forma sequencial com um intervalo de 0,5 segundos entre as ações. Este projeto é um exemplo prático para explorar a estrutura de controle `for`, arrays, e controle básico de hardware com o Arduino.


## Materiais Necessários
- **1 Arduino Uno (ou outra placa compatível)**
- **4 LEDs**
- **4 resistores de 220 Ω**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conexão dos LEDs:**
   - Conecte os ânodos (terminais positivos) dos LEDs aos pinos digitais 13, 9, 6 e 3 do Arduino.
   - Conecte os cátodos (terminais negativos) dos LEDs ao GND (terra) do Arduino através de resistores de 220 Ω.

2. **Diagrama de montagem:**
![fotoddd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Exerc%C3%ADcio_em_Sala_5/Diagrama_Aula_5.png)
<details>
<summary> :dvd: Teste Prático: Sequencial de 4 canais </summary>

[Sequencial de 4 canais](https://github.com/user-attachments/assets/fdacd06a-5b5d-4285-af78-d2eec4ffa06b)
</details>


## Código Comentado

```cpp
// Definindo os pinos dos LEDs
const int ledPins[] = {13, 9, 6, 3}; // Pinos onde os LEDs estão conectados


void setup() {
   // Configura os pinos dos LEDs como saída
   for (int i = 0; i < 4; i++) {
      pinMode(ledPins[i], OUTPUT); 
   }
}


void loop() {
   // Acende e apaga os LEDs sequencialmente
   for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH); // Acende o LED
      delay(500); // Espera 0,5 segundos
      digitalWrite(ledPins[i], LOW); // Apaga o LED
      delay(500); // Espera 0,5 segundos
   }
}
````


## Funcionamento
> O programa faz com que quatro LEDs conectados ao Arduino acendam e apaguem de forma sequencial, criando um efeito de "corrida de luz".
1. **Configuração Inicial (Função `setup`)**  
- A função `setup` é chamada apenas uma vez ao iniciar o Arduino.  
- O laço `for` percorre o array `ledPins` (que contém os números dos pinos onde os LEDs estão conectados) e configura cada pino como uma saída usando o comando `pinMode()`.  
    - Exemplo: Se o pino 13 for o primeiro do array, ele será configurado como saída, depois o pino 9, e assim por diante até o pino 3.  
  > Resultado: Os pinos 13, 9, 6 e 3 do Arduino estão prontos para controlar os LEDs.

2. **Laço Principal (Função `loop`)**  
- O código dentro da função `loop` é executado continuamente.  
- Outro laço `for` percorre o array `ledPins`. Em cada iteração:  
    1. O comando `digitalWrite(ledPins[i], HIGH)` acende o LED conectado ao pino atual.  
    2. O comando `delay(500)` mantém o LED aceso por 0,5 segundos.  
    3. O comando `digitalWrite(ledPins[i], LOW)` apaga o LED.  
    4. Outro `delay(500)` espera 0,5 segundos antes de passar ao próximo LED.  
  > Resultado:  
  > - O primeiro LED (pino 13) acende por 0,5 segundos e depois apaga.  
  > - O segundo LED (pino 9) acende por 0,5 segundos e depois apaga.  
  > - O processo continua para os LEDs no pino 6 e pino 3.  

### **Resumo do Comportamento**
  1. Os LEDs acendem e apagam um por vez, sempre na ordem definida pelo array `ledPins` (13 → 9 → 6 → 3).  
  2. Cada LED permanece aceso por 0,5 segundos e apagado por 0,5 segundos antes de passar para o próximo LED.  
  3. O padrão de acendimento se repete indefinidamente.  
> Quando o último LED (pino 3) termina, o `loop` começa novamente, criando um ciclo contínuo de luzes acendendo e apagando em sequência.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 27/12/24.)*
- [Epaminondaslage](https://www.bing.com/ck/a?!&&p=cf945232149fce13JmltdHM9MTcyNjcwNDAwMCZpZ3VpZD0yNGZkYWYyYS1lMjZiLTYzMWYtMzY0MC1iYmJiZTNlZTYyZGImaW5zaWQ9NTE5Mg&ptn=3&ver=2&hsh=3&fclid=24fdaf2a-e26b-631f-3640-bbbbe3ee62db&psq=src%3d%22https%3a%2f%2fgithub.com%2fEpaminondaslage%2fAluno_Fulano_de_Tal%2fblob%2fmain%2fExercicio_em_Casa_1%2fFigura.jpeg%22+alt%3d%22Circuito%22+width%3d%2250%25%22&u=a1aHR0cHM6Ly9naXRodWIuY29tL0VwYW1pbm9uZGFzbGFnZQ&ntb=1) foi responsável por instruir e coordernar este projeto.

### Aviso de Direitos Autorais
>[!WARNING]
>
>Este repositório contém materiais de terceiros protegidos por direitos autorais. A música "Mechanical Toys" de John Fiddy é usada apenas para fins educacionais e sem intenção de infringir os direitos. Para mais detalhes, veja [DISCLAIMER.md](./DISCLAIMER.md).

