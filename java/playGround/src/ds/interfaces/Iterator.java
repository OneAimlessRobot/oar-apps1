package ds.interfaces;

public interface Iterator<T> {
	
	T next();
	
	boolean hasNext();
	
	void rewind();

}
