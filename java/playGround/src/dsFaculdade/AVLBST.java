package dsFaculdade;
import java.io.Serializable;

///**
// * Returns the node whose key is the specified key;
// * or null if no such node exists.                                
// * Moreover, stores the last step of the path in lastStep.
// * @param key to be searched
// * @param lastStep - PathStep object referring to parent 
// * @return the found node, when the search is successful
// 
// */
//protected abstract BSTNode<K,V> findNode( K key, PathStep<K,V> lastStep );


import dsFaculdade.AVLBSTNode.NodeType;
public class AVLBST<K extends Comparable<K>,V> extends BinarySearchTree<K, V> implements Dictionary<K, V>, Serializable {

	/**
	 * Serial Version UID of the Class.
	 */
    static final long serialVersionUID = 0L;



    private Stack<PathStep<K,V>> path;
    /**
     * Tree Constructor - creates an empty tree.
     */
    public AVLBST( )                                    
    {    
    	super();
    }
    
    @Override
    public V insert( K key, V value )
    {   
    	V result=null;
        AVLBSTNode<K,V> node =(AVLBSTNode<K,V>) this.findNode(key);
        if ( node == null )
        {
            AVLBSTNode<K,V> newLeaf = new AVLBSTNode<K,V>(key, value,NodeType.E);
            this.linkSubtree(newLeaf);

            rotateNodesInsertion();
            currentSize++;
        }
        else {
            V oldValue = node.getValue();
            node.setValue(value);
            result= oldValue;
        }
        return result;
    }


	private void rotateNodesInsertion() {
		boolean grew= true;
		PathStep<K,V> lastStep = path.pop();
		AVLBSTNode<K,V> parent= (AVLBSTNode<K,V>)lastStep.parent;
		while(grew && parent!=null) {
			if(lastStep.isLeftChild) {
				switch(parent.getType()) {
				case E:
					parent.setType(NodeType.L);
					break;
				case L:
					rotateNodesLeft(parent);
					grew=false;
					break;
				case R:
					parent.setType(NodeType.E);
					grew=false;
					break;
				default:
					break;
				
				
				}
				
				
			}else {
				
				switch(parent.getType()) {
				case E:
					parent.setType(NodeType.R);
					break;
				case R:
					rotateNodesRight(parent);
					grew=false;
					break;
				case L:
					parent.setType(NodeType.E);
					grew=false;
					break;
				default:
					break;
				
				
				}
				
			}

			lastStep = path.pop();
			parent= (AVLBSTNode<K,V>)lastStep.parent;
			
		}
		
		
		
    	
    }
    private void rotateNodesRight(AVLBSTNode<K, V> parent) {
		AVLBSTNode<K,V> node= (AVLBSTNode<K,V>) parent.getRight();
		switch(node.getType()) {
		case L:
			doubleRightRot(parent,node);
			break;
		case E:
			simpleRightRot(parent,node);
			break;
		case R:
			simpleRightRot(parent,node);
			break;
		default:
			break;
		
		}
		
	}
    private void rotateNodesLeft(AVLBSTNode<K, V> parent) {
		AVLBSTNode<K,V> node= (AVLBSTNode<K,V>) parent.getLeft();
		switch(node.getType()) {
		case L:
			simpleLeftRot(parent,node);
			break;
		case E:
			simpleLeftRot(parent,node);
			break;
		case R:
			doubleLeftRot(parent,node);
			break;
		default:
			break;
		
		}
		
	}
protected void doubleLeftRot( AVLBSTNode<K,V> theRoot, AVLBSTNode<K,V> leftChild) { 
	AVLBSTNode<K,V> rightGrandchild = (AVLBSTNode<K,V>) leftChild.getRight(); 
	 switch ( rightGrandchild.getType() ) { 
	 case L: 
		 leftChild.setType(NodeType.E); 
		 theRoot.setType(NodeType.R); 
		 break; 
		 case E: 
			 leftChild.setType(NodeType.E); 
			 theRoot.setType(NodeType.E); 
		break; 
		case R: 
				 leftChild.setType(NodeType.L); 
				 theRoot.setType(NodeType.E); 
		break;
	 }
		rightGrandchild.setType(NodeType.E);
	leftChild.setRight( rightGrandchild.getLeft() );
	theRoot.setLeft( rightGrandchild.getRight() ); 
    rightGrandchild.setLeft(leftChild); 
    rightGrandchild.setRight(theRoot);
	linkSubtree(rightGrandchild);
    }

protected void doubleRightRot( AVLBSTNode<K,V> theRoot, AVLBSTNode<K,V> rightChild) { 
	AVLBSTNode<K,V> leftGrandchild = (AVLBSTNode<K,V>) rightChild.getLeft(); 
	 switch ( leftGrandchild.getType() ) { 
	 case R: 
		 theRoot.setType(NodeType.E); 
		 rightChild.setType(NodeType.R); 
		 break; 
		 case E: 
			 theRoot.setType(NodeType.E); 
			 rightChild.setType(NodeType.E); 
		break; 
		case L: 
			 theRoot.setType(NodeType.L); 
				 rightChild.setType(NodeType.E); 
		break;
	 }

		leftGrandchild.setType(NodeType.E);
	theRoot.setRight( leftGrandchild.getLeft() ); 
	rightChild.setLeft( leftGrandchild.getRight() ); 
	leftGrandchild.setLeft(theRoot);
	leftGrandchild.setRight(rightChild);
	linkSubtree(leftGrandchild);
    }

protected void simpleLeftRot(AVLBSTNode<K,V> theRoot, AVLBSTNode<K,V> leftChild) {
	theRoot.setType(NodeType.E);
	leftChild.setType(NodeType.E);
theRoot.setLeft( leftChild.getRight() ); 
leftChild.setRight(theRoot); 
this.linkSubtree(leftChild);
}

protected void simpleRightRot(AVLBSTNode<K,V> theRoot, AVLBSTNode<K,V> rightChild) {
theRoot.setType(NodeType.E);
rightChild.setType(NodeType.E);
theRoot.setRight( rightChild.getLeft() ); 
rightChild.setLeft(theRoot); 
this.linkSubtree(rightChild);
}
    protected AVLBSTNode<K,V> findNode( K key)
    {    

        path=new StackInList<>();
        path.push(new PathStep<>(null,false));
        BSTNode<K,V> node = root;
        while ( node != null )
        {
            int compResult = key.compareTo( node.getKey() );
            if ( compResult == 0 )
                return (AVLBSTNode<K, V>) node;
            else if ( compResult < 0 )
            {
                path.push(new PathStep<>(node,true));
                node = node.getLeft();
            }
            else
            {
                path.push(new PathStep<>(node,false));
                node = node.getRight();
            }
        }
        return null;                                                    
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
    protected BSTNode<K,V> minNode( BSTNode<K,V> theRoot){                                                       
            BSTNode<K,V> node =(BSTNode<K,V>) theRoot;
            while ( node.getLeft() != null ) 
            {                      
                path.push(new PathStep<>(node,true));
                node =  node.getLeft();
            }                                       
            return node;
    }/**
     * Returns the node with the smallest key 
     * in the tree rooted at the specified node.
     * Moreover, stores the last step of the path in lastStep.
     * Requires: theRoot != null.
     * @param theRoot - node that roots the tree
     * @param lastStep - Pathstep object to refer to the parent of theRoot
     * @return node containing the entry with the minimum key
     */
    protected BSTNode<K,V> maxNode( BSTNode<K,V> theRoot){                                                       
            BSTNode<K,V> node =(BSTNode<K,V>) theRoot;
            while ( node.getRight() != null ) 
            {                      
                path.push(new PathStep<>(node,false));
                node =  node.getRight();
            }                                       
            return node;
    }
    @Override
    public V remove( K key )
    {
        AVLBSTNode<K,V> node = (AVLBSTNode<K, V>) this.findNode(key);
        if ( node == null )
            return null;
        else
        {
            V oldValue = node.getValue();
            if ( node.getLeft() == null )
                // The left subtree is empty.
                this.linkSubtree((AVLBSTNode<K, V>) node.getRight());
            else if ( node.getRight() == null )
                // The right subtree is empty.
                this.linkSubtree((AVLBSTNode<K, V>) node.getLeft());
            else
            {
                // Node has 2 children. Replace the node's entry with
                // the 'minEntry' of the right subtree.
                path.top().set(node, false);
                AVLBSTNode<K,V> minNode = (AVLBSTNode<K, V>) this.minNode((AVLBSTNode<K, V>) node.getRight());
                node.setEntry( minNode.getEntry() );
                this.linkSubtree((AVLBSTNode<K, V>) minNode.getRight());
                rotateNodesRemove();
                currentSize--;
            }
            currentSize--;
            return oldValue;
        }                                 
    }                                


    private void rotateNodesRemove() {
    		boolean shrunk= true;
    		PathStep<K,V> lastStep = path.pop();
    		AVLBSTNode<K,V> parent= (AVLBSTNode<K,V>)lastStep.parent;
    		while(shrunk && parent!=null) {
    			if(lastStep.isLeftChild) {
    				switch(parent.getType()) {
    				case E:
    					parent.setType(NodeType.R);
      					shrunk=false;
    					break;
    				case R:
    					rotateNodesRight(parent);
    					shrunk=false;
    					break;
    				case L:
    					parent.setType(NodeType.E);
    					break;
    				default:
    					break;
    				
    				
    				}
    				
    				
    			}else {
    				
    				switch(parent.getType()) {
    				case E:
    					parent.setType(NodeType.L);
    					shrunk=false;
    					break;
    				case L:
    					rotateNodesLeft(parent);
    					shrunk=false;
    					break;
    				case R:
    					parent.setType(NodeType.E);
    					break;
    				default:
    					break;
    				
    				
    				}
    				
    			}

    			lastStep = path.pop();
    			parent= (AVLBSTNode<K,V>)lastStep.parent;
    			
    		}
		
	}

	private void rotateNodesRightR(AVLBSTNode<K, V> parent) {
		// TODO Auto-generated method stub
		
	}

	protected void linkSubtree( BSTNode<K,V> node) {
        
        if ( path.top().parent == null )
            // Change the root of the tree.
            root = node;
        else
            // Change a child of parent.
            if ( path.top().isLeftChild )
                path.top().parent.setLeft(node);
            else
                path.top().parent.setRight(node);



}
}
