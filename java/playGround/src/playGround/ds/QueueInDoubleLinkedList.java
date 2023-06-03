package playGround.ds;

import playGround.adt.Queue;
import playGround.adt.exceptions.QueueEmptyException;

public class QueueInDoubleLinkedList<T> implements Queue<T> {
	private T front;
	private DoubleLinkedList<T> struct;
	
	public QueueInDoubleLinkedList() {
		
		
		struct=new DoubleLinkedList<>();
		
	}
	

	public QueueInDoubleLinkedList(T[] arr) {
		
		for(int i=0;i<arr.length;i++) {
			
			this.enqueue(arr[i]);
			
		}
		
		
		
		
		
	}
	
	
	@Override
	public void enqueue(T elem) {
		front =elem;
		struct.add(elem,0);
		
	}

	@Override
	public T dequeue() throws QueueEmptyException {
		
		if(isEmpty()) {
			
			throw new QueueEmptyException();
			
		}
		
		T elem= struct.get(this.size());
		struct.remove(this.size());
		return elem;
	}

	@Override
	public boolean isEmpty() {
		return struct.isEmpty();
	}

	@Override
	public T front() throws QueueEmptyException {
		return front;
	}

	@Override
	public int size() {
		return struct.size();
	}

}
