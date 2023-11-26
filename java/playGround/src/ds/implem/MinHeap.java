package ds.implem;
/**
 * 
 * THIS IS NOT MINE
 * 
 */
import java.io.Serializable;

import ds.interfaces.MinPriorityQueue;
import dsFaculdad.exceptions.EmptyQueueException;
@SuppressWarnings("unchecked")
public class MinHeap<T extends Comparable<T>> implements MinPriorityQueue<T>, Serializable {

	private static final long serialVersionUID = 1L;
	private T[] arr;
	private int currentSize;
	private static final int GROWTH_FACTOR=2;
	public MinHeap(int capacity) {
		
		arr= (T[]) new Object[capacity];
		currentSize=0;
	}
	protected void buildArray( int capacity, T[] contents ){
		// Compiler gives a warning.
		T[] newArray = (T[]) new Object[capacity];
		System.arraycopy(contents, 0, newArray, 0, contents.length);
		arr=newArray;
	}
	protected void percolateDown( int firstPos ){
		T rootEntry = arr[firstPos];
		int hole = firstPos;
		int child = 2 * hole + 1; // Left
	while ( child < currentSize ) {
	// Find the smallest child.
	if ( child < currentSize - 1 && arr[child+1].compareTo(arr[child] ) < 0 )
	child++;
	// Compare the smallest child with rootKey.
	if ( arr[child].compareTo( rootEntry ) < 0 ) {
	arr[hole] = arr[child];
	hole = child;
	child = 2 * hole + 1; // Left child.
	}
	else
	break;
	}
	arr[hole] = rootEntry;
	}

	@Override
	public boolean isEmpty() {
		return currentSize==0;
	}

	

	@Override
	public int size() {
		return currentSize;
	}

	@Override
	public T front( ) throws EmptyQueueException {
		if ( this.isEmpty() )
		throw new EmptyQueueException();
		return arr[0];
	}
		
	public void enqueue( T value ){
		if ( this.isFull() )
		this.buildArray(GROWTH_FACTOR * arr.length, arr);
		// Percolate up.
		int hole = currentSize;
		int parent = (hole - 1) / 2;
		while ( hole > 0 &&
		value.compareTo( arr[parent] ) < 0 ){
		arr[hole] = arr[parent];
		hole = parent;
		parent = (hole - 1) / 2;
		}
		arr[hole] = value;
		currentSize++;
	}
	private boolean isFull() {
		return currentSize==arr.length;
	}
	public T dequeue( ) throws EmptyQueueException{
		if ( this.isEmpty() )
			throw new EmptyQueueException();
			T minEntry = arr[0];
			currentSize--;
			arr[0] = arr[currentSize];
			arr[currentSize] = null; // For garbage collection.
			if ( currentSize > 1 )
			this.percolateDown(0);
			return minEntry;
	}
	public MinHeap( T[] theArray ) {
		// Build a complete tree.
		this.buildArray(theArray.length, theArray);
		currentSize = theArray.length;
		// Build a priority tree.
		this.buildPriorityTree();
		}
		protected void buildPriorityTree( ) {
		for ( int i = (currentSize - 2) / 2; i >= 0; i-- )
		this.percolateDown(i);
		}
}
