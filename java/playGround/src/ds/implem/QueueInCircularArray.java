package ds.implem;

import java.io.Serializable;

import ds.exceptions.QueueEmptyException;
import ds.interfaces.Queue;
import ds.interfaces.TwoWayIterator;
import dsFaculdad.exceptions.FullQueueException;

public class QueueInCircularArray<T> implements Queue<T>, Serializable {

	private static final long serialVersionUID = 1L;


	protected T[] arr;
	protected static final int DEFAULT_SIZE=10;
	protected int front,back,size,capacity;
	@SuppressWarnings("unchecked")
	public QueueInCircularArray() {
		
		arr= (T[])new Object[DEFAULT_SIZE];
		front=back=size=0;
		capacity=DEFAULT_SIZE;
		
	}
	@SuppressWarnings("unchecked")
	public QueueInCircularArray(int capacity) {
		
		arr= (T[])new Object[capacity];
		front=back=size=0;
		this.capacity=capacity;
		
	}
	public String toString() {
		String result="[ ";
		if(isEmpty()) {
			return "[ ]";
		}
		else {
			TwoWayIterator<T> it= new ArrayIterator<>(arr);
			while(it.hasNext()) {
				T next= it.next();
				if(next==null) {
				result+="  ";
				}
				else {
				result+=next+" ";
				}
				}
			
		}
		result+="]";
		return result;
	}
	@Override
	public void enqueue(T elem) {
		if(size==capacity) {
			throw new FullQueueException();
		}
		size++;
		arr[back++]=elem;
		back=(back)%arr.length;
	}

	@Override
	public T dequeue() throws QueueEmptyException {
		if(isEmpty()) {
			throw new QueueEmptyException();
		}
		size--;
		T result=arr[front];
		arr[front]=null;
		front=(front+1)%arr.length;
		return result;
	}

	@Override
	public boolean isEmpty() {
		return size==0;
	}

	@Override
	public T front() throws QueueEmptyException {
		return arr[front];
	}

	@Override
	public int size() {
		return size;
	}

}
