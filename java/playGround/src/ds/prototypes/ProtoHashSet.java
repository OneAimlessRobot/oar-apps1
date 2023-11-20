package ds.prototypes;

import ds.implem.AbstractCollection;
import ds.implem.AbstractSet;
import ds.implem.DoubleLinkedList;
import ds.implem.TreeSet;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.MySet;
import ds.interfaces.MySortedSet;
import ds.interfaces.TwoWayIterator;

public class ProtoHashSet<T extends Comparable<T>> extends AbstractSet<T> implements MySet<T>,MySortedSet<T> {

	private static final long serialVersionUID = 1L;
	private static class HashSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{
		
		private int mainPos,first,last;
		private TwoWayIterator<T> current;
		private AbstractCollection<T>[] entries;
		public HashSetIterator(ProtoHashSet<T> set){
			
			this.entries=(AbstractCollection<T>[]) set.entries;
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
	private AbstractCollection<?>[] entries;
	private static final double LOAD_FACTOR=0.1;//(filas/numeroElems)
	private static final int INIT_SPINE_SIZE =16;
	private static final int GROW_FACTOR=2;
	private static final int MINIMAL_SIZE_FOR_TREES=64;
	private int numOfStoredElems,spineSize;
	public ProtoHashSet() {
		spineSize=INIT_SPINE_SIZE;
		numOfStoredElems=0;
		init();
		
		
		
	}
	private ProtoHashSet(int size,int numOfInserted) {

		spineSize=size;
		numOfStoredElems=numOfInserted;
		init();
		
		
		
	}
	private void init() {
		
		entries=(AbstractCollection<T>[])new AbstractCollection<?>[spineSize];

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
		addNoChecks(elem);
		numOfStoredElems++;

		if(isFull()) {
			reHash();
		}
		
	}
	private void addNoChecks(T elem) {
		int pos= computeElemPos(elem,spineSize);
		Collection<T> collection=((Collection<T>)entries[pos]);
		collection.add(elem);
		if(collection.size()==8&&numOfStoredElems>MINIMAL_SIZE_FOR_TREES) {
			treefy(pos);
		}
		
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
	public boolean contains(T elem) {

			int pos= Math.abs(elem.hashCode() % spineSize);
			Collection<T> col= ((Collection<T>)entries[pos]);
			if(col.isEmpty()) {
				col=null;
				return false;
			}
			boolean contains=col.contains(elem);			

			return contains;
	}

	@Override
	public Collection<T> copy() {
		Collection<T> collection= new ProtoHashSet<>();
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
	    ProtoHashSet<T> newSet= new ProtoHashSet<>(spineSize,numOfStoredElems);
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
	
	public void treefy(int pos) {
		
		if(entries[pos] instanceof DoubleLinkedList) {
			
			MySet<T> set= new TreeSet<>();
			Iterator<T> it= ((AbstractCollection<T>)entries[pos]).iterator();
			while(it.hasNext()) {
				set.add(it.next());
			}
			(entries[pos])=(AbstractCollection<T>)set;
			
			
			
		}
		
		
	}




}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////private void reHash() {
////int oldSize=spineSize;
////spineSize *= GROW_FACTOR;
////HashSet<T> set= new HashSet<>(spineSize,numOfStoredElems);
////for(int i=0;i<oldSize;i++) {
////	DoubleLinkedList<T> list=((DoubleLinkedList<T>)entries[i]);
////	if(!list.isEmpty()) {
////    	int pos=computeElemPos(list.get(0));
////    	if(set.entries[pos].isEmpty()) {
////	((DoubleLinkedList<T>)set.entries[pos]).append(list);
////    	}
////	}
////}
////
////
////entries = set.entries;
////set.entries=null;
////set=null;
////}
////private boolean checkExistenceOfList(DoubleLinkedList<T> list) {
////
////for(int i=0;i<spineSize;i++) {
////	
////	if(entries[i]==list) {
////		return true;
////	}
////}
////return false;
////
////}
////private void reHash() {
////int oldSize = spineSize;
////spineSize *= GROW_FACTOR;
////MyHashSet<T> set = new MyHashSet<>(spineSize, numOfStoredElems);
////
////for (int i = 0; i < oldSize; i++) {
////    DoubleLinkedList<T> list = (DoubleLinkedList<T>) entries[i];
////    if (!list.isEmpty()) {
////        int pos = this.computeElemPos(list.get(0),spineSize);
////        
////        if(set.entries[pos]!=list) {
////        	((DoubleLinkedList<T>)set.entries[pos]).append((DoubleLinkedList<T>)list.copy());
////        }
////        
////    }
////}
////
////entries = set.entries;
////set.entries = null;
////set = null;
////}
////public boolean intersects(MySet<T> collection) {
////// TODO Auto-generated method stub
////return false;
////}	public String toString() {
////
////if(isEmpty()) {
////
////
////return "[ ]";
////}
////String str="[ ";
////for(int i=0;i<spineSize;i++) {
////
////DoubleLinkedList<T> list= (DoubleLinkedList<T>) entries[i];
////str+=list.toString()+"\n";
////
////}
////str+=" ]";
////return str;
////
////
////}
////private boolean isEmptyAux(int index) {
////
////if(index==spineSize-1) {
////if(((DoubleLinkedList<T>)entries[index]).isEmpty()) {
////	return true;
////}
////}
////return ((DoubleLinkedList<T>)entries[index]).isEmpty() && isEmptyAux(index+1);
////
////
////}
////@Override
////public int size() {
////
////	int result=0;
////	for(int i=0;i<spineSize;i++) {
////		
////		DoubleLinkedList<T> cur= ((DoubleLinkedList<T>) entries[i]);
////		
////		result+=cur.size();
////		
////	}
////	return result;
////}

























//
//
//import playGround.abstractClasses.AbstractCollection;
//import playGround.adt.Collection;
//import playGround.adt.InvIterator;
//import playGround.adt.Iterator;
//import playGround.ds.*;
//import playGround.adt.TwoWayIterator;
//import playGround.adt.collections.MySet;
//
//public class ProtoHashSet<T> extends AbstractCollection<T> implements MySet<T> {
//
//	private static class HashSetIterator<T> implements TwoWayIterator<T>{
//		
//		private int mainPos,first,last;
//		private TwoWayIterator<T> current;
//		private DoubleLinkedList<T>[] entries;
//		public HashSetIterator(ProtoHashSet<T> set){
//			
//			this.entries=(DoubleLinkedList<T>[]) set.entries;
//			fullForward();
//			last=mainPos;
//			rewind();
//			first=mainPos;
//		}
//		@Override
//		public T next() {
//			if(!current.hasNext()) {
//				skipOneListForward();
//				skipEmptyListsForward();
//				
//			}
//			
//			return current.next();
//		}
//		@Override
//		public boolean hasNext() {
//			if(current.hasNext()) {
//				return true;
//			}
//			else if(mainPos<last) {
//				
//				return true;
//			}
//			return false;
//			
//		}
//
//		@Override
//		public void rewind() {
//			mainPos=0;
//			skipEmptyListsForward();
//		}
//		
//		private void skipEmptyListsForward() {
//			while(entries[mainPos].isEmpty()) {mainPos++;}
//			if(current!=null) {
//				current.close();
//			}
//					this.current =entries[mainPos].twoWayIterator();
//					
//		}
//		private void skipEmptyListsBackwards() {
//			while(entries[mainPos].isEmpty()) {mainPos--;}
//			if(current!=null) {
//				current.close();
//			}
//						this.current=entries[mainPos].twoWayIterator();
//					
//					
//		}
//		private void skipOneListForward() {
//			if(current!=null) {
//				current.close();
//			}
//
//			mainPos++;	
//		}
//
//		private void skipOneListBackwards() {
//			if(current!=null) {
//				current.close();
//			}
//
//			mainPos--;
//		}
//		@Override
//		public void close() {
//
//			if(current!=null) {
//				current.close();
//			}
//			entries=null;
//			
//		}
//
//		@Override
//		public T prev() {
//			if(!current.hasPrev()) {
//				skipOneListBackwards();
//				skipEmptyListsBackwards();
//				current.fullForward();
//				
//				
//			}
//			
//			return current.prev();
//		}
//
//		@Override
//		public void fullForward() {
//			mainPos=entries.length-1;
//			skipEmptyListsBackwards();
//			current.fullForward();
//		}
//
//		@Override
//		public boolean hasPrev() {
//			if(current.hasPrev()) {
//				return true;
//			}
//			else if(mainPos>first) {
//				
//				return true;
//			}
//			return false;
//		}
//		
//		
//		
//	}
//	private DoubleLinkedList<?>[] entries;
//	private static final double LOAD_FACTOR=0.1;//(filas/numeroElems)
//	private static final int INIT_SPINE_SIZE =16;
//	private static final int GROW_FACTOR=2;
//	private int numOfStoredElems,spineSize;
//	public ProtoHashSet() {
//		spineSize=INIT_SPINE_SIZE;
//		numOfStoredElems=0;
//		init();
//		
//		
//		
//	}
//	private ProtoHashSet(int size,int numOfInserted) {
//
//		spineSize=size;
//		numOfStoredElems=numOfInserted;
//		init();
//		
//		
//		
//	}
//	private void init() {
//		
//		entries=(DoubleLinkedList<T>[])new DoubleLinkedList<?>[spineSize];
//
//		for(int i=0;i<spineSize;i++) {
//			
//			entries[i]= new DoubleLinkedList<>();
//		}
//		
//		
//	}
//	private boolean isFull() {
//		
//		return getLoadFactor()<LOAD_FACTOR;
//		
//		
//	}
//	@Override
//	public void add(T elem) {
//		if(contains(elem)) {
//			return;
//		}
//		int pos= computeElemPos(elem,spineSize);
//		((DoubleLinkedList<T>) entries[pos]).add(elem);
//		numOfStoredElems++;
//
//		if(isFull()) {
//			reHash();
//		}
//		
//	}
//	private void addNoChecks(T elem) {
//		int pos= computeElemPos(elem,spineSize);
//		((DoubleLinkedList<T>) entries[pos]).add(elem);
//		
//	}
//	private int computeElemPos(T elem,int size) {
//
//		return Math.abs(elem.hashCode() % size);
//	}
//
//	@Override
//	public boolean isEmpty() {
//		
//		return numOfStoredElems==0;
//	}
//
//	@Override
//	public TwoWayIterator<T> twoWayIterator(){
//
//		return (TwoWayIterator<T>) new HashSetIterator<>(this);
//	}
//
//	@Override
//	public Iterator<T> iterator()  {
//		return (Iterator<T>) new HashSetIterator<>(this);
//	}
//
//	@Override
//	public InvIterator<T> backwardIterator() {
//		return (InvIterator<T>) new HashSetIterator<>(this);
//	}
//
//	@Override
//	public void destroy() {
//		if(!isEmpty()) {
//		for(int i=0;i<spineSize;i++) {
//			((DoubleLinkedList<T>) entries[i]).destroy();
//			entries[i]=null;
//		}
//		entries=null;
//		}
//	}
//
//	@Override
//	public int size() {
//		
//		return numOfStoredElems;
//	}
//	@Override
//	public void remove() {
//		// TODO Auto-generated method stub
//		
//	}
//	@Override
//	public boolean contains(T elem) {
//
//			int pos= Math.abs(elem.hashCode() % spineSize);
//			DoubleLinkedList<T> col= ((DoubleLinkedList<T>)entries[pos]);
//			if(col.isEmpty()) {
//				col=null;
//				return false;
//			}
//			boolean contains=col.contains(elem);			
//
//			return contains;
//	}
////
////
////	@Override
////	public boolean contains(T elem) {
////
////			int pos= Math.abs(elem.hashCode() % spineSize);
////			DoubleLinkedList<T> list= ((DoubleLinkedList<T>) entries[pos]);
////			if(list.isEmpty()) {
////				list=null;
////				return false;
////			}
////			Iterator<T> it = list.iterator();
////				while(it.hasNext()) {
////					if(it.next().equals(elem)) {
////						it.close();
////						list=null;
////						return true;
////					}
////				}
////				it.close();
////			
////			
////			return false;
////	}
//
//	@Override
//	public Collection<T> copy() {
//		Collection<T> collection= new MyHashSet<>();
//		if(isEmpty()) {
//			return collection;
//		}
//		Iterator<T> it= iterator();
//		while(it.hasNext()) {
//			
//			collection.add(it.next());
//		}
//		return collection;
//		
//	}
//	private double getLoadFactor() {
//		
//		return (double)spineSize/(double)numOfStoredElems;
//	}
//
//	private void reHash() {
//	    spineSize *= GROW_FACTOR;
//	    ProtoHashSet<T> newSet= new ProtoHashSet<>(spineSize,numOfStoredElems);
//	    Iterator<T> it= iterator();
//	    while(it.hasNext()) {
//	    	newSet.addNoChecks(it.next());
//	    }
//
//	    entries = newSet.entries;
//	    newSet.entries=null;
//	    newSet=null;
//	}
//	@Override
//	public void remove(T elem) {
//		if(contains(elem)) {
//			
//			int pos=computeElemPos(elem,spineSize);
//			DoubleLinkedList<T> list=(DoubleLinkedList<T>) this.entries[pos];
//			list.remove(list.getIndex(elem));
//			list=null;
//			numOfStoredElems--;
//		}
//		
//	}
//
//
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////private void reHash() {
////int oldSize=spineSize;
////spineSize *= GROW_FACTOR;
////HashSet<T> set= new HashSet<>(spineSize,numOfStoredElems);
////for(int i=0;i<oldSize;i++) {
////	DoubleLinkedList<T> list=((DoubleLinkedList<T>)entries[i]);
////	if(!list.isEmpty()) {
////    	int pos=computeElemPos(list.get(0));
////    	if(set.entries[pos].isEmpty()) {
////	((DoubleLinkedList<T>)set.entries[pos]).append(list);
////    	}
////	}
////}
////
////
////entries = set.entries;
////set.entries=null;
////set=null;
////}
////private boolean checkExistenceOfList(DoubleLinkedList<T> list) {
////
////for(int i=0;i<spineSize;i++) {
////	
////	if(entries[i]==list) {
////		return true;
////	}
////}
////return false;
////
////}
////private void reHash() {
////int oldSize = spineSize;
////spineSize *= GROW_FACTOR;
////MyHashSet<T> set = new MyHashSet<>(spineSize, numOfStoredElems);
////
////for (int i = 0; i < oldSize; i++) {
////    DoubleLinkedList<T> list = (DoubleLinkedList<T>) entries[i];
////    if (!list.isEmpty()) {
////        int pos = this.computeElemPos(list.get(0),spineSize);
////        
////        if(set.entries[pos]!=list) {
////        	((DoubleLinkedList<T>)set.entries[pos]).append((DoubleLinkedList<T>)list.copy());
////        }
////        
////    }
////}
////
////entries = set.entries;
////set.entries = null;
////set = null;
////}
////public boolean intersects(MySet<T> collection) {
////// TODO Auto-generated method stub
////return false;
////}	public String toString() {
////
////if(isEmpty()) {
////
////
////return "[ ]";
////}
////String str="[ ";
////for(int i=0;i<spineSize;i++) {
////
////DoubleLinkedList<T> list= (DoubleLinkedList<T>) entries[i];
////str+=list.toString()+"\n";
////
////}
////str+=" ]";
////return str;
////
////
////}
////private boolean isEmptyAux(int index) {
////
////if(index==spineSize-1) {
////if(((DoubleLinkedList<T>)entries[index]).isEmpty()) {
////	return true;
////}
////}
////return ((DoubleLinkedList<T>)entries[index]).isEmpty() && isEmptyAux(index+1);
////
////
////}
////@Override
////public int size() {
////
////	int result=0;
////	for(int i=0;i<spineSize;i++) {
////		
////		DoubleLinkedList<T> cur= ((DoubleLinkedList<T>) entries[i]);
////		
////		result+=cur.size();
////		
////	}
////	return result;
////}
//
//
//
//
//
