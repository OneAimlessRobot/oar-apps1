package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.MySortedSet;
import ds.interfaces.Stack;
import ds.interfaces.TwoWayIterator;

public class TreeSet<T extends Comparable<T>>  extends AbstractCollection<T> implements MySortedSet<T>{

	private static final long serialVersionUID = 1L;
	private static class TreeSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>,Serializable{

		private static final long serialVersionUID = 1L;
		private TreeNode<T> root;
		private Stack<TreeNode<T>> trail;
		private TreeNode<T> next,biggest,smallest;
		public TreeSetIterator(TreeNode<T> root) {

			this.root=root;
			trail=new StackInArray<>();
			fullForward();
			trail.destroy();
			rewind();
			
			
			
			
		}
		//https://www.geeksforgeeks.org/binary-tree-iterator-for-inorder-traversal/
		//mais umas cenas minhas
		@Override
		public T next() {
			try {
				next=trail.pop();
				if(next.getRight()!=null) {
					TreeNode<T> node= next.getRight();
					while(node!=null) {
						trail.push(node);
						node=node.getLeft();
						}
				}
				
				
			} catch (StackEmptyException e) {
				
			}
			return next.getElem();
			
			
		}

		@Override
		public boolean hasNext() {
			return next!=biggest;
		}

		@Override
		public void rewind() {
			rewindAux(root);
			
		}
		private void rewindAux(TreeNode<T> node) {
			while(node!=null) {
				if(node.getLeft()==null) {
				
				smallest=node;
			}
				trail.push(node);
				node=node.getLeft();
				}
			
			
		}
		@Override
		public T prev() {
			try {
				next=trail.pop();
				if(next.getLeft()!=null) {
					TreeNode<T> node= next.getLeft();
					while(node!=null) {
						trail.push(node);
						node=node.getRight();
						}
						
				}
			} catch (StackEmptyException e) {
				System.out.println("Stack vazia!!!!!!\n");
			}
			return next.getElem();
		}
		@Override
		public void fullForward() {
			fullForwardAux(root);
			
		}
		private void fullForwardAux(TreeNode<T> node) {
			while(node!=null) {
				if(node.getRight()==null) {
					
					biggest=node;
				}
			trail.push(node);
			node=node.getRight();
			}
			
		}
		@Override
		public boolean hasPrev() {
			return next!=smallest;
		}
		
	}
	private static class TreeNode<T> implements Serializable {
		
		private static final long serialVersionUID = 1L;
		private T elem;
		private TreeNode<T> left,right;
		
		public TreeNode(T elem,TreeNode<T> left,TreeNode<T> right) {
			
			setElem(elem);
			this.left=left;
			this.right=right;
			
			
		}

		public TreeNode<T> getLeft() {
			return left;
		}

		public void setLeft(TreeNode<T> newLeft) {
			this.left = newLeft;
		}
		public TreeNode<T> getRight() {
			return right;
		}
		public boolean noChildren() {
			
			return left==null && right==null;
		}
		public boolean allChildren() {
			
			return left!=null && right!=null;
		}

		public void setRight(TreeNode<T> newRight) {
			this.right = newRight;
		}

		public T getElem() {
			return elem;
		}

		public void setElem(T elem) {
			this.elem = elem;
		}
		
	}
	
	private TreeNode<T> root;
	public TreeSet() {
		
		root=null;
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
	private void addRec(T elem, TreeNode<T> aux) {
		if(aux.allChildren()) {
			
			if(elem.compareTo(aux.getElem())>0) {
				addRec(elem,aux.getRight());
			}
			else if(elem.compareTo(aux.getElem())<0) {
				addRec(elem,aux.getLeft());
			}
		}
		else if(aux.noChildren()) {
			if(elem.compareTo(aux.getElem())>0) {
				aux.setRight(new TreeNode<>(elem,null,null));
			}
			else if(elem.compareTo(aux.getElem())<0) {
				aux.setLeft(new TreeNode<>(elem,null,null));
			}
		}
		else if(aux.getRight()!=null&&aux.getLeft()==null) {
			if(elem.compareTo(aux.getElem())>0) {
				addRec(elem,aux.getRight());
			}
			else if(elem.compareTo(aux.getElem())<0) {
				aux.setLeft(new TreeNode<>(elem,null,null));
			}
			
		}
		else if(aux.getRight()==null&&aux.getLeft()!=null) {
			if(elem.compareTo(aux.getElem())<0) {
				addRec(elem,aux.getLeft());
			}
			else if(elem.compareTo(aux.getElem())>0) {
				aux.setRight(new TreeNode<>(elem,null,null));
			}
			
		}
	}
	private int sizeAux(TreeNode<T> node) {
		
		if(node==null) {
			
			return 0;
		}
		
			return 1+ sizeAux(node.getLeft())+sizeAux(node.getRight());
	
		
	}
	@Override
	public int size() {
		if(isEmpty()) {
			return 0;
		}
		return sizeAux(root);
	}
	@Override
	public boolean isEmpty() {
		return root==null;
	}
	@Override
	public TwoWayIterator<T> twoWayIterator() {
		
		return new TreeSetIterator<T>(root);
	}
	@Override
	public Iterator<T> iterator(){
		return (Iterator<T>)new TreeSetIterator<T>(root);
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
	private boolean existsRec(T elem, TreeNode<T> aux) {

		if(aux==null) {
			return false;
		}
		else if(aux==root) {
			if(aux.getElem()==null) {
				
				return false;	
			}
		}
		else if(aux.getElem().compareTo(elem)<0) {
			
			return false || existsRec(elem,aux.getLeft());
		}
		else if(aux.getElem().compareTo(elem)>0) {
			
			return false || existsRec(elem,aux.getRight());
		}
		else if(aux.getElem().compareTo(elem)==0) {
			return true;
		}
		return false;
	}

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
	public void remove(T elem) {
		// TODO Auto-generated method stub
		
	}
}
