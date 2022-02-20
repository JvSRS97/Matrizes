//---------------------------------------------------------------------------------------------------------------
// Universidade Federal de Sergipe
// Departamento de Matemática
// Aluno João Victor S. R. dos Santos
// Aracaju SE 28/01/2018
// Sintaxe: ./gerar-matriz n m
// Obs.: para gerar duas matriz, executar os seguintes comandos no terminal
// ./gerar-matriz n m && cp matriz-gerada.txt matriz-A.txt
// ./gerar-matriz g h && cp matriz-gerada.txt matriz-B.txt
//
//gera uma matriz no arquivo da seguinte forma:
//  n m A[1][1] A[1][2] ... A[1][m] A[2][1] A[2][2] ... A[2][m] ... A[n][1] A[n][2] ... A[n][m]
// Observe que a ordem da matriz está nas duas primeiras informações do arquivo
//---------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void main(int argc, char **argv)
{
	srand(time(NULL));
	int i,j,n,m;
	FILE *arq;
	n = atoi(argv[1]); //linhas
	m = atoi(argv[2]); //colunas
 	int A[n][m];

//----------------------------------------------------------------------------------------------------------------------------
//Botando a matriz A no arquivo txt
    arq = fopen("matriz-gerada.txt","w");        // Arquivo ASCII, para escrita
   if(!arq){
      printf( "\nErro na abertura do arquivo");
      exit(0);
    }	fprintf(arq,"%d %d ", n,m);
    	for(i=0;i<n;i++) {//define de linha em linha
		for(j=0;j<m;j++){
			A[i][j] = 1 + (rand()%100);//gera um número aleatorio de 1 a 100
			fprintf(arq,"%d ", A[i][j]); //Grava no arquivo
		}
	}
    fclose(arq);
//----------------------------------------------------------------------------------------------------------------------------
}
