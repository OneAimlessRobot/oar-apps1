#include <stdio.h>
#include <math.h>

// Esta "magica" para forçar um float a ser tratado como um int será
// um dia mais tarde estudada :-)
#define F2INT(F)  (*(int*)&(F))

void printBin( int val ) {
  int dimensao= 8*sizeof(int); 	// dimensão de um int EM BITS

  for (int i=0; i < dimensao; i++) {
    int bit = val & 0b10000000000000000000000000000000  ;		// extrair o bit da posição i
    int ZeroUm= bit >> 31;		// afectar a variavel a 0 ou 1
    if(ZeroUm <0){
    ZeroUm*=-1;
    }					// em função do bit extraido
    printf("%d", ZeroUm );
    val=val<<1;				// deslocar para ir buscar
					// o próximo bit
  }
  putchar('\n');
}


void printBinExponent(int val){


  val=val>>23;
  for(int i=0;i<8+1;i++){
  
  if(i==0){
  //salta o primeiro bit que é o sinal
  }
  else{
    int bit = val & 0b10000000  ;	
    int ZeroUm= bit >> 7;	
				
    if(ZeroUm <0){
    ZeroUm*=-1;
    }					
    printf("%d", ZeroUm );
    val=val<<1;
 }	
  
  }
  putchar('\n');

}

int main( ) {
  float f;
  scanf("%f",&f);
  printBin( F2INT(f) );
  printf("%.20f\n", f);
  printBinExponent(F2INT(f));
}
