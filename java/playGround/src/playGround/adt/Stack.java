package playGround.adt;

import playGround.adt.exceptions.*;
public interface Stack<T>{
	
	void push(T elem);
	
	T pop() throws StackEmptyException;
	
	T top() throws StackEmptyException;	
	
	boolean isEmpty();
	
	String toString();
	
	int size();
	
	void destroy();
}
