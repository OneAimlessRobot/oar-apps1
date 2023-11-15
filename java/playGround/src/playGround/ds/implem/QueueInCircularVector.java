package playGround.ds.implem;

import playGround.ds.exceptions.QueueEmptyException;
import playGround.ds.interfaces.Queue;

public class QueueInCircularVector<T> implements Queue<T> {

	private T[] struct;
	private T front;
	private int currPos,size;
	private static final int DEFAULT_SIZE=100;
	public QueueInCircularVector() {
		
		struct= (T[]) new Object[DEFAULT_SIZE];
		
	}
	public QueueInCircularVector(T[] arr) {
		
		struct= (T[]) new Object[arr.length];
		
		for(int i=0;i<arr.length;i++) {
			
			struct[i]=arr[i];
			
		}
		
		
		
	}
	@Override
	public void enqueue(T elem) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public T dequeue() throws QueueEmptyException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public T front() throws QueueEmptyException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int size() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	

}
