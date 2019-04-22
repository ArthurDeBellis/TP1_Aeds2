#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/TAD_Patricia.h"
#include "../Libs/IndInverso.h"
#include "../Libs/tst.h"
#include "../Libs/menu.h"
#include "../Libs/ConversaoPalavras.h"
#include "../Libs/listaBusca.h"

int ni = 0;

int main(){
  Apontador arvore;
  TipoPilha pilha;
  LRelevancia relevancia;
  NoTST* head = NULL;
  InicializaPatricia(&arvore);
  IniciaListaRelevancia(&relevancia);

  int opcao;
  int contBusca;
  int quantidadeTextos;
  int quantidadePalavras;
  char *palavraPesquisa;
  char *prefixo;
  char nomeArquivo[100], palavra[100], palavraBusca[100];;
  char *aux = NULL;
  char *auxBusca = NULL;
  palavraPesquisa = (char*)malloc(sizeof(char));
  prefixo = (char*)malloc(sizeof(char));


  menu_de_entradas();

  scanf("%d", &opcao);

  while(opcao != 4){
    if(opcao == 1){
      FILE *arquivo;

      printf("Digite a quantidade de arquivos a serem lidos: ");
      scanf("%d", &quantidadeTextos);

      for(int i = 0; i < quantidadeTextos; i++){
        printf("Nome do Arquivo (com extensão .txt): ");
        scanf("%s", nomeArquivo);
        printf("\n\n%s\n\n", nomeArquivo);
        arquivo = fopen(nomeArquivo, "r");

        if(!arquivo){
          printf("Fim da Leitura");
        }

        else {
          while(feof(arquivo) != 1){
            fscanf(arquivo, "%s ", palavra);
            aux =  palavra;
            aux = ConverteMaiusculo(aux);
            aux = IgnoraPontuacao(aux);
            arvore = Insere(aux, &arvore, i+1);
            head = InserirNoTST(aux, head);
            //Pesquisa(aux, arvore);
          }
        }
      }
      fclose(arquivo);
      //ImprimirLista();
      menu_de_entradas();
      scanf("%d", &opcao);
    }
    if(opcao == 2){

      FILE *arquivo2;
      arquivo2 = fopen(nomeArquivo, "r");

      if(!arquivo2){
        printf("Fim da Leitura");
      }
      while(feof(arquivo2) != 1){
        
        fscanf(arquivo2, "%s ", palavraBusca);
        auxBusca = palavraBusca;
        auxBusca = ConverteMaiusculo(auxBusca);
        auxBusca = IgnoraPontuacao(auxBusca);
        Empilha(palavra, &pilha);
        contBusca = Tamanho(pilha);

      }
      fclose(arquivo2);
      for(int i = 0; i < contBusca; i++){
        Desempilha(&pilha, auxBusca);
        RelevanciaFinal(arvore, contBusca, auxBusca, i, quantidadeTextos, &relevancia);
        printf("Desimpilhou: %s\n", auxBusca);
      }
      ImprimirListaRelevancia(relevancia);
      menu_de_entradas();
      scanf("%d", &opcao);
    }
    if(opcao == 3){
      printf("Digite o prefixo a ser pesquisado: \n");
      scanf("%s", prefixo);
      //printf("prefixo: %s\n", prefixo);
      AutoComplete(head, prefixo, prefixo);


      menu_de_entradas();
      scanf("%d", &opcao);
    }

  }
  return 0;
}
