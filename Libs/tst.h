#ifndef TST_H
#define TST_H


enum ntipo {NAO,SIM}; // não entendi isso aqui, mas presumi q era o marcador de fim de string

typedef struct NoTST {
  char letra;
  struct NoTST* Esq;
  struct NoTST* Dir;
  struct NoTST* Meio;
  enum ntipo Fim;
}NoTST;

NoTST* RAIZ;

NoTST* CriarNoTST(char letra, enum ntipo t);
NoTST* InserirNoTST(const char* palavra, NoTST* No);
NoTST* BuscarNoTST(const char* palavra);

void ImprimirMesmoPrefixo(const char* prefixo);

#endif
