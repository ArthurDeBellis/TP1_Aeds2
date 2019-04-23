#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/TAD_Patricia.h"
#include "../Libs/IndInverso.h"
#include "../Libs/tst.h"
#include "../Libs/menu.h"
#include "../Libs/ConversaoPalavras.h"

int ni = 0;

int main(){
  //Inicialização de estruturas necessarias
  Apontador arvore;
  LBusca busca;
  IniciaListaBusca(&busca);
  LRelevancia relevancia;
  NoTST* head = NULL;
  InicializaPatricia(&arvore);
  IniciaListaRelevancia(&relevancia);

  //Variaveis utilizadas para criação do programa
  int opcao;
  int contBusca=0;
  int quantidadeTextos;
  int quantidadePalavras;
  char *palavraPesquisa;
  char *prefixo;
  char nomeArquivo[100], nomeArquivoBusca[100], palavra[100], palavraBusca[100];;
  char *aux = NULL;
  char *auxBusca = NULL;
  palavraPesquisa = (char*)malloc(sizeof(char));
  prefixo = (char*)malloc(sizeof(char));


  menu_de_entradas();

  scanf("%d", &opcao);

  while(opcao != 4){
    if(opcao == 1){ //Criação do indice invertido
      FILE *arquivo;

      printf("Digite a quantidade de arquivos a serem lidos: ");
      scanf("%d", &quantidadeTextos);

      for(int i = 0; i < quantidadeTextos; i++){ // lendo todos os arquivos
        printf("Nome do Arquivo (com extensão .txt): ");
        scanf("%s", nomeArquivo);
        printf("\n\n%s\n\n", nomeArquivo);
        arquivo = fopen(nomeArquivo, "r");

        if(!arquivo){
          printf("Fim da Leitura");
        }

        else {
          while(feof(arquivo) != 1){ // lendo todas as palavras até terminar
            fscanf(arquivo, "%s ", palavra);
            aux =  palavra;
            aux = ConverteMaiusculo(aux);
            aux = IgnoraPontuacao(aux);
            arvore = Insere(aux, &arvore, i+1);
            head = InserirNoTST(aux, head);

          }
        }
      }
      fclose(arquivo);
      menu_de_entradas();
      scanf("%d", &opcao);
    }
    if(opcao == 2){ //Busca do indice invertido

      FILE *arquivo2;
      printf("Nome do Arquivo de Busca (com extensão .txt): ");
      scanf("%s", nomeArquivoBusca);
      arquivo2 = fopen(nomeArquivoBusca, "r");

      if(!arquivo2){
        printf("Fim da Leitura");
      }
      while(feof(arquivo2) != 1){ //lendo o arquivo de busca

        fscanf(arquivo2, "%s ", palavraBusca);
        auxBusca = palavraBusca;
        auxBusca = ConverteMaiusculo(auxBusca);
        auxBusca = IgnoraPontuacao(auxBusca);
        InserirNovoBusca(&busca, auxBusca);

        contBusca++;

      }
      fclose(arquivo2);
      for(int i = 0; i < quantidadeTextos; i++){
        RelevanciaFinal(arvore, contBusca, auxBusca, &relevancia, quantidadeTextos, i+1, &busca, i);
      }
      ImprimirListaRelevancia(relevancia);
      menu_de_entradas();
      scanf("%d", &opcao);
    }
    if(opcao == 3){ //Auto Completar palavras
      printf("Digite o prefixo a ser pesquisado: \n");
      scanf("%s", prefixo);
      AutoComplete(head, prefixo, prefixo);

      menu_de_entradas();
      scanf("%d", &opcao);
    }
  }
  menu_de_saida();
  return 0;

}
