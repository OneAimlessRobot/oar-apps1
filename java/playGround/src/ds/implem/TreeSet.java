package ds.implem;

import java.io.Serializable;

public class TreeSet<T extends Comparable<T>>  extends BinarySearchTree<T> {

	private static final long serialVersionUID = 1L;
	private static class TreeNode<T> extends BSTNode<T> implements Serializable {
		
		private static final long serialVersionUID = 1L;
		
		public TreeNode(T elem,BSTNode<T> left,BSTNode<T> right) {
			
			super(elem,left,right);
			
			
		}

	}
	PathStep<T> lastStep;
	public TreeSet() {
		
		super();
	}
	@Override
	public void add(T elem) {
		if(isEmpty()) {
			root=new TreeNode<>(elem,null,null);
			return;
		}
		if(contains(elem)) {
			return;
		}
			addRec(elem,root);
		
	}
	private void addRec(T elem, BSTNode<T> aux) {
		if(aux.getLeft()!=null&&aux.getRight()!=null) {
			
			if(elem.compareTo(aux.getEntry())>0) {
				addRec(elem,aux.getRight());
			}
			else if(elem.compareTo(aux.getEntry())<0) {
				addRec(elem,aux.getLeft());
			}
		}
		else if(!aux.isLeaf()) {
			if(elem.compareTo(aux.getEntry())>0) {
				aux.setRight(new TreeNode<>(elem,null,null));
			}
			else if(elem.compareTo(aux.getEntry())<0) {
				aux.setLeft(new TreeNode<>(elem,null,null));
			}
		}
		else if(aux.getRight()!=null&&aux.getLeft()==null) {
			if(elem.compareTo(aux.getEntry())>0) {
				addRec(elem,aux.getRight());
			}
			else if(elem.compareTo(aux.getEntry())<0) {
				aux.setLeft(new TreeNode<>(elem,null,null));
			}
			
		}
		else if(aux.getRight()==null&&aux.getLeft()!=null) {
			if(elem.compareTo(aux.getEntry())<0) {
				addRec(elem,aux.getLeft());
			}
			else if(elem.compareTo(aux.getEntry())>0) {
				aux.setRight(new TreeNode<>(elem,null,null));
			}
			
		}
	}
	private int sizeAux(TreeNode<T> node) {
		
		if(node==null) {
			
			return 0;
		}
		
			return 1+ sizeAux((TreeNode<T>) node.getLeft())+sizeAux((TreeNode<T>) node.getRight());
	
		
	}
	@Override
	public int size() {
		if(isEmpty()) {
			return 0;
		}
		return sizeAux((TreeNode<T>) root);
	}
	@Override
	public boolean isEmpty() {
		return root==null;
	}
	@Override
	public void finalize() {
		
		root=null;
		
	}
	@Override
	public void clear() {
		finalize();
		
	}
	
	
	@Override
	public  boolean contains(T elem) {
		
		if(isEmpty()) {
			return false;
		}
		return existsRec(elem,root);
	}
	private boolean existsRec(T elem, BSTNode<T> aux) {

		if(aux==null) {
			return false;
		}
		else if(aux==root) {
			if(aux.getEntry()==null) {
				
				return false;	
			}
		}
		else if(aux.getEntry().compareTo(elem)<0) {
			
			return false || existsRec(elem,aux.getLeft());
		}
		else if(aux.getEntry().compareTo(elem)>0) {
			
			return false || existsRec(elem,aux.getRight());
		}
		else if(aux.getEntry().compareTo(elem)==0) {
			return true;
		}
		return false;
	}
	@Override
	public void remove(T value) {
        TreeNode<T> node = (TreeNode<T>) this.findNode(value);
        if ( node == null )
            return;
        else
        {
            if ( node.getLeft() == null )
                // The left subtree is empty.
                this.linkSubtree((TreeNode<T>) node.getRight());
            else if ( node.getRight() == null )
                // The right subtree is empty.
                this.linkSubtree((TreeNode<T>) node.getLeft());
            else
            {
                // Node has 2 children. Replace the node's entry with
                // the 'minEntry' of the right subtree.
                lastStep.set(node, false);
                TreeNode<T> minNode = (TreeNode<T>) this.minNode((TreeNode<T>) node.getRight());
                node.setEntry( minNode.getEntry() );
                // Remove the 'minEntry' of the right subtree.
                this.linkSubtree((TreeNode<T>) minNode.getRight());
            }
            currentSize--;
        }   
	}
	 protected BSTNode<T>findNode( T value )
	    {      
			lastStep = new PathStep<T>(null, false);
	        BSTNode<T> node = root;
	        while ( node != null )
	        {
	            int compResult = value.compareTo( node.getEntry() );
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
	    protected BSTNode<T> minNode( BSTNode<T> theRoot){                                                       
	            BSTNode<T> node =(BSTNode<T>) theRoot;
	            while ( node.getLeft() != null ) 
	            {                      
	                lastStep.set(node, true);
	                node =  node.getLeft();
	            }                                       
	            return node;
	    }
	    protected void linkSubtree( BSTNode<T> node ) {
	        
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
