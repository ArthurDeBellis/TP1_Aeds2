#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/TAD_Patricia.h"

int main(){
  Apontador arvore = NULL;
  Insere("Carlos", &arvore);
  Pesquisa("Carlos", arvore);

  Insere("Arthur", &arvore);
  Pesquisa("Arthur", arvore);

  Insere("Saulo", &arvore);
  Pesquisa("Saulo", arvore);

  Insere("Pablo", &arvore);
  Pesquisa("Pablo", arvore);

  Insere("Samuel", &arvore);
  Pesquisa("Samuel", arvore);
  return 0;
}
