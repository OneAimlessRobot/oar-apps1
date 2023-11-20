package ds.interfaces;

import ds.exceptions.QueueEmptyException;

public interface DEQueue<T> extends Queue<T>{
	
	T back() throws QueueEmptyException;
	
	T dequeueBack() throws QueueEmptyException;
	
	void enqueueBack(T elem);
	
	

}
