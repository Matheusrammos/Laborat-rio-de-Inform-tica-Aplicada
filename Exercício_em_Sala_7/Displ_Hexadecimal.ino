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
