package playGround.adt;

public interface TwoWayIterator<T> extends Iterator<T>{

	T prev();
	
	void fullForward();
	
	boolean hasPrev();
}
