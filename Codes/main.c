#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/TAD_Patricia.h"

int main(){
  Apontador arvore = NULL;
  Insere("Carlos", &arvore);
  Pesquisa("Carlos", arvore);

  //Insere("Carlos", &arvore);
  //Pesquisa("Carlos", arvore);
  printf("\n");
  Insere("Carlosa", &arvore);
  Pesquisa("Carlos", arvore);
  printf("\n");
  //Insere("Pablo", &arvore);
  //Pesquisa("Pablo", arvore);
  //printf("\n");
  //Insere("Samuel", &arvore);
  //Pesquisa("Samuel", arvore);
  //printf("\n");
  return 0;
}
