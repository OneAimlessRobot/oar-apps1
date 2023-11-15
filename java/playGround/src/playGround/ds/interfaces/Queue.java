package playGround.ds.interfaces;

import playGround.ds.exceptions.QueueEmptyException;

public interface Queue<T> {

	void enqueue(T elem);
	
	T dequeue() throws QueueEmptyException;
	
	boolean isEmpty();
	
	T front() throws QueueEmptyException;
	
	String toString();
	
	int size();
}
