#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/IndInverso.h"

void IniciaLista(TLista *pLista){
  //Definindo os valor de pPrimeiro e pUltimo como nulos para iniciar a lista
  pLista->pPrimeiro = NULL;
  pLista->pUltimo = NULL;
}
int ListaVazia(TLista Lista){
  //Se o ponteiro for nulo retorna 1
  if(Lista.pPrimeiro == NULL){
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
    Lista->pPrimeiro = Celula;
    Lista->pUltimo = Celula;
    return;
  }
  else{
    p = Lista->pPrimeiro;
    while(p==NULL){//Percorrendo e conferindo se a palavra está inserida em algum texto
      if(idDoc == p->idDoc){
        p->qtde++;
        i=1;
      }
      p = p->pProx;
    }
    if(i==0){
      /*se i=0, ou seja, se a palavra não está em nenhum documento já registrado, cria uma nova célula
      para o documento atual e adiciona 1 à quantidade*/
      Celula = (ApIndInverso)malloc(sizeof(TCelula));
      Lista->pUltimo->pProx = Celula;
      Lista->pUltimo = Celula;
      Celula->qtde = 1;
      Celula->idDoc = idDoc;
      Celula->pProx = NULL;
    }
  }
}

void ImprimirLista(TLista Lista){
  ApIndInverso p = NULL;
  if(ListaVazia(Lista))
    printf("Lista vazia!");
  else{
    p = Lista.pPrimeiro;
    while(p==NULL){//Percorrendo e conferindo se a palavra está inserida em algum texto
      printf("idDoc = %d", p->idDoc);
      printf("Quantidade = %d", p->qtde);
      p = p->pProx;
    }
  }
}
