//Questão 1 do Exercício Prático 3
//Arthur Martinho - 813168
//Daniel Salgado - 821429

//declaração de variáveis utilizadas
int azul = 10;
int verde = 11;
int amarelo = 12;
int vermelho = 13;
int ciclo = 0;

//execução primária para definição de entradas e saídas
void setup() {
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  Serial.begin(9600);
}

//execução de código infinito
void loop() {

  digitalWrite(vermelho, HIGH);
  while (ciclo < 3) {
    digitalWrite(azul, HIGH);
    delay(1000);
    ciclo++;
    digitalWrite(azul, LOW);
    delay(1000);
  }
  digitalWrite(vermelho, LOW);
  //reseta a contagem do ciclo
  ciclo = 0;

  digitalWrite(verde, HIGH);
  while (ciclo < 4) {
    digitalWrite(azul, HIGH);
    delay(1000);
    ciclo++;
    digitalWrite(azul, LOW);
    delay(1000);
  }
  digitalWrite(verde, LOW);

  //reseta a contagem do ciclo
  ciclo = 0;

  digitalWrite(amarelo, HIGH);
  while (ciclo < 2) {
    digitalWrite(azul, HIGH);
    delay(1000);
    ciclo++;
    digitalWrite(azul, LOW);
    delay(1000);
  }
  digitalWrite(amarelo, LOW);
  //reseta a contagem do ciclo
  ciclo = 0;
}
