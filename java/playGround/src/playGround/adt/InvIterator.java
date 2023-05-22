package playGround.adt;

public interface InvIterator<T> {

	T prev();
	
	void fullForward();
	
	boolean hasPrev();
	
	void close();
}
