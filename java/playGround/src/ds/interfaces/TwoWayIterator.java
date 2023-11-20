package ds.interfaces;

//import playGround.adt.exceptions.CollectionEmptyException;

public interface TwoWayIterator<T> extends Iterator<T>{

	T prev();
	
	void fullForward();
	
	boolean hasPrev();
}
