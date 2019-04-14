#ifndef TAD_PATRICIA_H
#define TAD_PATRICIA_H

typedef enum{
  Interno, Externo
}TipoNo;

typedef struct IndInverso *ApIndInverso;

typedef struct NoPatricia *Apontador;

typedef struct IndInverso{
  int qtde;
  char* idDoc;
  ApIndInverso Prox;
}IndInverso;

typedef struct NoPatricia{
  TipoNo noArvore;
  /*union que contém as structs dos nós internos e externos*/
  union{
    struct{
      char letra;
      int posicao;
      Apontador Esq, Dir;
    }NoInterno;
    ApIndInverso Ind;
    struct{
      char *chave;
      /*struct da TST*/
    }NoExterno;
  }No;
}NoPatricia;

//Funções
char Letra(int posicao, char *Chave);
int ConfereNoExterno(Apontador arvore);
Apontador CriaNoInt(int index, char* letra, Apontador *esq, Apontador *dir);
Apontador CriaNoExt(char *palavra);
void Pesquisa(char *Chave, Apontador arvore);
Apontador InsereEntre(char *Chave, Apontador *arvore, int i);
int MenorPalavra(char* palavra1, char* palavra2);
#endif
