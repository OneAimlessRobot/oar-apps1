package playGround.ds;

import playGround.abstractClasses.AbstractCollection;
import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.Set;

public class VectorHashSet<T extends Comparable<T>> extends AbstractCollection<T> implements Set<T> {

	private static class VectorHashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{
		
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

			this.current=entries[++mainPos].twoWayIterator();	
		}

		private void skipOneListBackwards() {
			if(current!=null) {
				current.close();
			}

			this.current=entries[--mainPos].twoWayIterator();
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
	private Vector<?>[] entries;
	private static final int START_SIZE =10;
	private int VectorSizeForCollision,spineSize,fullBucketThreshold;
	public VectorHashSet() {
		VectorSizeForCollision=5;
		fullBucketThreshold=4;
		spineSize=START_SIZE;
		init();
		
		
		
	}
	private void init() {
		
		entries=new Vector<?>[START_SIZE];

		for(int i=0;i<START_SIZE;i++) {
			
			entries[i]= new Vector<>();
		}
		
		
	}
	private void grow() {
		
		Vector<T>[] aux= (Vector<T>[]) new Vector<?>[spineSize*2];
		int i=0,nextSize=spineSize*2;
		fullBucketThreshold*=2;
		for(;i<spineSize;i++) {
			
			aux[i]=(Vector<T>) entries[i].copy();
			entries[i].destroy();
			entries[i]=null;
		}
		for(;i<nextSize;i++) {

			aux[i]=new Vector<>(); 
			
		}
		spineSize=nextSize;
		entries=aux;		
	}
	private boolean isFull() {
		
		return countFullLists()>fullBucketThreshold;
		
		
	}
	@Override
	public void add(T elem) {
		if(isFull()) {
			grow();
		}
		if(exists(elem)) {
			return;
		}
		int pos= Math.abs(elem.hashCode() % spineSize);

		Vector<T> l=((Vector<T>) entries[pos]);
		l.add(elem);
		
	}

	@Override
	public int size() {

		int result=0;
		for(int i=0;i<spineSize;i++) {
			
			Vector<T> cur= ((Vector<T>) entries[i]);
			
			result+=cur.size();
			
		}
		return result;
	}
	
	private int countFullLists() {
		Vector<T>[] entrs= (Vector<T>[]) entries;
		int result=0;
		for(int i=0;i<spineSize;i++) {
			
			if(entrs[i].size()>VectorSizeForCollision) {
				result++;
			}
		}
		return result;
		
		
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

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new VectorHashSetIterator<>(this);
	}

	@Override
	public void destroy() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			((Vector<T>) entries[i]).destroy();
			entries[i]=null;
		}
		}
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}


	private boolean exists(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			Vector<T> list= ((Vector<T>) entries[pos]);
			
			if(list.isEmpty()) {
				list=null;
				return false;
			}
			Iterator<T> it = list.iterator();
				while(it.hasNext()) {
					if(it.next().compareTo(elem)==0) {
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

}
