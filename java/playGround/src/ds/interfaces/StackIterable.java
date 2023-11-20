package ds.interfaces;

public interface StackIterable<T> extends Stack<T> {
	
	Iterator<T> iterator();

	boolean contains(T elem);
}
