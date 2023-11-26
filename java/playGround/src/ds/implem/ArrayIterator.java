package ds.implem;

import java.io.Serializable;

import ds.interfaces.TwoWayIterator;
@SuppressWarnings("unchecked")
public class ArrayIterator<T> implements TwoWayIterator<T>, Serializable {

	private static final long serialVersionUID = 1L;
	private Object[] support;
	private int currPos;
	public ArrayIterator(T[] support) {
		this.support=support;
		currPos=0;
		
	}
	@Override
	public T next() {
		return (T) support[currPos++];
	}
	@Override
	public boolean hasNext() {
		return this.currPos!=support.length;
	}
	@Override
	public void rewind() {
		this.currPos=0;
	}
	@Override
	public T prev() {
		return (T) support[currPos--];
	}
	@Override
	public void fullForward() {
		currPos=support.length-1;
	}
	@Override
	public boolean hasPrev() {
		return currPos!=-1;
	}
	
	
}
