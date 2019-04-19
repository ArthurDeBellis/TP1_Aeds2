#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Libs/TAD_Patricia.h"
#include "../Libs/IndInverso.h"
#include "../Libs/tst.h"
#include "../Libs/menu.h"

char* ConverteMaiusculo(char *palavra);
char* IgnoraPontuacao(char *palavra);
int ni = 0;

int main(){
  Apontador arvore;
  int opcao, quantidade;

  InicializaPatricia(&arvore);

  menu_de_entradas();
  scanf("%d", &opcao);
  while(opcao != 0){
    if(opcao == 1){
      FILE *arquivo;
      char nomeArquivo[100], palavra[100];
      char *aux = NULL;

      printf("Digite a quantidade de arquivos a serem lidos: ");
      scanf("%d", &quantidade);

      for(int i = 0; i < quantidade; i++){
        printf("Nome do Arquivo (com extensão .txt): ");
        scanf("%s", nomeArquivo);

        arquivo = fopen(nomeArquivo, "r");

        if(!arquivo){
          printf("Fim da Leitura");
        }
        else {
          while(feof(arquivo) != 1){
            fscanf(arquivo, "%s ", palavra);
            aux = palavra;
            aux = ConverteMaiusculo(aux);
            aux = IgnoraPontuacao(aux);
            printf("%s\n", palavra);
            //arvore = Insere(palavra, &arvore, i+1);
            //Pesquisa(palavra, arvore);
          }



        }
        fclose(arquivo);
      }
    }
  //Quem casa quer casa. Porem ninguem casa. Ninguem quer casar tambem. Quer apartamento.
  arvore = Insere("SALAMANDRA", &arvore, 1);
  Pesquisa("SALAMANDRA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("QUEM", &arvore, 1);
  Pesquisa("QUEM", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  //NÃO TÁ INSERINDO PREFIXO APÓS A INSERÇÃO DE UMA PALAVRA COM ESSE MESMO PREFIXO, NEM INSERINDO
  //PALAVRA COM MAIS DE 8 LETRAS
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("QUER", &arvore, 1);
  Pesquisa("QUER", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("POREM", &arvore, 1);
  Pesquisa("POREM", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("NINGUEM", &arvore, 1);
  Pesquisa("NINGUEM", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("CASE", &arvore, 1);
  Pesquisa("CASE", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("NINGUEM", &arvore, 1);
  Pesquisa("NINGUEM", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("QUERIA", &arvore, 1);
  Pesquisa("QUERIA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("QUERO", &arvore, 1);
  Pesquisa("QUERO", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("CASADO", &arvore, 1);
  Pesquisa("CASADO", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("QUERIDA", &arvore, 1);
  Pesquisa("QUERIDA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("POTTER", &arvore, 1);
  Pesquisa("POTTER", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("POTE", &arvore, 1);
  Pesquisa("POTE", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTEIRA", &arvore, 1);
  Pesquisa("PORTEIRA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTA", &arvore, 1);
  Pesquisa("PORTA", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTAO", &arvore, 1);
  Pesquisa("PORTAO", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTO", &arvore, 1);
  Pesquisa("PORTO", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTUGAL", &arvore, 1);
  Pesquisa("PORTUGAL", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTUGAL", &arvore, 1);
  Pesquisa("PORTUGAL", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );
  ni = 0;
  arvore = Insere("PORTUGAL", &arvore, 1);
  Pesquisa("PORTUGAL", arvore);
  Ni(arvore, 1, &ni);
  printf("%d palavras no documento 1\n", ni );












  return 0;
  }
}

char* ConverteMaiusculo(char *palavra){
	long unsigned int i = 0;
	long unsigned int tamPalavra = 0;
	//Verificando o tamanho da palavra passada/
	while(palavra[tamPalavra] != '\0'){
		tamPalavra++;
	}
	//Fazendo a conversão das letras usando como base a tabela ASCII/
	while(i<tamPalavra){
		if(palavra[i] >= 97 && palavra[i] <= 122){
			palavra[i] -= 32;
		}
    i++;
	}
	//Retornando a palavra passada como parâmetro, já toda maiúscula/
	return palavra;
}

char* IgnoraPontuacao(char *palavra){
	long unsigned int i = 0;
  long unsigned int tamPalavra = 0;

  while(palavra[tamPalavra] != '\0'){
		tamPalavra++;
	}

  //transformando todos pontos, virgulas, exclamações e interrogações em 'espaço'
	while(i<tamPalavra){
    if(palavra[i] >= 33 && palavra[i] <= 47 || palavra[i] >= 58 && palavra[i] <= 64){
			palavra[i] = '\0';
		}
		i++;
	}
	return palavra;
}
