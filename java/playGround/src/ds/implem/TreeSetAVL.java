package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Stack;

public class TreeSetAVL<T extends Comparable<T>> extends BinarySearchTree<T> implements Serializable {

	protected static final long serialVersionUID = 1L;
	public static enum NodeType{
		L,R,E;
		
	}
private static class AVLBSTNode<T> extends BSTNode<T> implements Serializable {

    
	private static final long serialVersionUID = 1L;
	
	private NodeType type;
	public AVLBSTNode(T value,NodeType type) {
		super(value);
		this.type=type;
	}

	public NodeType getType() {
		return type;
	}
	public void setType(NodeType type) {
		this.type = type;
	}
	public String toString() {
		
		return "[ "+entry + " "+ type.toString()+" ]";
	}

}


private Stack<PathStep<T>> path;
/**
 * Tree Constructor - creates an empty tree.
 */
public TreeSetAVL( )                                    
{    
	super();
}

@Override
public void add( T value )
{   
    AVLBSTNode<T> node =(AVLBSTNode<T>) this.findNode(value);
    if ( node == null )
    {
        AVLBSTNode<T> newLeaf = new AVLBSTNode<>(value ,NodeType.E);
        this.linkSubtree(newLeaf);

        rotateNodesInsertion();
        currentSize++;
    }
    else {
    }
}


private void rotateNodesInsertion() {
	boolean grew= true;
	PathStep<T> lastStep=null;
	try {
		lastStep = path.pop();
	} catch (StackEmptyException e) {
	}
	AVLBSTNode<T> parent= (AVLBSTNode<T>)lastStep.parent;
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

		try {
			lastStep = path.pop();
		} catch (StackEmptyException e) {
		}
		parent= (AVLBSTNode<T>)lastStep.parent;
		
	}
	
	
	
	
}
private void rotateNodesRight(AVLBSTNode<T> parent) {
	AVLBSTNode<T> node= (AVLBSTNode<T>) parent.getRight();
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
private void rotateNodesLeft(AVLBSTNode<T> parent) {
	AVLBSTNode<T> node= (AVLBSTNode<T>) parent.getLeft();
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
protected void doubleLeftRot( AVLBSTNode<T> theRoot, AVLBSTNode<T> leftChild) { 
AVLBSTNode<T> rightGrandchild = (AVLBSTNode<T>) leftChild.getRight(); 
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

protected void doubleRightRot( AVLBSTNode<T> theRoot, AVLBSTNode<T> rightChild) { 
AVLBSTNode<T> leftGrandchild = (AVLBSTNode<T>) rightChild.getLeft(); 
 switch ( leftGrandchild.getType() ) { 
 case R: 
	 theRoot.setType(NodeType.L); 
	 rightChild.setType(NodeType.E); 
	 break; 
	 case E: 
		 theRoot.setType(NodeType.E); 
		 rightChild.setType(NodeType.E); 
	break; 
	case L: 
		 theRoot.setType(NodeType.E); 
			 rightChild.setType(NodeType.R); 
	break;
 }

	leftGrandchild.setType(NodeType.E);
theRoot.setRight( leftGrandchild.getLeft() ); 
rightChild.setLeft( leftGrandchild.getRight() ); 
leftGrandchild.setLeft(theRoot);
leftGrandchild.setRight(rightChild);
linkSubtree(leftGrandchild);
}

protected void simpleLeftRot(AVLBSTNode<T> theRoot, AVLBSTNode<T> leftChild) {
theRoot.setType(NodeType.E);
leftChild.setType(NodeType.E);
theRoot.setLeft( leftChild.getRight() ); 
leftChild.setRight(theRoot); 
this.linkSubtree(leftChild);
}

protected void simpleRightRot(AVLBSTNode<T> theRoot, AVLBSTNode<T> rightChild) {
theRoot.setType(NodeType.E);
rightChild.setType(NodeType.E);
theRoot.setRight( rightChild.getLeft() ); 
rightChild.setLeft(theRoot); 
this.linkSubtree(rightChild);
}
protected AVLBSTNode<T> findNode( T value)
{    

    path=new StackInLinkedList<>();
    path.push(new PathStep<>(null,false));
    BSTNode<T> node = root;
    while ( node != null )
    {
        int compResult = value.compareTo( node.getEntry() );
        if ( compResult == 0 )
            return (AVLBSTNode<T>) node;
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
protected BSTNode<T> minNode( BSTNode<T> theRoot){                                                       
        BSTNode<T> node =(BSTNode<T>) theRoot;
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
protected BSTNode<T> maxNode( BSTNode<T> theRoot){                                                       
        BSTNode<T> node =(BSTNode<T>) theRoot;
        while ( node.getRight() != null ) 
        {                      
            path.push(new PathStep<>(node,false));
            node =  node.getRight();
        }                                       
        return node;
}
@Override
public void remove( T value )
{
    AVLBSTNode<T> node = (AVLBSTNode<T>) this.findNode(value);
    if ( node == null )
        return;
    else
    {
        if ( node.getLeft() == null )
            // The left subtree is empty.
            this.linkSubtree((AVLBSTNode<T>) node.getRight());
        else if ( node.getRight() == null )
            // The right subtree is empty.
            this.linkSubtree((AVLBSTNode<T>) node.getLeft());
        else
        {
            // Node has 2 children. Replace the node's entry with
            // the 'minEntry' of the right subtree.
            path.push(new PathStep<>(node, false));
            AVLBSTNode<T> minNode = (AVLBSTNode<T>) this.minNode((AVLBSTNode<T>) node.getRight());
            node.setEntry( minNode.getEntry() );
            this.linkSubtree((AVLBSTNode<T>) minNode.getRight());
            rotateNodesRemove();
            currentSize--;
        }
    }                                 
}                                


private void rotateNodesRemove() {
		boolean shrunk= true;
		PathStep<T> lastStep=null;
		try {
			lastStep = path.pop();
		} catch (StackEmptyException e) {
		}
		AVLBSTNode<T> parent= (AVLBSTNode<T>)lastStep.parent;
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

			try {
				lastStep = path.pop();
			} catch (StackEmptyException e) {
				e.printStackTrace();
			}
			parent= (AVLBSTNode<T>)lastStep.parent;
			
		}
	
}

protected void linkSubtree( BSTNode<T> node) {
    
    try {
		if ( path.top().parent == null )
		    // Change the root of the tree.
		    root = node;
		else
			try {
				if ( path.top().isLeftChild )
				    path.top().parent.setLeft(node);
				else
				    path.top().parent.setRight(node);
			} catch (StackEmptyException e) {
			}
	} catch (StackEmptyException e) {
	}



}


}
