#include <complex.h>
#include <stdio.h>

int main(void){

    double a,b,c,d;
    printf("Insere aqui o teu numero complexo na forma ""a+bi""\n");
    scanf("%lf+%lfi",&a,&b);
    scanf("%lf+%lfi",&c,&d);
    complex x=CMPLX(a,b);
    complex z=CMPLX(c,d);
    printf("O teu numero complexo x é: %f + %fi",creal(x*z),cimag(x*z));
}