package playGround.abstractClasses;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;

public abstract class AbstractCollection<T> implements Collection<T> {

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

	@Override
	abstract public InvIterator<T> backwardIterator();

	@Override
	abstract public void destroy();

	@Override
	abstract public void remove();
	
	public String toString() {

		if(isEmpty()) {
			

			return "[ ]";
		}
		String str="[ ";
		Iterator<T> it = iterator();
			while(it.hasNext()) {
				str+= it.next().toString()+" ";
			}
			str+="]";
			it.close();
		return str;
		
		
	}

}
