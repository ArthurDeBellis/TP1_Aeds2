#ifndef LISTABUSCA_H
#define LISTABUSCA_H

typedef struct TCelulaPilha *ApontadorPilha;

typedef struct TCelulaPilha{
  char *chaveBusca;
  ApontadorPilha pProx;
}TCelulaPilha;

typedef struct{
  ApontadorPilha pFundo;
  ApontadorPilha pTopo;
  int Tamanho;
}TipoPilha;

//Funções
void FPVazia(TipoPilha *Pilha);
int Vazia(TipoPilha Pilha);
void Empilha(char *chave, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha, char *chave);
int Tamanho(TipoPilha Pilha);

/*int IniciaLista(TLista *pLista);
int ListaVazia(TLista Lista);
void InserirNovo(TLista *Lista, int idDoc);
//void InserirUltimo(TLista *Lista, int qtde, int idDoc);
//ApIndInverso ProcurarLista (TLista *pLista, int Id);

void ImprimirLista(TLista Lista);
*/

#endif
