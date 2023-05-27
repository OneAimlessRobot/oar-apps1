package playGround.ds;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.abstractClasses.AbstractList;
import playGround.adt.collections.List;

public class Vector<T> extends AbstractList<T> implements List<T> {

	private static class VectorIterator<T> implements TwoWayIterator<T>{
		
		private Vector<T> support;
		private int currPos;
		public VectorIterator(Vector<T> support) {
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
	private static final int INIT_SIZE=10;
	private int currPos,size;
	//Constroi uma stack vazia
	public Vector() {
		
		arr= (T[])new Object[INIT_SIZE];
		currPos=-1;
		size=INIT_SIZE;
		
	}
	//Constroi uma stack com elementos de um Array ordenados pela ordem em
	//que estao nele (ultimo elemento em cima, primeiro em baixo)
	public Vector(T[] elems) {
		
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
	
	public boolean isEmpty() {
		
		return this.currPos==-1;
	}
	@Override
	public int size() {
		return currPos+1;
	}
	@Override
	public void finalize() {
		while(currPos!=-1) {
			
			this.remove();
		}
		this.arr=null;
	}
	@Override
	public TwoWayIterator<T> twoWayIterator()  {
		return new VectorIterator<>(this);
	}
	@Override
	public Iterator<T> iterator()  {
		return (Iterator<T>) new VectorIterator<>(this);
	}
	@Override
	public void invert() {
		
	}
	@Override
	public T get(int index) {
		if(index >= this.size()|| index < 0) {
			
			throw new IndexOutOfBoundsException();
		}
			
		return arr[index];
	}
	@Override
	public void add(T elem, int index) {
		if(index<0||index>currPos-1) {
			return;
		}
		if(isFull()) {
			grow();
		}
		currPos++;
		int i=this.currPos;
		for(;i>=index;i--) {
			
			arr[i+1]=arr[i];
			
			
		}
		arr[index]=elem;
	}

	@Override
	public void remove(int index) {
		if(index<0||index>currPos) {
			return;
		}
		if(isEmpty()) {
		
			return;
		
		}
		arr[index]=null;
		for(int i=index;i<=currPos;i++) {
			arr[i]=arr[i+1];
			
		}
		currPos--;
		
	}
	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new VectorIterator<>(this);
	}

	@Override
	public Collection<T> copy() {
		Collection<T> collection= new Vector<>();
		if(isEmpty()) {
			return collection;
		}
		Iterator<T> it= iterator();
		while(it.hasNext()) {
			
			collection.add(it.next());
		}
		return collection;
		
	}
	@Override
	public int getIndex(T elem) {
		if(isEmpty()) {
			return -1;
		}
		int i=0;
		for(;i<currPos&&!get(i).equals(elem);i++);
		if(arr[i]==null) {
			return -1;
		}
		return i;
	}
	@Override
	public boolean contains(T elem) {
		return getIndex(elem)!=-1;
	}
	@Override
	public void clear() {
		while(currPos!=-1) {
			
			this.remove();
		}
	}
}
