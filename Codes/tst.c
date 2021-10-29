/*

Trabalho feito por:

Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480

*/

#include "../Libs/tst.h"

NoTST* CriarNoTST (char letra, ntipo t) //Realizando a criação do nó
{
  NoTST *NoTST = (struct NoTST*)malloc(sizeof(struct NoTST));
  NoTST->letra = letra;
  NoTST->Esq = NULL;
  NoTST->Meio = NULL;
  NoTST->Dir= NULL;
  NoTST->Fim = t;

  return NoTST;
}

NoTST* InserirNoTST (const char* palavra, NoTST* NoTST)//Realizando a inserção
{
  int i = strlen(palavra);

  if(NULL == NoTST)
    NoTST = CriarNoTST(palavra[0], NAO);

  if(palavra[0] < NoTST->letra)
	  NoTST->Esq = InserirNoTST(palavra, NoTST->Esq);

  else if(palavra[0] > NoTST->letra)
	  NoTST->Dir = InserirNoTST(palavra, NoTST->Dir);

  else {

	  if(i == 1) {
		  NoTST->Fim = SIM;
		  return NoTST;
	  } else
		  NoTST->Meio = InserirNoTST(++palavra,NoTST->Meio);
  }

  return NoTST;
}

int BuscarNoTST(NoTST *arvore, const char* palavra)//Buscando um nó
{
  long unsigned int i = 0;
  NoTST* NoTST = arvore;

  while(i < strlen(palavra)) {
	  if(NULL  == NoTST)
		  break;
	  if(palavra[i] < NoTST->letra)
		  NoTST = (NoTST)->Esq;
	  else if(palavra[i] > (NoTST)->letra)
		  NoTST = (NoTST)->Dir;
	  else {
		  if(i++ == strlen(palavra)-1 && NoTST->Fim == SIM){
          return 1;
      }
		  else
		  NoTST = (NoTST)->Meio;
	  }
  }

  return 0;
}

int OrdemAux(NoTST *arvore, char *recebePalavra, int i, char* pref){
  /*
    Nesta função, se a árvore não for nula, é feita a chamada recursiva para a
    esquerda, enquanto a variável 'recebePalavra' vai sendo preenchida com as
    chaves da arvore TST.
    Se a árvore chegar ao seu fim, é feito o printf do prefixo + o resto da palavra
    Se não, é chamada a árvore pelo meio, com a variável i incrementada, logo depois
    chama a função recursivamente para a direita
  */
  if(arvore != NULL){
    OrdemAux(arvore->Esq, recebePalavra, i, pref);
    recebePalavra[i] = arvore->letra;
    if(arvore->Fim){
      recebePalavra[i+1] = '\0';
      printf("%s%s\n", pref, recebePalavra);
    }
    OrdemAux(arvore->Meio, recebePalavra, i+1, pref);
    OrdemAux(arvore->Dir,recebePalavra, i, pref);
    return 1;
  }
  return 0;
}

void Ordem(NoTST *arvore, char* pref){
  /*
  Função principal que chama a função OrdemAux
  */
  char *recebePalavra = NULL;
  recebePalavra = (char*)malloc(sizeof(char));
  OrdemAux(arvore, recebePalavra,0, pref);
}

void AutoComplete(NoTST *arvore, char *pref, char* aux){
  /*
  Na função, é comparado o prefixo com a chave presente na árvore, seu valor define
  o desvio, se o prefixo for igual ao campo 'letra', é feita a conferencia se o próximo
  elemento do prefixo é igual a '\0', se for, é chamada a função de ordem com o campo aux,
  que tem como valor o próprio prefixo, se não, é chamada a função no meio com o prefixo
  incrementado
  */
  if(arvore != NULL){
    if(*pref < arvore->letra){
      AutoComplete(arvore->Esq, pref, aux);
      return;
    }
    else{
      if(*pref > arvore->letra){
        AutoComplete(arvore->Dir, pref, aux);
        return;
      }
      else{
        if(*(pref+1) == '\0'){
          Ordem(arvore->Meio, aux);
        }
        AutoComplete(arvore->Meio, pref+1, aux);
        return;
      }
    }
  }
  return;
}
