package playGround.adt;

import playGround.adt.exceptions.QueueEmptyException;

public interface Queue<T> {

	void enqueue(T elem);
	
	T dequeue() throws QueueEmptyException;
	
	boolean isEmpty();
	
	T front() throws QueueEmptyException;
	
	String toString();
	
	int size();
}
