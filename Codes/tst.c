#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "tst.h"

NoTST* CriarNoTST (char letra, ntipo t)
{
  NoTST *NoTST = (struct NoTST*)malloc(sizeof(struct NoTST));
  NoTST->letra = letra;
  NoTST->Esq = NULL;
  NoTST->Meio = NULL;
  NoTST->Dir= NULL;
  NoTST->Fim = t;

  return NoTST;
}

NoTST* InserirNoTST (const char* palavra, NoTST* NoTST)
{
  int i = strlen(palavra);

  if(NULL == NoTST)
    NoTST = CriarNoTST(palavra[0], NAO);

  if(palavra[0] < NoTST->letra)
	  NoTST->Esq = InserirNoTST(palavra, NoTST->Esq);

  else if(palavra[0] > NoTST->letra)
	  NoTST->Dir = InserirNoTST(palavra, NoTST->Dir);

  else {

	  if(i == 1) {
		  NoTST->Fim = SIM;
		  return NoTST;
	  } else
		  NoTST->Meio = InserirNoTST(++palavra,NoTST->Meio);
  }

  return NoTST;
}

NoTST* BuscarNoTST(NoTST *arvore, const char* palavra)
{
  long unsigned int i = 0;
  NoTST* NoTST = arvore;

  while(i < strlen(palavra)) {
	  if(NULL  == NoTST)
		  break;
	  if(palavra[i] < NoTST->letra)
		  NoTST = (NoTST)->Esq;
	  else if(palavra[i] > (NoTST)->letra)
		  NoTST = (NoTST)->Dir;
	  else {
		  if(i++ == strlen(palavra)-1)
		      return NoTST;
		  else
		  NoTST = (NoTST)->Meio;
	  }
  }

  return NULL;
}

int OrdemAux(NoTST *arvore, char *recebePalavra, int i){
  if(arvore != NULL){
    OrdemAux(arvore->Esq, recebePalavra, i);
    recebePalavra[i] = arvore->letra;
    if(arvore->Fim){
      recebePalavra[i+1]= '\0';
      printf("%s\n", recebePalavra);
    }
    OrdemAux(arvore->Meio, recebePalavra, i+1);
    OrdemAux(arvore->Dir,recebePalavra, i);
    return 1;
  }
  return 0;
}

void Ordem(NoTST *arvore){
  char recebePalavra[100];
  OrdemAux(arvore, recebePalavra,0);
}