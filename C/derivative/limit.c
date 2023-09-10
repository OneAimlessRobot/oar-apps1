#include <math.h>
#include <stdio.h>

int main(void){

}

void loopsucessao(int prec, long double ponto, char lado)
{

    for (int j = 1; j <= prec; j++)
    {

        printf("Un(%i)= %0.7f\n", j, sucessao(j, ponto, lado));
    }
}
long double sucessao(int n, long double lim, char lado)
{

    if (toupper(lado) == 'E')
    {

        return lim - (long double)1 / n;
    }
    else if (toupper(lado) == 'D')
    {
        return lim + (long double)1 / n;
    }
}