package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.Stack;
import ds.interfaces.TwoWayIterator;


public class HashTableBucket<T extends Comparable<T>> extends AbstractCollection<T> implements Collection<T> {

	private static final long serialVersionUID = 1L;

	private static interface BucketNode<T extends Comparable<T>>{
		
		
	}
	
		private static class BucketListNode<T extends Comparable<T>> implements BucketNode<T>,Serializable{
			
			private static final long serialVersionUID = 1L;
			private T elem;
			private BucketNode<T> next,prev;
			
			public BucketListNode(T elem,BucketListNode<T> next,BucketListNode<T> prev) {
				
				this.elem=elem;
				this.next=next;
				
				
			}
			
			public BucketListNode<T> getNext(){
				
				return (BucketListNode<T>) this.next;
			}
			public void setNext(BucketNode<T> BucketListNode) {
				
				this.next=BucketListNode;
			}
			public BucketListNode<T> getPrev(){
				
				return (BucketListNode<T>) this.prev;
			}
			public void setPrev(BucketNode<T> trail) {
				
				this.prev=trail;
			}
			
			public T getElem() {
				
				return this.elem;
				
			}
			
			
			
			
		}
	private static class BucketTreeNode<T extends Comparable<T>> implements BucketNode<T>{
		
		private T elem;
		private BucketNode<T> left,right;
		
		public BucketTreeNode(T elem,BucketNode<T> left,BucketNode<T> right) {
			
			setElem(elem);
			this.left=left;
			this.right=right;
			
			
		}

		public BucketNode<T> getLeft() {
			return left;
		}

		public void setLeft(BucketNode<T> newLeft) {
			this.left = newLeft;
		}
		public BucketNode<T> getRight() {
			return right;
		}
		public boolean noChildren() {
			
			return left==null && right==null;
		}
		public boolean allChildren() {
			
			return left!=null && right!=null;
		}

		public void setRight(BucketTreeNode<T> newRight) {
			this.right = newRight;
		}

		public T getElem() {
			return elem;
		}

		public void setElem(T elem) {
			this.elem = elem;
		}
		
	}
	private static class HashTableListBucketIterator<T extends Comparable<T>> implements TwoWayIterator<T>,Serializable{

		private static final long serialVersionUID = 1L;
		private BucketListNode<T> next;
		private int status;
		
		public HashTableListBucketIterator(BucketListNode<T> initNode,BucketListNode<T> endNode) {
			next= initNode;
			status=1;
			
			
			
		}
		@Override
		public T next() {
			if(status==1) {
				status=0;
				
			}
			T elem= next.getElem();
			if(next.getNext()==null) {
				status=-1;
			}
			else {
				next=next.getNext();
			}
			return elem;
		}

		@Override
		public boolean hasNext() {
			return next!=null&&status!=-1;
		}

		@Override
		public void rewind() {
			while(this.hasPrev()) {
				this.prev();
			}
			
		}
		@Override
		public T prev() {
			if(status==-1) {
				status=0;
				
			}
			T elem= next.getElem();
			if(next.getPrev()==null) {
				status=1;
			}
			else {
				next=next.getPrev();
			}
			return elem;
		}
		@Override
		public void fullForward() {
			while(this.hasNext()) {
				this.next();
			}
			
		}
		@Override
		public boolean hasPrev() {
			
			return next!=null&&  status!=1;
		}
		
		
	}
	private static class HashTableTreeBucketIterator<T extends Comparable<T>> implements TwoWayIterator<T>,Serializable{

		private static final long serialVersionUID = 1L;
		private BucketNode<T> root;
		private Stack<BucketNode<T>> trail;
		private BucketNode<T> next,biggest,smallest;
		public HashTableTreeBucketIterator(BucketTreeNode<T> root) {

			this.root=biggest=smallest=root;
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
				if((BucketTreeNode<T>) ((BucketTreeNode<T>) next).getRight()!=null) {
					BucketTreeNode<T> node= (BucketTreeNode<T>) ((BucketTreeNode<T>) next).getRight();
					while(node!=null) {
						trail.push(node);
						node=(BucketTreeNode<T>) ((BucketTreeNode<T>) node).getLeft();
						}
				}
				
				
			} catch (StackEmptyException e) {
				
			}
			return ((BucketTreeNode<T>) next).getElem();
			
			
		}

		@Override
		public boolean hasNext() {
			return next!=biggest;
		}

		@Override
		public void rewind() {
			rewindAux(root);
			
		}
		private void rewindAux(BucketNode<T> node) {
			while(node!=null) {
				if((BucketTreeNode<T>) ((BucketTreeNode<T>) node).getLeft()==null) {
				
				smallest=node;
			}
				trail.push(node);
				node=(BucketTreeNode<T>) ((BucketTreeNode<T>) node).getLeft();
				}
			
			
		}
		@Override
		public T prev() {
			try {
				next=trail.pop();
				if((BucketTreeNode<T>) ((BucketTreeNode<T>) next).getLeft()!=null) {
					BucketNode<T> node= (BucketTreeNode<T>) ((BucketTreeNode<T>) next).getLeft();
					while(node!=null) {
						trail.push(node);
						node=(BucketTreeNode<T>) ((BucketTreeNode<T>) node).getRight();
						}
						
				}
			} catch (StackEmptyException e) {
				System.out.println("Stack vazia!!!!!!\n");
			}
			return ((BucketTreeNode<T>) next).getElem();
		}
		@Override
		public void fullForward() {
			fullForwardAux(root);
			
		}
		private void fullForwardAux(BucketNode<T> node) {
			while(node!=null) {
				if((BucketTreeNode<T>) ((BucketTreeNode<T>) node).getRight()==null) {
					
					biggest=node;
				}
			trail.push(node);
			node=(BucketTreeNode<T>) ((BucketTreeNode<T>) node).getRight();
			}
			
		}
		@Override
		public boolean hasPrev() {
			return next!=smallest;
		}
	}
	
	
	private static class HashTableBucketIterator<T extends Comparable<T>> implements TwoWayIterator<T>,Serializable{

		private static final long serialVersionUID = 1L;
		private HashTableListBucketIterator<T> itForList;
		private HashTableTreeBucketIterator<T> itForTree;
		public HashTableBucketIterator(BucketNode<T> startList,BucketNode<T> endList,BucketNode<T> root) {

			itForList= new HashTableListBucketIterator<>((BucketListNode<T>)startList,(BucketListNode<T>) endList);
			
			itForTree=new HashTableTreeBucketIterator<>((BucketTreeNode<T>)root);
			rewind();
			
			
			
		}
		//https://www.geeksforgeeks.org/binary-tree-iterator-for-inorder-traversal/
		//mais umas cenas minhas
		@Override
		public T next() {
			if(itForList.hasNext()) {
				
				return itForList.next();
			}
			else {
				return itForTree.next();
				
			}
			
			
		}

		@Override
		public boolean hasNext() {
			return itForList.hasNext()||itForTree.hasNext();
		}

		@Override
		public void rewind() {
			itForList.rewind();
			itForTree.rewind();
		}
		@Override
		public T prev() {
			if(itForTree.hasPrev()) {
				
				return itForTree.prev();
			}
			else {
				return itForList.next();
				
			}
		}
		@Override
		public boolean hasPrev() {
			return itForList.hasPrev()||itForTree.hasPrev();
		}
		@Override
		public void fullForward() {
			itForList.fullForward();
			itForTree.fullForward();
			
		}
	}
	
	private BucketNode<T> head,trail,root;
	private int currSize,currListSize,treefylimit;
	private boolean treeMode;
	public HashTableBucket(int treefylimit) {
		clear();
		this.treefylimit=treefylimit;
		
		
	}
	private void addLast(BucketListNode<T> node) {
		
		if(node!=null) {
		
			node.setPrev(trail);
			((BucketListNode<T>)trail).setNext((BucketNode<T>)node);
			trail=node;
		}
		
	}
	@Override
	public void add(T elem) {
		
		BucketNode<T> node=new BucketListNode<>(elem,null,null);
		if(isEmpty()) {
			trail=head=node;
		}
		else if(!treeMode) {
			if( currSize ==treefylimit) {
				
				treefy(elem);
			}
			else {
			addLast((BucketListNode<T>)node);
			currListSize++;
			}
		}
		else {
			
			addRec(elem,(BucketTreeNode<T>)root);
		}
		currSize++;
		
	}

	private void addRec(T elem, BucketTreeNode<T> aux) {
		if(aux.allChildren()) {
			
			if(elem.compareTo(aux.getElem())>0) {
				addRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getRight());
			}
			else if(elem.compareTo(((BucketTreeNode<T>) aux).getElem())<0) {
				addRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getLeft());
			}
		}
		else if(aux.noChildren()) {
			if(elem.compareTo(aux.getElem())>0) {
				aux.setRight(new BucketTreeNode<>(elem,null,null));
			}
			else if(elem.compareTo(aux.getElem())<0) {
				aux.setLeft(new BucketTreeNode<>(elem,null,null));
			}
		}
		else if(aux.getRight()!=null&&aux.getLeft()==null) {
			if(elem.compareTo(aux.getElem())>0) {
				addRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getRight());
			}
			else if(elem.compareTo(aux.getElem())<0) {
				aux.setLeft(new BucketTreeNode<>(elem,null,null));
			}
			
		}
		else if(aux.getRight()==null&&aux.getLeft()!=null) {
			if(elem.compareTo(aux.getElem())<0) {
				addRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getLeft());
			}
			else if(elem.compareTo(aux.getElem())>0) {
				aux.setRight(new BucketTreeNode<>(elem,null,null));
			}
			
		}
	}
	private void treefy(T elem) {
		
		treeMode=true;
		root= new BucketTreeNode<>(elem,null,null);
		
		
	}

	@Override
	public Collection<T> copy() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void clear() {
		root=trail=head=null;
		currSize=0;
		currListSize=0;
		treeMode=false;
	}

	private BucketTreeNode<T> existsRec(T elem, BucketNode<T> aux) {

		if(aux==null) {
			return null;
		}
		else if(aux==root) {
			if(((BucketTreeNode<T>) aux).getElem()==null) {
				
				return null;	
			}
		}
		else if( ((BucketTreeNode<T>) aux).getElem().compareTo(elem)<0) {
			
			return  existsRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getLeft());
		}
		else if(((BucketTreeNode<T>) aux).getElem().compareTo(elem)>0) {
			
			return  existsRec(elem,(BucketTreeNode<T>) ((BucketTreeNode<T>) aux).getRight());
		}
		else if(((BucketTreeNode<T>) aux).getElem().compareTo(elem)==0) {
			return (BucketTreeNode<T>) aux;
		}
		return null;
	}
	@Override
	public boolean contains(T elem) {
		if(isEmpty()) {
			return false;
		}
		BucketNode<T> node=this.head;
		while(node!=null) {
			if((((BucketListNode<T>) node).getElem().equals(elem))){
			
				break;
			}
			else {
				node=(BucketListNode<T>) ((BucketListNode<T>) node).getNext();
				
			}
		}
		if(node==null) {
			if(!treeMode) {
				return false;
			}
			else {
				return (existsRec(elem, (BucketTreeNode<T>)root))!=null;
			}
		}
		return true;
	}

	@Override
	public void remove(T elem) {
		if(!treeMode) {
			removeList(getIndex(elem));
			
			
		}
		else {
			removeTree(existsRec(elem,root));
			currSize--;
			
		}

	}
	
	private void removeTree(BucketTreeNode<T> node) {
		T storedInRoot=null;
		BucketTreeNode<T> original =node;
		if(node.getLeft()!=null) {
			
			BucketTreeNode<T> leftone=node=(BucketTreeNode<T>) node.getLeft();
			node=maxNodeRec(node);
			storedInRoot=node.getElem();
			original.setElem(storedInRoot);
			while(leftone.getRight()!=node) {
				
				leftone=(BucketTreeNode<T>) leftone.getRight();
			}
			leftone.setRight(null);
			return;
		}
		else if(node.getRight()!=null) {
			
			BucketTreeNode<T> rightone=node=(BucketTreeNode<T>) node.getRight();
			node=minNodeRec(node);
			storedInRoot=node.getElem();
			original.setElem(storedInRoot);
			while(rightone.getLeft()!=node) {
				
				rightone=(BucketTreeNode<T>) rightone.getLeft();
			}
			rightone.setLeft(null);
		}
		else {
			node=null;
		}
		
		
		
	}
	private BucketTreeNode<T> maxNodeRec( BucketTreeNode<T> node )
    {                                                                   
        if ( node.getRight() == null )                            
            return node;                                             
        else                                                     
            return this.maxNodeRec( (BucketTreeNode<T>) node.getRight() );                       
    }                               

    private BucketTreeNode<T> minNodeRec( BucketTreeNode<T> node )
	   {                                                                   
	       if ( node.getRight() == null )                            
	           return node;                                             
	       else                                                     
	           return this.minNodeRec( (BucketTreeNode<T>) node.getLeft() );                       
	   }   
	private void removeList(int index) {
		if(isEmpty()) {
			
			return;
		
		}
		if(index <=0) {
			
			removeListFirst();
		}
		else if(index >=currListSize-1) {

			removeListLast();
		}
		else {
			
			removeListMiddle(index);
		
		}
		currSize--;
		currListSize--;
	}

	private int getIndex(T elem) {
		if(isEmpty()) {
			return -1;
		}
		BucketListNode<T> node=(BucketListNode<T>)head;
		int i=0;
		while(node!=null&&!node.getElem().equals(elem)) {
			node=node.getNext();
			i++;
			}
		if(node==null) {
			return -1;
		}
		return i;
	}
private void removeListLast() {
		
	BucketListNode<T> node=((BucketListNode<T>)trail).getPrev();
		trail=node;
		
		
	}
	private void removeListFirst() {
		
		BucketListNode<T> node=((BucketListNode<T>)head).getNext();
		head=node;
		
		
	}
	private void removeListMiddle(int index) {
		

		BucketListNode<T> j = null;
		int i;
		if(index>currListSize/2) {
			
			i=currListSize-1;
			j=(BucketListNode<T>) trail;
			for(;i>index;i--,j=j.getPrev());
				
		}
		else if(index<=currListSize/2) {
			
			i=0;
			j=(BucketListNode<T>) head;
			for(;i<index;i++,j=j.getNext());
		}

		j.getNext().setPrev(j.getPrev());
		j.getPrev().setNext(j.getNext());
		
	}


	@Override
	public int size() {
		TwoWayIterator<T> it= twoWayIterator();
		int counter=0;
		while(it.hasNext()) {
			
			counter++;
			it.next();
			
			
		}
		return counter;
		
		//		return currSize;
	}

	@Override
	public boolean isEmpty() {
		return size()==0;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return new HashTableBucketIterator<>(head,trail,root);
	}

	@Override
	public Iterator<T> iterator() {
		return (Iterator<T>)new HashTableBucketIterator<>(head,trail,root);
	}


}
