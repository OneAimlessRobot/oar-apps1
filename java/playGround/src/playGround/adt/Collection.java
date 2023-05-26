package playGround.adt;

import playGround.adt.exceptions.CollectionEmptyException;

public interface Collection<T> {
//Stacks in linked lists are way slower than stacks in arrays if the latter ones dont have to grow every fucking second
	void add(T elem);
	
	int size();
	
	Collection<T> copy();
	
	boolean isEmpty();
	
	TwoWayIterator<T> twoWayIterator();

	Iterator<T> iterator();
	
	InvIterator<T> backwardIterator();
	
	String toString();
	
	void destroy();
	
	void remove();
	
	boolean contains(T elem);
	
}
