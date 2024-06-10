//Trabalho AEDS1 2023/1 - Daniel Salgado

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura Geral de informacao dos veiculos
typedef struct VeiculoGeral{
  char placa[9];
  char marca[50];
  char modelo[50];
  int ano;
  float preco;
  char tipo[50];
  char observacao[100];
}VeiculoGeral;


//Case 1 - Funcao para listar veiculos na tela do usuario
//Lista feita!
void ListarVeiculo(VeiculoGeral veiculo[], int NVeiculos){
  if(NVeiculos == 0){
    printf("\nNenhum veiculo cadastrado!\n");
  }else{
    printf("\nO total de veiculos cadastrados no sistema é: %d\n", NVeiculos);
    for(int i=0;i<NVeiculos;i++){
      printf("\n\nInformacoes do carro cadastrado %d:\n\n", i+1);
      printf("Placa: %s", veiculo[i].placa);
      printf("\nMarca: %s", veiculo[i].marca);
      printf("\nModelo: %s", veiculo[i].modelo);
      printf("\nAno: %d", veiculo[i].ano);
      printf("\nPreco: %.2f", veiculo[i].preco);
      printf("\nTipo: %s", veiculo[i].tipo);
      printf("\nObservacao: %s", veiculo[i].observacao);
    }
  }
}


//Case 2 - Funcao para pesquisar um veiculo
//Pesquisa feita!
void PesquisarVeiculo(VeiculoGeral veiculo[], int NVeiculos){
  //criação de uma nova variavel que recebera a pesquisa da placa, para comparar com as placas existentes.
  VeiculoGeral pesquisaPlaca;
  
  printf("\nDigite o numero da placa do veiculo que deseja ver: ");
  scanf(" %[^\n]", pesquisaPlaca.placa);

  //verificar se a placa tem 7 caracteres
  while(strlen(pesquisaPlaca.placa)!=7){
    printf("\nQuantidade invalida de caracteres! Tente novamente: ");
    scanf(" %[^\n]", pesquisaPlaca.placa);
  }

  for(int i=0;i<NVeiculos;i++){
    if(strcmp(veiculo[i].placa, pesquisaPlaca.placa)==0){
      printf("\nPlaca: %s", veiculo[i].placa);
      printf("\nMarca: %s", veiculo[i].marca);
      printf("\nModelo: %s", veiculo[i].modelo);
      printf("\nAno: %d", veiculo[i].ano);
      printf("\nPreco: %f", veiculo[i].preco);
      printf("\nTipo: %s", veiculo[i].tipo);
      printf("\nObservacao: %s", veiculo[i].observacao);
      return;
    }
  }
   printf("\nVeiculo nao encontrado\n");
}


//Case 3 - Funcao para cadastrar um veiculo
//NVeiculos será ponteiro, pois conseguirá ser mudado nas funções/main
//Cadastro feito!
void CadastrarVeiculo(VeiculoGeral veiculo[], int *NVeiculos){
  //criação de uma nova variável que recebera as informacoes de um novo carro.
  VeiculoGeral veiculoNovo;

  char resposta;
  
  //fazer com que so possa ter 7 caracteres na placa
  printf("\nDigite a placa do veiculo que deseja cadastrar: ");
  scanf(" %[^\n]", veiculoNovo.placa);

  //verificar se a placa tem 7 caracteres
  while(strlen(veiculoNovo.placa)!=7){
    printf("\nQuantidade invalida de caracteres! Tente novamente: ");
    scanf(" %[^\n]", veiculoNovo.placa);
  }

  //Verificar placas repetidas
  for(int i=0;i<*NVeiculos;i++){
    if(strcmp(veiculo[i].placa, veiculoNovo.placa)==0){
      printf("\nEsta placa ja esta cadastrada.\n");
      return;
    }
  }

  //novas informacoes
  printf("\nDigite a marca do veiculo: ");
  scanf(" %[^\n]", veiculoNovo.marca);
  veiculoNovo.marca[strlen(veiculoNovo.marca)] = '\0';

  printf("\nDigite o modelo do veiculo: ");
  scanf(" %[^\n]", veiculoNovo.modelo);
  veiculoNovo.modelo[strlen(veiculoNovo.modelo)] = '\0';

  printf("\nDigite o ano do veiculo: ");
  scanf("%d", &veiculoNovo.ano);

  printf("\nDigite o preço do veiculo: ");
  scanf("%f", &veiculoNovo.preco);

  printf("\nDigite o tipo do veiculo(Carro ou Moto): ");
  scanf(" %[^\n]", veiculoNovo.tipo);
  veiculoNovo.tipo[strlen(veiculoNovo.tipo)] = '\0';

  printf("\nDeseja adicionar uma observacao? Digite S para sim e N para nao: ");
  scanf(" %c", &resposta);

  while(!(resposta == 'S' || resposta == 'N')){
      printf("\nResposta invalida, favor digitar novamente: ");
      scanf(" %c", &resposta);
  }

  if(resposta == 'S'){
    printf("\nDigite sua observacao: ");
    scanf(" %[^\n]", veiculoNovo.observacao);
  }
  //mensagem que pediu, informando o sucesso no cadastro
  printf("\n\nVeículo Cadastrado!\n");

  //faz com que o veiculoNovo seja cadastrado no vetor que lê os veiculos, presente no arquivo.
  veiculo[*NVeiculos] = veiculoNovo;
  
  //soma o número de veiculos, para colocar na linha 1 do arquivo e checar em outras funções.
  ++(*NVeiculos);
}


//Depois de Cadastrar o Veiculo, a função de Gravar sera ativada, na mesma Case, pra aparecer no arquivo
void GravaVeiculo(VeiculoGeral veiculo[], int NVeiculos) {

  //abre o arquivo para escrita
  FILE *arq = fopen("veiculos.txt", "w");

  if (arq != NULL) {
    fprintf(arq, "%d\n", NVeiculos);
    
    for (int i = 0; i < NVeiculos; i++) {
      fprintf(arq, "%s;%s;%s;%d;%.2f;%s;%s\n", veiculo[i].placa, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco, veiculo[i].tipo, veiculo[i].observacao);  
    }
    
    fclose(arq);
    
  } else {
    printf("As informacoes do veiculo nao foram salvas. Favor tentar novamente.");
  }
}


//Case 4 - Funcao para editar um veiculo
//Edicao feita!
void EditarVeiculo(VeiculoGeral veiculo[], int NVeiculos){
  //criação de uma nova variavel que recebera a pesquisa da placa, para comparar com as placas existentes.
  VeiculoGeral editarPlaca;
  
  printf("\nDigite o numero da placa do veiculo que quer editar: ");
  scanf(" %[^\n]", editarPlaca.placa);

  //verificar se a placa tem 7 caracteres
  while(strlen(editarPlaca.placa)!=7){
    printf("\nQuantidade invalida de caracteres! Tente novamente: ");
    scanf(" %[^\n]", editarPlaca.placa);
  }

  //escrevendo novamente os dados da nova placa
  for(int i=0;i<NVeiculos;i++){
    if(strcmp(veiculo[i].placa, editarPlaca.placa)==0){

      printf("\n\nInformacoes do carro cadastrado %d:\n\n", i+1);
      printf("\nPlaca: %s", veiculo[i].placa);
      printf("\nMarca: %s", veiculo[i].marca);
      printf("\nModelo: %s", veiculo[i].modelo);
      printf("\nAno: %d", veiculo[i].ano);
      printf("\nPreco: %.2f", veiculo[i].preco);
      printf("\nTipo: %s", veiculo[i].tipo);
      printf("\nObservacao: %s", veiculo[i].observacao);

      
      printf("\n\nDigite as novas informacoes: \n");
      printf("\nMarca: ");
      scanf(" %[^\n]", veiculo[i].marca);
      printf("\nModelo: ");
      scanf(" %[^\n]", veiculo[i].modelo);
      printf("\nAno: ");
      scanf(" %d", &veiculo[i].ano);
      printf("\nPreco: ");
      scanf(" %f", &veiculo[i].preco);
      printf("\nTipo: ");
      scanf(" %[^\n]", veiculo[i].tipo);
      printf("\nObservacao: ");
      scanf(" %[^\n]", veiculo[i].observacao);

      printf("\nInformacoes do veiculo editadas com sucesso!\n");
      return;
    }
  }
   printf("\nVeiculo nao encontrado\n");
}

//Case 5 - Funcao para excluir veiculo
void ExcluirVeiculo(VeiculoGeral veiculo[], int *NVeiculos){
  
  VeiculoGeral excluirPlaca;
  
  VeiculoGeral veiculoExcluido;

  char resposta;
  
  printf("\nDigite o numero da placa do veiculo que quer excluir: ");
  scanf(" %[^\n]", excluirPlaca.placa);

  //comparar com algum terminal para finalizar
  for (int i = 0; i < *NVeiculos; i++) {
    if (strcmp(veiculo[i].placa, excluirPlaca.placa) == 0) {
      printf("\n\nInformacoes do carro cadastrado %d:\n\n", i+1);
      printf("\nPlaca: %s", veiculo[i].placa);
      printf("\nMarca: %s", veiculo[i].marca);
      printf("\nModelo: %s", veiculo[i].modelo);
      printf("\nAno: %d", veiculo[i].ano);
      printf("\nPreco: %.2f", veiculo[i].preco);
      printf("\nTipo: %s", veiculo[i].tipo);
      printf("\nObservacao: %s", veiculo[i].observacao);

      printf("\n\nDeseja excluir este veiculo? Digite S para sim, e N para nao: ");
      scanf(" %c", &resposta);

      while(!(resposta == 'S' || resposta == 'N')){
        printf("\nResposta invalida, favor digitar novamente: ");
        scanf(" %c", &resposta);
      }

      if (resposta == 'S') {
        //como J fica igual a I, e na segunda condição o contador esta diminuindo, quando aumenta o j em veiculo[j+1], o veiculo so vai percorrer uma linha a menos, excluindo a nao lida. Esquema: j=0, veiculo = 3, j=1, veiculo = 2 e para
        for (int j = i; j < (*NVeiculos) - 1; j++) {
          veiculo[j] = veiculo[j + 1];
        }
        //reduz a contagem apos a exclusao da linha
        (*NVeiculos)--;
        printf("\nVeiculo excluido com sucesso!\n");
        return;
      } else if(resposta == 'N'){
        printf("\nExclusao de veiculo cancelada!\n");
        return;
      }
    }
  }
  printf("\nVeiculo nao encontrado!");
}



int main(){

  int NVeiculos;

  //Ler para receber a quantidade de veiculos
  FILE * arq = fopen("veiculos.txt", "r");

  if (arq == NULL) {
    printf("O arquivo nao foi aberto corretamente! Favor tentar novamente.");
    return 1;
  }
    fscanf(arq, "%d", &NVeiculos);

  //Colocando o valor de Veiculo como 1000, ele consegue armazenar caracter suficiente
    VeiculoGeral veiculo[1000];
  
    for (int i = 0; i < NVeiculos; i++) {
      fscanf(arq, " %[^;];%[^;];%[^;];%d;%f;%[^;];%[^\n]", veiculo[i].placa, veiculo[i].marca, veiculo[i].modelo, &veiculo[i].ano, &veiculo[i].preco, veiculo[i].tipo, veiculo[i].observacao);
    }
  
    fclose(arq);
  
  
  int opcao;

  //Menu e opções de resposta para cada função
  do{
    printf("\n\nLoja de Automóveis Daniel Salgado");
    printf("\n\n1 - Listar todos os veiculos");
    printf("\n2 - Pesquisar um veiculo");
    printf("\n3 - Cadastrar um veiculo");
    printf("\n4 - Editar um veiculo");
    printf("\n5 - Excluir um veiculo");
    printf("\n6 - Sair do Programa");
    printf("\n\nDigite a opcao que deseja: ");
    scanf("%d", &opcao);

    //chamando a funcao GravaVeiculo em cada caso que necessita de editar o arquivo, desse jeito, ele consegue editar o arquivo sem sobreescrever o que ja existe.
    
    switch(opcao){
      case 1: 
        ListarVeiculo(veiculo, NVeiculos);
      break;
    
      case 2: 
        PesquisarVeiculo(veiculo, NVeiculos);
      break;
    
      case 3: 
        CadastrarVeiculo(veiculo, &NVeiculos);
        GravaVeiculo(veiculo, NVeiculos);
      break;
      
      case 4: 
        EditarVeiculo(veiculo, NVeiculos);
        GravaVeiculo(veiculo, NVeiculos);
      break;
    
      case 5:
        ExcluirVeiculo(veiculo, &NVeiculos);
        GravaVeiculo(veiculo, NVeiculos);
      break;

      case 6:
        printf("\nEncerrando o programa!");
      break;

      default:
      printf("\nFavor digite um número de opcao valido!\n");
    }
    
  }while(opcao!=6);

  printf("\nAperte ENTER para fechar o programa! ");
  
  return 0;
}
