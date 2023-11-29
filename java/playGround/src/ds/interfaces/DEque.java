package ds.interfaces;

public interface DEque<T> extends Queue<T> {
	
	T dequeueBack();
	
	void enqueueFront(T elem);
	
	T back();

}
