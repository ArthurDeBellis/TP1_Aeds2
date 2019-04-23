/*

Trabalho feito por:

Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480

*/

#ifndef TAD_PATRICIA_H
#define TAD_PATRICIA_H
#include "IndInverso.h"

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


//Funções implementadas
void InicializaPatricia(Apontador *arvore);
short ConfereNoExterno(Apontador arvore);
Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir);
Apontador CriaNoExt(char *palavra, int idDoc);
Apontador Pesquisa(char *Chave, Apontador arvore);
Apontador InsereEntre(char *Chave, char comp,Apontador *arvore, int i, int idDoc);
Apontador Insere(char *Chave, Apontador *arvore, int idDoc);
void Ni(Apontador arvore, int arquivo, int *ni);
int OcorrenciadeChaveemI(Apontador arvore, char* Chave, int i);
int DocumentoscomChave(Apontador arvore, char* Chave);
float PesoTermo(float n, Apontador arvore, char *Chave, int idDoc);
float Relevancia(float n, int q, int ni, char *Chave, Apontador arvore, LBusca *busca, int narquivo);

int IniciaListaRelevancia(LRelevancia *pLista);
int ListaRelevanciaVazia(LRelevancia Lista);
void InserirNovoRelevancia(LRelevancia *Lista, float relevancia, int narquivo);

void RelevanciaFinal(Apontador arvore, int q, char *Chave, LRelevancia *Lista, float n, float idDoc, LBusca *busca, int narquivo);
void ImprimirListaRelevancia(LRelevancia Lista);
int IniciaListaBusca(LBusca *pLista);
void InserirNovoBusca(LBusca *Lista, char *nome);
#endif
