#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#ifndef TST_H
#define TST_H

typedef enum ntipo {
  NAO,SIM
}ntipo;

typedef struct NoTST {
  char letra;
  struct NoTST* Esq;
  struct NoTST* Dir;
  struct NoTST* Meio;
  ntipo Fim;
}NoTST;

NoTST* RAIZ;

NoTST* CriarNoTST(char letra, ntipo t);
NoTST* InserirNoTST(const char* palavra, NoTST* No);
NoTST* BuscarNoTST(NoTST* arvore, const char* palavra);
void BuscaProfunda(const char* prefixo, NoTST* inicio);
void ImprimirMesmoPrefixo(NoTST* arvore, const char* prefixo);

#endif

