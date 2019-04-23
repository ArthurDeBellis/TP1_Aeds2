#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../Libs/TAD_Patricia.h"
//criamos listas encadeadas para armazenar a relevancia e os termos de busca

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
  InserirNovo(&(arvore->No.NoExterno.lista), idDoc, palavra);
  arvore->noArvore = Externo;
  strcpy(arvore->No.NoExterno.chave, palavra);
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
      return arvore;
    }
    else{
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
    if (Chave[i]>(*arvore)->No.NoExterno.chave[i]){//se o caractere comparado da chave com o do no for maior
      return (CriaNoInt(i, Chave[i], arvore, &p) );//ele vai para a direita, senão vai para a esquerda, e o no encontrado vai para o outro lado
    }
      return (CriaNoInt(i, (*arvore)->No.NoExterno.chave[i], &p, arvore));
    }
  }

  else{
    if (i < (*arvore)->No.NoInterno.posicao) {//se a posição do caractere a ser comparado for maior do que a passada pela função inser
      p = CriaNoExt(Chave, idDoc);
      if(Chave[i]>comp){
        return  (CriaNoInt(i, Chave[i], arvore, &p)); //chave vai para a direita
      }
      else{
        return  (CriaNoInt(i, comp, &p, arvore));//chave vai para a esquerda
      }
    }
    else{
       if ((*arvore)->No.NoInterno.posicao==i){//se a posição a ser comparada for igual a do no
        p = CriaNoExt(Chave, idDoc);
        if((*arvore)->No.NoInterno.letra < Chave[i]){
          return (CriaNoInt(i, Chave[i], arvore, &p));//se caractere da chave for maior, chave vai para a direita
        }
        else{
          (*arvore)->No.NoInterno.Esq = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Esq,i, idDoc);//chama insere entre para a esquerda
          return(*arvore);
        }
      }
      else{
        if((*arvore)->No.NoInterno.letra == Chave[(*arvore)->No.NoInterno.posicao]){//se a letra do no for igual a da chave
          (*arvore)->No.NoInterno.Dir = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Dir,i, idDoc);//chama essa função para a direita
        }
        else{
          (*arvore)->No.NoInterno.Esq = InsereEntre(Chave, comp, &(*arvore)->No.NoInterno.Esq,i, idDoc);//chama essa função para a esquerda
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

    }
    while(1){
      if(Chave[posicaoDiferente] != p->No.NoExterno.chave[posicaoDiferente]){
        break;
      }
      posicaoDiferente++;
    }

    /*
    Se a variável 'posição diferente' for maior ou igual ao tamanho
    da chave, significa que os dois são iguais, ou seja, não deve ser
    inserido
    */
    if (strcmp(Chave, p->No.NoExterno.chave) == 0){
      InserirNovo(&(p->No.NoExterno.lista), idDoc, Chave);
      return (*arvore);
    }
    return (InsereEntre(Chave, p->No.NoInterno.letra, arvore, posicaoDiferente, idDoc));
  }


void Ni(Apontador arvore, int arquivo, int* ni){//da um ordem e conta quantos nos externos a arvore tem
  ApIndInverso p = NULL;
  if(arvore->noArvore == Externo){
    p = arvore->No.NoExterno.lista.pPrimeiro;
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
  //pesquisa quantas vezes a palavra chave aparece no documento i
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
  ApIndInverso p = NULL;//Mostra quantos documentos possuem a chave
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

float PesoTermo(float n, Apontador arvore, char *Chave, int idDoc){
  float log2 = log10f(n)/log10f(2), f, d;//w da formula

  f = OcorrenciadeChaveemI(arvore, Chave, idDoc);
  d = DocumentoscomChave(arvore, Chave);
  return(f*(log2/d));

}

float Relevancia(float n, int q, int ni, char *Chave, Apontador arvore, LBusca *busca, int narquivo){
    ApBus p = busca->pPrimeiro->pProx;
    float r, somatorio = 0;// finaliza a formula de relevancia


    while(p!=NULL){
      somatorio = somatorio+ PesoTermo(n, arvore, p->nome, narquivo);
      p = p->pProx;
    }
    if(ni == 0)
    {
      r = 0;
    }
    else{
      r=(1/(float)ni)*somatorio;
    }
    //printf("%d é o Ni\n", ni);
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
  //Se a lista for vazia retorna 1
  if(Lista.pPrimeiro == Lista.pUltimo){
    return 1;
  }
  else{
    return 0;
  }
}

void InserirNovoRelevancia(LRelevancia *Lista, float relevancia, int narquivo){
  ApRel Celula = NULL, p = NULL;// insere celula de maneira ordenada decrescente na lista encadeada q armazena os arquivos e as relevancias
  int i = 0; //contador
  if(Lista->pPrimeiro==Lista->pUltimo){
    //Conferindo se a lista é vazia, se sim, define todos os valores
    Celula = (ApRel)malloc(sizeof(CelRelevancia));
    Celula->relevancia = relevancia;
    Celula->pProx = NULL;
    Celula->idDoc = narquivo;
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
    Celula->idDoc = narquivo;
    Celula->pProx = p->pProx;
    p->pProx = Celula;
    if(p->pProx== NULL)
      Lista->pUltimo = Celula;

    return;
    }


}

void RelevanciaFinal(Apontador arvore, int q, char *Chave, LRelevancia *Lista, float n, float idDoc, LBusca *busca, int narquivo){
  int ni = 0; //insere a relevanica e o texto na lista
  float relev;
  for(int i = 0;i<q;i++){
    Ni(arvore, i+1, &ni);

    relev = Relevancia(n, q, ni, Chave, arvore, busca, i+1);
    InserirNovoRelevancia(Lista, relev, narquivo);

    ni=0;
  }
}

void ImprimirListaRelevancia(LRelevancia Lista){ //imprime os arquivos de acordo com a relevancia
  ApRel p , aux;
  p = Lista.pPrimeiro->pProx;

  while(p!=NULL){
    printf("%dºarquivo\n", p->idDoc+1);

    p = p->pProx;
  }

  p = Lista.pPrimeiro->pProx;
  Lista.pPrimeiro->pProx = NULL;
  Lista.pUltimo = Lista.pPrimeiro;

}
//lista encadeada que armazena os termos de busca
int IniciaListaBusca(LBusca *pLista){
  ApBus Celula = NULL;
  //Definindo os valor de pPrimeiro e pUltimo como nulos para iniciar a lista
  Celula = (ApBus)malloc(sizeof(Celbusca));
  Celula->pProx = NULL;
  pLista->pPrimeiro = Celula;
  pLista->pUltimo = Celula;
  return 1;

}

int ListaBuscaVazia(LBusca Lista){
  if(Lista.pPrimeiro == Lista.pUltimo){
    return 1;
  }
  else{
    return 0;
  }

}

void InserirNovoBusca(LBusca *Lista, char *nome){
  ApBus Celula = NULL;

    //Conferindo se a lista é vazia, se sim, define todos os valores
    Celula = (ApBus)malloc(sizeof(Celbusca));
    Celula->nome = (char*)malloc(sizeof(char));
    strcpy(Celula->nome, nome);
    Lista->pUltimo->pProx = Celula;
    Lista->pUltimo = Celula;
    Celula->pProx=NULL;
    return;

}
