#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/TAD_Patricia.h"


/*char Letra(int posicao, char *Chave){
  int j;
  char c;
  int tamChave = strlen(Chave);

  if (posicao == 0){
    return 0;
  }
  else {
     for (j = 1; j <= tamChave; j++){
       c = Chave[j-1];
     }
     return (c);
   }
*/

int Letras(Apontador *arvore, char *palavra1, char *palavra2){
  int i = 0;
  //int tamPalavra = 0;
  while(palavra1[i] != '\0' || palavra2[i] != '\0'){
    //tamPalavra++;

    if(palavra1[i] == '\0' || palavra2[i] == '\0'){
      (*arvore)->No.NoInterno.posicao = i;
      if(strcmp(&palavra1[i], &palavra2[i]) < 0){
        (*arvore)->No.NoInterno.letra = palavra2[i];
        return 1;
      }
      else{
        (*arvore)->No.NoInterno.letra = palavra1[i];
        return 0;
      (*arvore)->No.NoInterno.letra = palavra1[i];
      }
    }

    if(palavra1[i] != palavra2[i]){
      (*arvore)->No.NoInterno.posicao = i;
      if(strcmp(&palavra1[i], &palavra2[i]) < 0){
        (*arvore)->No.NoInterno.letra = palavra2[i];
        return 1;
      }
      else{
        (*arvore)->No.NoInterno.letra = palavra1[i];
        return 0;
      }
    }
    i++;
  }
}


//A função verifica se o nó é externo
int ConfereNoExterno(Apontador arvore){
  return(arvore -> noArvore == Externo);
}

Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir){
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore -> noArvore = Interno;
  arvore -> No.NoInterno.Esq= *esq;
  arvore -> No.NoInterno.Dir= *dir;
  arvore -> No.NoInterno.posicao= index;
  arvore -> No.NoInterno.letra = letra;
  return arvore;
}

void CriaNoExt(char *palavra, Apontador *arvore){
  *arvore = NULL;
  *arvore = (Apontador)malloc(sizeof(NoPatricia));
  (*arvore) -> noArvore = Externo;
  //(*arvore) -> No.NoExterno.chave = (char*)malloc(sizeof(char));
  strcpy((*arvore) -> No.NoExterno.chave, palavra);
  printf("chave: %s\n", (*arvore) -> No.NoExterno.chave);
}

void Pesquisa(char *Chave, Apontador arvore){
  int tamChave = strlen(Chave);
  if(ConfereNoExterno(arvore)){
    printf("%s\n", Chave);
    printf("%c\n", arvore -> No.NoInterno.letra);
    printf("%d\n", arvore -> No.NoInterno.posicao);
    printf("Ta quase encontrando o erro\n");
    printf("posicão : %c\n", arvore -> No.NoExterno.chave[0]);
    //Comparando no externo
    if(strcmp(Chave, arvore->No.NoExterno.chave) == 0){
      printf("Elemento encontrado: %s\n", Chave);
    }
    else
      printf("Elemento não encontrado\n");
    return;
  }
  printf("cade o erro?\n");
  //Desvios, se a posição e letra for menor vai para a esquerda, se não, vai para a direita

  if(tamChave >= arvore->No.NoInterno.posicao && Chave[arvore->No.NoInterno.posicao] < (arvore)->No.NoInterno.letra)
    Pesquisa(Chave, arvore->No.NoInterno.Esq);
  else
    Pesquisa(Chave, arvore->No.NoInterno.Dir);
}
Apontador InsereEntre(char *Chave, Apontador *arvore, int i){
  //printf("OI\n");
  Apontador p = NULL;
  char aux[50];
  printf("OI função entre\n");
  if (ConfereNoExterno(*arvore) || i < (*arvore)->No.NoInterno.posicao){
    printf("Quero morrer\n" );
    CriaNoExt(Chave, &p);
    //if (Chave[i] < (*arvore)-> No.NoInterno.letra)

    printf("Quero morrer 4\n" );
    // (Apontador *arvore, char *palavra1, char *palavra2)
    strcpy(aux, (*arvore) -> No.NoExterno.chave);
    printf("chave : %s\n", (*arvore) -> No.NoExterno.chave);
    printf("chave aux : %s\n", aux);
    if (Letras(arvore, (*arvore)->No.NoExterno.chave, Chave) == 1){
      //strcpy((*arvore) -> No.NoExterno.chave, aux);
      printf("chave : %s\n", (*arvore) -> No.NoExterno.chave);
      printf("chave aux 2: %s\n", aux);
      printf("Ziviane doente\n");
      // (int index, char letra, Apontador *esq, Apontador *dir)
      printf("%c\n", (*arvore) -> No.NoInterno.letra);
      printf("%d\n", (*arvore) -> No.NoInterno.posicao);
      return (CriaNoInt((*arvore) -> No.NoInterno.posicao, (*arvore) -> No.NoInterno.letra, arvore, &p));
    }
    else{
      printf("Ziviane doente 37\n");
      return (CriaNoInt((*arvore) -> No.NoInterno.posicao, (*arvore) -> No.NoInterno.letra, &p, arvore));

    }
  }

  //else{
    printf("Entrou no else\n");

    /*TODO -> Correção do else pela função letra
    if (Letra((*arvore)->No.NoInterno.posicao, Chave) == 1)
      (*arvore)->No.NoInterno.Dir = InsereEntre(Chave,&(*arvore)->No.NoInterno.Dir,i);
    else
      (*arvore)->No.NoInterno.Esq = InsereEntre(Chave,&(*arvore)->No.NoInterno.Esq,i);
    *///return (*arvore);

  //}
}
void Insere(char *Chave, Apontador *arvore){
  Apontador p;
  int i = 0;
  if (*arvore == NULL){
    (CriaNoExt(Chave, &(*arvore)));
    return;
  }
  else{
    printf("else\n");
    p = *arvore;
    printf("%d\n", (*arvore) -> noArvore);

    while (!ConfereNoExterno(p)){
      printf("While\n");
      if(Letras(&p, (p)->No.NoExterno.chave, Chave) == 1){
        p = p->No.NoInterno.Dir;
      }
      else{
        p = p->No.NoInterno.Esq;
      }
      i = 1;
      //while ((i <= MenorPalavra(Chave, p->No.NoExterno.chave))){
        //i++;
      }
      //if (i > MenorPalavra(Chave, p->No.NoExterno.chave) && Letras((int)i, Chave) == Letras((int)i, p->No.NoExterno.chave)){
      //  printf("Erro: chave ja esta na arvore\n"); return;
    //  }
      }
      InsereEntre(Chave, arvore, i);
      printf("%c\n", (*arvore) -> No.NoInterno.letra);
      printf("%d\n", (*arvore) -> No.NoInterno.posicao);
      printf("encontrar erro\n");
    }
  //}

/*int MenorPalavra(char* palavra1, char* palavra2){
  int i, j;
  i = strlen(palavra1);
  j = strlen(palavra2);
  if(i>j)
    return j;
  else
    return i;
}*/
