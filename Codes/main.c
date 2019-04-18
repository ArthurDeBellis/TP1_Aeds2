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

int main(){
  Apontador arvore;
  int opcao, quantidade, tamChave;
  int j;

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

          }



        }
        fclose(arquivo);
      }
    }

  arvore = Insere("Arthur", &arvore);
  Pesquisa("Arthur", arvore);

  arvore = Insere("Pablo", &arvore);
  Pesquisa("Pablo", arvore);

  arvore = Insere("Saulo", &arvore);
  Pesquisa("Saulo", arvore);

  arvore = Insere("Apatico", &arvore);
  Pesquisa("Apatico", arvore);

  arvore = Insere("Pablo", &arvore);
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
			palavra[i] = 32;
		}
		i++;
	}
	return palavra;
}
