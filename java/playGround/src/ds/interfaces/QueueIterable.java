package ds.interfaces;

public interface QueueIterable<T> extends Queue<T> {

	
	Iterator<T> iterator();
	boolean contains(T elem);
}
