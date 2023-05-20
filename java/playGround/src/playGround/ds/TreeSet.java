package playGround.ds;

import playGround.adt.Iterator;
import playGround.adt.Stack;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.Set;

public class TreeSet<T extends Comparable<T>> implements Set<T>{

	private static class TreeSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{

		private TreeNode<T> root;
		private Stack<TreeNode<T>> nodes;
		public TreeSetIterator(TreeSet<T> set) {
			this.root=set.root;
			nodes=new StackInArray<>();
			
			
		}
		@Override
		public T next() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return false;
		}

		@Override
		public void rewind() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public T prev() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void fullForward() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public boolean hasPrev() {
			// TODO Auto-generated method stub
			return false;
		}
		
		
	}
	private static class TreeNode<T> {
		
		private T elem;
		private TreeNode<T> left,right;
		
		public TreeNode(T elem,TreeNode<T> left,TreeNode<T> right) {
			
			this.setElem(elem);
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

		public void setRight(TreeNode<T> newRight) {
			this.left = newRight;
		}

		public T getElem() {
			return elem;
		}

		public void setElem(T elem) {
			this.elem = elem;
		}
		
	}
	
	private TreeNode<T> root;
	private int size;
	public TreeSet() {
		
		this.root=null;
		this.size=0;
	}
	@Override
	public void add(T elem) {
		TreeNode<T> node= new TreeNode<>(elem,null,null);
		if(isEmpty()) {
			this.root=node;
			return;
		}
		addRec(elem,this.root);
		
	}
	private void addRec(T elem, TreeNode<T> aux) {
		
		if(aux==null) {
			
			aux=new TreeNode<>(elem,null,null);
		}
		else if(aux!=null&& elem.compareTo(aux.getLeft().getElem())<0) {
			addRec(elem,aux.getLeft());
		}
		else if(aux!=null&& elem.compareTo(aux.getLeft().getElem())>0) {
			addRec(elem,aux.getRight());
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
		return this.root==null;
	}
	@Override
	public TwoWayIterator<T> twoWayIterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Iterator<T> iterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public void destroy() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public boolean exists(T elem) {
		
		if(isEmpty()) {
			return false;
		}
		return existsRec(elem,root);
	}
	private boolean existsRec(T elem, TreeNode<T> aux) {
		
		if(aux==null) {
			return false;
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
}
