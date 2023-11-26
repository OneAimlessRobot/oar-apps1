package ds.implem;

import java.io.Serializable;

import ds.interfaces.MySet;
import ds.exceptions.StackEmptyException;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.implem.QueueInDoubleLinkedList;
import ds.interfaces.QueueIterable;
import ds.interfaces.Stack;
import ds.interfaces.TwoWayIterator;

public abstract class BinarySearchTree<T extends Comparable<T>> implements MySet<T>, Serializable {
	abstract static class BSTNode<T> implements Serializable
	{                                                                   

		/**
		 * Serial Version UID of the Class.
		 */
	    static final long serialVersionUID = 0L;


	    /**
	     * Entry stored in the node.
	     */
	    protected T entry;                                      

	    /**
	     * (Pointer to) the left child.
	     * 
	     */
	    protected BSTNode<T> leftChild;

	    /**
	     * (Pointer to) the right child.
	     * 
	     */
	    protected BSTNode<T> rightChild;


	    /**
	     * Constructor for BST nodes
	     * 
	     * @param key to be stored in this BST tree node
	     * @param value to be stored in this BST tree node
	     * @param left sub-tree of this node
	     * @param right sub-tree of this node
	     */
	    public BSTNode(T value, BSTNode<T> left, BSTNode<T> right )
	    {                                                                
	        entry = value;
	        leftChild = left; 
	        rightChild = right;                                      
	    }


	    /**
	     * Constructor for BST nodes
	     * 
	     * @param key to be stored in this BST tree node
	     * @param value to be stored in this BST tree node
	     */
	    public BSTNode( T value)
	    {    
	        this(value, null, null);
	    }


	    /**
	     * Returns the entry (key and value) of the current node.
	     * 
	     * @return
	     */
	    public T getEntry( )                           
	    {
	        return entry;
	    }






	    /**
	     * Returns the left child node of the current node.
	     * 
	     * @return
	     */
	    public BSTNode<T> getLeft( )                                     
	    {    
	        return leftChild;
	    }


	    /**
	     * Returns the right child node of the current node.
	     * 
	     * @return
	     */
	    public BSTNode<T> getRight( )                                    
	    {    
	        return rightChild;
	    }


	    /**
	     * Assigns a new entry (key and value) to the current BST node
	     *   
	     * @param newEntry
	     */
	    public void setEntry( T newEntry )
	    {    
	        entry = newEntry;
	    }





	    public String toString() {
	    	
	    	return entry.toString();
	    }


	    /**
	     * Sets the new left child node of the this node
	     * 
	     * @param newLeft the new left child node of the current node
	     */
	    public void setLeft( BSTNode<T> newLeft )                     
	    {    
	        leftChild = newLeft;
	    }


	    /**
	     * Sets the new right child node of the this node
	     * 
	     * @param newLeft the new right child node of the current node
	     */
	    public void setRight( BSTNode<T> newRight )                   
	    {    
	        rightChild = newRight;
	    }


	    /**
	     * Returns true iff the node is a leaf.
	     * 
	     * @return
	     */
	    public boolean isLeaf( )                                
	    {    
	        return leftChild == null && rightChild == null;          
	    }                                                                  


	}

private static class BSTNodeIterator<T> implements Serializable{
		
		private static final long serialVersionUID = 1L;
		protected Stack<BSTNode<T>> path;
		private BSTNode<T> root,smallest,biggest,next;
		private boolean forward;
		public BSTNodeIterator(BSTNode<T> root) {
			this.root=next=root;
			forward=true;
			fullForward();
			rewind();
			
		}
		
		
		public boolean hasNext() {
			return next!=biggest && biggest!=null;
		}

		public BSTNode<T> next(){
				if(!forward) {
					
					switchDirection();
				}
				BSTNode<T> node=null;
				try {
					node = next= path.pop();
				} catch (StackEmptyException e) {
					e.printStackTrace();
				}
				
				if(node.getRight()!=null) {
					
					path.push(node.getRight());
					
					node=node.getRight();
					while(node.getLeft()!=null){
						
						path.push(node.getLeft());
						node=node.getLeft();
						
					}
				}
				
				return next;
		}

		private void switchDirection() {
			BSTNode<T> current= next;
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
		public void rewind() {
			if(root==null) {
				return;
			}
			path= new StackInLinkedList<>();
			next=root;
			do{
				
				
				path.push(next);
				if(next.getLeft()==null) {
					smallest=next;
				}
				next= next.getLeft();
				
			}while(next!=null);
			
		}




		public BSTNode<T> previous() {
			if(forward) {
				
				switchDirection();
			}
			BSTNode<T> node=null;
			try {
				node = next= path.pop();
			} catch (StackEmptyException e) {
				e.printStackTrace();
			}
			
			if(node.getLeft()!=null) {
				
				path.push(node.getLeft());
				
				node=node.getLeft();
				while(node.getRight()!=null){
					
					path.push(node.getRight());
					node=node.getRight();
					
				}
			}
			return next;
		}


		public void fullForward() {
			if(root==null) {
				return;
			}
			path= new StackInLinkedList<>();
			next=root;
			do{
				
				
				path.push(next);
				if(next.getRight()==null) {
					biggest=next;
				}
				next= next.getRight();
				
			}while(next!=null);
			
		}


		public boolean hasPrevious() {
			return next!=smallest && smallest!=null;
		}
		
	}
protected static class BSTIterator<T> implements TwoWayIterator<T>,Serializable{
		
		private static final long serialVersionUID = 1L;
		protected Stack<BSTNode<T>> path;
		private BSTNode<T> root,smallest,biggest,next;
		private boolean forward;
		public BSTIterator(BSTNode<T> root) {
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
		public T next() {
				if(!forward) {
					
					switchDirection();
				}
				BSTNode<T> node=null;
				try {
					node = next= path.pop();
				} catch (StackEmptyException e) {
					e.printStackTrace();
				}
				
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
			BSTNode<T> current= next;
			if(forward) {
				forward=!forward;
				fullForward();
				while(hasPrev()) {
					prev();
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
			path= new StackInLinkedList<>();
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
		public T prev() {

			if(forward) {
				
				switchDirection();
			}
			BSTNode<T> node=null;
			try {
				node = next= path.pop();
			} catch (StackEmptyException e) {
				e.printStackTrace();
			}
			
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
			path= new StackInLinkedList<>();
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
		public boolean hasPrev() {
			return next!=smallest && smallest!=null;
		}
		
	}
protected static class BSTDepthIterator<T> implements Iterator<T>,Serializable{
	
	private static final long serialVersionUID = 1L;
	protected Stack<BSTNode<T>> path;
	private BSTNode<T> root;
	public BSTDepthIterator(BSTNode<T> root) {
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
	public T next() {
			BSTNode<T> node=null;
			try {
				node = path.pop();
			} catch (StackEmptyException e) {
				e.printStackTrace();
			}
			T result= node.getEntry();

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
		path= new StackInLinkedList<>();
		path.push(root);
		
	}


	
}
protected static class BSTBreadthIterator<T> implements Iterator<T>,Serializable{
	
	private static final long serialVersionUID = 1L;
	protected QueueIterable<BSTNode<T>> path;
	private BSTNode<T> root;
	public BSTBreadthIterator(BSTNode<T> root) {
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
	public T next() {
			BSTNode<T> node= path.dequeue();
			T result= node.getEntry();

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
		path= new QueueInDoubleLinkedList<>();
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
    protected BSTNode<T> root;                                

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
    protected static class PathStep<T> implements Serializable
    {

        private static final long serialVersionUID = 1L;

		/**
         * The parent of the node.
         */
        public BSTNode<T> parent;

        /**
         * The node is the left or the right child of parent.
        */
        public boolean isLeftChild;

        /**
         * PathStep constructor
         * @param theParent - ancestor of the current node
         * @param toTheLeft - will be true of the current node is the left child of theParent
         */
        public  PathStep( BSTNode<T> theParent, boolean toTheLeft )
        {
            parent = theParent;
            isLeftChild = toTheLeft;
        }


        /**
         * Method to set node parent before moving in the tree
         * @param newParent - ancestor of the current node
         * @param toTheLeft - will be true of the current node is the left child of theParent
         */
        public void set( BSTNode<T> newParent, boolean toTheLeft ) {

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
    public T find( T key )                             
    {    
        BSTNode<T> node = this.findNode(root, key);
        if ( node == null )                                   
            return null;                                    
        else                                                     
            return node.getEntry();
    }
    @Override
    public boolean contains(T elem) {
    	return find(elem)!=null;
    }
    @Override
    public void clear() {
    	root=null;
    	currentSize=0;
    }


    /**
     * Returns the node whose key is the specified key;
     * or null if no such node exists.        
     *                         
     * @param node where the search starts 
     * @param key to be found
     * @return the found node, when the search is successful
     */
    protected BSTNode<T> findNode( BSTNode<T> node, T key )
    {                                                                   
        if ( node == null )
            return null;
        else
        {
            int compResult = key.compareTo( node.getEntry() );
            if ( compResult == 0 )
                return node;                                         
            else if ( compResult < 0 )
                return this.findNode(node.getLeft(), key);
            else                                                     
                return  this.findNode(node.getRight(), key); 
        }                 
    }

   protected BSTNode<T> minNode( BSTNode<T> node )
   {                                                                   
       if ( node.getRight() == null )                            
           return node;                                             
       else                                                     
           return this.maxNode( node.getLeft() );                       
   }      


    /**
     * Returns the node with the largest key 
     * in the tree rooted at the specified node.
     * Requires: node != null.
     * @param node that roots the tree
     * @return node with the largest key in the tree
     */
    protected BSTNode<T> maxNode( BSTNode<T> node )
    {                                                                   
        if ( node.getRight() == null )                            
            return node;                                             
        else                                                     
            return this.maxNode( node.getRight() );                       
    }                               



    protected int calculateSubtreeHeight(BSTNode<T> node) {
    	if (node == null) {
            return 0;
        }
    	QueueIterable<BSTNode<T>> queue=new QueueInDoubleLinkedList<>();
    	queue.enqueue(node);
    	// empty tree has a height of 0
        
     
        BSTNode<T> front=null;
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
    
    protected int getHeightDifference(BSTNode<T> node) {
    	
    	return calculateSubtreeHeight(node.getLeft())-calculateSubtreeHeight(node.getRight());
    	
    }
    
    public void printHeightDifferences() {
    	
    	BSTNodeIterator<T> it= new BSTNodeIterator<>(root);
    	while(it.hasNext()) {
    		BSTNode<T> node= it.next();
    		int coiso=0;
    		System.out.println((coiso=getHeightDifference(node))+ " ");
    		if(Math.abs(coiso)>=2) {
    			System.out.println("Birthday bukcake");
    			System.exit(-1);
    		}
    	}
    	
    	
    }
    /**
     * Links a new subtree, rooted at the specified node, to the tree.
     * The parent of the old subtree is stored in lastStep.
     * @param node - root of the subtree
     * @param lastStep - PathStep object referring to the parent of the old subtree
     */
    abstract protected void linkSubtree( BSTNode<T> node);

    @Override
    public String toString() {

    	if(isEmpty()) {
    		return "[ ]";
    	}
    	String result="[";
    	Iterator<T> it= iterator();
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
    	Iterator<T> it= depthIterator();
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
    	Iterator<T> it= breadthIterator();
    	while(it.hasNext()) {
    		
    		result+=" "+it.next()+" ";
    	}
    	result+="]";
    	return result;
    
    	
    }


    @Override
    public abstract void remove( T key ); 
    
    @Override
    public abstract void add( T value );                 


	@Override
	public Collection<T> copy() {
		Collection<T> collection= new TreeSet<>();
		if(isEmpty()) {
			return collection;
		}
		Iterator<T> it= iterator();
		while(it.hasNext()) {
			
			collection.add(it.next());
		}
		return collection;
		
	}

    @Override
    /**
     * Returns an iterator of the entries in the dictionary 
     * which preserves the key order relation.
     * @return  key-order iterator of the entries in the dictionary
     */
    public TwoWayIterator<T> twoWayIterator() 
    {
    	return new BSTIterator<>(root);
    }
    public Iterator<T> iterator() 
    {
    	return (Iterator<T>)new BSTIterator<>(root);
    }

    public Iterator<T> breadthIterator( ) 
    {
    	return (Iterator<T>) new BSTBreadthIterator<>(root);
    }
    public Iterator<T> depthIterator( ) 
    {
    	return (Iterator<T>) new BSTDepthIterator<>(root);
    }


}
