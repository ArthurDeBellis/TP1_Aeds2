#ifndef TAD_PATRICIA_H
#define TAD_PATRICIA_H
#include "IndInverso.h"

typedef enum{
  Interno, Externo
}TipoNo;

typedef struct NoPatricia *Apontador;

typedef struct NoPatricia{
  TipoNo noArvore;
  /*union que contém as structs dos nós internos e externos*/
  union{
    struct{
      char letra;
      int posicao;
      Apontador Esq, Dir;
    }NoInterno;
      char *chave;
  }No;
}NoPatricia;

//Funções implementadas
void InicializaPatricia(Apontador *arvore);
short ConfereNoExterno(Apontador arvore);
Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir);
Apontador CriaNoExt(char *palavra);
void Pesquisa(char *Chave, Apontador arvore);
Apontador InsereEntre(char *Chave, Apontador *arvore, int i);
Apontador Insere(char *Chave, Apontador *arvore);

#endif
