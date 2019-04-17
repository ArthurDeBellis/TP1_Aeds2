#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/TAD_Patricia.h"

int main(){
  Apontador arvore;

  InicializaPatricia(&arvore);

  arvore = Insere("Arthur", &arvore);
  Pesquisa("Arthur", arvore);

  arvore = Insere("Pablo", &arvore);
  Pesquisa("Pablo", arvore);

  arvore = Insere("Saulo", &arvore);
  Pesquisa("Saulo", arvore);

  arvore = Insere("Apatico", &arvore);
  Pesquisa("Apatico", arvore);

  arvore = Insere("Pablo", &arvore);
  return 0;
}
