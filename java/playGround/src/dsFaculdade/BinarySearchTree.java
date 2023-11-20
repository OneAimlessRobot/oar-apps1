package dsFaculdade;

import java.io.Serializable;

/**
 * BinarySearchTree implementation
 * @author AED team
 * @version 1.0
 * @param <K> Generic type Key, must extend comparable
 * @param <V> Generic type Value 
 */
public abstract class BinarySearchTree<K extends Comparable<K>, V> 
    implements OrderedDictionary<K,V>, Serializable
{                                                                   

protected static class BSTIterator<K,V> implements TwoWayIteratorEntries<K,V>{
		
		private static final long serialVersionUID = 1L;
		protected Stack<BSTNode<K,V>> path;
		private BSTNode<K,V> root,smallest,biggest,next;
		private boolean forward;
		public BSTIterator(BSTNode<K,V> root) {
			this.root=next=root;
			forward=true;
			fullForward();
			rewind();
			
		}
		
		
		@Override
		public boolean hasNext() {
			return next!=biggest && biggest!=null;
		}

		@Override
		public Entry<K, V> next() throws NoSuchElementException {
				if(!hasNext()) {
					throw new NoSuchElementException();
				}
				if(!forward) {
					
					switchDirection();
				}
				BSTNode<K,V> node=next= path.pop();
//				Entry<K,V> result= node.getEntry();
				
				if(node.getRight()!=null) {
					
					path.push(node.getRight());
					
					node=node.getRight();
					while(node.getLeft()!=null){
						
						path.push(node.getLeft());
						node=node.getLeft();
						
					}
				}
				
				return next.getEntry();
		}

		private void switchDirection() {
			BSTNode<K,V> current= next;
			if(forward) {
				forward=!forward;
				fullForward();
				while(hasPrevious()) {
					previous();
					if(next==current) {
						break;
					}
				}
				
			}else {
				forward=!forward;
				rewind();
				while(hasNext()) {
					next();
					if(next==current) {
						break;
					}
				}
				
			}
			
			
		}
		@Override
		public void rewind() {
			if(root==null) {
				return;
			}
			path= new StackInList<>();
			next=root;
			do{
				
				
				path.push(next);
				if(next.getLeft()==null) {
					smallest=next;
				}
				next= next.getLeft();
				
			}while(next!=null);
			
		}




		@Override
		public Entry<K, V> previous() throws NoSuchElementException {
			if(!hasPrevious()) {
				throw new NoSuchElementException();
			}

			if(forward) {
				
				switchDirection();
			}
			BSTNode<K,V> node=next= path.pop();
//			Entry<K,V> result= node.getEntry();
			
			if(node.getLeft()!=null) {
				
				path.push(node.getLeft());
				
				node=node.getLeft();
				while(node.getRight()!=null){
					
					path.push(node.getRight());
					node=node.getRight();
					
				}
			}
			return next.getEntry();
		}


		@Override
		public void fullForward() {
			if(root==null) {
				return;
			}
			path= new StackInList<>();
			next=root;
			do{
				
				
				path.push(next);
				if(next.getRight()==null) {
					biggest=next;
				}
				next= next.getRight();
				
			}while(next!=null);
			
		}


		@Override
		public boolean hasPrevious() {
			return next!=smallest && smallest!=null;
		}
		
	}
protected static class BSTDepthIterator<K,V> implements IteratorEntries<K,V>{
	
	private static final long serialVersionUID = 1L;
	protected Stack<BSTNode<K,V>> path;
	private BSTNode<K,V> root;
	public BSTDepthIterator(BSTNode<K,V> root) {
		this.root=root;
		rewind();
		
	}
	
	
	@Override
	public boolean hasNext() {
		if(path==null) {
			return false;
		}
		return !path.isEmpty();
	}

	@Override
	public Entry<K, V> next() throws NoSuchElementException {
			if(!hasNext()) {
				throw new NoSuchElementException();
			}
			BSTNode<K,V> node= path.pop();
			Entry<K,V> result= node.getEntry();

			if(node.getLeft()!=null) {
				path.push(node.getLeft());
			}
			if(node.getRight()!=null) {
				path.push(node.getRight());
			}
			
			return result;
	}
	@Override
	public void rewind() {
		if(root==null) {
			return;
		}
		path= new StackInList<>();
		path.push(root);
		
	}


	
}
protected static class BSTBreadthIterator<K,V> implements IteratorEntries<K,V>{
	
	private static final long serialVersionUID = 1L;
	protected Queue<BSTNode<K,V>> path;
	private BSTNode<K,V> root;
	public BSTBreadthIterator(BSTNode<K,V> root) {
		this.root=root;
		rewind();
		
	}
	
	
	@Override
	public boolean hasNext() {
		if(path==null) {
			return false;
		}
		return !path.isEmpty();
	}

	@Override
	public Entry<K, V> next() throws NoSuchElementException {
			if(!hasNext()) {
				throw new NoSuchElementException();
			}
			BSTNode<K,V> node= path.dequeue();
			Entry<K,V> result= node.getEntry();

			if(node.getLeft()!=null) {
				path.enqueue(node.getLeft());
			}
			if(node.getRight()!=null) {
				path.enqueue(node.getRight());
			}
			return result;
	}
	@Override
	public void rewind() {
		if(root==null) {
			return;
		}
		path= new QueueInList<>();
		path.enqueue(root);
		
	}


	
}
	/**
	 * Serial Version UID of the Class.
	 */
    static final long serialVersionUID = 0L;


    /**
     * The root of the tree.                                            
     * 
     */
    protected BSTNode<K,V> root;                                

    /**
     * Number of entries in the tree.                                  
     * 
     */
    protected int currentSize;                   


    /**
     * Inner class to store path steps 
	 * @author AED team
	 * @version 1.0
     * @param <K> Generic type Key, must extend comparable
     * @param <V> Generic type Value 
     */
    protected static class PathStep<K,V> implements Serializable
    {

        private static final long serialVersionUID = 1L;

		/**
         * The parent of the node.
         */
        public BSTNode<K,V> parent;

        /**
         * The node is the left or the right child of parent.
        */
        public boolean isLeftChild;

        /**
         * PathStep constructor
         * @param theParent - ancestor of the current node
         * @param toTheLeft - will be true of the current node is the left child of theParent
         */
        public  PathStep( BSTNode<K,V> theParent, boolean toTheLeft )
        {
            parent = theParent;
            isLeftChild = toTheLeft;
        }


        /**
         * Method to set node parent before moving in the tree
         * @param newParent - ancestor of the current node
         * @param toTheLeft - will be true of the current node is the left child of theParent
         */
        public void set( BSTNode<K,V> newParent, boolean toTheLeft ) {

            parent = newParent;
            isLeftChild = toTheLeft;

        	
        }

    }


    /**
     * Tree Constructor - creates an empty tree.
     */
    public BinarySearchTree( )                                    
    {    
        root = null;
        currentSize = 0;
    }


    @Override
    public boolean isEmpty( )                               
    {    
        return root == null;
    }


    @Override
    public int size( )                                      
    {    
        return currentSize;
    }


    @Override
    public V find( K key )                             
    {    
        BSTNode<K,V> node = this.findNodeRec(root, key);
        if ( node == null )                                   
            return null;                                    
        else                                                     
            return node.getValue();
    }


    /**
     * Returns the node whose key is the specified key;
     * or null if no such node exists.        
     *                         
     * @param node where the search starts 
     * @param key to be found
     * @return the found node, when the search is successful
     */
    protected BSTNode<K,V> findNodeRec( BSTNode<K,V> node, K key )
    {                                                                   
        if ( node == null )
            return null;
        else
        {
            int compResult = key.compareTo( node.getKey() );
            if ( compResult == 0 )
                return node;                                         
            else if ( compResult < 0 )
                return this.findNodeRec(node.getLeft(), key);
            else                                                     
                return  this.findNodeRec(node.getRight(), key); 
        }                 
    }

   @Override
    public Entry<K,V> minEntry( ) throws EmptyDictionaryException
   {
	   
       
	   if ( this.isEmpty() )                              
		   throw new EmptyDictionaryException();           

	   		return this.minNodeRec(root).getEntry();   
	   
	   
   }


   /**
    * Returns the node with the smallest key 
    * in the tree rooted at the specified node.
    * Moreover, stores the last step of the path in lastStep.
    * Requires: theRoot != null.
    * @param theRoot - node that roots the tree
    * @param lastStep - Pathstep object to refer to the parent of theRoot
    * @return node containing the entry with the minimum key
    */
   abstract protected BSTNode<K,V> maxNode( BSTNode<K,V> theRoot);
   
   abstract protected BSTNode<K,V> minNode( BSTNode<K,V> theRoot);
   
   
   protected BSTNode<K,V> minNodeRec( BSTNode<K,V> node )
   {                                                                   
       if ( node.getRight() == null )                            
           return node;                                             
       else                                                     
           return this.minNodeRec( node.getLeft() );                       
   }      

    @Override
    public Entry<K,V> maxEntry( ) throws EmptyDictionaryException
    {                                                                   
        if ( this.isEmpty() )                              
            throw new EmptyDictionaryException();           

        return this.maxNodeRec(root).getEntry();                    
    }


    /**
     * Returns the node with the largest key 
     * in the tree rooted at the specified node.
     * Requires: node != null.
     * @param node that roots the tree
     * @return node with the largest key in the tree
     */
    protected BSTNode<K,V> maxNodeRec( BSTNode<K,V> node )
    {                                                                   
        if ( node.getRight() == null )                            
            return node;                                             
        else                                                     
            return this.maxNodeRec( node.getRight() );                       
    }                               



    protected int calculateSubtreeHeight(BSTNode<K,V> node) {
    	if (node == null) {
            return 0;
        }
    	Queue<BSTNode<K,V>> queue=new QueueInList<>();
    	queue.enqueue(node);
    	// empty tree has a height of 0
        
     
        BSTNode<K,V> front=null;
        int height = 0;
     
        // loop till queue is empty
        while (!queue.isEmpty())
        {
            // calculate the total number of nodes at the current level
            int size = queue.size();
     
            // process each node of the current level and enqueue their
            // non-empty left and right child
            while ((size--)>0)
            {
                front = queue.dequeue();
     
                if (front.getLeft()!=null) {
                    queue.enqueue(front.getLeft());
                }
     
                if (front.getRight()!=null) {
                    queue.enqueue(front.getRight());
                }
            }
     
            // increment height by 1 for each level
            height++;
        }
        return height;
    	
    }
    protected int getHeightDifference(BSTNode<K,V> node) {
    	
    	return calculateSubtreeHeight(node.getLeft())-calculateSubtreeHeight(node.getRight());
    	
    }
    /**
     * Links a new subtree, rooted at the specified node, to the tree.
     * The parent of the old subtree is stored in lastStep.
     * @param node - root of the subtree
     * @param lastStep - PathStep object referring to the parent of the old subtree
     */
    abstract protected void linkSubtree( BSTNode<K,V> node);

    public String toString() {

    	if(isEmpty()) {
    		return "[ ]";
    	}
    	String result="[";
    	TwoWayIteratorEntries<K,V> it= iterator();
    	while(it.hasNext()) {
    		
    		result+=" "+it.next()+" ";
    	}
    	result+="]";
    	return result;
    
    	
    }

    public String toStringDepth() {

    	if(isEmpty()) {
    		return "[ ]";
    	}
    	String result="[";
    	IteratorEntries<K,V> it= depthIterator();
    	while(it.hasNext()) {
    		
    		result+=" "+it.next()+" ";
    	}
    	result+="]";
    	return result;
    
    	
    }

    public String toStringBreadth() {

    	if(isEmpty()) {
    		return "[ ]";
    	}
    	String result="[";
    	IteratorEntries<K,V> it= breadthIterator();
    	while(it.hasNext()) {
    		
    		result+=" "+it.next()+" ";
    	}
    	result+="]";
    	return result;
    
    	
    }

    abstract protected BSTNode<K,V> findNode( K key);

    @Override
    public abstract V remove( K key ); 
    
    @Override
    public abstract V insert( K key ,V value );                 

    @Override
    /**
     * Returns an iterator of the entries in the dictionary 
     * which preserves the key order relation.
     * @return  key-order iterator of the entries in the dictionary
     */
    public TwoWayIteratorEntries<K,V> iterator( ) 
    {
    	return (TwoWayIteratorEntries<K,V>) new BSTIterator<>(root);
    }

    public IteratorEntries<K,V> breadthIterator( ) 
    {
    	return (IteratorEntries<K,V>) new BSTBreadthIterator<>(root);
    }
    public IteratorEntries<K,V> depthIterator( ) 
    {
    	return (IteratorEntries<K,V>) new BSTDepthIterator<>(root);
    }

}

