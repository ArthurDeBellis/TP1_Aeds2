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
  arvore = Insere("QUEM", &arvore, 1);
  Pesquisa("QUEM", arvore);
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  arvore = Insere("QUER", &arvore, 1);
  Pesquisa("QUER", arvore);
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  arvore = Insere("POREM", &arvore, 1);
  Pesquisa("POREM", arvore);
  arvore = Insere("NINGUEM", &arvore, 1);
  Pesquisa("NINGUEM", arvore);
  arvore = Insere("CASA", &arvore, 1);
  Pesquisa("CASA", arvore);
  arvore = Insere("NINGUEM", &arvore, 1);
  Pesquisa("NINGUEM", arvore);
  arvore = Insere("QUER", &arvore, 1);
  Pesquisa("QUER", arvore);
  arvore = Insere("CASAR", &arvore, 1);
  Pesquisa("CASAR", arvore);
  arvore = Insere("TAMBEM", &arvore, 1);
  Pesquisa("TAMBEM", arvore);
  arvore = Insere("QUER", &arvore, 1);
  Pesquisa("QUER", arvore);
  arvore = Insere("APARTAMENTO", &arvore, 1);
  Pesquisa("APARTAMENTO", arvore);


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
