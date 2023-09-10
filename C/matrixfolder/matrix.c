#include <stdio.h>
#include <math.h>
#include "matrixmath.h"
#include "matrixmathcomplex.h"
#include "matrixcompare.h"

int main(void)
{
	int l1, l2, c1, c2, j;
	char s, m, e;
	float k, l, o;
	complex z;
	printf("coloca o numero de linhas e colunas da 1ª matrix separados por um '"
		   "x"
		   "':\n");
	scanf("%ix%i", &l1, &c1);
	printf("coloca o numero de linhas e colunas da 2ª matrix separados por um '"
		   "x"
		   "':\n");
	scanf("%ix%i", &l2, &c2);

	float matrix[l1][c1], matrix2[l2][c2], matrixsum[l1][c1], matrixmult[l1][c2], matrixT[c1][l1];
	complex matrixC[l1][c1], matrixC2[l2][c2], matrixsumC[l1][c1], matrixmultC[l1][c2], matrixTC[c1][l1];

	printf("Pretendes que as matrizes sejam complexas ou só reais? (C/R)\n");
	do
	{
		scanf("%c", &e);
	} while (e != 'C' && e != 'R');
	if (e == 'R')
	{
		printf("O valor que se vai colocar como k;\n");
		scanf("%f", &k);
		printf("queres preencher as matrizes de forma livre ou que ambas sejam escalares k? (L/E)\n");
		scanf("%c", &m);
		do
		{
			scanf("%c", &m);
		} while (m != 'L' && m != 'E');
		if (m == 'E')
		{

			fillmatrixdiag(k, l1, c1, matrix);
			fillmatrixdiag(k, l2, c2, matrix2);
		}
		else if (m == 'L')
		{
			printf("Insere os elementos da 1ª matriz, um a um;\n");
			fillmatrixfree(l1, c1, matrix);
			printf("Insere os elementos da 2ª matriz, um a um;\n");
			fillmatrixfree(l2, c2, matrix2);
		}
		printf("A 1ª matriz:\n");
		printmatrix(l1, c1, matrix);
		printf("A 2ª matriz:\n");
		printmatrix(l2, c2, matrix2);

		printf("queres:\n1- somar;\n2 -multiplicar;\n3- transpor uma delas;\n4 -verificar se uma delas é simetrica;\n4 -verificar se uma delas é hemi-simétrica;\n(S/M/T/P/H)\n");
		do
		{
			scanf("%c", &s);
		} while (s != 'S' && s != 'M' && s != 'T' && s != 'P' && s != 'H');
		if (((c1 != c2 || l1 != l2) && (s == 'S' || s == 'K' || s == 'P' || s == 'H')) || ((c1 != l2) && s == 'M'))
		{
			printf("mano... isso assim n dá\n");
			return 1;
		}
		else if (s == 'S')
		{
			summatrices(l1, c1, l2, c2, matrix, matrix2, matrixsum);
			printf("A matrix soma:\n");
			printmatrix(l1, c1, matrixsum);
		}
		else if (s == 'M')
		{
			multmatrices(l1, l2, c1, c2, matrix, matrix2, matrixmult);
			printf("A matrix produto:\n");
			printmatrix(l1, c2, matrixmult);
		}
		else if (s == 'T')
		{
			int opcao4;
			printf("Qual das matrizes queres transpor?(1/2)\n");
			scanf("%i", &opcao4);
			do
			{
				scanf("%i", &opcao4);
			} while (opcao4 != 1 && opcao4 != 2);
			if (opcao4 == 1)
			{
			transpose(l1, c1, matrix, matrixT);
			printf("A matrix transposta:\n");
			printmatrix(c1, l1, matrixT);
			}
			else
			{
			transpose(l2, c2, matrix2, matrixT);
			printf("A matrix transposta:\n");
			printmatrix(c2, l2, matrixT);
			}
		}
		else if (s == 'P')
		{
			int opcao3;
			printf("Qual das matrizes queres testar para simetria?(1/2)\n");
			scanf("%i", &opcao3);
			do
			{
				scanf("%i", &opcao3);
			} while (opcao3 != 1 && opcao3 != 2);
			if (opcao3 == 1)
			{
			symetric(l1, c1, matrix);
			}
			else
			{

			symetric(l2, c2, matrix2);
			}
		}
		else if (s == 'H')
		{
			int opcao4;
			printf("Qual das matrizes queres testar para hemi-simetria?(1/2)\n");
			scanf("%i", &opcao4);
			do
			{
				scanf("%i", &opcao4);
			} while (opcao4 != 1 && opcao4 != 2);
			if (opcao4 == 1)
			{
			hemisymetric(l1, c1, matrix);
			}
			else
			{

			hemisymetric(l2, c2, matrix2);
			}
		}
	}
	else
	{

		printf("O valor que se vai colocar como complexo l(na forma a+bi);\n");
		scanf("%f+%fi", &l, &o);
		z = CMPLX(l, o);
		printf("queres preencher as matrizes de forma livre ou que ambas sejam escalares complexas l? (L/E)\n");
		scanf("%c", &m);
		do
		{
			scanf("%c", &m);
		} while (m != 'L' && m != 'E');
		if (m == 'E')
		{

			fillmatrixdiagcomplex(z, l1, c1, matrixC);
			fillmatrixdiagcomplex(z, l2, c2, matrixC2);
		}
		else if (m == 'L')
		{
			printf("Insere os elementos da 1ª matriz, um a um na forma "
				   "a+bi"
				   "\n");
			fillmatrixfreecomplex(l1, c1, matrixC);
			printf("Insere os elementos da 2ª matriz da mesma forma que a primeira\n");
			fillmatrixfreecomplex(l2, c2, matrixC2);
			printf("A 1ª matriz:\n");
			printmatrixcomplex(l1, c1, matrixC);
			printf("A 2ª matriz:\n");
			printmatrixcomplex(l2, c2, matrixC2);
		}

		printf("queres:\n1- somar;\n2 -multiplicar;\n3- transpor uma delas;\n4 -verificar se uma delas é hermitica?\n(S/M/T/H)\n");
		do
		{
			scanf("%c", &s);
		} while (s != 'S' && s != 'M' && s != 'T' && s != 'H');
		if (((c1 != c2 || l1 != l2) && (s == 'S' || s == 'K' || s == 'H')) || ((c1 != l2) && s == 'M'))
		{
			printf("mano... isso assim n dá\n");
			return 1;
		}
		else if (s == 'S')
		{
			summatricescomplex(l1, c1, l2, c2, matrixC, matrixC2, matrixsumC);
			printf("A matrix soma:\n");
			printmatrixcomplex(l1, c1, matrixsumC);
		}
		else if (s == 'M')
		{
			multmatricescomplex(l1, l2, c1, c2, matrixC, matrixC2, matrixmultC);
			printf("A matrix produto:\n");
			printmatrixcomplex(l1, c2, matrixmultC);
		}
		else if (s == 'T')
		{
			int opcao;
			printf("Qual delas queres transpor?\n");
			scanf("%i", &opcao);
			do
			{
				scanf("%i", &opcao);
			} while (opcao != 1 && opcao != 2);
			if (opcao == 1)
			{
				transposecomplex(l1, c1, matrixC, matrixTC);
				printf("A matrix transposta:\n");
				printmatrixcomplex(c1, l1, matrixTC);
			}
			else
			{

				transposecomplex(l2, c2, matrixC2, matrixTC);
				printf("A matrix transposta:\n");
				printmatrixcomplex(c2, l2, matrixTC);
			}
		}
		else if (s == 'H')
		{
			int opcao2;
			printf("Qual delas queres testar para hermicidade?\n");
			scanf("%i", &opcao2);
			do
			{
				scanf("%i", &opcao2);
			} while (opcao2 != 1 && opcao2 != 2);
			if (opcao2 == 1)
			{
			hermitic(l1, c1, matrixC);
			}
			else if(opcao2==2)
			{

			hermitic(l2, c2, matrixC2);
			}
		}
	}
}
