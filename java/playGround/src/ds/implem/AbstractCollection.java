package ds.implem;

import java.io.Serializable;

import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.TwoWayIterator;


public abstract class AbstractCollection<T> implements Collection<T>,Serializable{

	private static final long serialVersionUID = 1L;

	@Override
	abstract public void add(T elem);

	@Override
	abstract public int size();

	@Override
	abstract public boolean isEmpty();

	@Override
	abstract public TwoWayIterator<T> twoWayIterator();


	@Override
	abstract public Iterator<T> iterator();


	public String toString() {

		if(isEmpty()) {
			

			return "[ ]";
		}
		String str="[";
		Iterator<T> it = iterator();
			while(it.hasNext()) {
				str+= " "+it.next().toString()+" ";
			}
			str+="]";
		return str;
		
		
	}
	
	

}
