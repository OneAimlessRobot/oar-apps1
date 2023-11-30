package ds.implem;

import java.io.Serializable;

import ds.exceptions.QueueEmptyException;
import ds.interfaces.DEque;
import dsFaculdade.exceptions.FullQueueException;

public class DEqueInCircularArray<T> extends QueueInCircularArray<T> implements DEque<T>, Serializable {

	private static final long serialVersionUID = 1L;


	public DEqueInCircularArray() {
		super();
		
	}
	public DEqueInCircularArray(int capacity) {
		super(capacity);
		
	}
	@Override
	public T dequeueBack() {
		if(isEmpty()) {
			throw new QueueEmptyException();
		}
		size--;
		T result=arr[back];
		arr[back]=null;
		if(back==0) {
			back= arr.length-1;
		}
		else {
		back--;
		}
		return result;
	}
	@Override
	public void enqueueFront(T elem) {
		if(size==capacity) {
			throw new FullQueueException();
		}
		size++;
		arr[front]=elem;
		if(front==0) {
			front= arr.length-1;
		}
		else {
		front--;
		}
		}
	@Override
	public T back() {
		
		return arr[back];
	}

}
