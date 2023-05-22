package playGround.ds;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.List;
import playGround.adt.collections.Set;

public class LinkedHashSet<T extends Comparable<T>> implements Set<T> {

	private static class LinkedHashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{
		
		private int mainPos,size;
		private TwoWayIterator<T> current;
		private LinkedHashSet<T> set;
		private T next;
		public LinkedHashSetIterator(LinkedHashSet<T> set) {
			
			init(set);
			
		}
		private void init(LinkedHashSet<T> set) {
			
			size=set.spineSize;
			rewind();
			this.set=set;
			
			
		}
		@Override
		public T next() {
			if(!current.hasNext()) {
				advanceIterator();
				
			}
			return current.next();
		}

		private void advanceIterator() {
			DoubleLinkedList<T>[] spineFromSet=((DoubleLinkedList<T>[])set.entries);
			current=spineFromSet[mainPos++].twoWayIterator();
			spineFromSet=null;
			
		}
		@Override
		public boolean hasNext() {
			DoubleLinkedList<T>[] spineFromSet=((DoubleLinkedList<T>[])set.entries);
			boolean hasNext= next!=spineFromSet[size].get(set.maxEntryLen()-1);
			spineFromSet=null;
			return hasNext;
			
		}

		@Override
		public void rewind() {
			mainPos=0;
			DoubleLinkedList<T> currList=((DoubleLinkedList<T>)set.entries[mainPos]);
			current=currList.twoWayIterator();
			next=currList.get(0);
			currList=null;
		}

		@Override
		public void close() {
			// TODO Auto-generated method stub
			
		}

		private void backstepIterator() {
			DoubleLinkedList<T>[] spineFromSet=((DoubleLinkedList<T>[])set.entries);
			current=spineFromSet[mainPos--].twoWayIterator();
			spineFromSet=null;
			
		}
		@Override
		public T prev() {
			if(!current.hasPrev()) {
				backstepIterator();
				
			}
			return current.prev();
		}

		@Override
		public void fullForward() {
			mainPos=size-1;
			DoubleLinkedList<T> currList=((DoubleLinkedList<T>)set.entries[mainPos]);
			current=currList.twoWayIterator();
			next=currList.get(set.maxEntryLen()-1);
			currList=null;
		}

		@Override
		public boolean hasPrev() {

			DoubleLinkedList<T>[] spineFromSet=((DoubleLinkedList<T>[])set.entries);
			boolean hasPrev= next!=spineFromSet[0].get(0);
			spineFromSet=null;
			return hasPrev;
		}
		
		
		
	}
	private DoubleLinkedList<?>[] entries;
	private static final int START_SIZE =10;
	private int threshold,spineSize;
	public LinkedHashSet() {
		threshold=3;
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
		for(;i<spineSize;i++) {
			((DoubleLinkedList<T>) entries[i]).destroy();
			entries[i]=null;
		}
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
		int pos= Math.abs(elem.hashCode() % spineSize);
		System.out.println(pos);
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
	public TwoWayIterator<T> twoWayIterator() {

		return (TwoWayIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public Iterator<T> iterator() {
		return (Iterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new LinkedHashSetIterator<>(this);
	}

	@Override
	public void destroy() {
		for(int i=0;i<spineSize;i++) {
			((DoubleLinkedList<T>) entries[i]).destroy();
			entries[i]=null;
		}
	}
	
	public String toString() {
		

		if(isEmpty()) {
			
			return "[ ]";
		}
		DoubleLinkedList<T>[] itArr= (DoubleLinkedList<T>[]) entries;	
		String str="";
		for(int i=0;i<spineSize;i++) {
			
			str+=itArr[i].toString()+ "\n";
		
		}
		return str;
		
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
				System.out.println("Empty!!!!");
				return false;
			}
			Iterator<T> it= list.iterator();
			
			while(it.hasNext()) {
				if(elem.equals(it.next())) {
					return true;
				}
			}
			it.close();
			return false;
	}

}
