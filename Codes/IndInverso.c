#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/IndInverso.h"

int IniciaLista(TLista *pLista){
  ApIndInverso Celula = NULL;
  //Definindo os valor de pPrimeiro e pUltimo como nulos para iniciar a lista
  Celula = (ApIndInverso)malloc(sizeof(TCelula));
  Celula->qtde = 0;
  Celula->idDoc = 0;
  Celula->pProx = NULL;
  pLista->pPrimeiro = Celula;
  pLista->pUltimo = Celula;
  return 1;
}
int ListaVazia(TLista Lista){
  //Se o ponteiro for nulo retorna 1
  if(Lista.pPrimeiro == Lista.pUltimo){
    return 1;
  }
  else{
    return 0;
  }
}
void InserirNovo(TLista *Lista, int idDoc){
  ApIndInverso Celula = NULL, p = NULL;
  int i = 0; //contador
  if(ListaVazia(*Lista)){
    //Conferindo se a lista é vazia, se sim, define todos os valores
    Celula = (ApIndInverso)malloc(sizeof(TCelula));
    Celula->qtde = 1;
    Celula->idDoc = idDoc;
    Celula->pProx = NULL;
    Lista->pUltimo->pProx = Celula;
    Lista->pUltimo = Celula;
    return;
  }
  else{
    p = Lista->pUltimo;
    if(p->idDoc == idDoc){
      p->qtde++;
    }
    else{
      Celula = (ApIndInverso)malloc(sizeof(TCelula));
      Celula->qtde = 1;
      Celula->idDoc = idDoc;
      Celula->pProx = NULL;
      p->pProx = Celula;
      Lista->pUltimo = Celula;
      return;
    }

  }
}

void ImprimirLista(TLista Lista){
  ApIndInverso p = NULL;
  p = Lista.pPrimeiro;
  if(ListaVazia(Lista))
    printf("Lista vazia!");
  else{
    p = Lista.pPrimeiro->pProx;
    while(p!=NULL){//Percorrendo e conferindo se a palavra está inserida em algum texto
      printf("idDoc = %d\n", p->idDoc);
      printf("Quantidade = %d\n", p->qtde);
      p = p->pProx;
    }
  }
}
