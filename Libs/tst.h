#ifndef TST_H
#define TST_H

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

NoTST* CriarNoTST(char letra, ntipo t);
NoTST* InserirNoTST(const char* palavra, NoTST* No);
int BuscarNoTST(NoTST *arvore, const char* palavra);
int OrdemAux(NoTST *arvore, char *recebePalavra, int i, char* pref);
void Ordem(NoTST *arvore, char* pref);
void AutoComplete(NoTST *arvore, char *pref, char* aux);

#endif
