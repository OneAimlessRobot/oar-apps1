package ds.implem;

import java.io.Serializable;

import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.MySet;
import ds.interfaces.TwoWayIterator;

public class MyHashSetTreefy<T extends Comparable<T>> extends AbstractSet<T> implements MySet<T> {

	private static final long serialVersionUID = 1L;



	private static class HashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>,Serializable{
		
		private static final long serialVersionUID = 1L;
		private int mainPos,first,last;
		private TwoWayIterator<T> current;
		private Collection<T>[] entries;
		public HashSetIterator(MyHashSetTreefy<T> set){
			
			this.entries=(Collection<T>[]) set.entries;
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
			while(entries[mainPos].isEmpty()&&mainPos<entries.length-1) {mainPos++;}
			
					this.current =entries[mainPos].twoWayIterator();
					
		}
		private void skipEmptyListsBackwards() {
			while(entries[mainPos].isEmpty()&&mainPos>0) {mainPos--;}
			
						this.current=entries[mainPos].twoWayIterator();
					
					
		}
		private void skipOneListForward() {
			

			mainPos++;	
		}

		private void skipOneListBackwards() {
			
			mainPos--;
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
	private Collection<T>[] entries;
	private static final double LOAD_FACTOR=0.75;//(filas/numeroElems)
	private static final int INIT_SPINE_SIZE =256;
	private static final int GROW_FACTOR=2;
	private static final int TREEFY_AMMOUNT=100;
	private int numOfStoredElems,spineSize;
	public MyHashSetTreefy() {
		spineSize=INIT_SPINE_SIZE;
		numOfStoredElems=0;
		init();
		
		
		
	}
	private MyHashSetTreefy(int size,int numOfInserted) {

		spineSize=size;
		numOfStoredElems=numOfInserted;
		init();
		
		
		
	}
	private void init() {
		
		entries=(Collection<T>[])new Collection[spineSize];

		for(int i=0;i<spineSize;i++) {
			
			entries[i]= new HashTableBucket<>(TREEFY_AMMOUNT);
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
		((Collection<T>) entries[pos]).add(elem);

		numOfStoredElems++;

		if(isFull()) {
			reHash();
		}
		
	}
	private void addNoChecks(T elem) {
		int pos= computeElemPos(elem,spineSize);
		entries[pos].add(elem);

		numOfStoredElems++;
		
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
	public void clear() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			
			entries[i].clear();
		}
		numOfStoredElems=0;
		}
	}

	@Override
	public int size() {

		
		return numOfStoredElems;
	}
	@Override
	public boolean contains(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			Collection<T> col= ((Collection<T>)entries[pos]);
			if(col==null) {
				return false;
			}
			if(col.isEmpty()) {
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
	    MyHashSetTreefy<T> newSet= new MyHashSetTreefy<>(spineSize,0);
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
			Collection<T> list=(Collection<T>) this.entries[pos];
			list.remove(elem);
			list=null;
			numOfStoredElems--;
		}
		
	}




}