#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Libs/TAD_Patricia.h"

//A função verifica se o nó é externo
char Letra(int posicao, char *Chave){ /* Retorna o i-esimo Letra da chave k a partir da esquerda */
  int j;
  char c;
  if (posicao == 0){
    return 0;
  }
  else {
     for (j = 1; j <= strlen(Chave); j++){
       c = Chave[j-1];
     }
     return (c);
   }
}

int ConfereNoExterno(Apontador arvore){
  return(arvore -> noArvore == Externo);
}

Apontador CriaNoInt(int index, char *letra, Apontador *esq, Apontador *dir){
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore -> No.NoInterno.Esq= *esq;
  arvore -> No.NoInterno.Dir= *dir;
  arvore -> No.NoInterno.posicao= index;
  strcpy(&(arvore->No.NoInterno.letra), letra);
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
Apontador InsereEntre(char *Chave, Apontador *arvore, int i){
  Apontador p;
  if (ConfereNoExterno(*arvore) || i < (*arvore)->No.NoInterno.posicao){ /* cria um novo no externo */
    p = CriaNoExt(Chave);
  if (Letra(i, Chave) == 1)
    return (CriaNoInt(i, Chave, arvore, &p));
  else
    return (CriaNoInt(i, Chave, &p, arvore));
  }
  else{
    if (Letra((*arvore)->No.NoInterno.posicao, Chave) == 1)
      (*arvore)->No.NoInterno.Dir = InsereEntre(Chave,&(*arvore)->No.NoInterno.Dir,i);
  else
    (*arvore)->No.NoInterno.Esq = InsereEntre(Chave,&(*arvore)->No.NoInterno.Esq,i);
  return (*arvore);
  }
}
Apontador Insere(char *Chave, Apontador *arvore){
  Apontador p;
  int i;
  if (*arvore == NULL)
    return (CriaNoExt(Chave));
  else{
    p = *arvore;
    while (!ConfereNoExterno(p)){
      if (Letra(p->No.NoInterno.posicao, Chave) == 1)
        p = p->No.NoInterno.Dir;
      else
        p = p->No.NoInterno.Esq;
    }
/* acha o primeiro Letra diferente */
  i = 1;
  while ((i <= MenorPalavra(Chave, p->No.NoExterno.chave)) & (Letra((int)i, Chave) == Letra((int)i, p->No.NoExterno.chave))){
    i++;
  }
  if (i > MenorPalavra(Chave, p->No.NoExterno.chave)){
    printf("Erro: chave ja esta na arvore\n"); return (*arvore);
  }
  else
    return (InsereEntre(Chave, arvore, i));
  }
}
int MenorPalavra(char* palavra1, char* palavra2){
  int i, j;
  i = strlen(palavra1);
  j = strlen(palavra2);
  if(i>j)
    return j;
  else
    return i;
}
