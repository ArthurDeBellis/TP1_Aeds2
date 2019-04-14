#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Libs/tst.h"

NoTST* CriarNoTST (char w, enum ntipo t)
{
  NoTST *NoTST = (struct NoTST*)malloc(sizeof (struct NoTST));
  NoTST->letra = letra;
  NoTST->Esq = NULL;
  NoTST->Meio = NULL;
  NoTST->Dir= NULL;
  NoTST->ntipo = t;

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
		  NoTST->ntipo = SIM;
		  return NoTST;
	  } else
		  NoTST->Meio = InserirNoTST(++palavra,NoTST->Meio);
  }

  return NoTST;
}

struct NoTST* BuscarNoTST(const char* palavra)
{
  int i = 0;
  NoTST* NoTST = RAIZ;

  while(i < strlen(palavra)) {
	  if(NULL  == NoTST)
		  break;
	  if(palavra[i] < NoTST->letra)
		  NoTST = NoTST->Esq;
	  else if(palavra[i] > NoTST->letra)
		  NoTST = NoTST->Dir;
	  else {
		  if(i++ == strlen(palavra) - 1  && NoTST->ntipo == SIM)
		      return NoTST;
		  else
		  NoTST = NoTST->Meio;
	  }
  }

  return NULL;
}

struct NoTST* BuscarNoTST2(const char* palavra)
{
  int i = 0;
  NoTST* NoTST = RAIZ;

  while(i < strlen(palavra)) {
	  if(NULL  == NoTST)
		  break;
	  if(palavra[i] < NoTST->letra)
		  NoTST = NoTST->Esq;
	  else if(palavra[i] > NoTST->letra)
		  NoTST = NoTST->Dir;
	  else {
		  if(i++ == strlen(palavra) - 1)
		      return NoTST;
		  else
		  NoTST = NoTST->Meio;
	  }
  }

  return NULL;
}

void BuscaProfunda(const char* prefixo, NoTST* inicio)
{

	if(inicio->ntipo != NAO)
		printf("ENCONTRADO:%s%c\n",prefixo,inicio->letra);

	if(inicio->Esq != NULL)
		BuscaProfunda(prefixo, inicio->Esq);

	if(inicio->Dir != NULL)
		BuscaProfunda(prefixo, inicio->Dir);

	if(inicio->Meio != NULL) {
		char *prefixo = (char *)malloc(strlen(prefixo) + 2);
		sprintf(prefixo,"%s%c",prefixo,inicio->letra);
		BuscaProfunda(prefixo,inicio->Meio);
	}
}

void ImprimirMesmoPrefixo(const char* prefixo)
{

	NoTST* corrente = BuscarNoTST2(prefixo);

	if(NULL == corrente)
		printf("Sem paçavras com o prefixo %s\n",prefixo);
	else {
		BuscaProfunda(prefixo,corrente->Meio);
	}
}
