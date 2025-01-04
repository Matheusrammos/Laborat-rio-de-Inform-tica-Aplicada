# Roleta com LEDs

## Descrição
Este projeto simula uma roleta luminosa utilizando seis LEDs e um botão, com controle de velocidade e parada gradual. A roleta é acionada ao pressionar o botão, e os LEDs piscam sequencialmente, desacelerando até que um LED final seja destacado como o "vencedor". A interface com o Serial Monitor permite acompanhar o número gerado aleatoriamente.

### Sobre o Push Botton:
- O **push button** (ou botão de pressão) é um componente essencial neste projeto, atuando como um interruptor momentâneo que controla o início e a parada da roleta luminosa. Simples e eficiente, ele é amplamente utilizado em circuitos eletrônicos e projetos com Arduino devido à sua confiabilidade e facilidade de integração.
1. **Funcionamento Momentâneo:**  
   - O push button fecha o circuito apenas enquanto está pressionado. Assim que é liberado, o circuito se abre novamente.  
   - No contexto deste projeto, ele alterna o estado da variável `a`, funcionando como um "interruptor lógico" que inicia ou interrompe o funcionamento da roleta.  

2. **Estrutura e Conexões:**  
   - **Terminais:** O botão possui quatro terminais, embora apenas dois sejam necessários para conexão elétrica. Os outros dois facilitam a montagem e fornecem redundância.  
   - **Conexão ao Arduino:** No projeto, um terminal do botão é conectado ao pino digital 13, configurado como entrada. O outro terminal é ligado ao GND (terra).  

3. **Tipos Comuns:**  
   - **Normalmente Aberto (NO):** O circuito permanece desconectado até o botão ser pressionado, como usado neste projeto.  
   - **Normalmente Fechado (NC):** O circuito permanece conectado e se desconecta apenas quando o botão é pressionado.  

#### **Vantagens no Projeto:**  
- **Controle Simples:** Com um único pressionamento, é possível ativar ou desativar a roleta.  
- **Versatilidade:** Pode ser usado em diferentes contextos para iniciar ou pausar funções.  
- **Custo-Benefício:** É um componente barato, robusto e amplamente disponível.  

#### **Considerações Técnicas:**  
- **Debouncing:** Devido à natureza física dos contatos internos, um botão pode gerar sinais elétricos instáveis ao ser pressionado. Neste projeto, o problema é mitigado com um pequeno atraso (`delay(50)`) no código.  
- **Pull-down ou Pull-up Resistor:** Para garantir leituras confiáveis no Arduino, um resistor pull-down interno ou externo pode ser necessário para evitar flutuações de sinal quando o botão não é pressionado.  

O **push button** desempenha um papel crucial na interação com o usuário, tornando este projeto intuitivo e acessível mesmo para iniciantes.

   <img height="200" width="283" align="right" alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/454ddd04-1086-4226-8b8f-7cb032603cd3">
   
   > <img height="200" width="300" alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/7696e638-6d4b-4f56-9ffc-ed535ae8bded">




## Materiais Necessários
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **6 LED (integrado aos pinos de 3 a 8)**
- **6 Resistor de 220 Ω**
- **1 Botão/Push button (integrado no pino 13)**
- **1 Resistor de 10 kΩ (pull-dow)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**


## Montagem do Circuito
1. **Conexão dos LEDs:**
   - Conecte o ânodo (lado maior) no respéctivo pino de forma horária.
   - Conecte o cátodo (lado menor) ao GND.
     
2. **Conectar o Botão:** 
   - Um terminal do botão deve ser conectado ao pino digital 13 do Arduino.
   - O outro terminal do botão deve ser conectado ao VCC (5V) da placa.

3. **Configuração do Resistor pull-dow**:
   - Conecte um resistor de 10 kΩ entre o pino 13 (onde o botão está conectado) e o GND (terra). Isso garantirá que o pino 13 esteja em um estado baixo quando o botão não estiver pressionado.

4. **Diagrama de montagem:**
![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Projeto_Final_de_Disciplina/Diagrama_TRFinal.png)

<details>
<summary> :card_index_dividers: Diagrama EXTRA: Circuito Digital </summary>

![sh](https://github.com/Matheusrammos/LIA-Docs/blob/main/Projeto_Final_de_Disciplina/Circuito_Digital.png)
</details>



## :cyclone: Código Comentado
```cpp
// Definindo pinos e algumas variáveis
const int ledPins[] = {3, 4, 5, 6, 7, 8}; // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13; // Pino do botão
bool a = false; // Variável iterruptora
long x; // Número de piscadas
int p; // Tempo de cada piscada


void setup() {
  // Inicializando o pino do botão como entrada
  pinMode(buttonPin, INPUT); 

  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }

  // Inicializando o gerador de números aleatórios
  randomSeed(analogRead(0)); // Gera a semente para números aleatórios

  // Inicializando a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
  Serial.begin(9600); 
}


void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Se o botão for pressionado
    a = !a; // O "interruptor" marcará 'true'
  }

  if (a == true) { // Se o "interrruptor" marcar 'true'
    x = random(41, 591); // Gerar um número aleatório de 41 a 590
    Serial.println(x); // Mostrar esse número no Serial Monitor

    // Acende e apaga os LEDs sequencialmente
    for (int i = 0; i < 7; i++) {
      // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
      if (i == 6) { // Estado temporário
        i = 0; // Resetado para o pino 3
      }

      p = 1000/x; // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição
      digitalWrite(ledPins[i], HIGH); // Acende o respectivo LED
      delay(p); // Espera o tempo de piscada
      digitalWrite(ledPins[i], LOW); // Apaga o mesmo
      x--; // O valor de "x" diminui em 1

      // Indicando o LED escolhido
      if (x == 0) {
        delay(70);
        digitalWrite(ledPins[i], LOW);
        delay(100);
        digitalWrite(ledPins[i], HIGH);
        delay(100);
        digitalWrite(ledPins[i], LOW);
        delay(100);
        digitalWrite(ledPins[i], HIGH);
        delay(3000);
        a = !a;
        i = 7;
      }
    }
  }
}
````


### Funcionamento

> Este projeto utiliza seis LEDs conectados a um Arduino que acendem de forma sequencial, simulando uma roleta. A velocidade da roleta é determinada por um número gerado aleatoriamente, e o ciclo é interrompido gradualmente até que um LED final permaneça piscando. O botão controla o início e o fim da roleta. 
1. **Configuração Inicial:**
   - Os LEDs são conectados aos pinos digitais 3 a 8 e configurados como saídas.
   - O botão é conectado ao pino 13 e configurado como entrada.
   - O gerador de números aleatórios é inicializado usando `randomSeed(analogRead(0))` para criar a semente baseada em ruído analógico.
   - A comunicação serial é iniciada para monitoramento no Serial Monitor.

2. **Controle do Botão:**
   - O estado do botão é monitorado com `digitalRead(buttonPin)`.
   - Quando o botão é pressionado, a variável `a` é alternada entre verdadeiro (`true`) e falso (`false`), ativando ou desativando o funcionamento da roleta.

3. **Início da Roleta:**
   - Quando `a` é verdadeiro, um número aleatório `x` entre 41 e 590 é gerado.
   - Esse número controla a velocidade e o tempo total da roleta.

4. **Sequência dos LEDs:**
   - Os LEDs acendem e apagam sequencialmente em um ciclo controlado pelo valor de `x`. A velocidade é ajustada dinamicamente com base no cálculo `p = 1000 / x`.
   - O número `x` diminui gradualmente a cada ciclo, fazendo com que a roleta desacelere.

5. **Finalização:**
   - Quando `x` atinge 0, a roleta para, e o LED atual pisca algumas vezes para indicar o resultado final.
   - Após o LED piscar, a roleta aguarda 3 segundos antes de ser desativada completamente.

6. **Reinício:**
   - O processo pode ser reiniciado pressionando o botão novamente.


## Desafios Enfrentados  
> O desenvolvimento deste projeto foi uma oportunidade de consolidar conceitos aprendidos ao longo das aulas, como o uso de resistores [pull-dow](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Casa_1#ultilizando-um-resistor-pull-dow), [sequencial de LEDs](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Sala_5), [geração de números aleatórios](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Sala_6#funcionamento) e [interação com o Monitor Serial](https://github.com/Matheusrammos/LIA-Docs/tree/main/Exerc%C3%ADcio_em_Casa_2). Porém, alguns desafios se destacaram:  

1. **Repetição das Piscadas LED**  
- O principal obstáculo foi implementar a repetição contínua dos LEDs até o cumprimento total do número de piscadas gerado aleatoriamente (`x`). Inicialmente, o código interrompia o ciclo ao acender o LED do pino 8, já que o valor final da variável `i` no loop `for` era 5.  
   - **Solução:**  
     Para resolver isso, implementei um estado temporário no loop. Quando `i` atingia 6, a variável era redefinida para 0, criando uma sequência ininterrupta que simula o giro contínuo da roleta. Essa abordagem foi inspirada nos princípios dos contadores assíncronos estudados em Sistemas Digitais.

2. **Controle da Velocidade da Roleta**  
- Ajustar a velocidade de piscada de forma dinâmica, de modo que ela desacelerasse gradualmente, exigiu um cálculo preciso. Foi necessário criar uma relação inversa entre o tempo de piscada (`p`) e o número total de piscadas (`x`) para que a transição ocorresse suavemente.  

3. **Gerenciamento do Estado da Roleta**  
- A alternância entre ativar e desativar a roleta, controlada pela variável booleana `a`, precisou de ajustes para garantir que a roleta pudesse ser reiniciada de forma consistente após o término de cada ciclo.

4. **Interação com o Monitor Serial**  
- Implementar a exibição do número aleatório gerado (`x`) no Monitor Serial exigiu a inicialização correta da comunicação e a formatação dos dados para facilitar a leitura durante os testes.

Esses desafios foram superados com criatividade e aplicação dos conceitos aprendidos, permitindo a construção de um projeto funcional, didático e alinhado aos objetivos do curso.

### Maior Desafio:

   O maior desafio foi implementar a repetição contínua das piscadas dos LEDs. Inicialmente, no `void loop()`, ao usar o loop `for (int i = 0; i < 6; i++) {`, a variável "i" chegava ao valor 5, acionando o LED do pino 8 e encerrando o ciclo, sem completar o número total de piscadas definido pela variável "x". Isso impedia que o comportamento esperado da roleta fosse reproduzido corretamente.

A solução foi implementar um "estado temporário", inspirado nos conceitos de contadores assíncronos estudados na disciplina de Sistemas Digitais. Essa abordagem permitiu redefinir o valor da variável "i" para 0 quando atingisse 6, criando um ciclo contínuo. Com a modificação para `for (int i = 0; i < 7; i++) {`, o valor de "i" era instantaneamente reiniciado ao atingir 6, proporcionando a impressão de que a roleta girava de forma fluida e ininterrupta.


## Participações
- Este projeto contou com a assistência do ChatGPT, um assistente virtual da OpenAI, para fornecer informações e orientações durante o desenvolvimento e a elaboração da documentação.
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 04/01/25.)*
