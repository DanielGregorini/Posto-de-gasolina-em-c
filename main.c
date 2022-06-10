#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include "header.h"

int main(void){

  //variaveis
  float gasolinaComum, gasolinaAd, etanol; //preços
  int tCarrosAtendidos= 0; //relatorios
  float tLitrosVendidos = 0, tVendas = 0; //relatorios
  float tLitrosVendidosGC = 0, tVendasGC = 0; //relatorios
  float tLitrosVendidosGA = 0, tVendasGA = 0; //relatorios
  float tLitrosVendidosET = 0, tVendasET = 0; //relatorios
  int fila = 0, nCarrosFila = 0, menu = 0; //tamanho da fila, numero de caros na fila, e menu
  float bombaGasolinaComum = 200, bombaGasolinaAd = 200, bombaEtanol = 200; //tanques
  bool carroAbastecido = false; //variavel para saber se foi chamado outro carro
  struct TCarro *carros; //o vetor com struct do registro de carros
  
  printf("\nDaniel Mahl Gregorini - UTFPR Medianeira\n\n\n");
  printf("Olá, Bem-vindo!\n");
  printf("Esse programa vai ajudar o gerenciamento de um posto de combustíveis.\n");
  ll();
  
  //preços e fila
  do{
    printf("\nInforme o preço da gasolina comum: R$:");
    scanf("%f", &gasolinaComum);
    ll();
    printf("\nInforme o preço da gasolina aditivada: R$:");
    scanf("%f", &gasolinaAd);
    ll();
    printf("\nInforme o preço do etanol:  R$:");
    scanf("%f", &etanol);
    ll();
    printf("\nInforme o tamanho da fila de carros: ");
    scanf("%d", &fila);
    ll();
    
    //verifica se os valores dos combustiveis sao negativos
    if (gasolinaComum <= 0 || gasolinaAd <= 0 || etanol <= 0 || fila <=0){
      printf("Algum valor foi informado errado, por favor corrija\n");
    }
  } while(gasolinaComum <= 0 || gasolinaAd <= 0 || etanol <= 0 || fila <=0); 

  
 //litros na bomba
  do{
    printf("\nInforme quantos litros têm no bomba de gasolina comum: ");
    scanf("%f", &bombaGasolinaComum);
    ll();
    printf("\nInforme quantos litros têm no bomba de gasolina aditivada: ");
    scanf("%f", &bombaGasolinaAd);
    ll();
    printf("\nInforme quantos litros têm na bomba de etanol: ");
    scanf("%f", &bombaEtanol);
    ll();
    //verifica se os valores dos combustiveis sao negativos
    if (bombaGasolinaComum <= 0 || bombaGasolinaComum <= 0 || bombaEtanol <= 0){
      printf("Algum valor foi informado errado, por favor corrija\n");
    }
  } while(bombaGasolinaComum <= 0 || bombaGasolinaComum <= 0 || bombaEtanol <= 0); 

  //alocando dinamicamente o vetor principal
  carros = (struct TCarro*) calloc(fila, sizeof(struct TCarro)); 

  //menu principal
  while (menu != 6) {
    
     //printf("\nGC: R$%.2f, GA: R$%.2f, ET: R$%.2f.\n", gasolinaComum, gasolinaAd, etanol);
     printf("MENU PRINCIPAL:\n\n");
     printf("1-Adicionar um carro na fila.\t\t\tFila:%d/%d\n",nCarrosFila, fila);
     printf("2-Abastecer carro.\n");
     printf("3-Chamar o próximo.\n");
     printf("4-Relatórios.\n");
     printf("5-Adicionar combustível nas bombas.\n");
     printf("6-Encerrar. \n");
     scanf("%d", &menu);

    switch (menu){
 
      case (1):
        addCarro(carros, &nCarrosFila, fila, gasolinaComum, gasolinaAd, etanol, &bombaGasolinaComum, &bombaGasolinaAd, &bombaEtanol);
        break;
      
      case (2):
        abastecer(carros, &nCarrosFila, fila, &tLitrosVendidos, &tVendas, &tCarrosAtendidos, &tLitrosVendidosGC, &tVendasGC, &tLitrosVendidosGA, &tVendasGA, &tLitrosVendidosET, &tVendasET, &carroAbastecido);
        break;
      
      case (3):
        chamarCarro(&carroAbastecido, nCarrosFila);
        break;
      
      case (4): 
        relatorios(carros, nCarrosFila, bombaGasolinaComum, bombaGasolinaAd, bombaEtanol, tLitrosVendidos, tVendas, tCarrosAtendidos, tLitrosVendidosGC, tVendasGC, tLitrosVendidosGA, tVendasGA, tLitrosVendidosET, tVendasET);
        break;
      
      case (5):
        addCombustivel(&bombaGasolinaComum, &bombaGasolinaAd, &bombaEtanol);
        
        break;

      case (6):
        printf("Você selecionou a opção 6: Encerrar\n\n");
        
        break;
      
      default:
        printf("Opção invalida!!\n\n");
        sleep(1);
        ll();
        break;
        }
    }

  free(carros);
  return 0;
}