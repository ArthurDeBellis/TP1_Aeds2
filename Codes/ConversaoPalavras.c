/*

Trabalho feito por:

Arthur De Bellis - 03503
Saulo Miranda Silva - 03475
Pablo Ferreira - 03480

*/

#include "../Libs/ConversaoPalavras.h"

char* ConverteMaiusculo(char *palavra){
	long unsigned int i = 0;
	long unsigned int tamPalavra = 0;
	//Verificando o tamanho da palavra passada/
	while(palavra[tamPalavra] != '\0'){
		tamPalavra++;
	}
	//Fazendo a conversão das letras usando como base a tabela ASCII/
	while(i<tamPalavra){
		if(palavra[i] >= 65 && palavra[i] <= 90){
			palavra[i] += 32;
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
    if((palavra[i] >= 33 && palavra[i] <= 47) || (palavra[i] >= 58 && palavra[i] <= 64)){
			palavra[i] = '\0';
		}
		i++;
	}
	return palavra;
}
