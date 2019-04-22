#include <math.h>
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
  arvore->No.NoExterno.chave = (char*)malloc(sizeof(char));
  IniciaLista(&(arvore->No.NoExterno.lista));
  //printf("Aqui foi tbm\n" );
  InserirNovo(&(arvore->No.NoExterno.lista), idDoc);
  arvore->noArvore = Externo;
  //printf("Aqui foi\n" );
  strcpy(arvore->No.NoExterno.chave, palavra);
  //printf("%s\n", arvore -> No. NoExterno.chave);
  //printf("Aqui foi\n" );
  return arvore;
}

Apontador Pesquisa(char *Chave, Apontador arvore){
  //Variável para receber o tamanho da chave
  int tamChave = strlen(Chave);

  if (ConfereNoExterno(arvore)){
    /*
    Se o nó conferido for externo e igual à chave existente no nó externo, mostra-se na tela
    que o elemento foi encontrado
    */
    if (strcmp(Chave, arvore->No.NoExterno.chave) == 0){

      printf("\nElemento encontrado: %s\n", arvore->No.NoExterno.chave);
      //ImprimirLista(arvore->No.NoExterno.lista);
      return arvore;
    }
    else{
      printf("Elemento nao encontrado\n");
      return NULL;
    }
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

Apontador InsereEntre(char *Chave, char comp, Apontador *arvore, int i, int idDoc){
  Apontador p;
  if (ConfereNoExterno(*arvore))
  { // cria um novo no externo *
    p = CriaNoExt(Chave, idDoc);
    if (Chave[i]>(*arvore)->No.NoExterno.chave[i]){
      return (CriaNoInt(i, Chave[i], arvore, &p) );
    }
    else{
      return (CriaNoInt(i, (*arvore)->No.NoExterno.chave[i], &p, arvore));
    }
  }

  else{
    if (i < (*arvore)->No.NoInterno.posicao) {
      p = CriaNoExt(Chave, idDoc);
      if(Chave[i]>comp){
        return  (CriaNoInt(i, Chave[i], arvore, &p));
      }
      else{
        return  (CriaNoInt(i, comp, &p, arvore));
      }
    }
    else{
       if ((*arvore)->No.NoInterno.posicao==i){
        p = CriaNoExt(Chave, idDoc);
        if((*arvore)->No.NoInterno.letra < Chave[i]){
          return (CriaNoInt(i, Chave[i], arvore, &p));
        }
        else{
          (*arvore)->No.NoInterno.Esq = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Esq,i, idDoc);
          return(*arvore);
        }
      }
      else{
        if((*arvore)->No.NoInterno.letra == Chave[(*arvore)->No.NoInterno.posicao]){
          (*arvore)->No.NoInterno.Dir = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Dir,i, idDoc);
        }
        else{
          (*arvore)->No.NoInterno.Esq = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Esq,i, idDoc);
        }
        return (*arvore);
    }
    }
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
  /*  for (posicaoDiferente = 0; Chave[posicaoDiferente]; posicaoDiferente++){
      if(Chave[posicaoDiferente] != p->No.NoExterno.chave[posicaoDiferente])
        break;
    }
*/    while(1){
      if(Chave[posicaoDiferente] != p->No.NoExterno.chave[posicaoDiferente]){
        break;
      }
      posicaoDiferente++;
    }

    /*
    Se a variável 'posição diferente' for maior ou igual ao tamanho
    da chave, significa que os dois são iguais, ou seja, não deve ser
    inserido
    */printf(" %s == %s\n", Chave, p->No.NoExterno.chave);
    if (strcmp(Chave, p->No.NoExterno.chave) == 0){
      printf("Erro: chave ja esta na arvore\n");
      InserirNovo(&(p->No.NoExterno.lista), idDoc);
      //printf("POSIÇÃO DIFERENTE = %d\n",posicaoDiferente);
      return (*arvore);
    }
  //  printf("POSIÇÃO DIFERENTE = %d\n",posicaoDiferente);
    return (InsereEntre(Chave, p->No.NoInterno.letra, arvore, posicaoDiferente, idDoc));
  }
}

void Ni(Apontador arvore, int arquivo, int* ni){
  ApIndInverso p = NULL;
  if(arvore->noArvore == Externo){
    p = arvore->No.NoExterno.lista.pPrimeiro;
    printf("%s\n", arvore->No.NoExterno.chave);
    while(p!=NULL){
      if(arquivo == p->idDoc){
        *ni= *ni+1;
      }
      p = p->pProx;
    }
  }
  else{
    Ni(arvore->No.NoInterno.Esq, arquivo, ni);
    Ni(arvore->No.NoInterno.Dir, arquivo, ni);
  }
  return;
}

int OcorrenciadeChaveemI(Apontador arvore, char *Chave, int i){
  //Variável para receber o tamanho da chave
  ApIndInverso p = NULL;
  Apontador no = Pesquisa(Chave, arvore);


  if(no!=NULL){
    p = no->No.NoExterno.lista.pPrimeiro->pProx;
    while(p!=NULL){
      if(i==p->idDoc){
        return p->qtde;
      }
      p = p->pProx;
    }
  }
  else{
    return 0;
  }
}

int DocumentoscomChave(Apontador arvore, char* Chave){
  ApIndInverso p = NULL;
  Apontador no = Pesquisa(Chave, arvore);
  int i = 0;

  if(no!=NULL){
    p = no->No.NoExterno.lista.pPrimeiro->pProx;
    while(p!=NULL){
      i++;
      p = p->pProx;
    }
  }
  return i;
}

float PesoTermo(float n, float d, float f){
  float log2 = log10f(n)/log10(2);
  printf("%f ocorrencias\n", f);

    printf("%f log\n", log2);
  return(f*(log2/d));

}
float Relevancia(float n, float d, float f, int q, int ni){
    float r, somatorio = 0;
    int j;

    for (j=1; j <= q; j++) {
      somatorio += PesoTermo(n, d, f);
    }
    r=(1/ni)*somatorio;
    return r;
}

int IniciaListaRelevancia(LRelevancia *pLista){
  ApRel Celula = NULL;
  //Definindo os valor de pPrimeiro e pUltimo como nulos para iniciar a lista
  Celula = (ApRel)malloc(sizeof(CelRelevancia));
  Celula->relevancia = 0;
  Celula->pProx = NULL;
  pLista->pPrimeiro = Celula;
  pLista->pUltimo = Celula;
  return 1;
}

int ListaRelevanciaVazia(LRelevancia Lista){
  //Se o ponteiro for nulo retorna 1
  if(Lista.pPrimeiro == Lista.pUltimo){
    return 1;
  }
  else{
    return 0;
  }
}
void InserirNovoRelevancia(LRelevancia *Lista, float relevancia, char *nome){
  ApRel Celula = NULL, p = NULL;
  int i = 0; //contador
  if(Lista->pPrimeiro==Lista->pUltimo){
    //Conferindo se a lista é vazia, se sim, define todos os valores
    Celula = (ApRel)malloc(sizeof(CelRelevancia));
    Celula->relevancia = relevancia;
    strcpy(Celula->nome, nome);
    Celula->pProx = NULL;
    Lista->pUltimo->pProx = Celula;
    Lista->pUltimo = Celula;
    return;
  }
  else{
    p = Lista->pPrimeiro;
    if(Lista->pUltimo->relevancia>relevancia){
      p = Lista->pUltimo;
    }
    else{
      while(relevancia<p->pProx->relevancia){
        p= p->pProx;
      }
    }

    Celula = (ApRel)malloc(sizeof(CelRelevancia));
    Celula->relevancia = relevancia;
    strcpy(Celula->nome, nome);
    Celula->pProx = p->pProx;
    p->pProx = Celula;
    if(p->pProx== NULL)
      Lista->pUltimo = Celula;

    return;
    }


}

void RelevanciaFinal(Apontador arvore, int q, char *Chave, int idDoc, float nArquivos, LRelevancia *Lista){
  int ni = 0;
  float d, f, relev;
  Ni(arvore, idDoc, &ni);
  f = OcorrenciadeChaveemI(arvore, Chave, idDoc );
  d = DocumentoscomChave(arvore, Chave);
  relev = Relevancia( nArquivos, d, f, q, ni);
  InserirNovoRelevancia(Lista, relev, Chave);
}

void ImprimirListaRelevancia(LRelevancia Lista){
  ApRel p = NULL, aux;
  p = Lista.pPrimeiro->pProx;
  while(p!=NULL){
    printf("%s\n", p->nome);
    p = p->pProx;
  }
  p = Lista.pPrimeiro->pProx;
  Lista.pPrimeiro->pProx = NULL;
  Lista.pUltimo = Lista.pPrimeiro;
  while (p!=NULL) {
    aux = p;
    p=p->pProx;
    free(p);
  }
}
