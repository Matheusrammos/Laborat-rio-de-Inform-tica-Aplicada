// Definindo os pinos e algumas variáveis
const int ledPin = 13; // Pino do LED
const int buttonPin = 5; // Pino do Botão
int PushCounter = 0; // Contador
int LastState = 0; // Estado anterior
int Estbutton = 0; // Estado atual

void setup() {
  // Configurando o pino do Led como saída, e o do Botão, como entrada
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW); // Estado inicial do LED é em baixo (LOW)
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps. Isso é necessário para começar a enviar dados ao Serial Monitor
}

void loop() {
Estbutton = digitalRead(buttonPin); // Sincronizando o estado do botão a leitura atual do mesmo
  if ((LastState == LOW) && (Estbutton == HIGH)) { // Se houver uma transição positiva (negativo -> positivo)
    PushCounter++; // Soma 1 à variável "PushCounter"
    digitalWrite(ledPin, HIGH); // Acende o LED
    Serial.print("Número de apertadas no botão:"); // Printa a informação no serial monitor
    Serial.println(PushCounter); 
  }
  if (Estbutton == LOW)  { // Se o botão não for precionado
    digitalWrite(ledPin, LOW); // Apaga o LED
    }
  delay(50);
LastState = Estbutton; //Save State
}
