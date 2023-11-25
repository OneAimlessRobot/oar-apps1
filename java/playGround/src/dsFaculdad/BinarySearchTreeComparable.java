package dsFaculdad;

import java.io.Serializable;

/**
 * BinarySearchTree implementation
 * @author AED team
 * @version 1.0
 * @param <K> Generic type Key, must extend comparable
 * @param <V> Generic type Value 
 */
public abstract class BinarySearchTreeComparable<K extends Comparable<K>, V> 
     extends BinarySearchTree<K,V> implements OrderedDictionary<K,V>, Serializable
{       
    private static final long serialVersionUID = 1L;
	protected Comparator<K> comparator;

    
    /**
     * Tree Constructor - creates an empty tree.
     */
    public BinarySearchTreeComparable(Comparator<K> comparator )                                    
    {    
    	super();
        this.comparator=comparator;
    }
    /**
     * Returns the node whose key is the specified key;
     * or null if no such node exists.        
     *                         
     * @param node where the search starts 
     * @param key to be found
     * @return the found node, when the search is successful
     */
    protected BSTNode<K,V> findNode( BSTNode<K,V> node, K key )
    {                                                                   
        if ( node == null )
            return null;
        else
        {
            int compResult = comparator.compare(key, node.getKey() );
            if ( compResult == 0 )
                return node;                                         
            else if ( compResult < 0 )
                return this.findNode(node.getLeft(), key);
            else                                                     
                return  this.findNode(node.getRight(), key); 
        }                 
    }

}

