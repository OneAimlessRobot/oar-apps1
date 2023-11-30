package ds.implem;

import java.io.Serializable;
import java.util.Arrays;

import ds.exceptions.QueueEmptyException;
import ds.exceptions.StackEmptyException;
import ds.interfaces.DEStack;
import ds.interfaces.Iterator;
import dsFaculdade.exceptions.FullQueueException;
import dsFaculdade.exceptions.FullStackException;

@SuppressWarnings("unchecked")
public class DEStackInCircularArray<T> implements DEStack<T>, Serializable {

	private static final long serialVersionUID = 1L;

	protected T[] arr;
	protected static final int DEFAULT_SIZE=10;
	protected int front,back,size,capacity;
	public DEStackInCircularArray() {

		
		arr= (T[])new Object[DEFAULT_SIZE];
		front=back=size=0;
		capacity=DEFAULT_SIZE;
		
	}
	public DEStackInCircularArray(int capacity) {

		
		arr= (T[])new Object[DEFAULT_SIZE];
		front=back=size=0;
		this.capacity=capacity;
		
	}
	@Override
	public void push(T elem) {
		if(size==capacity) {
			throw new FullStackException();
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
	public T pop() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		size--;
		T result=arr[front];
		arr[front]=null;
		front=(front+1)%arr.length;
		return result;
	}

	@Override
	public T top() throws StackEmptyException {

		
		return arr[front];
	}

	@Override
	public boolean isEmpty() {
		return size==0;
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public void destroy() {
		Arrays.fill(arr, null);
		
	}

	@Override
	public T popBack() throws StackEmptyException {
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
	public T back() throws StackEmptyException {
		return arr[front];
	}

	@Override
	public void pushBack(T elem) {
		if(size==capacity) {
			throw new FullQueueException();
		}
		size++;
		arr[back++]=elem;
		back=(back)%arr.length;
		
	}
	@Override
	public Iterator<T> iterator() {
		return new ArrayIterator<>(arr);
	}
	@Override
	public boolean contains(T elem) {
		for(int i=0;i<arr.length;i++) {
			
			if(arr[i].equals(elem)) {
				return true;
			}
		}
		return false;
	}

}
