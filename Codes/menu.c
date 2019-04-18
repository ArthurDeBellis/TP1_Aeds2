#include <stdio.h>
#include <stdlib.h>
#include "../Libs/menu.h"

void menu_de_entradas(){
  printf("====================================================================\n");
  printf("|                                                                  |\n");
  printf("|                           TP01 AEDS 2                            |\n");
  printf("|                                                                  |\n");
  printf("====================================================================\n");

  printf("\n");

  printf("  1. Construir a Árvore.\n");
  printf("  2. Buscar na Árvore.\n");
  printf("  0. Desejo sair.\n");
  
  printf("\n");

  printf("====================================================================\n");

  printf("Modo escolhido: ");
}

void menu_de_confirmacao(){
  printf("====================================================================\n");
  printf("\n");
  printf("Você deseja realmente parar a execução do programa?\n");
  printf("[S/n]: ");
}

void menu_de_saida(){
  printf("====================================================================\n");
  printf("\n");
  printf("Trabalho feito por:\n\n -> Arthur De Bellis - 03503\n -> Saulo Miranda Silva - 03475\n -> Pablo Ferreira - 03480\n");
  printf("\n");
  printf("====================================================================\n");
}

void menu_de_odenacoes(){
  printf("====================================================================\n");
  printf("|                                                                  |\n");
  printf("|               Selecione o Algoritmo de Ordenação:                |\n");
  printf("|                                                                  |\n");
  printf("====================================================================\n");

  printf("\n");

  printf("1. Bolha.\n");
  printf("2. Seleção.\n");
  printf("3. Inserção.\n");
  printf("4. ShellSort.\n");
  printf("5. QuickSort.\n");
  printf("6. HeapSort.\n");
  printf("0. Sair.\n");

  printf("\n");

  printf("====================================================================\n");

  printf("Algoritmo escolhido: ");
}

void menu_arquivo(){
  printf("====================================================================\n");
  printf("|                                                                  |\n");
  printf("|               Nome do Arquivo: cenario[N]:                       |\n");
  printf("|               N - 1 à 12                                         |\n");
  printf("|               N - 0 Sair                                         |\n");
  printf("|                                                                  |\n");
  printf("====================================================================\n");

}
