/*
Trabalho feito por:
Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480
*/

#ifndef INDINVERSO_H
#define INDINVERSO_H

#include "estruturas.h"

//Funções
int IniciaLista(TLista *pLista); // Função para criar a lista vazia
int ListaVazia(TLista Lista); //Função para conferir se a lista é vazia
void InserirNovo(TLista *Lista, int idDoc, char *nome); //Função para inserir um novo elemento na lista
void ImprimirLista(TLista Lista); //Função para imprimir lista

#endif
