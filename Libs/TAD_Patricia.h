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
    struct{
      char *chave;
      ApIndInverso Ind;
    }NoExterno;
  }No;
}NoPatricia;

//Funções
char Letra(int posicao, char *Chave);
int ConfereNoExterno(Apontador arvore);
Apontador CriaNoInt(int index, char* letra, Apontador *esq, Apontador *dir);
void CriaNoExt(char *palavra, Apontador *arvore);
void Pesquisa(char *Chave, Apontador arvore);
Apontador InsereEntre(char *Chave, Apontador *arvore, int i);
Apontador Insere(char *Chave, Apontador *arvore);
int MenorPalavra(char* palavra1, char* palavra2);
#endif
