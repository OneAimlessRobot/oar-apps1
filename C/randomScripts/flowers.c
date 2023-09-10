#include <stdio.h>
int emptyVase(int flowersInVase);

int main(void)
{
    int n=9;
    int j=emptyVase(n);
    printf("numero de passos=%i\n",j);

}
int emptyVase(int flowersInVase)
{
    if (flowersInVase > 0)
    {
        // take one flower and
        return 1 + emptyVase(flowersInVase - 1);
    }
    else
    {
        return 0;
    }

}