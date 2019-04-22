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
#include "../Libs/IndInverso.h"

int IniciaLista(TLista *pLista){ // Função para criar a lista vazia
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
int ListaVazia(TLista Lista){ //Função para conferir se a lista é vazia
  //Se o ponteiro for nulo retorna 1
  if(Lista.pPrimeiro == Lista.pUltimo){
    return 1;
  }
  else{
    return 0;
  }
}
void InserirNovo(TLista *Lista, int idDoc,char *nome){ //Função para inserir um novo elemento na lista
  ApIndInverso Celula = NULL, p = NULL;
  int i = 0; //contador
  if(ListaVazia(*Lista)){
    //Conferindo se a lista é vazia, se sim, define todos os valores
    Celula = (ApIndInverso)malloc(sizeof(TCelula));
    Celula->qtde = 1;
    Celula->idDoc = idDoc;
    Celula->nome = (char*)malloc(sizeof(char));
    strcpy(Celula->nome, nome);
    Celula->pProx = NULL;
    Lista->pUltimo->pProx = Celula;
    Lista->pUltimo = Celula;
    return;
  }
  else{ // se a lista não for vazia a quantidade recebe +1 pois a palavra se repete no mesmo documento
    p = Lista->pUltimo;
    if(p->idDoc == idDoc){
      p->qtde++;
      return;
    }
    else{ //se a idDoc inserido for diferente do idDoc da palavra atual, é criado uma nova celula
      Celula = (ApIndInverso)malloc(sizeof(TCelula));
      Celula->qtde = 1;
      Celula->idDoc = idDoc;
      Celula->nome = (char*)malloc(sizeof(char));
      strcpy(Celula->nome, nome);
      Celula->pProx = NULL;
      p->pProx = Celula;
      Lista->pUltimo = Celula;
      return;
    }

  }
}

void ImprimirLista(TLista Lista){ //Função para imprimir lista
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
