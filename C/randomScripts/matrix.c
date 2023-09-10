#include <stdio.h>
#include <math.h>

void fillmatrixdiag(float k, int m, int n, float array[m][n]);
void summatrices(int lA, int cA, int lB, int cB, float arrayA[lA][cA], float arrayB[lB][cB], float arraysum[lA][cA]);
void multmatrices(int lA, int cA, int lB, int cB, float arrayA[lA][cA], float arrayB[lB][cB], float arraymult[lA][cB]);
void printmatrix(int l, int c, float array[l][c]);
void fillmatrixfree(int m, int n, float array[m][n]);

int main(void)
{
	int l1, l2, c1, c2;
	char s, m;
	float k;

	printf("O valor que se vai colocar como k;\n");
	scanf("%f", &k);
	printf("coloca o numero de linhas e colunas da 1ª matrix separados por um '"
		   "x"
		   "':\n");
	scanf("%ix%i", &l1, &c1);
	printf("coloca o numero de linhas e colunas da 2ª matrix separados por um '"
		   "x"
		   "':\n");
	scanf("%ix%i", &l2, &c2);

	float matrix[l1][c1], matrix2[l2][c2], matrixsum[l1][c1], matrixmult[l1][c2];

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
	else
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
	printf("queres somar o multiplicar? (S/M)\n");
	do
	{
		scanf("%c", &s);
	} while (s != 'S' && s != 'M');
	if (((c1 != c2 || l1 != l2) && s == 'S') || ((c1 != l2) && s == 'M'))
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
}

void fillmatrixdiag(float k, int m, int n, float array[m][n])
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				array[i][j] = 0;
			}
			else
				array[i][j] = k;
		}
	}
}

void fillmatrixfree(int m, int n, float array[m][n])
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%f", &array[i][j]);
		}
	}
}
void summatrices(int lA, int cA, int lB, int cB, float arrayA[lA][cA], float arrayB[lB][cB], float arraysum[lA][cA])
{

	for (int i = 0; i < lA; i++)
	{
		for (int j = 0; j < cB; j++)
		{
			arraysum[i][j] = arrayA[i][j] + arrayB[i][j];
		}
	}
}

void multmatrices(int lA, int cA, int lB, int cB, float arrayA[lA][cA], float arrayB[lB][cB], float arraymult[lA][cB])
{
	/* Implementei isto de outro gajo. Nem sei bem porque é que funciona, nem porque é que a minha abordagem não estava a functionar... devia ter a haver com o facto de que a cada volta do loop do somatório o valor era reduzido a 0, por isso só restava o produto dos dois ultimos*/
	for (int i = 0; i < lA; i++)
	{
		for (int j = 0; j < cB; j++)
		{

				arraymult[i][j] = 0;
			
			for (int k = 0; k < cB; k++)
			{
				arraymult[i][j] += arrayA[i][k] * arrayB[k][j];
			}
		}
	}
}

void printmatrix(int l, int c, float array[l][c])
{

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%0.2f ", array[i][j]);
		}
		printf("\n");
	}
}