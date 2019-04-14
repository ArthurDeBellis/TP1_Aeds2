#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Libs/TAD_Patricia.h"

//A função verifica se o nó é externo
int ConfereNoExterno(Apontador arvore){
  return(arvore -> noArvore == Externo);
}

Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir){
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore -> No.NoInterno.Esq= *esq;
  arvore -> No.NoInterno.Dir= *dir;
  arvore -> No.NoInterno.posicao= index;
  strcpy(&(arvore -> No.NoInterno.letra), &letra);
  return arvore;
}

Apontador CriaNoExt(char *palavra){
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore -> noArvore = Externo;
  strcpy(arvore -> No.NoExterno.chave, palavra);
  return arvore;
}

void Pesquisa(char *Chave, Apontador arvore){
  if(ConfereNoExterno(arvore)){
    //Comparando no externo
    if(strcmp(Chave, arvore->No.NoExterno.chave) == 0)
      printf("Elemento encontrado\n");
    else
      printf("Elemento não encontrado\n");
    return;
  }
  //Desvios, se a posição e letra for menor vai para a esquerda, se não, vai para a direita
  if(strlen(Chave) >= arvore->No.NoInterno.posicao && Chave[arvore->No.NoInterno.posicao] < (arvore)->No.NoInterno.letra)
    Pesquisa(Chave, arvore->No.NoInterno.Esq);
  else
    Pesquisa(Chave, arvore->No.NoInterno.Dir);
}
