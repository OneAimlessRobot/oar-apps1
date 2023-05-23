package playGround.adt;

import playGround.adt.exceptions.CollectionEmptyException;

public interface Collection<T> {
//Stacks in linked lists are way slower than stacks in arrays if the latter ones dont have to grow every fucking second
	void add(T elem);
	
	int size();
	
	boolean isEmpty();
	
	TwoWayIterator<T> twoWayIterator() throws CollectionEmptyException;

	Iterator<T> iterator() throws CollectionEmptyException;
	
	InvIterator<T> backwardIterator() throws CollectionEmptyException;
	
	String toString();
	
	void destroy();
	
	void remove();
	
}
