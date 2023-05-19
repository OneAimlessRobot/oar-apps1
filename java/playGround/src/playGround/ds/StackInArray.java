package playGround.ds;

import playGround.adt.*;
import playGround.adt.exceptions.StackEmptyException;

public class StackInArray<T> implements  Stack<T>{
	
	private T[] arr;
	private static final int INIT_SIZE=10;
	private int topPos,size;
	//Constroi uma stack vazia
	public StackInArray() {
		
		arr= (T[])new Object[INIT_SIZE];
		topPos=-1;
		size=INIT_SIZE;
		
	}
	//Constroi uma stack com elementos de um Array ordenados pela ordem em
	//que estao nele (ultimo elemento em cima, primeiro em baixo)
	public StackInArray(T[] elems) {
		
		arr= (T[])new Object[elems.length];
		topPos=-1;
		size=elems.length;
		for(int i=0;i<elems.length;i++) {
			
			this.push(elems[i]);
		}
		
		
	}
	@Override
	public void push(T elem) {
		if(isFull()) {
			
			grow();
		}
		arr[++topPos]=elem;
		
	}
	private void grow() {
		
		T[] aux= (T[]) new Object[size*2];
		
		for(int i=0;i<size;i++) {
			
			aux[i]=arr[i];
		}
		size*=2;
		arr=aux;		
	}
	private boolean isFull() {
		
		return topPos==size;
		
	}
	@Override
	
	//Isto so faz o objeto invisivel para a stack. A responsabilidade de libertar
	//A memoria é de quem mete cenas lá dentro.
	public T pop() throws StackEmptyException {
		if(isEmpty()) {
			
			throw new StackEmptyException();
		}
		T elem= arr[topPos--];
		return elem;
		
	}
	//tentei adicionar um indicador bonitinho do topo da stack mas ndn
	public String toString() {
		
		if(isEmpty()){
			
			return "[ ]";
		}
		String str="[ ";
		for(int i=this.topPos;i>-1;i--) {
			
			str+= arr[i].toString()+" ";
		}
		str+="]";
				
		return str;
		
	}
	public boolean isEmpty() {
		
		return this.topPos==-1;
	}
	@Override
	public T top() throws StackEmptyException {
		if(isEmpty()) {
			
			throw new StackEmptyException();
		}
		return arr[topPos];
	}
	@Override
	public int size() {
		return topPos;
	}
			

}


