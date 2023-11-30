package ds.interfaces;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;

public interface Bias<T extends Comparable<T>> extends Serializable {
	
	int getBias();
	
	void insert(T elem);
	
	void remove(T elem) throws StackEmptyException;
	
	int size();
	
	Iterator<T> iterator();
	
	boolean isEmpty();
	
	boolean isBalanced();
	
	void balance();

}
