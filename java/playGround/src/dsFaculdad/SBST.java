package dsFaculdad;

import java.io.Serializable;



public class SBST<K extends Comparable<K>, V> extends BinarySearchTree<K, V> implements Dictionary<K, V>, Serializable {

	private static final long serialVersionUID = 1L;


    private PathStep<K,V> lastStep;
	
	public SBST() {
		
		super();
	}
	

    @Override
    public V insert( K key, V value )
    {                                                             
        BSTNode<K,V> node = this.findNode(key);
        if ( node == null )
        {
            BSTNode<K,V> newLeaf = new SBSTNode<K,V>(key, value);
            linkSubtree(newLeaf);
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
        SBSTNode<K,V> node = (SBSTNode<K, V>) this.findNode(key);
        if ( node == null )
            return null;
        else
        {
            V oldValue = node.getValue();
            if ( node.getLeft() == null )
                // The left subtree is empty.
                this.linkSubtree((SBSTNode<K, V>) node.getRight());
            else if ( node.getRight() == null )
                // The right subtree is empty.
                this.linkSubtree((SBSTNode<K, V>) node.getLeft());
            else
            {
                // Node has 2 children. Replace the node's entry with
                // the 'minEntry' of the right subtree.
                lastStep.set(node, false);
                SBSTNode<K,V> minNode = (SBSTNode<K, V>) this.minNode((AVLBSTNode<K, V>) node.getRight());
                node.setEntry( minNode.getEntry() );
                // Remove the 'minEntry' of the right subtree.
                this.linkSubtree((SBSTNode<K, V>) minNode.getRight());
            }
            currentSize--;
            return oldValue;
        }   
	}
	 protected BSTNode<K,V> findNode( K key )
	    {      
			lastStep = new PathStep<K,V>(null, false);
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
	    protected BSTNode<K,V> minNode( BSTNode<K,V> theRoot){                                                       
	            BSTNode<K,V> node =(BSTNode<K,V>) theRoot;
	            while ( node.getLeft() != null ) 
	            {                      
	                lastStep.set(node, true);
	                node =  node.getLeft();
	            }                                       
	            return node;
	    }
	    protected void linkSubtree( BSTNode<K,V> node ) {
	        
	        if ( lastStep.parent == null )
	            // Change the root of the tree.
	            root = node;
	        else
	            // Change a child of parent.
	            if ( lastStep.isLeftChild )
	                lastStep.parent.setLeft(node);
	            else
	                lastStep.parent.setRight(node);


	
}

}
