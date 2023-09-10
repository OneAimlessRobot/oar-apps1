import java.util.*;



public class Main{

	public static void main(String[] args){
	
	System.out.println("Insere o numero a testar");
	Scanner in= new Scanner(System.in);
	
	
	}
private void binoper(int x) {

  System.out.printf("\nb = %d %x\n", x, x);
  
  int resultado = x; // completar
  
  //intersecao de 1 com o numero a avaliar. Sera 0 se for par e 0 se for impar
  int aux=Integer.toBinaryString(2);
  resultado = x&aux==1;
  
  System.out.printf("a) %d  %x\n", resultado,resultado );
  
  /*Resultado dividido por 2^2=4*/
  resultado= x>>2;
  
  System.out.printf("b) %d  %x\n", resultado, resultado);
  
  resultado= (x<<3)+(x<<2);
  System.out.printf("c) %d  %x\n", resultado, resultado);
}
}
