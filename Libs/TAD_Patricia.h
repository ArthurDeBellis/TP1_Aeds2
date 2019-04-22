#ifndef TAD_PATRICIA_H
#define TAD_PATRICIA_H
#include "IndInverso.h"

typedef enum{
  Interno, Externo
}TipoNo;

typedef struct NoPatricia *Apontador;

typedef struct CelRelevancia *ApRel;

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
  char nome[25];
  ApRel pProx;
}CelRelevancia;

typedef struct{
  ApRel pPrimeiro;
  ApRel pUltimo;
}LRelevancia;

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
float PesoTermo(float n, float d, float f);
float Relevancia(float n, float d, float f, int q, int ni);

int IniciaListaRelevancia(LRelevancia *pLista);
int ListaRelevanciaVazia(LRelevancia Lista);
void InserirNovoRelevancia(LRelevancia *Lista, float relevancia, char *nome);

void RelevanciaFinal(Apontador arvore, int q, char *Chave, int idDoc, float nArquivos, LRelevancia *Lista);
void ImprimirListaRelevancia(LRelevancia Lista);
#endif
