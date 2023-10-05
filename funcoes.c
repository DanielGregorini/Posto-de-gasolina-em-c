#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#ifdef __linux__
  #include <windows.h>
#elif _WIN32  
  #include <unistd.h>
#else
#endif


//struct principal
struct TCarro { 
  char dono[40];
  char modelo[45];
  char placa[15];
  float conta;
  int tipoDeCombustivel;
  float litros;
};

struct TCarro addCarroAux(float gasolinaComum, float gasolinaAd, float etanol, float **bombaGasolinaComum, float **bombaGasolinaAd, float **bombaEtanol){
  //função aux para adicionar o carro
  struct TCarro aux;
  bool n = false;
  aux.conta = 0;
  ll();
  //adicionando um novo carro
  printf("\nO nome do dono do carro: ");
  lerString(aux.dono, 40);
  ll();
  
  printf("\nO modelo do carro: ");
  lerString(aux.modelo, 45);
  ll();
  
  printf("\nA placa do carro: ");
  lerString(aux.placa, 15);
  ll();

   do{
    printf("\nTipo de combustivel:\n1-Gasolina comum: %.2f Litros\t\tPreço: R$%.2f\n2-Gasolina Aditivada: %.2f litros\tPreço: R$%.2f\n3-Etanol: %.2f litros\t\t\t\tPreço: R$%.2f\n",**bombaGasolinaComum,gasolinaComum, **bombaGasolinaAd,gasolinaAd, **bombaEtanol, etanol);
     
    //printf("\nPreços:\nGasolina comum: R$%.2f\nGasolina Aditivada: R$%.2f\nEtanol: R$%.2f\n",gasolinaComum, gasolinaAd, etanol);
     
    scanf("%d", &aux.tipoDeCombustivel);

    switch(aux.tipoDeCombustivel){

      case (1):
        do{
          printf("\nQuantidade de litros: ");
          scanf("%f", &aux.litros);
          
          if(aux.litros <= 0 || aux.litros > **bombaGasolinaComum){
            printf("\nInsira quantidade valida!\n");
          }
        }while(aux.litros <= 0 || aux.litros > **bombaGasolinaComum);
        aux.conta = aux.litros * gasolinaComum;
        **bombaGasolinaComum = **bombaGasolinaComum - aux.litros;
        n = true;
      break;

      case (2):
        do{
          printf("\nQuantidade de litros: ");
          scanf("%f", &aux.litros);
          if(aux.litros <= 0 || aux.litros > **bombaGasolinaAd){
            printf("\nInsira quantidade valida!\n");
          }
        }while(aux.litros <= 0 || aux.litros > **bombaGasolinaAd);
        aux.conta = aux.litros * gasolinaAd;
        **bombaGasolinaAd = **bombaGasolinaAd - aux.litros;
        n = true;
      break;

      case (3):
        do{
          printf("\nQuantidade de litros: ");
          scanf("%f", &aux.litros);
          
          if(aux.litros <= 0 || aux.litros > **bombaEtanol) {
            printf("\nInsira quantidade valida!\n");
          }
          
        }while(aux.litros <= 0 || aux.litros > **bombaEtanol);
        
        aux.conta = aux.litros * etanol;
        **bombaEtanol = **bombaEtanol - aux.litros;
        n = true;
      break;
      
      default:
        printf("\nTipo invalido!");
      break;
      
    }
  
  }while(n != true);

  ll(); //apresentando o carro.
  printf("Você adicionou um carro:\n\n");
  printf("Nome do dono: %s\n", aux.dono);
  printf("Placa do carro: %s\n", aux.placa);
  printf("Modelo do carro: %s\n", aux.modelo);
  switch(aux.tipoDeCombustivel){
    case (1):
       printf("Tipo de combustível %d - gasolina comum \n", aux.tipoDeCombustivel);
    break;
    case (2):
      printf("Tipo de combustível %d - gasolina aditivada \n", aux.tipoDeCombustivel);
    break;
    case (3):
      printf("Tipo de combustível %d - etanol \n", aux.tipoDeCombustivel);
    break;
  }
  printf("Quantidade de litros de combustível: %.2f\n", aux.litros);
  printf("A conta ficou: R$:%.2f\n\n", aux.conta);

  return aux;
}

void addCarro(struct TCarro *carros, int *nCarrosFila, int fila, float gasolinaComum, float gasolinaAd, float etanol, float *bombaGasolinaComum, float *bombaGasolinaAd, float *bombaEtanol){ 

  int sMenu, ssMenu;
  ll();
  
  while (sMenu != 2 ){
   printf("\n1-Adicionar um carro na fila\n2-Sair\n\n");
   scanf("%d", &sMenu);
   printf("\n\n");
    
   switch (sMenu) {

    case (1):
      if (fila > *nCarrosFila) {
        printf("Carro Adicionado\n\n");
        
        carros[*nCarrosFila] = addCarroAux(gasolinaComum, gasolinaAd, etanol, &bombaGasolinaComum, &bombaGasolinaAd, &bombaEtanol);
        *nCarrosFila = *nCarrosFila + 1;
        
      }else{
        printf("Fila cheia!!\n\n");
      }
      break;

    case (2):
      printf("Voltando ao menu principal\n\n");
      ll();
      break; 
     
    default:
      printf("Opção invalida!!\n\n");
      break;
    }
  }
  
}

void abastecer(struct TCarro *carros, int *nCarrosFila, int fila, float *tLitrosVendidos, float *tVendas, int *tCarrosAtendidos, float *tLitrosVendidosGC, float *tVendasGC, float *tLitrosVendidosGA, float *tVendasGA, float *tLitrosVendidosET, float *tVendasET, bool *carroAbastecido){
  //função para abastecer o carro
  int sMenu = 0;
  struct TCarro *p; //ponteiro para mover o vetor
  ll();

  while(sMenu != 2 && *nCarrosFila > 0){

    struct TCarro *p;
      
    printf("1-Abastecer\n2-Sair\n");
    scanf("%d", &sMenu);
      
      switch(sMenu){
        case(1):
    
          if(*carroAbastecido == true){

            *tLitrosVendidos = *tLitrosVendidos + carros[0].litros;
            *tVendas = *tVendas + carros[0].conta;
            *tCarrosAtendidos = *tCarrosAtendidos + 1;

            switch(carros[0].tipoDeCombustivel){ 
              //relatorio individual de cada tipo de combustivel
              case(1):
                *tLitrosVendidosGC = *tLitrosVendidosGC + carros[0].litros;
                *tVendasGC = *tVendasGC + carros[0].conta;
              break;
        
              case(2):
                *tLitrosVendidosGA = *tLitrosVendidosGA + carros[0].litros;
                *tVendasGA = *tVendasGA + carros[0].conta;
              break;
              
              case(3):
                *tLitrosVendidosET = *tLitrosVendidosET + carros[0].litros;
                *tVendasET = *tVendasET + carros[0].conta;
              break;
            
            }
          
            p = &carros[0]; //p = ponteiro do primeiro carro
          
            for(int i = 0; i <= *nCarrosFila; i++){
              *(p+i) = *(p+1+i); 
            }
          
            p = &carros[*nCarrosFila];//p = ponteiro do ultimo carro que vai ser removido

            //removendo o ultimo
            strcpy( (*p).dono , "\n");
            strcpy( (*p).modelo , "\n");
            strcpy( (*p).placa , "\n");
            (*p).tipoDeCombustivel= 0;
            (*p).litros= 0;
            (*p).conta = 0;
          
            *nCarrosFila = *nCarrosFila - 1; //remove um carro da fila
            printf("\n\nCarro removido\n\n");

            pausa();
            *carroAbastecido = false;
            
          }else{
            if(*nCarrosFila <= 0){
              printf("\nFila vazia...");
            
            }else{   
              printf("\nChame o proximo...");
              
            }
          }          
          
        break;
      
        case(2):
          ll();
        break;
            
        default:
          printf("Opção invalida.\n\n");
        break; 
        }
     }

  if(*nCarrosFila <= 0){
    ll();
    printf("\n0 carros na fila!!\n\n");
  }
  
 pausa();
 ll();
}

void chamarCarro(bool *carroAbastecido, int nCarrosFila){
 //função para chamar o proximo carro na fila
  ll();
  
  if(nCarrosFila > 0){
    printf("\nCarro foi chamado.\n\n");
    *carroAbastecido = true;
  }else{
    printf("\nFila Vazia.\n\n");
  }

  pausa();
  ll();
}

void relatorios(struct TCarro *carros, int nCarrosFila, float  bombaGasolinaComum, float  bombaGasolinaAd, float bombaEtanol, float tLitrosVendidos, float tVendas, int tCarrosAtendidos, float tLitrosVendidosGC, float tVendasGC, float tLitrosVendidosGA, float tVendasGA, float tLitrosVendidosET, float tVendasET){ 
 //função para o menu dos relatorios 
  ll();
  int subMenu;

  while (subMenu != 6 ) {
    printf("1-Quantidade de litros vendidos.\n");
    printf("2-Valor total arrecadado com as vendas.\n");
    printf("3-Quantidade de carros atendidos.\n");
    printf("4-Quantidade de combustível restante em cada tanque.\n");
    printf("5-Carros na fila.\n");
    printf("6-Voltar ao menu principal.\n");
    scanf("%d", &subMenu);
    
    switch (subMenu) {
  
      case 1:
        ll();
        printf("Litros de todos os combustíveis: %.2f\n", tLitrosVendidos);
        printf("Litros gasolina comum: %.2f\n", tLitrosVendidosGC);
        printf("Litros gasosina aditivada: %.2f\n", tLitrosVendidosGA);
        printf("Litros Etanol: %.2f\n\n", tLitrosVendidosET);
      break;

      case 2:
        ll();
        printf("Valor arrecadado total: R$:%.2f\n", tVendas);
        printf("Valor arrecadado com gasolina comum: R$:%.2f\n", tVendasGC);
        printf("Valor arrecadado com gasolina aditivada: R$:%.2f\n", tVendasGA);
        printf("Valor arrecadado com etanol: R$:%.2f\n\n", tVendasET);
      break;

      case 3:
        ll();
        printf("Total de carros atentidos: %d\n\n", tCarrosAtendidos);
      break;

      case 4:
        ll();
        printf("Tanque de gasolina comum: %.2f litros.\n", bombaGasolinaComum);
        printf("Tanque de gasolina aditivada: %.2f litros.\n", bombaGasolinaAd);
        printf("Tanque de etanol: %.2f litros.\n\n\n", bombaEtanol);
      break;

      case 5:
        exibirCarros(carros, nCarrosFila);
      break;

      case 6:
        ll();
      break;

      default:
      printf("Opção invalida.\n\n");
      break;    
    }
  }  
  ll();
}

void exibirCarros(struct TCarro *carros, int nCarrosFila) {
  int i;
  ll();

  if (nCarrosFila > 0) {
    for (i = 0; i < nCarrosFila; i++) {

      printf("Carro: %d.\n", (i + 1));
      printf("Nome do dono: %s\n", carros[i].dono);
      printf("Modelo do carro: %s\n", carros[i].modelo);
      printf("Placa do carro: %s\n", carros[i].placa);
      switch (carros[i].tipoDeCombustivel) { //mostrar o tipo de combustivel
        case 1:
          printf("Tipo de combustivel %d: gasolina comum\n", carros[i].tipoDeCombustivel);
          break;
        case 2:
          printf("Tipo de combustivel %d: gasolina aditivada\n", carros[i].tipoDeCombustivel);
          break;
        case 3:
          printf("Tipo de combustivel %d: etanol\n", carros[i].tipoDeCombustivel);
          break;  
      }
      printf("Quantidade de litros: %.2f\n", carros[i].litros);
      printf("Conta: %.2f\n\n", carros[i].conta);
    }

  } else {
    printf("\n0 carros na fila.\n");
    pausa();
    ll();
  }
  printf("\n\n\n");
}

void addCombustivel(float *bombaGasolinaComum, float *bombaGasolinaAd, float *bombaEtanol) {
  
  int sMenu;
  bool aux = 0;//aux 
  float litros;
  ll();
  
  while(sMenu != 4){

    aux= 0; 

    printf("\nAdicionar/Remover combustível na bomba de:\n");
    printf("1-Gasolina comum: %.2f litros\n2-Gasolina Aditivada: %.2f litros\n3-Etanol: %.2flitros\n4-Voltar ao menu principal\n", *bombaGasolinaComum, *bombaGasolinaAd, *bombaEtanol);
    scanf("%d", &sMenu);

    switch(sMenu){

      case 1:

        while(aux == 0){ 
          
          printf("\nQuantos litros quer adicionar ou remover: ");
          scanf("%f", &litros);

          if ((*bombaGasolinaComum + litros) >= 0){
            *bombaGasolinaComum = *bombaGasolinaComum + litros;
            aux = 1;
          }else{
            printf("\nEscreva uma quantidade válida\n");
          }
        }
        
      break;

      case 2:

        while(aux == 0){ 
          
          printf("\nQuantos litros quer adicionar ou remover: ");
          scanf("%f", &litros);

          if ((*bombaGasolinaAd + litros) >= 0){
            *bombaGasolinaAd = *bombaGasolinaAd + litros;
            aux = 1;
          }else{
            printf("\nEscreva uma quantidade válida\n");
          }
        }

      break;

      case 3:
        
        while(aux == 0){ 
          
          printf("\nQuantos litros quer adicionar ou remover: ");
          scanf("%f", &litros);

          if ((*bombaEtanol + litros) >= 0){
            *bombaEtanol = *bombaEtanol + litros;
            aux = 1;
          }else{
            printf("\nEscreva uma quantidade válida\n");
          }
        }

      break;

      case 4:
        ll();
      break;

      default:
        printf("\nInsira um opção válida\n");

      break;
    }
    
    ll();
  }

  ll();

}


//retorna a string sem \n no final
void lerString(char *string, int tamanho){
  fgets(string, tamanho, stdin);
  string[strcspn(string, "\n")] = 0; //tirar o "\n" da string
}

//limpa o buffer quando lê uma string
void limpaBuffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

//limpa a tela
void ll(){
  printf("\n\nPressione Enter para continuar...\n");
  limpaBuffer();
  #ifdef __linux__
    system("clear");
  #elif _WIN32  
    system("cls");
  #else
  #endif
}

//pausa o sistema
void pausa(){
  #ifdef __linux__
    usleep(1000);
  #elif _WIN32    
    sleep(1);
  #else
  #endif
}
