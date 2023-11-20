package ds.implem;

import java.io.Serializable;

import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.TwoWayIterator;

public class Vector<T> extends AbstractList<T> implements Serializable {

	private static final long serialVersionUID = 1L;
	private static class VectorIterator<T> implements TwoWayIterator<T>, Serializable{
		
		private static final long serialVersionUID = 1L;
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
	
	
	public boolean isEmpty() {
		
		return this.currPos==-1;
	}
	@Override
	public int size() {
		return currPos+1;
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
		for(int i=index;i<currPos;i++) {
			arr[i]=arr[i+1];
			
		}
		currPos--;
		
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
            int i=-1;
            for(;i<currPos;) {
                    i++;
            if(elem.equals(get(i))) {
                    return i;
            }
            }
            return -1;
    }

	@Override
	public boolean contains(T elem) {
		return getIndex(elem)!=-1;
	}
	@Override
	public void clear() {
		while(currPos!=-1) {
			
			this.remove(currPos--);
		}
	}
	@Override
	public void update(T elem, int index) {
		if(isEmpty()) {
			
			return;
		
		}
		int i=0;
		for(;i<currPos&&i<index&&index>-1;i++);
		arr[i]=elem;
	}
}
