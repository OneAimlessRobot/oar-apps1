package ds.interfaces;

public interface List<T> extends Collection<T> {

	void invert();
	
	T get(int index);
	
	void add(T elem, int index);
	
	void remove(int pos);
	
	int getIndex(T elem);
	
	void update(T elem, int index);
	
	
}
