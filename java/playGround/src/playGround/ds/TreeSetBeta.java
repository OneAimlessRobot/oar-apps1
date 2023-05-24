package playGround.ds;

import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.Stack;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.Set;
import playGround.adt.exceptions.StackEmptyException;

public class TreeSetBeta<T extends Comparable<T>> implements Set<T>{

	private static class TreeSetIterator<T extends Comparable<T>> implements TwoWayIterator<T>{

		private TreeNode<T> root;
		private Stack<TreeNode<T>> trail;
		private boolean forward;
		private TreeNode<T> next,biggest,smallest;
		public TreeSetIterator(TreeNode<T> root) {
			this.root=root;
			trail=new StackInArray<>();
			init();
			
			
			
		}
		//https://www.geeksforgeeks.org/binary-tree-iterator-for-inorder-traversal/
		//mais umas cenas minhas
		@Override
		public T next() {
			try {
				if(!forward) {
					changeDirection();
					
				}
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
			forward=true;
			
			
		}
		@Override
		public T prev() {
			try {
				if(forward) {
					changeDirection();
					
				}
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
		private void init() {
			fullForward();
			trail.destroy();
			rewind();
			
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
			forward=false;
			
			
		}
		private void changeDirection() {
			
			TreeSetIterator<T> it= new TreeSetIterator<>(root);
			
			if(forward) {
				forward=false;
				it.fullForward();
				while(it.next!=this.next) {
					it.prev();
				}
				
			}
			else {
				
				forward= true;
				it.rewind();
				while(it.next!=this.next) {
					it.next();
				}
			}
			this.close();
			copyIterator(it);
			it=null;
		}
		private void copyIterator(TreeSetIterator<T> it) {
			

			this.next=it.next;
			this.smallest=it.smallest;
			this.biggest=it.biggest;
			this.root=it.root;
			this.trail=it.trail;
		}
		@Override
		public boolean hasPrev() {
			return next!=smallest;
		}
		@Override
		public void close() {
			next=null;
			trail.destroy();
			trail=null;
			root=null;
			smallest=null;
			biggest=null;
			
		}
		
		
	}
	private static class TreeNode<T> {
		
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
		public void destroy() {
			elem = null;
			left=null;
			right=null;
		}
		
	}
	
	private TreeNode<T> root;
	public TreeSetBeta() {
		
		root=null;
	}
	@Override
	public void add(T elem) {
	
		if(isEmpty()) {
			root=new TreeNode<>(elem,null,null);
		}
		else if(!exists(elem)) {
			addRec(elem,root);
		}
		
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
	public Iterator<T> iterator() {
		return (Iterator<T>)new TreeSetIterator<T>(root);
	}

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>)new TreeSetIterator<T>(root);
	}
	@Override
	public void destroy() {
		if(isEmpty()) {
			return;
		}
		if(this.size()==1) {
			root.destroy();
			return;
		}
		destroyAux(root,0);
		root.destroy();
		
	}
	//FUNCIONA!!!!!!! se meteres prints no final de cada linha de chamada recursiva, has de reparar que o tamanho desce por 1!!!!
	private void destroyAux(TreeNode<T> aux,int numOflevels) {
		

		if(aux.getLeft()!=null&&aux.getRight()==null) {
			destroyAux(aux.getLeft(),numOflevels++);
			aux.getLeft().destroy();
			aux.setLeft(null);
			aux.destroy();
		}
		if(aux.getLeft()==null&&aux.getRight()!=null) {
			destroyAux(aux.getRight(),numOflevels++);
			aux.getRight().destroy();
			aux.setRight(null);
			aux.destroy();
		}
		if(aux.allChildren()) {
			destroyAux(aux.getRight(),numOflevels++);
			destroyAux(aux.getLeft(),numOflevels++);
			aux.getLeft().destroy();
			aux.setLeft(null);
			aux.getRight().destroy();
			aux.setRight(null);
			aux.destroy();
		}
		
	}
	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}
	public String toString() {

		if(isEmpty()) {
			
			return "[ ]";
		}
		String str="[ ";
		TwoWayIterator<T> it= this.twoWayIterator();
		while(it.hasNext()) {
					
			
			
			str+= it.next().toString() + " ";
			
			
		}
		str+=" ]";
		it.close();
		return str;
	}
	private boolean exists(T elem) {
		
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
	@Override
	public Collection<T> copy() {
		Collection<T> collection= new TreeSetBeta<>();
		if(isEmpty()) {
			return collection;
		}
		Iterator<T> it= iterator();
		while(it.hasNext()) {
			
			collection.add(it.next());
		}
		return collection;
	}
}
