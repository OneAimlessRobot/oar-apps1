package dsFaculdad;
;

/**
 * Doubly linked list Implementation 
 * @author AED  Team
 * @version 1.0
 * @param <K, V> Generics - K extends Comparable
 * 
 */
public class OrderedDoubleList<K extends Comparable<K>, V> 
	implements OrderedDictionary<K , V> {

    /**
	 * Serial Version UID of the Class
	 */
    static final long serialVersionUID = 0L;
    
	/**
     *  Node at the head of the list.
     */
	protected DoubleListNode<Entry<K,V>> head;

    /**
     * Node at the tail of the list.
     */
	protected DoubleListNode<Entry<K,V>> tail;

    /**
     * Number of elements in the list.
     */
	protected int currentSize;
	
    /**
     * Constructor of an empty ordered double linked list.
     * head and tail are initialized as null.
     * currentSize is initialized as 0.
     */
	public OrderedDoubleList() {
		head=null;
		tail=null;
		currentSize=0;
	}

    /**
     * Inserts the Entry element before node after.
     * Precondition: after is not the head of the ordered double list.
     * @param element - Entry to be inserted
     * @param after - Node to be next to the new node  
     */
	protected void addBeforeNode(Entry<K,V> element, DoubleListNode<Entry<K,V>> after){
		DoubleListNode<Entry<K,V>> prevNode = after.getPrevious();
        DoubleListNode<Entry<K,V>> newNode = new DoubleListNode<Entry<K,V>>(element, prevNode, after);
        prevNode.setNext(newNode);
        after.setPrevious(newNode);
	  	currentSize++;
	}
	
    /**
     * Inserts the Entry element at the first position in the list.
     * @param element - Entry to be inserted
     */
    protected void addFirst( Entry<K,V> element )
    {
        DoubleListNode<Entry<K,V>> newNode = new DoubleListNode<Entry<K,V>>(element, null, head);
        if ( this.isEmpty() )
            tail=head = newNode;
        else
            head.setPrevious(newNode);
        head = newNode;

	  	currentSize++;
    }


    /**
     * Inserts the Entry element at the last position in the list.
     * @param element - Entry to be inserted
     */
    protected void addLast( Entry<K,V> element )
    {
    	DoubleListNode<Entry<K,V>> newNode = new DoubleListNode<>(element, tail, null);
        if ( this.isEmpty() )
            tail=head = newNode;
        else
            tail.setNext(newNode);
        tail = newNode;
	  	currentSize++;
    }

	@Override
    public Entry<K, V> maxEntry() throws EmptyDictionaryException {
		return tail.getElement();
	}

    @Override
	public Entry<K, V> minEntry() throws EmptyDictionaryException {
    	return head.getElement();
	}

    /**
     * Returns the node with the Entry with Key key
     * in the list, if the list contains this entry.
     * Otherwise, returns null.
     * @param key - Key of type K to be searched
     * @return DoubleListNode<E> where the Entry with key was found, or the one with the key immmediately after 
     */
	protected DoubleListNode<Entry<K,V>> findNode (K key){
		DoubleListNode<Entry<K,V>> node = head;
		while(node!=null && key.compareTo(node.getElement().getKey())>0) {
			

				node=node.getNext();
		}
		return node;
	}
	
    @Override
	public V find(K key) {
		DoubleListNode<Entry<K,V>> node = findNode(key);
		if(node==null || key.compareTo(node.getElement().getKey())<0) {
			
			return null;
		}
		return node.getElement().getValue();
	}


	@Override
	public V insert(K key, V value) {
		 Entry<K,V> newNode=new EntryClass<K,V> (key, value);
		DoubleListNode<Entry<K,V>> node = findNode(key);
		if ((node!=null) &&(key.compareTo(node.getElement().getKey())==0)){
			V oldValue= node.getElement().getValue();	
			node.setElement(newNode);
			  return oldValue;
		}
		else { 
			if (node==head){
		  	addFirst(newNode);
			}
			else if(node==null) {
			  	addLast(newNode);
				
				
			}
			else {
				addBeforeNode(newNode,node);
			}

		}
		  return null;
	}
	
	@Override
    public boolean isEmpty() {
	
		return currentSize==0;
	}

    @Override
	public TwoWayIteratorEntries<K, V> iterator() {
		return new DoubleListIteratorEntries<K,V>(head,tail);
	}

    /**
     * Removes the first node in the list.
     * Pre-condition: the list is not empty.
     */
    protected void removeFirstNode( )
    {
        head = head.getNext();
        if ( head == null )
            tail = null;
        else
            head.setPrevious(null);
        currentSize--;
    }


    /**
     * Removes and returns the value at the first entry in the list.
     */
    protected V removeFirst( ) throws EmptyDictionaryException
    {
    	if ( this.isEmpty() )
            throw new EmptyDictionaryException();

        V value = head.getElement().getValue();
        this.removeFirstNode();
        return value;
    }


    /**
     * Removes the last node in the list.
     * Pre-condition: the list is not empty.
     */
    protected void removeLastNode( )
    {
    	tail = tail.getPrevious();
        if ( tail == null )
            head = null;
        else
            tail.setNext(null);
        currentSize--;
    }


    /**
     * Removes and returns the value at the last entry in the list.
     */
    protected V removeLast( ) throws EmptyDictionaryException
    {
        if ( this.isEmpty() )
            throw new EmptyDictionaryException();

        V value = tail.getElement().getValue();
        this.removeLastNode();
        return value;
    }

    /**
     * Removes the specified node from the list.
     * Pre-condition: the node is neither the head nor the tail of the list.
     * @param node - middle node to be removed
     */
    protected void removeMiddleNode( DoubleListNode<Entry<K,V>> node )
    {

		node.getNext().setPrevious(node.getPrevious());
		node.getPrevious().setNext(node.getNext());

	  	currentSize--;

    }

    public String toString() {
    	
    	TwoWayIteratorEntries<K,V> entries= iterator();
    	String result="[";
    	while(entries.hasNext()) {
    		result+=" " +entries.next()+ " ";
    		
    	}
    	result+= "]";
    	return result;
    	
    }
    
    @Override
    public V remove(K key) {
		DoubleListNode<Entry<K,V>> node = findNode(key);
		V result=null;
		if ((node == null) || (key.compareTo(node.getElement().getKey())<0)) {
			
			return result;
		}

		else { 
			if (node==head){
		  	result=removeFirst();
			}
			else if(node==tail) {
			  	result=removeLast();
				
				
			}
			else {
				result= node.getElement().getValue();
				removeMiddleNode(node);
			}
		}
		return result;
	}

    @Override
	public int size() {
		return currentSize;
	}
	
	
}
