
#include <stdio.h>

void binoper(int x) {

  printf("\nb = %d %x\n", x, x);
  int resultado = x; // completar
  
  //intersecao de 1 com o numero a avaliar. Sera 0 se for par e 0 se for impar
  int aux=0b0000000000000000000000000001;
  resultado = x&aux==1;
  
  printf("a) %d  %x\n", resultado,resultado );
  
  /*Resultado dividido por 2^2=4*/
  resultado= x>>2;
  
  printf("b) %d  %x\n", resultado, resultado);
  
  resultado= (x<<3)+(x<<2);
  printf("c) %d  %x\n", resultado, resultado);
}

int main() {

  int x;

  printf ("Indique o número a testar:\n");
  scanf("%d", &x);
  binoper(x);
  return 0;
}

