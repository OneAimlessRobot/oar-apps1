package ds.interfaces;

import ds.exceptions.StackEmptyException;
public interface Stack<T>{
	
	void push(T elem);
	
	T pop() throws StackEmptyException;
	
	T top() throws StackEmptyException;	
	
	boolean isEmpty();
	
	int size();
	
	void destroy();

}
