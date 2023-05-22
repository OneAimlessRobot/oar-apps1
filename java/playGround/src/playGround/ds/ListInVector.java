package playGround.ds;

import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.List;

public class ListInVector<T> implements List<T> {

	private static class VectorIterator<T> implements TwoWayIterator<T>{
		
		private ListInVector<T> support;
		private int currPos;
		public VectorIterator(ListInVector<T> support) {
			
			this.support=support;
			currPos=0;
			
		}
		@Override
		public T next() {
			return support.get(currPos++);
		}
		@Override
		public boolean hasNext() {
			return this.currPos!=support.size();
		}
		@Override
		public void rewind() {
			this.currPos=0;
		}
		@Override
		public T prev() {
			return support.get(currPos--);
		}
		@Override
		public void fullForward() {
			currPos=support.size()-1;
		}
		@Override
		public boolean hasPrev() {
			return currPos!=-1;
		}
		@Override
		public void close() {
			support=null;
			
		}
		
		
		
	}
	private T[] arr;
	private static final int INIT_SIZE=1;
	private int currPos,size;
	//Constroi uma stack vazia
	public ListInVector() {
		
		arr= (T[])new Object[INIT_SIZE];
		currPos=-1;
		size=INIT_SIZE;
		
	}
	//Constroi uma stack com elementos de um Array ordenados pela ordem em
	//que estao nele (ultimo elemento em cima, primeiro em baixo)
	public ListInVector(T[] elems) {
		
		arr= (T[])new Object[INIT_SIZE];
		currPos=-1;
		size=INIT_SIZE;
		for(int i=0;i<elems.length;i++) {
			this.add(elems[i]);
		}
		
		
	}
	@Override
	public void add(T elem) {
		if(isFull()) {
			
			grow();
		}
		arr[++currPos]=elem;
		
	}
	private void grow() {
		
		T[] aux= (T[]) new Object[size*2];
		
		for(int i=0;i<size;i++) {
			
			aux[i]=arr[i];
		}
		for(int i=0;i<size;i++) {
			arr[i]=null;
		}
		size*=2;
		arr=aux;		
	}
	private boolean isFull() {
		
		return currPos==size-1;
		
	}
	@Override
	
	//Isto so faz o objeto invisivel para a stack. A responsabilidade de libertar
	//A memoria é de quem mete cenas lá dentro.
	public void remove() {
		if(isEmpty()) {
			return;
		}
		arr[currPos--]=null;
		
	}
	//tentei adicionar um indicador bonitinho do topo da stack mas ndn
//	public String toString() {
//		
//		if(isEmpty()){
//			
//			return "[ ]";
//		}
//		String str="[ ";
//		for(int i=0;i<this.size();i--) {
//			
//			str+= arr[i].toString()+" ";
//		}
//		str+="]";
//				
//		return str;
//		
//	}
	public boolean isEmpty() {
		
		return this.currPos==-1;
	}
	@Override
	public int size() {
		return currPos+1;
	}
	@Override
	public void destroy() {
		while(currPos!=-1) {
			
			this.remove();
		}
	}
	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return new VectorIterator<>(this);
	}
	@Override
	public Iterator<T> iterator() {
		return (Iterator<T>) new VectorIterator<>(this);
	}
	@Override
	public void invert() {
		
	}
	@Override
	public T get(int index) {
		if(index >= this.size()|| index < 0) {
			
			return null;
		}
			
		return arr[index];
	}
	@Override
	public void add(T elem, int index) {
		if(isFull()) {
			
			grow();
		}

		currPos++;
		if(index <=0) {
			
			addFirst(elem);
		}
		else if(index >=currPos) {
		
			addLast(elem);
		}
		else {
			
			addMiddle(elem,index);
		
		}
		
	}
	private void addFirst(T elem) {
		int i=this.currPos-1;
		for(;i>0;i--) {
			
			arr[i+1]=arr[i];
			
			
		}
		arr[0]=elem;
		
	}
	private void addLast(T elem) {
		arr[currPos]=elem;
		
		
	}
	private void addMiddle(T elem, int index) {
		int i=this.currPos-1;
		for(;i>index;i--) {
			
			arr[i+1]=arr[i];
			
			
		}
		arr[index]=elem;
	}
	private void removeFirst() {
		
		for(int i=0;i<currPos-1;i++) {
			arr[i]=arr[i+1];
			
		}
		
	}
	private void removeLast() {
		arr[currPos]=null;
	}
	private void removeMiddle(int index) {
		for(int i=index;i<currPos-1;i++) {
			arr[i]=arr[i+1];
			
		}
		
	}
	@Override
	public void remove(int index) {
		if(isEmpty()) {
		
			return;
		
		}
		currPos--;
		if(index <0) {
			
			removeFirst();
		}
		else if(index >=currPos) {

			removeLast();
		}
		else {
			
			removeMiddle(index);
		
		}
	}
	
	public String toString() {
		
		if(isEmpty()) {
			
			return "[ ]";
		}
		String str="[ ";
		Iterator<T> it= this.iterator();
		while(it.hasNext()) {
			
			str+= it.next().toString() + " ";
			
			
		}
		str+=" ]";
		it.close();
		return str;
				
		
	}
	@Override
	public InvIterator<T> backwardIterator() {
		// TODO Auto-generated method stub
		return null;
	}
}
