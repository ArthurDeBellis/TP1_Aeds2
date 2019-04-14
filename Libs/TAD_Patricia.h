#ifndef TAD_PATRICIA_H
#define TAD_PATRICIA_H

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
      /*struct da TST*/
    }NoExterno;
  }No;
}NoPatricia;

//Funções
int ConfereNoExterno(Apontador arvore);
Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir);
Apontador CriaNoExt(char *palavra);
void Pesquisa(char *Chave, Apontador arvore);

#endif
