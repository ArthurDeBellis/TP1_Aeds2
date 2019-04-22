#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/listaBusca.h"

void FPVazia(TipoPilha *Pilha)
{
  Pilha->pTopo = (ApontadorPilha) malloc(sizeof(TCelulaPilha));
  Pilha->pFundo = Pilha->pTopo;
  Pilha->pTopo->pProx = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{
  return (Pilha.pTopo == Pilha.pFundo);
}

void Empilha(char *chave, TipoPilha *Pilha)
{
  ApontadorPilha Aux;
  Aux = (ApontadorPilha) malloc(sizeof(TCelulaPilha));
  Pilha->pTopo->chaveBusca = (char*)malloc(sizeof(char));
  strcpy(Pilha->pTopo->chaveBusca, chave);
  Aux->pProx = Pilha->pTopo;
  Pilha->pTopo = Aux;
  Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, char *chave)
{
  ApontadorPilha q;
  if (Vazia(*Pilha)) {
    printf("Erro: lista vazia\n");
    return;
}
  q = Pilha->pTopo;
  Pilha->pTopo = q->pProx;
  strcpy(chave, q->pProx->chaveBusca);
  //chave = q->pProx->chaveBusca;
  free(q);
  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{
  return (Pilha.Tamanho);
}
