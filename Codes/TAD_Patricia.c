#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/TAD_Patricia.h"


void InicializaPatricia(Apontador *arvore){
  //Inicializa a árvore
  *arvore = NULL;
}

short ConfereNoExterno(Apontador arvore){
  //Confere se o nó é externo
  return (arvore -> noArvore == Externo);
}

Apontador CriaNoInt(int index, char letra, Apontador *esq, Apontador *dir){
  /*
  Nessa função é criada uma árvore e ela é dada como retorno, é alocado um espaço de memória
  e os campos da struct são preenchidos com o que foi passado de parâmetro, além da indicação
  do noArvore como Interno
  */
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore -> noArvore = Interno;
  arvore -> No.NoInterno.Esq= *esq;
  arvore -> No.NoInterno.Dir= *dir;
  arvore -> No.NoInterno.posicao= index;
  arvore -> No.NoInterno.letra = letra;
  return arvore;
}

Apontador CriaNoExt(char *palavra, int idDoc){
  /*
  Cria-se a arvore a ser retornada e nela preenche-se a palavra a ser inserida e indica-se
  seu nó como externo
  */
  Apontador arvore;
  arvore = (Apontador)malloc(sizeof(NoPatricia));
  arvore->No.chave = (char*)malloc(sizeof(char));
  IniciaLista(&(arvore->No.lista));
  InserirNovo(&(arvore->No.lista), idDoc);
  arvore->noArvore = Externo;
  //printf("Aqui foi\n" );
  strcpy(arvore->No.chave, palavra);
  return arvore;
}

void Pesquisa(char *Chave, Apontador arvore){
  //Variável para receber o tamanho da chave
  int tamChave = strlen(Chave);

  if (ConfereNoExterno(arvore)){
    /*
    Se o nó conferido for externo e igual à chave existente no nó externo, mostra-se na tela
    que o elemento foi encontrado
    */
    if (strcmp(Chave, arvore->No.chave) == 0){
      printf("Elemento encontrado: %s\n", Chave);
      ImprimirLista(arvore->No.lista);
    }
    else{
      printf("Elemento nao encontrado\n");
    }
    return;
  }
  /*
  Se o nó não for externo, confere-se os campos 'posicao' e 'letra', para saber se a
  busca deve prosseguir para a direita ou para esquerda do nó que está sendo olhado
  */
  if ((Chave[arvore->No.NoInterno.posicao] < (arvore)->No.NoInterno.letra) && (tamChave >= arvore->No.NoInterno.posicao)){
    Pesquisa(Chave, arvore->No.NoInterno.Esq);
  }

  else{
    Pesquisa(Chave, arvore->No.NoInterno.Dir);
  }
}

Apontador InsereEntre(char *Chave, Apontador *arvore, int i, int idDoc){
  Apontador p = NULL;
  if (ConfereNoExterno(*arvore) || i < (*arvore)->No.NoInterno.posicao){
    /*
    Se a árvore for formada por um nó externo ou então o index passado como
    parâmetro for menor que o campo 'posicao', cria-se um nó externo na árvore
    auxiliar e então confere, entre a Chave a ser inserida no index indicado e o
    No já existente, qual letra é maior, para poder achar qual será a subárvore
    a direita e a esquerda e sua maior letra
    */
    p = CriaNoExt(Chave, idDoc);

    if (Chave[i]<((*arvore)->No.chave[i]))
      return (CriaNoInt(i,((*arvore)->No.chave[i]), &p, arvore));
    else
      return (CriaNoInt(i,Chave[i], arvore,  &p));
  }
  else{
    /*
    Se não, compara a letra da palavra a ser inserida com o campo 'letra' para
    se descobrir o lado que se chama recursivamente o insere entre
    */
    if (Chave[(*arvore)->No.NoInterno.posicao] >= (*arvore)->No.NoInterno.letra)
      (*arvore)->No.NoInterno.Dir = InsereEntre(Chave,&(*arvore)->No.NoInterno.Dir,i, idDoc);
    else
      (*arvore)->No.NoInterno.Esq = InsereEntre(Chave,&(*arvore)->No.NoInterno.Esq,i, idDoc);
    //Ao final, retorna-se a árvore
    return (*arvore);
  }
}

Apontador Insere(char *Chave, Apontador *arvore, int idDoc){
  Apontador p;
  int posicaoDiferente = 0;
  int tamChave = strlen(Chave);
  if (*arvore == NULL)
    //Se não existir nenhum elemento, cria-se o primeiro elemento da árvore
    return (CriaNoExt(Chave, idDoc));
  else{
    //A árvore auxiliar 'p' recebe a árvore passada por parâmetro
    p = *arvore;
    while (!ConfereNoExterno(p)){
      /*
      Enquanto o nó conferido for interno, compara-se os campos 'letra' e 'posicao'
      para saber se deve-se ir para a esquerda ou direita
      */
      if ((Chave[p->No.NoInterno.posicao] < (p)->No.NoInterno.letra) && (tamChave >= p->No.NoInterno.posicao))
        p = p->No.NoInterno.Esq;
      else
        p = p->No.NoInterno.Dir;
    }
    //O While a seguir confere em qual posição que a chave a ser inserida e a existente se diferem em relação a letra
    while(posicaoDiferente < Chave[posicaoDiferente]){
      if(Chave[posicaoDiferente] != p->No.chave[posicaoDiferente])
        break;
      posicaoDiferente++;
    }

    /*
    Se a variável 'posição diferente' for maior ou igual ao tamanho
    da chave, significa que os dois são iguais, ou seja, não deve ser
    inserido
    */
    if (posicaoDiferente >= tamChave){
      printf("Erro: chave ja esta na arvore\n");
      InserirNovo(&(p->No.lista), idDoc);
      return (*arvore);
    }

    return (InsereEntre(Chave, arvore, posicaoDiferente, idDoc));
  }
}
