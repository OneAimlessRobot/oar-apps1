package dsFaculdade.implem;

import dsFaculdade.exceptions.EmptyQueueException;
import dsFaculdade.interfaces.List;
import dsFaculdade.interfaces.Queue;

/**
 * Queue List Implementation 
 * @author AED  Team
 * @version 1.0
 * @param <E> Generic Element
 * 
 */
public class QueueInList<E> implements Queue<E>
{ 

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
    public QueueInList( )           
    {
        list = new DoubleList<E>();
    }


    @Override
    public boolean isEmpty( ) 
    {
        return list.isEmpty();
    }


    @Override
    public int size( )        
    {
        return list.size();
    }

                                             
    @Override
    public void enqueue( E element )
    {    
        list.addLast(element);
    }


    public String toString() {
    	String str="[";
			QueueInList<E> isAQueue= new QueueInList<>();
			
			while(!isEmpty()) {
				isAQueue.enqueue(dequeue());
				
			}
			while(!isAQueue.isEmpty()) {
				str+=" "+isAQueue.dequeue().toString()+" ";
				
			}
			this.list=isAQueue.list;
			
			str+="]";
    	return str;
    	
    	
    }
    @Override
    public E dequeue( ) throws EmptyQueueException   
    {
        if ( list.isEmpty() )
            throw new EmptyQueueException();

        return list.removeFirst();
    }


}