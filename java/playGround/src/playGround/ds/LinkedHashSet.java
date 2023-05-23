package playGround.ds;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.List;
import playGround.adt.collections.Set;
import playGround.adt.exceptions.CollectionEmptyException;

public class LinkedHashSet<T extends Comparable<T>> implements Set<T> {

	private static class LinkedHashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{
		
		private int mainPos,size,first,last;
		private TwoWayIterator<T> current;
		private LinkedHashSet<T> set;
		public LinkedHashSetIterator(LinkedHashSet<T> set) throws CollectionEmptyException {
			
			size=set.spineSize;
			this.set=set;
			init();
			rewind();
			first=mainPos;
			fullForward();
			last=mainPos;
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
			
			return current.hasNext()&&mainPos<=last;
			
		}

		@Override
		public void rewind() {
			mainPos=0;
			skipEmptyListsForward();
			current.rewind();
		}
		
		private void skipEmptyListsForward() {
			DoubleLinkedList<T>[] spine=(DoubleLinkedList<T>[])set.entries;
	
					while(spine[mainPos].isEmpty()) {
					try {
					TwoWayIterator<T> it=spine[++mainPos].twoWayIterator();
					current=it;
					} catch (CollectionEmptyException e) {
					
				}
					}
		}
		private void skipOneListForward() {
			
			DoubleLinkedList<T> currList=((DoubleLinkedList<T>)set.entries[++mainPos]);
				
					try {
						current=currList.twoWayIterator();
					} catch (CollectionEmptyException e) {
					}
				}
		private void skipEmptyListsBackwards() {

					while(((DoubleLinkedList<T>[])set.entries)[--mainPos].isEmpty());
					try {
						this.current=((DoubleLinkedList<T>[])set.entries)[mainPos].twoWayIterator();
						int i=0;
						boolean value= i<5;
						i++;
						current=current;
						System.out.println(i);
					} catch (CollectionEmptyException e) {
					}
		}
		@Override
		public void close() {
			// TODO Auto-generated method stub
			
		}

		private void backstepIterator() {
			DoubleLinkedList<T>[] spineFromSet=((DoubleLinkedList<T>[])set.entries);

			try {
				current=spineFromSet[mainPos--].twoWayIterator();
			} catch (CollectionEmptyException e) {
			}
			spineFromSet=null;
			
		}
		@Override
		public T prev() {
			if(!current.hasPrev()) {
				skipEmptyListsBackwards();
				
			}
			
			return current.next();
		}

		@Override
		public void fullForward() {
			mainPos=size-1;
			skipEmptyListsBackwards();
			current.fullForward();
		}

		@Override
		public boolean hasPrev() {


			return current.hasPrev()&&mainPos>=first;
		}
		@Override
		public void init() throws CollectionEmptyException {
			if(set.isEmpty()) {
				throw new CollectionEmptyException();
			}
			
		}
		
		
		
	}
	private DoubleLinkedList<?>[] entries;
	private static final int START_SIZE =10;
	private int threshold,spineSize;
	public LinkedHashSet() {
		threshold=11;
		spineSize=START_SIZE;
		init();
		
		
		
	}
	private void init() {
		
		entries=(DoubleLinkedList<T>[])new DoubleLinkedList<?>[START_SIZE];

		for(int i=0;i<START_SIZE;i++) {
			
			entries[i]= new DoubleLinkedList<>();
		}
		
		
	}
	private void grow() {
		
		DoubleLinkedList<T>[] aux= (DoubleLinkedList<T>[]) new DoubleLinkedList<?>[spineSize*2];
		int i=0,nextSize=spineSize*2;
		
		for(;i<spineSize;i++) {
			
			aux[i]=(DoubleLinkedList<T>) entries[i];
		}
		for(;i<nextSize;i++) {

			aux[i]=new DoubleLinkedList<T>(); 
			
		}
		i=0;
//		for(;i<spineSize;i++) {
//			((DoubleLinkedList<T>) entries[i]).destroy();
//			entries[i]=null;
//		}
		spineSize=nextSize;
		entries=aux;		
	}

	private int maxEntryLen() {
		
		int result=0;
		for(int i=0;i<spineSize;i++) {
			
			DoubleLinkedList<T> cur= ((DoubleLinkedList<T>) entries[i]);
			
			result=cur.size()< result ? result :  cur.size();
			
			
			
		}
		return result;
		
	}
	private boolean isFull() {
		
		return maxEntryLen()>threshold;
		
		
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
		((DoubleLinkedList<T>) entries[pos]).add(elem);
		
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
	public TwoWayIterator<T> twoWayIterator() throws CollectionEmptyException {

		return (TwoWayIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public Iterator<T> iterator() throws CollectionEmptyException {
		return (Iterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public InvIterator<T> backwardIterator() throws CollectionEmptyException {
		return (InvIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public void destroy() {
		if(!isEmpty()) {
		for(int i=0;i<spineSize;i++) {
			((DoubleLinkedList<T>) entries[i]).destroy();
			entries[i]=null;
		}
		}
	}
	
	public String toString() {
		

		try {

			String str="";
			Iterator<T> it= this.iterator();
			while(it.hasNext()) {
				T elem= it.next();
				System.out.println(elem);
				str+=elem.toString() +" ";
			}
			str+="\n";
			return str;
		} catch (CollectionEmptyException e) {
			return "[ ]";
		}
		
//		DoubleLinkedList<T>[] itArr= (DoubleLinkedList<T>[]) entries;
//		for(int i=0;i<spineSize;i++) {
//			
//			System.out.println(itArr[i].size());
//			str+=itArr[i].toString()+ "\n";
//		
//		}
		
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
			Iterator<T> it;
			try {
				it = list.iterator();
				while(it.hasNext()) {
					if(elem.equals(it.next())) {
						it.close();
						list=null;
						return true;
					}
				}
				it.close();
			} catch (CollectionEmptyException e) {
			}
			
			return false;
	}

}
