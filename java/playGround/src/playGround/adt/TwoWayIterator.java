package playGround.adt;

import playGround.adt.exceptions.CollectionEmptyException;

public interface TwoWayIterator<T> extends Iterator<T>{

	void init() throws CollectionEmptyException;
	T prev();
	
	void fullForward();
	
	boolean hasPrev();
}
