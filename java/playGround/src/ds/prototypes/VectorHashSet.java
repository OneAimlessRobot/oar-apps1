package ds.prototypes;

import ds.implem.AbstractCollection;
import ds.implem.Vector;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.MySet;
import ds.interfaces.TwoWayIterator;

public class VectorHashSet<T> extends AbstractCollection<T> implements MySet<T> {

	private static final long serialVersionUID = 1L;
	private static class VectorHashSetIterator<T> implements TwoWayIterator<T>{
		
		private int mainPos,first,last;
		private TwoWayIterator<T> current;
		private Vector<T>[] entries;
		public VectorHashSetIterator(VectorHashSet<T> set){
			
			this.entries=(Vector<T>[]) set.entries;
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
			
					this.current =entries[mainPos].twoWayIterator();
					
		}
		private void skipEmptyListsBackwards() {
			while(entries[mainPos].isEmpty()) {mainPos--;}
			
						this.current=entries[mainPos].twoWayIterator();
					
					
		}
		private void skipOneListForward() {
			
			this.current=entries[++mainPos].twoWayIterator();	
		}

		private void skipOneListBackwards() {
			if(current!=null) {
			}

			this.current=entries[--mainPos].twoWayIterator();
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
	private Vector<?>[] entries;
	private static final double LOAD_FACTOR=0.75;//(filas/numeroElems)
	private static final int INIT_SPINE_SIZE =1000;
	private static final int GROW_FACTOR=2;
	private int numOfStoredElems,spineSize;
	public VectorHashSet() {
		spineSize=INIT_SPINE_SIZE;
		numOfStoredElems=0;
		init();
		
		
		
	}private VectorHashSet(int size,int numOfInserted) {

		spineSize=size;
		numOfStoredElems=numOfInserted;
		init();
		
		
		
	}
private void init() {
		
		entries=(Vector<T>[])new Vector<?>[spineSize];

		for(int i=0;i<spineSize;i++) {
			
			entries[i]= new Vector<>();
		}
		
		
	}
private boolean isFull() {
	
	return getLoadFactor()<LOAD_FACTOR;
	
	
}
private double getLoadFactor() {
	
	return (double)spineSize/(double)numOfStoredElems;
}
@Override
public void add(T elem) {
	if(contains(elem)) {
		return;
	}
	if(isFull()) {
		reHash();
	}
	int pos= Math.abs(elem.hashCode() % spineSize);
	((Vector<T>) entries[pos]).add(elem);
	numOfStoredElems++;
	
}
private void addNoChecks(T elem) {
	int pos= Math.abs(elem.hashCode() % spineSize);
	((Vector<T>) entries[pos]).add(elem);
	
}
private int computeElemPos(T elem,int size) {

	return Math.abs(elem.hashCode() % size);
}
	@Override
	public boolean isEmpty() {
		
		return isEmptyAux(0);
	}
	private boolean isEmptyAux(int index) {
		
		if(index==spineSize-1) {
		if(((Vector<T>)entries[index]).isEmpty()) {
			return true;
		}
		}
		return ((Vector<T>)entries[index]).isEmpty() && isEmptyAux(index+1);
		
		
	}

	@Override
	public TwoWayIterator<T> twoWayIterator(){

		return new VectorHashSetIterator<>(this);
	}

	@Override
	public Iterator<T> iterator()  {
		return new VectorHashSetIterator<>(this);
	}

	private void reHash() {
	    int oldSize = spineSize;
	    spineSize *= GROW_FACTOR;
	    VectorHashSet<T> set = new VectorHashSet<>(spineSize, numOfStoredElems);

	    for (int i = 0; i < oldSize; i++) {
	        Vector<T> list = (Vector<T>) entries[i];
	        if (!list.isEmpty()) {
	            int pos = computeElemPos(list.get(0),spineSize);
	            set.entries[pos]=list;
	            
	        }
	    }

	    entries = set.entries;
	    set.entries = null;
	    set = null;
	}
	
	@Override
	public boolean contains(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			Vector<T> list= ((Vector<T>) entries[pos]);
			
			if(list.isEmpty()) {
				list=null;
				return false;
			}
			Iterator<T> it = list.iterator();
				while(it.hasNext()) {
					if(it.next().equals(elem)) {
						list=null;
						return true;
					}
				}
			
			
			return false;
	}

	@Override
	public Collection<T> copy() {
		Collection<T> collection= new VectorHashSet<>();
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
	public int size() {
		return numOfStoredElems;
	}

	@Override
	public void remove(T elem) {
		if(contains(elem)) {
			
			int pos=computeElemPos(elem,spineSize);
			Vector<T> list=(Vector<T>) this.entries[pos];
			Iterator<T> it=list.iterator();
			while(it.hasNext()&&!elem.equals(it.next()));
			list.remove(list.getIndex(elem));
			numOfStoredElems--;
		}
		
	}
	@Override
	public void clear() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			((Vector<T>) entries[i]).clear();
		}
		numOfStoredElems=0;
		}
	}


}
