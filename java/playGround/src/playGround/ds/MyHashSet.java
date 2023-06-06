package playGround.ds;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.abstractClasses.*;
import playGround.adt.collections.MySet;

public class MyHashSet<T> extends AbstractSet<T> implements MySet<T> {

	private static class HashSetIterator<T> implements TwoWayIterator<T>{
		
		private int mainPos,first,last;
		private TwoWayIterator<T> current;
		private DoubleLinkedList<T>[] entries;
		public HashSetIterator(MyHashSet<T> set){
			
			this.entries=(DoubleLinkedList<T>[]) set.entries;
			fullForward();
			last=mainPos;
			rewind();
			first=mainPos;
		}
		@Override
		public T next() {
			if(!current.hasNext()) {
				skipOneListForward();
				skipEmptyListsForward();
				
			}
			
			return current.next();
		}
		@Override
		public boolean hasNext() {
			if(current.hasNext()) {
				return true;
			}
			else if(mainPos<last) {
				
				return true;
			}
			return false;
			
		}

		@Override
		public void rewind() {
			mainPos=0;
			skipEmptyListsForward();
		}
		
		private void skipEmptyListsForward() {
			while(entries[mainPos].isEmpty()) {mainPos++;}
			if(current!=null) {
				current.close();
			}
					this.current =entries[mainPos].twoWayIterator();
					
		}
		private void skipEmptyListsBackwards() {
			while(entries[mainPos].isEmpty()) {mainPos--;}
			if(current!=null) {
				current.close();
			}
						this.current=entries[mainPos].twoWayIterator();
					
					
		}
		private void skipOneListForward() {
			if(current!=null) {
				current.close();
			}

			mainPos++;	
		}

		private void skipOneListBackwards() {
			if(current!=null) {
				current.close();
			}

			mainPos--;
		}
		@Override
		public void close() {

			if(current!=null) {
				current.close();
			}
			entries=null;
			
		}

		@Override
		public T prev() {
			if(!current.hasPrev()) {
				skipOneListBackwards();
				skipEmptyListsBackwards();
				current.fullForward();
				
				
			}
			
			return current.prev();
		}

		@Override
		public void fullForward() {
			mainPos=entries.length-1;
			skipEmptyListsBackwards();
			current.fullForward();
		}

		@Override
		public boolean hasPrev() {
			if(current.hasPrev()) {
				return true;
			}
			else if(mainPos>first) {
				
				return true;
			}
			return false;
		}
		
		
		
	}
	private DoubleLinkedList<?>[] entries;
	private static final double LOAD_FACTOR=0.75;//(filas/numeroElems)
	private static final int INIT_SPINE_SIZE =64;
	private static final int GROW_FACTOR=2;
	private int numOfStoredElems,spineSize;
	public MyHashSet() {
		spineSize=INIT_SPINE_SIZE;
		numOfStoredElems=0;
		init();
		
		
		
	}
	private MyHashSet(int size,int numOfInserted) {

		spineSize=size;
		numOfStoredElems=numOfInserted;
		init();
		
		
		
	}
	private void init() {
		
		entries=(DoubleLinkedList<T>[])new DoubleLinkedList<?>[spineSize];

		for(int i=0;i<spineSize;i++) {
			
			entries[i]= new DoubleLinkedList<>();
		}
		
		
	}
	private boolean isFull() {
		
		return getLoadFactor()<LOAD_FACTOR;
		
		
	}
	@Override
	public void add(T elem) {
		if(contains(elem)) {
			return;
		}
		int pos= computeElemPos(elem,spineSize);
		((DoubleLinkedList<T>) entries[pos]).add(elem);
		numOfStoredElems++;

		if(isFull()) {
			reHash();
		}
		
	}
	private void addNoChecks(T elem) {
		int pos= computeElemPos(elem,spineSize);
		((DoubleLinkedList<T>) entries[pos]).add(elem);
		
	}
	private int computeElemPos(T elem,int size) {

		return Math.abs(elem.hashCode() % size);
	}

	@Override
	public boolean isEmpty() {
		
		return numOfStoredElems==0;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator(){

		return (TwoWayIterator<T>) new HashSetIterator<>(this);
	}

	@Override
	public Iterator<T> iterator()  {
		return (Iterator<T>) new HashSetIterator<>(this);
	}

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new HashSetIterator<>(this);
	}

	public void finalize() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			int size=((DoubleLinkedList<T>) entries[i]).size();
			numOfStoredElems-=size;
			entries[i]=null;
		}
		entries=null;
		}
	}

	@Override
	public int size() {
		
		return numOfStoredElems;
	}
	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public boolean contains(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			DoubleLinkedList<T> col= ((DoubleLinkedList<T>)entries[pos]);
			if(col.isEmpty()) {
				col=null;
				return false;
			}
			boolean contains=col.contains(elem);			

			return contains;
	}


	@Override
	public Collection<T> copy() {
		Collection<T> collection= new MyHashSet<>();
		if(isEmpty()) {
			return collection;
		}
		Iterator<T> it= iterator();
		while(it.hasNext()) {
			
			collection.add(it.next());
		}
		return collection;
		
	}
	private double getLoadFactor() {
		
		return (double)spineSize/(double)numOfStoredElems;
	}

	private void reHash() {
	    spineSize *= GROW_FACTOR;
	    MyHashSet<T> newSet= new MyHashSet<>(spineSize,numOfStoredElems);
	    Iterator<T> it= iterator();
	    while(it.hasNext()) {
	    	newSet.addNoChecks(it.next());
	    }

	    entries = newSet.entries;
	    newSet.entries=null;
	    newSet=null;
	}
	@Override
	public void remove(T elem) {
		if(contains(elem)) {
			
			int pos=computeElemPos(elem,spineSize);
			DoubleLinkedList<T> list=(DoubleLinkedList<T>) this.entries[pos];
			list.remove(list.getIndex(elem));
			list=null;
			numOfStoredElems--;
		}
		
	}



	@Override
	public void clear() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			int size=((DoubleLinkedList<T>) entries[i]).size();
			((DoubleLinkedList<T>) entries[i]).finalize();
			numOfStoredElems-=size;
		}
		}
	}


}