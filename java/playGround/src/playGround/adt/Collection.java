package playGround.adt;

public interface Collection<T> {
//Stacks in linked lists are way slower than stacks in arrays if the latter ones dont have to grow every fucking second
	void add(T elem);
	
	int size();
	
	boolean isEmpty();
	
	TwoWayIterator<T> twoWayIterator();

	Iterator<T> iterator();
	
	String toString();
	
	void destroy();
	
	void remove();
	
}
