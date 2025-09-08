// Questão 2 do EP3
// Arthur Martinho - 813168
// Daniel Salgado - 821429

// valorA = led vermelho
int pinoA = 13;
// valorB = led amarelo
int pinoB = 12;
// saida = led verde
int saida = 11;
// vai1 = led azul
int vai1 = 10;
// opcode
int opcode;
int result;
int valorA;
int valorB;

void setup() {
  Serial.begin(9600);
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(saida, OUTPUT);
  pinMode(vai1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    valorA = Serial.parseInt();
    valorB = Serial.parseInt();
    opcode = Serial.parseInt();
    
    if (opcode == 0) {
      result = portaAnd(valorA, valorB);
      Serial.print("Valor A = ");
      Serial.println(valorA);
      mostra(valorA, pinoA);
      Serial.print("Valor B = ");
      Serial.println(valorB);
      mostra(valorB, pinoB);
      Serial.print("OP Code = ");
      Serial.println(opcode);
      Serial.print("Operacao And = ");
      Serial.println(result);
      mostra(result, saida);
      Serial.println();
    }

    if (opcode == 1) {
      result = portaOr(valorA, valorB);
      Serial.print("Valor A = ");
      Serial.println(valorA);
      mostra(valorA, pinoA);
      Serial.print("Valor B = ");
      Serial.println(valorB);
      mostra(valorB, pinoB);
      Serial.print("OP Code = ");
      Serial.println(opcode);
      Serial.print("Operacao Or = ");
      Serial.println(result);
      mostra(result, saida);
      Serial.println();
    }

    if (opcode == 2) {
      result = portaNot(valorA);
      Serial.print("Valor A = ");
      Serial.println(valorA);
      mostra(valorA, pinoA);
      Serial.print("Valor B = ");
      Serial.println(valorB);
      mostra(valorB, pinoB);
      Serial.print("OP Code = ");
      Serial.println(opcode);
      Serial.print("NOT valorA = ");
      Serial.println(result);
      mostra(result, saida);
      Serial.println();
    }

    if (opcode == 3) {
      result = portaSoma(valorA, valorB);
      Serial.print("Valor A = ");
      Serial.println(valorA);
      mostra(valorA, pinoA);
      Serial.print("Valor B = ");
      Serial.println(valorB);
      mostra(valorB, pinoB);
      Serial.print("OP Code = ");
      Serial.print(opcode);
      Serial.println();
      Serial.print("Soma = ");
      Serial.println(result);
      mostra(result, saida);
      mostra(portaAnd(valorA, valorB), vai1);
    }
  }
}

int portaSoma(int a, int b){ 
  return (a ^ b);
}

int portaOr(int a, int b){ 
  return (a | b); 
}

int portaAnd(int a, int b){ 
  return (a & b); 
}

int portaNot(int a){ 
  if(a == 1)
    return 0;
  else
    return 1;
  
}

int mostra(int a, int porta){
  if (a == 1)
    digitalWrite(porta, 1);
  else
    digitalWrite(porta, 0);
}
