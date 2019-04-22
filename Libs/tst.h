/*

Trabalho feito por:

Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480

*/
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

NoTST* CriarNoTST(char letra, ntipo t); //Funçào para criar um nó
NoTST* InserirNoTST(const char* palavra, NoTST* No); //Função que realiza a inserção
int BuscarNoTST(NoTST *arvore, const char* palavra); //Função de busca que retorna 1 se o elemento for achado e 0 se não
int OrdemAux(NoTST *arvore, char *recebePalavra, int i, char* pref); //Função auxiliar para imprimir a árvore inteira
void Ordem(NoTST *arvore, char* pref); //Função principal para imprimir a árvore
void AutoComplete(NoTST *arvore, char *pref, char* aux); //Função que recebe o prefixo e realiza o Auto Complete

#endif
