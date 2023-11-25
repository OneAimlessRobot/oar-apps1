// package dataStructures;
// import java.io.Serializable;

// public abstract class BSTList<K extends Comparable<K>> implements List<K>{


//     protected static class BSTListIterator<K extends Comparable<K>> implements TwoWayIterator<K>{
		
// 		private static final long serialVersionUID = 1L;
// 		protected Stack<BSTNode<K,K>> path;
// 		private BSTListNode<K> root,smallest,biggest,next;
// 		private boolean forward;
// 		public BSTListIterator(BSTListNode<K> root) {
// 			this.root=next=root;
// 			forward=true;
// 			fullForward();
// 			rewind();
			
// 		}
		
		
// 		@Override
// 		public boolean hasNext() {
// 			return next!=biggest && biggest!=null;
// 		}

// 		@Override
// 		public K next() throws NoSuchElementException {
// 				if(!hasNext()) {
// 					throw new NoSuchElementException();
// 				}
// 				if(!forward) {
					
// 					switchDirection();
// 				}
// 				BSTListNode<K> node=next= path.pop();
// //				K result= node.getEntry();
				
// 				if(node.getRight()!=null) {
					
// 					path.push(node.getRight());
					
// 					node=node.getRight();
// 					while(node.getLeft()!=null){
						
// 						path.push(node.getLeft());
// 						node=node.getLeft();
						
// 					}
// 				}
				
// 				return next.getEntry();
// 		}

// 		private void switchDirection() {
// 			BSTListNode<K> current= next;
// 			if(forward) {
// 				forward=!forward;
// 				fullForward();
// 				while(hasPrevious()) {
// 					previous();
// 					if(next==current) {
// 						break;
// 					}
// 				}
				
// 			}else {
// 				forward=!forward;
// 				rewind();
// 				while(hasNext()) {
// 					next();
// 					if(next==current) {
// 						break;
// 					}
// 				}
				
// 			}
			
			
// 		}
// 		@Override
// 		public void rewind() {
// 			if(root==null) {
// 				return;
// 			}
// 			path= new StackInList<>();
// 			next=root;
// 			do{
				
				
// 				path.push(next);
// 				if(next.getLeft()==null) {
// 					smallest=next;
// 				}
// 				next= next.getLeft();
				
// 			}while(next!=null);
			
// 		}




// 		@Override
// 		public K previous() throws NoSuchElementException {
// 			if(!hasPrevious()) {
// 				throw new NoSuchElementException();
// 			}

// 			if(forward) {
				
// 				switchDirection();
// 			}
// 			BSTListNode<K> node=next= path.pop();
// //			K result= node.getEntry();
			
// 			if(node.getLeft()!=null) {
				
// 				path.push(node.getLeft());
				
// 				node=node.getLeft();
// 				while(node.getRight()!=null){
					
// 					path.push(node.getRight());
// 					node=node.getRight();
					
// 				}
// 			}
// 			return next.getEntry();
// 		}


// 		@Override
// 		public void fullForward() {
// 			if(root==null) {
// 				return;
// 			}
// 			path= new StackInList<>();
// 			next=root;
// 			do{
				
				
// 				path.push(next);
// 				if(next.getRight()==null) {
// 					biggest=next;
// 				}
// 				next= next.getRight();
				
// 			}while(next!=null);
			
// 		}


// 		@Override
// 		public boolean hasPrevious() {
// 			return next!=smallest && smallest!=null;
// 		}
		
// 	}
// protected static class BSTDepthIterator<K extends Comparable<K>> implements Iterator<K>{
	
// 	private static final long serialVersionUID = 1L;
// 	protected Stack<BSTListNode<K>> path;
// 	private BSTListNode<K> root;
// 	public BSTDepthIterator(BSTListNode<K> root) {
// 		this.root=root;
// 		rewind();
		
// 	}
	
	
// 	@Override
// 	public boolean hasNext() {
// 		if(path==null) {
// 			return false;
// 		}
// 		return !path.isEmpty();
// 	}

// 	@Override
// 	public K next() throws NoSuchElementException {
// 			if(!hasNext()) {
// 				throw new NoSuchElementException();
// 			}
// 			BSTListNode<K> node= path.pop();
// 			K result= node.getEntry();

// 			if(node.getLeft()!=null) {
// 				path.push(node.getLeft());
// 			}
// 			if(node.getRight()!=null) {
// 				path.push(node.getRight());
// 			}
			
// 			return result;
// 	}
// 	@Override
// 	public void rewind() {
// 		if(root==null) {
// 			return;
// 		}
// 		path= new StackInList<>();
// 		path.push(root);
		
// 	}


	
// }
// protected static class BSTBreadthIterator<K> implements Iterator<K>{
	
// 	private static final long serialVersionUID = 1L;
// 	protected Queue<BSTListNode<K>> path;
// 	private BSTListNode<K> root;
// 	public BSTBreadthIterator(BSTListNode<K> root) {
// 		this.root=root;
// 		rewind();
		
// 	}
	
	
// 	@Override
// 	public boolean hasNext() {
// 		if(path==null) {
// 			return false;
// 		}
// 		return !path.isEmpty();
// 	}

// 	@Override
// 	public K next() throws NoSuchElementException {
// 			if(!hasNext()) {
// 				throw new NoSuchElementException();
// 			}
// 			BSTListNode<K> node= path.dequeue();
// 			K result= node.getEntry();

// 			if(node.getLeft()!=null) {
// 				path.enqueue(node.getLeft());
// 			}
// 			if(node.getRight()!=null) {
// 				path.enqueue(node.getRight());
// 			}
// 			return result;
// 	}
// 	@Override
// 	public void rewind() {
// 		if(root==null) {
// 			return;
// 		}
// 		path= new QueueInList<>();
// 		path.enqueue(root);
		
// 	}


	
// }
// 	/**
// 	 * Serial Version UID of the Class.
// 	 */
//     static final long serialVersionUID = 0L;


//     /**
//      * The root of the tree.                                            
//      * 
//      */
//     protected BSTListNode<K> root;                                

//     /**
//      * Number of entries in the tree.                                  
//      * 
//      */
//     protected int currentSize;                   


//     /**
//      * Inner class to store path steps 
// 	 * @author AED team
// 	 * @version 1.0
//      * @param <K> Generic type Key, must extend comparable
//      * @param <V> Generic type Value 
//      */
//     protected static class PathStep<K,V> implements Serializable
//     {

//         private static final long serialVersionUID = 1L;

// 		/**
//          * The parent of the node.
//          */
//         public BSTListNode<K> parent;

//         /**
//          * The node is the left or the right child of parent.
//         */
//         public boolean isLeftChild;

//         /**
//          * PathStep constructor
//          * @param theParent - ancestor of the current node
//          * @param toTheLeft - will be true of the current node is the left child of theParent
//          */
//         public  PathStep( BSTListNode<K> theParent, boolean toTheLeft )
//         {
//             parent = theParent;
//             isLeftChild = toTheLeft;
//         }


//         /**
//          * Method to set node parent before moving in the tree
//          * @param newParent - ancestor of the current node
//          * @param toTheLeft - will be true of the current node is the left child of theParent
//          */
//         public void set( BSTListNode<K> newParent, boolean toTheLeft ) {

//             parent = newParent;
//             isLeftChild = toTheLeft;

        	
//         }

//     }


//     /**
//      * Tree Constructor - creates an empty tree.
//      */
//     public BSTList( )                                    
//     {    
//         root = null;
//         currentSize = 0;
//     }


//     @Override
//     public boolean isEmpty( )                               
//     {    
//         return root == null;
//     }


//     @Override
//     public int size( )                                      
//     {    
//         return currentSize;
//     }


//     @Override
//     public int find( K key )                             
//     {  
//         return 0; /* 
//         BSTListNode<K> node = this.findNode(root, key);
//         if ( node == null )                                   
//             return -1;                                    
//         else                                                     
//             return node.getEntry();*/
//     }


//     /**
//      * Returns the node whose key is the specified key;
//      * or null if no such node exists.        
//      *                         
//      * @param node where the search starts 
//      * @param key to be found
//      * @return the found node, when the search is successful
//      */
//     protected BSTListNode<K> findNode( BSTListNode<K> node, K key )
//     {                                                                   
//         if ( node == null )
//             return null;
//         else
//         {
//             int compResult = key.compareTo( node.getEntry() );
//             if ( compResult == 0 )
//                 return node;                                         
//             else if ( compResult < 0 )
//                 return this.findNode(node.getLeft(), key);
//             else                                                     
//                 return  this.findNode(node.getRight(), key); 
//         }                 
//     }

   
//    protected BSTListNode<K> minNode( BSTListNode<K> node )
//    {                                                                   
//        if ( node.getRight() == null )                            
//            return node;                                             
//        else                                                     
//            return this.maxNode( node.getLeft() );                       
//    }      

   

//     protected int calculateSubtreeHeight(BSTListNode<K> node) {
//     	if (node == null) {
//             return 0;
//         }
//     	Queue<BSTListNode<K>> queue=new QueueInList<>();
//     	queue.enqueue(node);
//     	// empty tree has a height of 0
        
     
//         BSTListNode<K> front=null;
//         int height = 0;
     
//         // loop till queue is empty
//         while (!queue.isEmpty())
//         {
//             // calculate the total number of nodes at the current level
//             int size = queue.size();
     
//             // process each node of the current level and enqueue their
//             // non-empty left and right child
//             while ((size--)>0)
//             {
//                 front = queue.dequeue();
     
//                 if (front.getLeft()!=null) {
//                     queue.enqueue(front.getLeft());
//                 }
     
//                 if (front.getRight()!=null) {
//                     queue.enqueue(front.getRight());
//                 }
//             }
     
//             // increment height by 1 for each level
//             height++;
//         }
//         return height;
    	
//     }
//     protected int getHeightDifference(BSTListNode<K> node) {
    	
//     	return calculateSubtreeHeight(node.getLeft())-calculateSubtreeHeight(node.getRight());
    	
//     }
//     /**
//      * Links a new subtree, rooted at the specified node, to the tree.
//      * The parent of the old subtree is stored in lastStep.
//      * @param node - root of the subtree
//      * @param lastStep - PathStep object referring to the parent of the old subtree
//      */
//     abstract protected void linkSubtree( BSTListNode<K> node);

//     @Override
//     public String toString() {

//     	if(isEmpty()) {
//     		return "[ ]";
//     	}
//     	String result="[";
//     	TwoWayIterator<K> it= iterator();
//     	while(it.hasNext()) {
    		
//     		result+=" "+it.next()+" ";
//     	}
//     	result+="]";
//     	return result;
    
    	
//     }

//     public String toStringDepth() {

//     	if(isEmpty()) {
//     		return "[ ]";
//     	}
//     	String result="[";
//     	Iterator<K> it= depthIterator();
//     	while(it.hasNext()) {
    		
//     		result+=" "+it.next()+" ";
//     	}
//     	result+="]";
//     	return result;
    
    	
//     }

//     public String toStringBreadth() {

//     	if(isEmpty()) {
//     		return "[ ]";
//     	}
//     	String result="[";
//     	Iterator<K> it= breadthIterator();
//     	while(it.hasNext()) {
    		
//     		result+=" "+it.next()+" ";
//     	}
//     	result+="]";
//     	return result;
    
    	
//     }


//     @Override
//     public abstract boolean remove( K key ); 
    
//     @Override
//     public abstract void add( K key );                 

//     @Override
//     /**
//      * Returns an iterator of the entries in the dictionary 
//      * which preserves the key order relation.
//      * @return  key-order iterator of the entries in the dictionary
//      */
//     public TwoWayIterator<K> iterator( ) 
//     {
//     	return (TwoWayIterator<K>) new BSTListIterator<>(root);
//     }

//     public Iterator<K> breadthIterator( ) 
//     {
//     	return (Iterator<K>) new BSTBreadthIterator<>(root);
//     }
    
//     public Iterator<K> depthIterator( ) 
//     {
//     	return (Iterator<K>) new BSTDepthIterator<>(root);
//     }


    
// }
package dsFaculdad;



