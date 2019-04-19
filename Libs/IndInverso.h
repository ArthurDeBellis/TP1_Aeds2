#ifndef INDINVERSO_H
#define INDINVERSO_H

typedef struct TCelula *ApIndInverso;

typedef struct TCelula{
  int qtde;
  int idDoc;
  ApIndInverso pProx;
}TCelula;

typedef struct{
  ApIndInverso pPrimeiro;
  ApIndInverso pUltimo;
}TLista;

//Funções
int IniciaLista(TLista *pLista);
int ListaVazia(TLista Lista);

void InserirNovo(TLista *Lista, int idDoc);
//void InserirUltimo(TLista *Lista, int qtde, int idDoc);


//ApIndInverso ProcurarLista (TLista *pLista, int Id);

void ImprimirLista(TLista Lista);


#endif
