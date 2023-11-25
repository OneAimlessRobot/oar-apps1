package dsFaculdad;                                         

import java.io.Serializable;

/**
 * BST node implementation
 * 
 * @author AED team
 * @version 1.0
 *
 * @param <K> Generic type Key
 * @param <V> Generic type Value 
 */
abstract class BSTListNode<K> implements Serializable
{                                                                   

	/**
	 * Serial Version UID of the Class.
	 */
    static final long serialVersionUID = 0L;


    /**
     * Entry stored in the node.
     */
    protected K entry;                                      

    /**
     * (Pointer to) the left child.
     * 
     */
    protected BSTListNode<K> leftChild;

    /**
     * (Pointer to) the right child.
     * 
     */
    protected BSTListNode<K> rightChild;


    /**
     * Constructor for BST nodes
     * 
     * @param key to be stored in this BST tree node
     * @param value to be stored in this BST tree node
     * @param left sub-tree of this node
     * @param right sub-tree of this node
     */
    public BSTListNode( K key, BSTListNode<K> left,  BSTListNode<K> right )
    {                                                                
        entry = key;
        leftChild = left; 
        rightChild = right;                                      
    }


    /**
     * Constructor for BST nodes
     * 
     * @param key to be stored in this BST tree node
     * @param value to be stored in this BST tree node
     */
    public BSTListNode( K key )
    {    
        this(key, null, null);
    }


    /**
     * Returns the entry (key and value) of the current node.
     * 
     * @return
     */
    public K getEntry( )                           
    {
        return entry;
    }



    /**
     * Returns the left child node of the current node.
     * 
     * @return
     */
    public BSTListNode<K> getLeft( )                                     
    {    
        return leftChild;
    }


    /**
     * Returns the right child node of the current node.
     * 
     * @return
     */
    public BSTListNode<K> getRight( )                                    
    {    
        return rightChild;
    }


    /**
     * Assigns a new entry (key and value) to the current BST node
     *   
     * @param newEntry
     */
    public void setEntry( K  newEntry )
    {    
        entry = newEntry;
    }




    @Override
    public String toString() {
    	
    	return entry.toString();
    }


    /**
     * Sets the new left child node of the this node
     * 
     * @param newLeft the new left child node of the current node
     */
    public void setLeft( BSTListNode<K> newLeft )                     
    {    
        leftChild = newLeft;
    }


    /**
     * Sets the new right child node of the this node
     * 
     * @param newLeft the new right child node of the current node
     */
    public void setRight( BSTListNode<K> newRight )                   
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
