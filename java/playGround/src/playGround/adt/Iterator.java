package playGround.adt;

public interface Iterator<T> {
	
	T next();
	
	boolean hasNext();
	
	void rewind();
	
	void close();

}
