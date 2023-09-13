
void fillarray(int n, int prec1, long double *array)
{
    int i;
    long double prec2 = 1 / prec1;
    long double sum;
    *array = sum;
    for (i = 0, sum = (long double)-n; sum < n; i++)
    {
       (*(array+i) )= sum;
        sum += (long double)1 / prec1;
    }
}