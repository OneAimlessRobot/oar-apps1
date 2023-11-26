package dsFaculdad.implem;

import dsFaculdad.exceptions.EmptyQueueException;
import dsFaculdad.interfaces.InvertibleQueue;

public class InvertibleQueueInList<E> extends QueueInList<E> implements InvertibleQueue<E>  {

	/**
	 * Serial Version UID of the Class
	 */
    static final long serialVersionUID = 0L;


    /**
     * Memory of the queue: a list.
     */                  
    private boolean inverted;
    /**
     * Constructor create an empty Doubly Linked List.
     */
    public InvertibleQueueInList( )           
    {
        super();
        inverted=false;
    }


	@Override
	public boolean isEmpty() {
		return list.isEmpty();
	}

	@Override
	public int size() {
		return list.size();
	}

	@Override
	public void enqueue(E element) {
		if(!inverted) {
			super.enqueue(element);
		}
		else {
			list.addFirst(element);
			
		}
	}


	@Override
	public E dequeue() throws EmptyQueueException {
		E result;
		if(!inverted) {
			result= super.dequeue();
		}
		else {
			result=list.removeLast();
			
		}
		return result;
	}

	@Override
	public void invert() {
		if(!inverted) {
			inverted=true;
			return;	
		}
		inverted=false;
			

	}

}
