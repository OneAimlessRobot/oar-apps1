package ds.implem;

import java.io.Serializable;

import ds.interfaces.List;


public abstract class AbstractList<T> extends AbstractCollection<T> implements List<T>,Serializable{

	private static final long serialVersionUID = 1L;

	public void remove(T elem) {
		
		this.remove(this.getIndex(elem));
	}
}
