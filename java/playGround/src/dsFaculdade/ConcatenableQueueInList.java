package dsFaculdade;

public class ConcatenableQueueInList<E> implements ConcatenableQueue<E> {

	/**
	 * Serial Version UID of the Class
	 */
    static final long serialVersionUID = 0L;


    /**
     * Memory of the queue: a list.
     */
    protected List<E> list;                     

    /**
     * Constructor create an empty Doubly Linked List.
     */
    public ConcatenableQueueInList( )           
    {
        list = new DoubleList<E>();
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
		list.add(0, element);

	}

	@Override
	public E dequeue() throws EmptyQueueException {
		
		return list.remove(list.size());
	}

	@Override
	public void append(ConcatenableQueue<E> addition) {
		
		if(!(addition instanceof ConcatenableQueueInList)) {
		while(!addition.isEmpty()) {
			
			this.enqueue(addition.dequeue());
			
		}
		}
		else {
			
			this.list.append(((ConcatenableQueueInList<E>)addition).list);
			
		}

	}

}
