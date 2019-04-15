#ifndef INDINVERSO_H
#define INDINVERSO_H

typedef struct IndInverso *ApIndInverso;

typedef struct IndInverso{
  int qtde;
  char* idDoc;
  ApIndInverso Prox;
}IndInverso;

#endif
