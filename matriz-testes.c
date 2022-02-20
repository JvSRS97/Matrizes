//--------------------------------------------------------------------
// Universidade Federal de Sergipe
// Departamento de Matemática
// Aluno João Victor S. R. dos Santos
// Aracaju SE 28/01/2018
// obs.: para compilar: gcc matriz-testes.c -lm -o matriz-testes
// Sintaxe: ./matriz-testes
//--------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "struct.h" 

 void main(int argc, char **argv){
  FILE *arq;
  int i=0, j=0, k;
  matriz A,B;

A = ler_matriz(arq,"matriz-A.txt"); 
B = ler_matriz(arq,"matriz-B.txt"); 

//testando leitura dos arquivos
	imprimir_matriz("A",A);
	imprimir_matriz("B",B);

//-------------------------------------------------------
	//testando multiplicação de uma matriz por um escalar
	matriz A_2;
	A_2 = x_matriz(2,A);
	imprimir_matriz("2.A",A_2);
//-------------------------------------------------------

//-------------------------------------------------------
	//testando soma de matrizes
	matriz C;
	C = somar_matrizes(A,B);
	imprimir_matriz("A+B",C);
//-------------------------------------------------------

//-------------------------------------------------------
	//testando subtração de matrizes
	matriz D,D_1;
	D = subtrair_matrizes(A,B);
	D_1 = subtrair_matrizes(B,A);
	imprimir_matriz("A-B",D);
	imprimir_matriz("B-A",D_1);
//-------------------------------------------------------

//-------------------------------------------------------
	//testando o produto de matrizes
	matriz E,E_1;
	E = prod_matrizes(A,B);
	E_1 = prod_matrizes(B,A);
	imprimir_matriz("A.B",E);
	imprimir_matriz("B.A",E_1);
//-------------------------------------------------------


//--------------------------------------------
	//testando criação de matrizes identidade
	matriz I_4,I_5;
	imprimir_matriz("I4",I_4);
	imprimir_matriz("I5",I_5);

	I_4 = criar_id_n(4);
	I_5 = criar_id_n(5); 

	imprimir_matriz("I4",I_4);
	imprimir_matriz("I5",I_5);
//--------------------------------------------

//--------------------------------------------
	//testando transposta
	matriz A_t,B_t;
	A_t = transpose(A);
	B_t = transpose(B);
	imprimir_matriz("A_t",A_t);
	imprimir_matriz("B_t",B_t);
//--------------------------------------------


//---------------------------------------------------------
	//testando o produto de matrizes pela matriz identidade
	matriz F,G,H,J;
	F = criar_id_n(A.n);
	G = criar_id_n(A.m);
	
	H = prod_matrizes(A,G);
	J = prod_matrizes(F,A);

	imprimir_matriz("A.I",H);
	imprimir_matriz("I.A",J);	
//---------------------------------------------------------

//---------------------------------------------------------
	//testando troca de duas linhas
	matriz L;
	L = trocar_linhas(100,200,A);//testando erro
	L = trocar_linhas(1,2,A);
	imprimir_matriz("A_(l12)",L);
//---------------------------------------------------------

//---------------------------------------------------------
	//testando troca de duas colunas
	matriz M;
	M = trocar_colunas(100,200,A);//testando erro
	M = trocar_colunas(1,3,A);
	imprimir_matriz("A_(c34)",M);

//---------------------------------------------------------

//---------------------------------------------------------
	//testando remoção de linha e coluna
	matriz N;
	N = remov_linha_coluna(100,200,A);//testando erro
	N = remov_linha_coluna(1,3,A);
	imprimir_matriz("A_(l1c3)",N);
//---------------------------------------------------------

//---------------------------------------------------------
	//testando o cálculo do traço
	printf("\n Tr(A) = %.1f.",tr(A));
	printf("\n Tr(B) = %.1f.",tr(B));	
//---------------------------------------------------------

//-----------------------------------------------------------------
	//testando o cálculo do determinante
		printf("\n det(A) = %.1f.", det(A));
		printf("\n det(B) = %.1f.\n", det(B));
//-----------------------------------------------------------------

//-----------------------------------------------------------------
	//testando o cálculo da inversa
		matriz adj_A,adj_B;
		adj_A = adj(A);
		adj_B = adj(B);		

		imprimir_matriz("adj(A)",adj_A);
		printf("-> A^-1 = 1/%.1f * adj(A).\n\n",det(A));
		
		imprimir_matriz("adj(B)",adj_B);
		printf("-> A^-1 = 1/%.1f * adj(B).\n\n",det(B));
//-----------------------------------------------------------------

//-----------------------------------------------------------------
	//testando a decomposição LU
		decomp_LU("A",A);
		decomp_LU("B",B);
//-----------------------------------------------------------------
}
