/*

Trabalho feito por:

Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480

*/

#ifndef LISTABUSCA_H
#define LISTABUSCA_H

typedef struct TCelulaPilha *ApontadorPilha; //Criação de um ApontadorPilha

typedef struct TCelulaPilha{ //Struct da celula da pilha
  char *chaveBusca;
  ApontadorPilha pProx;
}TCelulaPilha;

typedef struct{ //Struct da Pilha
  ApontadorPilha pFundo;
  ApontadorPilha pTopo;
  int Tamanho;
}TipoPilha;

//Funções
void FPVazia(TipoPilha *Pilha); //Função para criar uma pilha vazia
int Vazia(TipoPilha Pilha); //Função para conferir se a pilha é vazia
void Empilha(char *chave, TipoPilha *Pilha); //Função para empilhar a palavra
void Desempilha(TipoPilha *Pilha, char *chave); //Função para desempilhar a palavra
int Tamanho(TipoPilha Pilha); //Função para saber o tamanho da pilha

#endif
