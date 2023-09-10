#include <stdio.h>
#include <math.h>

int collatz(int n);
int main(void)
{

    /* preciso de escrever uma função que aceite todos os numeros inteiros positivos e cuspa 1. Qualquer numero inteiro converte-se em 1.
    Os passos em pseudocode que a função tem de seguir são:
    1-Se o numero é igual a 1, pára
    2-Se o numero é par, faz numero/2;
    3-Se o numero é ímpar, faz 2 para (3*numero +1);
    cada coisa destas é um passo.
    Temos por ex: 6. 6 é diferente de 1. Logo, o primeiro passo é, por ser par dividir por 2. Dá 3. Como 3 é ímpar, multiplicamos por 3 e somamos 1 e dividimos por 2. dá 5. 5 é ímpar.
    Multiplicamos por 3, somamos 1 e dividimos por 2. Dá 8. Dividimos por 2. Dá 4. Dividimos por 2. Dá 2. Dividimos por 2. Dá 1. 1=1 logo acabou o programa. 
    O objetivo é pegar num inteiro positivo, dividi-lo por 2 caso seja >1 e par, e multiplicá-lo por 3, somar 1 e dividir por 2 caso seja ímpar
    até chegar a 1, como sabemos que vai e parar o programa. NICE! Já defini por loops*/
    int k;
    printf("escreve aqui n\n");
    scanf("%i", &k);
    int j = collatz(k);
    printf("o numero de passos é %i\n", j);
}

int collatz(int n)
{
    int i;
    for (i = 0; n > 1; i++)
    {
        i--;
        if (remainder(n, 2) == 0)
        {
            n = n / 2;
            printf("n vale %i\n", n);
            i++;
        }

        else if (remainder(n, 2) != 0)
        {
            i++;
            n = (3 * n + 1);
            printf("n vale %i\n", n);
            i++;
            n=n/2;
            printf("n vale %i\n", n);
        }
    }
    return i;
}