package playGround.adt.abstractClasses;
import playGround.adt.collections.List;

public abstract class AbstractList<T> extends AbstractCollection<T> implements List<T>{

	public void remove(T elem) {
		
		this.remove(this.getIndex(elem));
	}
}
