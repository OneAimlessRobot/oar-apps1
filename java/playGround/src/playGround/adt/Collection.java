package playGround.adt;

public interface Collection<T> {

	void add(T elem);
	
	int size();
	
	boolean isEmpty();
	
	TwoWayIterator<T> twoWayIterator();

	Iterator<T> iterator();
	
	String toString();
	
	void destroy();
	
}
