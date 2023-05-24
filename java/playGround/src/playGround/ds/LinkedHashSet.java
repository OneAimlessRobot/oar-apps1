package playGround.ds;

import playGround.abstractClasses.AbstractCollection;
import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.Set;
import playGround.aux.smallAlgorithms.CollectionAlgorithms;

public class LinkedHashSet<T extends Comparable<T>> extends AbstractCollection<T> implements Set<T> {

	private static class LinkedHashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{
		
		private int mainPos,first,last;
		private TwoWayIterator<T> current;
		private DoubleLinkedList<T>[] entries;
		public LinkedHashSetIterator(LinkedHashSet<T> set){
			
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
	private static final int START_SIZE =1000;
	private int numOfStoredElems,spineSize;
	private static final double loadFactorThreshold=0.9;
	public LinkedHashSet() {
		spineSize=START_SIZE;
		numOfStoredElems=0;
		init();
		
		
		
	}
	private LinkedHashSet(int size,int numOfInserted) {

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
		
		return getLoadFactor()<0.75;
		
		
	}
	@Override
	public void add(T elem) {
		if(exists(elem)) {
			return;
		}
		if(isFull()) {
			reHash();
		}
		int pos= Math.abs(elem.hashCode() % spineSize);
		((DoubleLinkedList<T>) entries[pos]).add(elem);
		numOfStoredElems++;
		
	}

	@Override
	public int size() {

		int result=0;
		for(int i=0;i<spineSize;i++) {
			
			DoubleLinkedList<T> cur= ((DoubleLinkedList<T>) entries[i]);
			
			result+=cur.size();
			
		}
		return result;
	}
//	private int countFullLists() {
//		DoubleLinkedList<T>[] entrs= (DoubleLinkedList<T>[]) entries;
//		int result=0;
//		for(int i=0;i<spineSize;i++) {
//			
//			if(entrs[i].size()>VectorSizeForCollision) {
//				result++;
//			}
//		}
//		return result;
//		
//		
//	}
	@Override
	public boolean isEmpty() {
		
		return isEmptyAux(0);
	}
	private boolean isEmptyAux(int index) {
		
		if(index==spineSize-1) {
		if(((DoubleLinkedList<T>)entries[index]).isEmpty()) {
			return true;
		}
		}
		return ((DoubleLinkedList<T>)entries[index]).isEmpty() && isEmptyAux(index+1);
		
		
	}

	@Override
	public TwoWayIterator<T> twoWayIterator(){

		return (TwoWayIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public Iterator<T> iterator()  {
		return (Iterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public void destroy() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			((DoubleLinkedList<T>) entries[i]).destroy();
			entries[i]=null;
		}
		entries=null;
		}
	}


	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}


	private boolean exists(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			DoubleLinkedList<T> list= ((DoubleLinkedList<T>) entries[pos]);
			if(list.isEmpty()) {
				list=null;
				return false;
			}
			Iterator<T> it = list.iterator();
				while(it.hasNext()) {
					if(elem.compareTo(it.next())==0) {
						it.close();
						list=null;
						return true;
					}
				}
				it.close();
			
			
			return false;
	}

	@Override
	public Collection<T> copy() {
		Collection<T> collection= new LinkedHashSet<>();
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
		
		return (double)this.numOfStoredElems/(double)this.spineSize;
	}
	private void reHash() {
		LinkedHashSet<T> collection= new LinkedHashSet<>(spineSize*=2,this.numOfStoredElems);
		Iterator<T> it= this.iterator();
		while(it.hasNext()) {
			
			collection.add(it.next());
		}
		this.entries=collection.entries;
		this.numOfStoredElems=collection.numOfStoredElems;
		collection=null;
	}

}
