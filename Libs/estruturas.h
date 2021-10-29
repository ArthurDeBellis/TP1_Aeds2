#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

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

typedef struct TCelula *ApIndInverso; //Criação de um Apontador da lista do Indice Inverso

typedef struct TCelula{
  char *nome; //Struct da celula da pilha
  int qtde;
  int idDoc;
  ApIndInverso pProx;
}TCelula;

typedef struct{ //Struct da Pilha
  ApIndInverso pPrimeiro;
  ApIndInverso pUltimo;
}TLista;

typedef enum{
  Interno, Externo
}TipoNo;

typedef struct NoPatricia *Apontador;

typedef struct CelRelevancia *ApRel;

typedef struct Celbusca *ApBus;

typedef struct NoPatricia{
  TipoNo noArvore;
  /*union que contém as structs dos nós internos e externos*/
  union{
    struct{
      char letra;
      int posicao;
      Apontador Esq, Dir;
    }NoInterno;
    struct{
      char *chave;
      TLista lista;
    }NoExterno;
    }No;
}NoPatricia;

typedef struct CelRelevancia{
  float relevancia;
  int idDoc;
  ApRel pProx;
}CelRelevancia;

typedef struct{
  ApRel pPrimeiro;
  ApRel pUltimo;
}LRelevancia;

typedef struct Celbusca{
  char *nome;
  ApBus pProx;
}Celbusca;

typedef struct{
  ApBus pPrimeiro;
  ApBus pUltimo;
}LBusca;


#endif