package ds.implem;

import java.io.Serializable;

import ds.interfaces.Comparator;
import ds.interfaces.List;
public class MinHeapComparable<T extends Comparable<T>> extends MinHeap<T> implements Serializable{

	private static final long serialVersionUID = 1L;
	private Comparator<T> comparator;
	public MinHeapComparable(int capacity,Comparator<T> comp) {
		super(capacity);
		comparator=comp;
	}

		public void enqueue( T value ){
			if ( this.isFull() )
			this.buildArray(GROWTH_FACTOR * arr.length, arr);
			// Percolate up.
			int hole = currentSize;
			int parent = (hole - 1) / 2;
			while ( hole > 0 &&
			comparator.compare( value,arr[parent] ) < 0 ){
			arr[hole] = arr[parent];
			hole = parent;
			parent = (hole - 1) / 2;
			}
			arr[hole] = value;
			currentSize++;
		}
		protected void percolateDown( int firstPos ){
			T rootEntry = arr[firstPos];
			int hole = firstPos;
			int child = 2 * hole + 1; // Left
		while ( child < currentSize ) {
		// Find the smallest child.
		if ( child < currentSize - 1 && comparator.compare(arr[child+1],arr[child] ) < 0 )
		child++;
		// Compare the smallest child with rootKey.
		if ( comparator.compare(arr[child], rootEntry ) < 0 ) {
		arr[hole] = arr[child];
		hole = child;
		child = 2 * hole + 1; // Left child.
		}
		else
		break;
		}
		arr[hole] = rootEntry;
		}
		public MinHeapComparable( T[] theArray,Comparator<T> comp ) {
			// Build a complete tree.
			comparator=comp;
			this.buildArray(theArray.length, theArray);
			currentSize = theArray.length;
			// Build a priority tree.
			this.buildPriorityTree();
			}
			public MinHeapComparable( List<T> theArray,Comparator<T> comp ) {
				// Build a complete tree.
				comparator=comp;
				this.buildArrayFromList(theArray);
				currentSize = theArray.size();
				// Build a priority tree.
				this.buildPriorityTree();
				}




				
}
