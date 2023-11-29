package ds.implem;
import ds.exceptions.StackEmptyException;
import ds.interfaces.Bias;

public class BiasInDoubleList<T> extends StackInDoubleLinkedList<T> implements Bias<T>{


	private static final long serialVersionUID = 1L;

	public BiasInDoubleList() {
		
		super();
	}
	@Override
	public T popBack() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		T elem= support.get(support.size()-1);
		support.remove(support.size()-1);
		
		return elem;
	}

	@Override
	public T back() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		T elem= support.get(support.size()-1);
		return elem;
	}

	@Override
	public void pushBack(T elem) {

		support.add(elem,support.size()-1);
	}




}
