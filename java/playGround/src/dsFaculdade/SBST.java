package dsFaculdade;

import java.io.Serializable;


public class SBST<K extends Comparable<K>, V> extends BinarySearchTree<K, V> implements Dictionary<K, V>, Serializable {

	private static final long serialVersionUID = 1L;

	
	public SBST() {
		
		super();
	}
	

    @Override
    public V insert( K key, V value )
    {                                                                   
        PathStep<K,V> lastStep = new PathStep<K,V>(null, false);
        BSTNode<K,V> node = this.findNode(key, lastStep);
        if ( node == null )
        {
            BSTNode<K,V> newLeaf = new SBSTNode<K,V>(key, value);
            this.linkSubtree(newLeaf, lastStep);
            currentSize++;
            return null;   
        }                                 
        else 
        {
            V oldValue = node.getValue();
            node.setValue(value);
            return oldValue;
        }
    }


	@Override
	public V remove(K key) {
		PathStep<K,V> lastStep = new PathStep<K,V>(null, false);
        SBSTNode<K,V> node = (SBSTNode<K, V>) this.findNode(key, (PathStep<K,V>)lastStep);
        if ( node == null )
            return null;
        else
        {
            V oldValue = node.getValue();
            if ( node.getLeft() == null )
                // The left subtree is empty.
                this.linkSubtree((SBSTNode<K, V>) node.getRight(), lastStep);
            else if ( node.getRight() == null )
                // The right subtree is empty.
                this.linkSubtree((SBSTNode<K, V>) node.getLeft(), lastStep);
            else
            {
                // Node has 2 children. Replace the node's entry with
                // the 'minEntry' of the right subtree.
                lastStep.set(node, false);
                SBSTNode<K,V> minNode = (SBSTNode<K, V>) this.minNode((AVLBSTNode<K, V>) node.getRight(), lastStep);
                node.setEntry( minNode.getEntry() );
                // Remove the 'minEntry' of the right subtree.
                this.linkSubtree((SBSTNode<K, V>) minNode.getRight(), lastStep);
            }
            currentSize--;
            return oldValue;
        }   
	}
	 protected BSTNode<K,V> findNode( K key, PathStep<K,V> lastStep )
	    {      
	        BSTNode<K,V> node = root;
	        while ( node != null )
	        {
	            int compResult = key.compareTo( node.getKey() );
	            if ( compResult == 0 )
	                return node;
	            else if ( compResult < 0 )
	            {
	                lastStep.set(node, true);
	                node = node.getLeft();
	            }
	            else
	            {
	                lastStep.set(node, false);
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
	    protected BSTNode<K,V> minNode( BSTNode<K,V> theRoot, 
	        PathStep<K,V> lastStep ){                                                       
	            BSTNode<K,V> node =(BSTNode<K,V>) theRoot;
	            while ( node.getLeft() != null ) 
	            {                      
	                lastStep.set(node, true);
	                node =  node.getLeft();
	            }                                       
	            return node;
	    }

}
