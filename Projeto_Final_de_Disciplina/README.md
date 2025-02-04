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

   <img height="200" width="303" align="right" alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/454ddd04-1086-4226-8b8f-7cb032603cd3">
   
   > <img height="200" width="310" alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/7696e638-6d4b-4f56-9ffc-ed535ae8bded">
   > 
   > <img height="300" width="603"  alt="WhileDIAGRAMA" src="https://github.com/user-attachments/assets/3dd7da58-2744-456b-86a5-990ecb17d68f">
   >
   > O **push button** desempenha um papel crucial na interação com o usuário, tornando este projeto intuitivo e acessível mesmo para iniciantes.


## Materiais Necessários
- **1 Placa Arduino (por exemplo, Arduino Uno)**
- **1 Buzzer (integrado aos pino 12)**
- **6 LEDs (integrado aos pinos de 3 a 8)**
- **2 LEDs (para indicar os resultados - integrado aos pinos 9 e 10)**
- **6 Resistores de 220 Ω**
- **1 Botão/Push button (integrado no pino 13)**
- **1 Resistores de 10 kΩ (pull-dow)**
- **Fios de conexão (jumpers)**
- **1 Protoboard (opcional, para montagem do circuito)**

<details>
<summary> :card_index_dividers: Detalhes EXTRAS: Tabela de Materias </summary>
   
[Materiais-Detalhes](https://github.com/user-attachments/files/18581050/bom.csv)
</details>


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

![fotodd](https://github.com/Matheusrammos/LIA-Docs/blob/main/Projeto_Final_de_Disciplina/Diagrama_TRAfinal.png)

<details>
<summary> :card_index_dividers: Diagrama EXTRA: Circuito Digital </summary>

[Circuito Digital](https://github.com/user-attachments/files/18581037/Copy.of.Mighty.Duup.1.pdf)
</details>




## :cyclone: Código Comentado
```cpp


#include <TimerOne.h>  // Biblioteca para usar Timer

// Definindo pinos e algumas variáveis
const int ledPins[] = { 3, 4, 5, 6, 7, 8, 9, 10 };  // Pinos onde os LEDs estão conectados (Pinos dos 6 LEDs)
const int buttonPin = 13;                           // Pino do botão
const int buzzerPin = 12;                           // Pino do buzzer
bool a = false;                                     // Variável iterruptora
long x;                                             // Número de piscadas
int p;                                              // Tempo de cada piscada
int c = 0;                                          // LED excolhido
int som[] = { 58, 108, 0, 0, 0, 0, 500, 120, 300, 350 };

bool z = false;  // Modo Tigrinho
int counter = 0;
bool estadoLEDs = false;
int vitorias = 0;
int chance;
int sorte;



void setup() {

  pinMode(buttonPin, INPUT);    // Inicializando o pino do botão como entrada
  pinMode(buzzerPin, OUTPUT);   // Configura o pino do buzzer como saída

  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);  // Configura os pinos dos LEDs como saída
  }

  randomSeed(analogRead(0));    // Inicializando o gerador de números aleatórios
  Serial.begin(9600);           // Inicializando a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}



// Alterna os LEDs no modo Tigrinho
void piscarLEDs() {
  if (z && !a) { // Só funciona se o Modo do Tigrinho estiver ativo e se a roleta não estvier funcionando 
    estadoLEDs = !estadoLEDs; // Inverte estado dos LEDs
    for (int i = 0; (i < 6); i++) {
      if (i == c) {  // Pula o LED atualmente escolhido
        i++;
      }
      if (i == 6){
        break;
      }
      digitalWrite(ledPins[i], estadoLEDs);
    }
  }
}



// Função para girar a roleta
void giraRoleta() {
  // Se o "interrruptor" marcar "true"
  if (a) {                             
    if (z) {                                            // Se o modo Tigrinho estiver ativo
      // Ajusta as chances de vitória conforme histórico de "vitorias"
      if (vitorias < 2) {
        chance = 80;                                  // 80% de chance de ganhar
      } else if (vitorias < 5) {
        chance = 50;                                  // 50% de chance de ganhar
        vitorias = vitorias--;
      } else {
        chance = 28;                                  // 28% de chance de ganhar
        vitorias -= 2;                                // vitorias = vitorias - 2;
      }

      sorte = random(0, 101);                           // Gera um número de 0 a 100 que corresponde a "sorte" do jogador
      Serial.println(sorte);                            // Mostrar esse número no Serial Monitor

      // Determina se o jogador vence ou perde
      if (sorte <= chance) {                          // Se o número sorteado, a "sorte", for menor que a variável que deternina a chance de vitória do jogador, o jogador terá seu LED excolhido
        while (x <= 10) {                             // Enquanto o número de transições de LEDs for menor ou igual a 10
          x = ((c % 6) + 6 * sorte + 1);              // Essa expressão força a vitória do jogador
          Serial.println((x % 6) - 1);                // Esse número representa extamente o LED que será excolhido após o giro da roleta
        }
        vitorias++;                                     // O número de vitórias é acrescentado em 1
      } else {                                        // Se o número sorteado, a "sorte", for maior que a variável que deternina a chance de vitória do jogador, o jogador não terá seu LED excolhido
        do {                                          // Realizará no mínimo uma vez
          x = random(41, 591);                        // Sorteará um número entre 41 e 590, tal que ele representa o número de transições LEDs
        } while (((x % 6) - 1) == c);                 // O progama sorteará um novo número até que o LED que representa o resultado final seja diferente do LED excolhido (força a derrota do jogador)
      }
      Serial.println(vitorias);                         // Mostra o número de vitorias até o momento


    // Se o "interrruptor" marcar "false"
    } else {
      x = random(41, 591);                              // Gera um número entre 41 e 590, tal que ele representa o número de transições LEDs
      Serial.println(x);                                // Mostrar esse número no Serial Monitor
    }



    // Percorre os LEDs simulando o giro da roleta (transição LED)
    for (int i = 0; i < 7; i++) { 
      // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
      if (i == 6) {                                     // Estado temporário
        i = 0;                                          // Resetado para o pino 3
      }

      p = 1000 / x;                                     // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição
      digitalWrite(ledPins[i], HIGH);                   // Acende o respectivo LED

      if (digitalRead(ledPins[i]) == HIGH) {          // Toca um som a cada transição LED
        tone(buzzerPin, som[z]);                      // Toca a nota correspondente
        delay(p / 2);                                 // Espera metade do tempo de piscada
        noTone(buzzerPin);                            // Deixa de tocar a nota
      }
      delay(p / 2);                                     // Espera metade do tempo de piscada
      digitalWrite(ledPins[i], LOW);                    // Apaga o mesmo
      x--;                                              // O valor de "x" diminui em 1

      // Indicando o LED escolhido
      if (x == 0) {                                   // Quando as trandições LEDs terminar, exibir o resultado
        if (c == i) {                               // Se o LED excolhido corresponde ao resultado (se o jogador tiver ganhado)
          c = 7;                                    // LED da vitória acende (LED verde - PIN 10)
        } else {                                    // Se o LED excolhido não corresponde ao resultado (se o jogador tiver perdido)               
          c = 6;                                    // LED da derrota acende (LED vermelho - PIN 9)
        }
        // Raliza uma breve animação que indica o LED sorteado 
        digitalWrite(ledPins[c], HIGH);               // Acende o LED que corresponde ao resultado (acende o LED verde ou o LED vermelho)

        delay(70);                                    // Espera 700 mili segundos   
        digitalWrite(ledPins[i], LOW);                // Apaga o LED sorteado
        delay(100);                                   // Espera 100 mili segundos              
        digitalWrite(ledPins[i], HIGH);               // Acende o LED sorteado
        tone(buzzerPin, som[c]);                      // Toca a nota correspondente
        delay(60);                                    // Espera 60 mili segundos
        noTone(buzzerPin);                            // Deixa de tocar a nota
        delay(40);                                    // Espera 40 mili segundos
        digitalWrite(ledPins[i], LOW);                // Apaga o LED sorteado
        delay(100);                                   // Espera 100 mili segundos     
        digitalWrite(ledPins[i], HIGH);               // Acende o LED sorteado
        tone(buzzerPin, som[c+2]);                    // Toca a nota correspondente
        delay(60);                                    // Espera 60 mili segundos
        noTone(buzzerPin);                            // Deixa de tocar a nota

        if (digitalRead(buttonPin) == HIGH) {       // Se o botão estiver pressinado
          // Ativa ou desativa o Modo Tigrinho (modo secreto)
          z = !z;                                   // Ativa ou desativa a variável do Modo Tigirnho
          vitorias = 0;                             // Reseta vitóras
          c = 0;                                    // Reseta o índice de LEDs
            // Liga o LED vermelho e o LED verde
          digitalWrite(ledPins[6], HIGH);        
          digitalWrite(ledPins[7], HIGH);       

          if (z == true) {                        // Se "z" for ativado
            digitalWrite(ledPins[i], LOW);        // O LED que representa o resultado se apaga

            introModoTigrin();                    // O programa é forçado a 
            a = false;                            // Desativa o modo de roleta
            loop();
          }
        }

        // Finaliza a roleta
        delay(4940);                                  // Espera 4940 mili segundos (4,94 segundos)
        digitalWrite(ledPins[i], LOW);                // O LED que representa o resultado se apaga 
        a = false;                                    // Desativa o modo de roleta
        c = 0;                                        // Reseta o índice de LEDs
        i = 7;                                        // Força a saída do comando for
          // Desliga o LED vermelho e o LED verde
        digitalWrite(ledPins[6], LOW);    
        digitalWrite(ledPins[7], LOW);          
      }
    }
  }
}



// Transição entre o Modo Padrão e o Modo do Trigrinho
void introModoTigrin() {
  // Animação intro para entrar no Modo Tigrinho
  for (int i = 0; (i < 7) && (z == true); i++) {
    p = 130;                              // O tempo de piscada ficará maior a cada ciclo, pois o valor de "x" diminuirá a cada repetição

    // i = 6 será considerado como estado temporário. Quando isso ocorrer, a roleta, após o LED do pino 8 desligar, resetará para o LED do pino 3
    if (i == 6) {                         // Estado temporário
      i = 0;                              // Resetado para o pino 3
      c++;
    }

    if ((c == 2) && (i == 1)) {
      digitalWrite(ledPins[5], LOW);      // Apaga o mesmo
    } else if (c == 3) {
      if (i == 1) {
        digitalWrite(ledPins[4], LOW);    // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[5], LOW);    // Apaga o mesmo
      }
    } else if (c == 4) {
      if (i == 1) {
        digitalWrite(ledPins[3], LOW);    // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[4], LOW);    // Apaga o mesmo
      } else if (i == 3) {
        digitalWrite(ledPins[5], LOW);    // Apaga o mesmo
      }
    } else if (c == 5) {
      if (i == 1) {
        digitalWrite(ledPins[2], LOW);    // Apaga o mesmo
      } else if (i == 2) {
        digitalWrite(ledPins[3], LOW);    // Apaga o mesmo
      } else if (i == 3) {
        digitalWrite(ledPins[4], LOW);    // Apaga o mesmo
      } else if (i == 4) {
        digitalWrite(ledPins[5], LOW);    // Apaga o mesmo
      } else if (i == 5) {
        digitalWrite(ledPins[0], LOW);    // Apaga o mesmo
      }
    } else if (c == 6) {
      c = 0;
      vitorias++;
      if (vitorias == 2) {
        counter = 0;
        vitorias = 0;
        digitalWrite(ledPins[6], LOW);
        digitalWrite(ledPins[7], LOW);
        delay(500);
        return;
      }
    }
    digitalWrite(ledPins[i], HIGH);       // Acende o respectivo LED
    if (digitalRead(ledPins[i]) == HIGH) {
      tone(buzzerPin, som[z]);            // Toca a nota correspondente
      delay(p / 2);                       // Espera metade do tempo de piscada
      noTone(buzzerPin);                  // Deixa de tocar a nota
    }
    delay((p / 2) + (p / 2) * c);         // Espera metade do tempo de piscada
    digitalWrite(ledPins[i - c], LOW);    // Apaga o mesmo
  }
}



void loop() {
  for (int counter = 0; counter <= 6;) {
    digitalWrite(ledPins[6], LOW);
    digitalWrite(ledPins[7], LOW);

    if (z == true) {
      Timer1.initialize(1200000);             // Configura Timer para 1200ms (1.200.000 microssegundos)
      Timer1.attachInterrupt(piscarLEDs);     // Ativa interrupção a cada 500ms
      Serial.println(counter);                // Mostrar esse número no Serial Monitor

      if (estadoLEDs == true) {
        digitalWrite(ledPins[c], LOW);        // Acende o respectivo LED
        digitalWrite(ledPins[c - 1], HIGH);   // Acende o respectivo LED
      } else {
        digitalWrite(ledPins[c], HIGH);       // Acende o respectivo LED
        digitalWrite(ledPins[c - 1], LOW);    // Acende o respectivo LED
      }

      if (digitalRead(buttonPin) == HIGH) {   // Se o botão for pressionado
        counter++;
        delay(80);
      }

      if ((digitalRead(buttonPin) == LOW) && (counter >= 1 && counter <= 4)) {
        if (estadoLEDs == true) {
          digitalWrite(ledPins[c], HIGH);     // Acende o respectivo LED
        } else {
          digitalWrite(ledPins[c], LOW);      // Acende o respectivo LED
        }
        c++;
        if (c == 6) {
          c = 0;
        }
        tone(buzzerPin, 108);
        delay(60);                          // Espera 60 mili segundos
        noTone(buzzerPin);                  // Deixa de tocar a nota
        counter = 0;

      } else if ((counter > 4) && ((digitalRead(buttonPin) == LOW) || (digitalRead(buttonPin) == HIGH))) {
        a = !a;
        counter = 0;
        Timer1.stop();
        giraRoleta();
      }


    } else {
      Serial.println(counter);                // Mostrar esse número no Serial Monitor
      digitalWrite(ledPins[c], HIGH);         // Acende o respectivo LED
      if (digitalRead(buttonPin) == HIGH) {   // Se o botão for pressionado
        counter++;
        delay(80);
      }

      if ((digitalRead(buttonPin) == LOW) && (counter >= 1 && counter <= 4)) {
        digitalWrite(ledPins[c], LOW);        // Apaga o mesmo
        c++;                                  // O "interruptor" marcará 'true'
        tone(buzzerPin, som[z]);              // Toca a nota correspondente
        delay(60);                            // Espera 60 mili segundos
        noTone(buzzerPin);                    // Deixa de tocar a nota
        if (c == 6) {
          c = 0;
        }
        counter = 0;

      } else if ((counter > 4) && ((digitalRead(buttonPin) == LOW) or (digitalRead(buttonPin) == HIGH))) {
        a = !a;
        counter = 0;
        Timer1.stop();
        giraRoleta();
      }
    }
  }
}
````


## Funcionamento

> Este projeto utiliza seis LEDs conectados a um Arduino que acendem de forma sequencial, simulando uma roleta. A velocidade da roleta é determinada por um número gerado aleatoriamente, e o ciclo é interrompido gradualmente até que um LED final permaneça piscando. O botão controla o início e o fim da roleta. 
1. **Configuração Inicial:**
   - **LEDs**: Seis LEDs são conectados aos pinos digitais 3 a 8 e configurados como saídas.  
   - **Botão**: Um botão é conectado ao pino 13 e configurado como entrada.  
   - **Buzzer**: Conectado ao pino 12 e utilizado para emitir sons ao longo da execução.  
   - **Gerador Aleatório**: `randomSeed(analogRead(0))` é usado para inicializar a geração de números aleatórios, garantindo variação entre execuções.  
   - **Monitoramento Serial**: A comunicação serial é iniciada (`Serial.begin(9600)`) para exibir informações no Serial Monitor.  

2. **Controle do Botão:**
   - O estado do botão é monitorado com `digitalRead(buttonPin)`.
   - Quando o botão é pressionado, a variável `a` é alternada entre verdadeiro (`true`) e falso (`false`), ativando ou desativando o funcionamento da roleta.

3. **Início da Roleta:**
   - Quando `a` é verdadeiro, um número aleatório `x` entre 41 e 590 é gerado.
   - Esse número controla a velocidade e o tempo total da roleta.

4. **Sequência dos LEDs:**
   - Os LEDs piscam sequencialmente, simulando o movimento da roleta.  
   - A velocidade da piscagem é determinada pela fórmula `p = 1000 / x`.  
   - O número `x` diminui gradualmente a cada ciclo, fazendo com que a roleta desacelere.
   - O buzzer emite um tom curto quando um LED acende.  

5. **Finalização:**
   - Quando `x` atinge 0, a roleta para, e o LED atual pisca algumas vezes para indicar o resultado final.
   - Dependendo do LED final, diferentes frequências de som são emitidas pelo buzzer para indicar se foi um resultado esperado ou não.  

6. **Reinício:**
   - Após um pequeno tempo de espera, o sistema é reinicializado e aguarda uma nova interação do usuário via botão.  
      > Essa lógica torna o projeto interativo e dinâmico, podendo ser usado como base para jogos ou sorteios eletrônicos.


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
  *(OPENAI. ChatGPT. Disponível em: ChatGPT - [OpenAI](https://www.openai.com/chatgpt). Acesso em: 28/01/25.)*
