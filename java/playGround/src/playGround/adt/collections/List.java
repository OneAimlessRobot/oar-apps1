package playGround.adt.collections;

import playGround.adt.Collection;

public interface List<T> extends Collection<T> {

	void invert();
	
	T get(int index);
	
	void add(T elem, int index);
	
	void remove(int pos);
}
