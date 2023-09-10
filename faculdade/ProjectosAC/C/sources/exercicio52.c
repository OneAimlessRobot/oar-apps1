
#include <stdio.h>

void binoper(int x) {

  printf("\nb = %d %x\n", x, x);
  int resultado = x; // completar
  
  int aux=0b0000000000000000000000000010;
  resultado = x|aux;
  
  printf("a) %d  %x\n", resultado,resultado );
  
  aux= 0b000011111111111111111111111111;
  resultado= x&aux;
  
  printf("b) %d  %x\n", resultado, resultado);

  resultado = x<<4; // completar
  printf("c) %d  %x\n", resultado, resultado);
}

int main() {

  int x;

  printf ("Indique o número a testar:\n");
  scanf("%d", &x);
  binoper(x);
  return 0;
}

