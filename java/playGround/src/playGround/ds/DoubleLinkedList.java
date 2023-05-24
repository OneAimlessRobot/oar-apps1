package playGround.ds;

import playGround.adt.collections.List;
import playGround.adt.exceptions.StackEmptyException;
import playGround.adt.Collection;
import playGround.adt.InvIterator;
import playGround.adt.Iterator;
import playGround.adt.Stack;
import playGround.adt.TwoWayIterator;

public class DoubleLinkedList<T> implements List<T> {

	private static class DLLIterator<T> implements TwoWayIterator<T>{

		private Node<T> next,smallest;
		private int status;
		
		public DLLIterator(Node<T> initNode) {
			next= initNode;
			init();
			while(initNode.getNext()!=null) {
				
				initNode=initNode.getNext();
				
			}
			status=1;
			
			
			
		}
//		public void init() throws CollectionEmptyException {
//			if(smallest==null) {
//				throw new CollectionEmptyException();
//			}
//		}
		public void init(){
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
			return status!=-1;
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
			
			return status!=1;
		}
		@Override
		public void close() {
//			next.destroy();
//			next=null;
//			largest.destroy();
//			largest=null;
//			smallest.destroy();
//			smallest=null;
//			
		}
		
		
		
	}
	private static class Node<T>{
		
		private T elem;
		private Node<T> next,prev;
		
		public Node(T elem,Node<T> next,Node<T> prev) {
			
			this.elem=elem;
			this.next=next;
			
			
		}
		
		public Node<T> getNext(){
			
			return this.next;
		}
		public void setNext(Node<T> node) {
			
			this.next=node;
		}
		public Node<T> getPrev(){
			
			return this.prev;
		}
		public void setPrev(Node<T> node) {
			
			this.prev=node;
		}
		
		
		public void setElem(T elem) {
			
			this.elem= elem;
		}
		
		public T getElem() {
			
			return this.elem;
			
		}
		public void destroy() {
			
			this.elem=null;
			this.prev=null;
			this.next=null;
		}
		
		
		
		
	}
	
	private Node<T> head,trail;
	private int length;
	//O valor da cabeça nao importa
	public DoubleLinkedList() {
		
		
		trail=head=null;
		length=0;
		
		
		
	}
	@Override
	public boolean isEmpty() {
		return head==null;
	}
	@Override
	public void add(T elem) {
		Node<T> node=new Node<>(elem,null,null);
		if(isEmpty()) {
			
			head=trail=node;
			length++;
			return;
			
		}
		else {
			
			addLast(node);
		}
		length++;
	}

	@Override
	public void add(T elem, int index) {
		Node<T> node=new Node<>(elem,null,null);
		if(isEmpty()) {
		
			head=trail=node;
			length++;
			return;
		
		}
		else if(index <0) {
			
			addFirst(node);
		}
		else if(index >=length) {
		
			addLast(node);
		}
		else {
			
			addMiddle(node,index);
		
		}
		length++;
		
	}
	private void addMiddle(Node<T> node, int index) {
		
		if(node!=null) {
			Node<T> j = null;
			int i;
			if(index>length/2) {
				
				i=length-1;
				j=trail;
				for(;i>index;i--,j=j.getPrev());
					
			}
			else if(index<=length/2) {
				
				i=0;
				j=head;
				for(;i<index;i++,j=j.getNext());
					
			}
			node.setPrev(j.getPrev());
			node.setNext(j);
			j.getPrev().setNext(node);
			j.setPrev(node);
			
		}
		
		
	}
	private void addLast(Node<T> node) {
		
		if(node!=null) {
		
			node.setPrev(trail);
			trail.setNext(node);
			trail=node;
		}
		
	}
	private void addFirst(Node<T> node) {

		if(node!=null) {
		
			node.setNext(head);
			head.setPrev(node);
			head=node;
		}
		
	}
	
	public String toString() {

		if(isEmpty()) {
			

			return "[ ]";
		}
		String str="[ ";
		TwoWayIterator<T> it;
			it = this.twoWayIterator();
			while(it.hasNext()) {
				str+= it.next().toString()+" ";
			}
			str+="]";
			it.close();
		return str;
		
		
	}

	@Override
	public Iterator<T> iterator() {
		return (Iterator<T>) new DLLIterator<T>(head);
	}
	public int size() {
		
		return length;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return new DLLIterator<T>(head);
	}
	@Override
	public void invert() {
		

		Stack<T> stck= new StackInArray<>();
		for(Node<T> i= head;i!=null;i=i.getNext()) {
			
			
			stck.push(i.getElem());
			
		}
		
		DoubleLinkedList<T> aux= new DoubleLinkedList<>();
		try {
		while(!stck.isEmpty()) {
				aux.add(stck.pop());
			
		}
		}catch (StackEmptyException e) {
			System.out.println("Stack vazia(????????)");
		}
		stck.destroy();
		this.destroy();
		this.head=aux.head;
	}
	@Override
	public T get(int index) {

		Node<T> j = null;
		T result=null;
		int i;
		if(index <0) {
			
			result= head.getElem();
		}
		else if(index >= length-1) {
			
			result= trail.getElem();
		}
		else if(index>length/2) {
			
			i=length-1;
			j=trail;
			for(;i>index;i--,j=j.getPrev());
			result= j.getElem();
				
		}
		else if(index<=length/2) {
			
			i=0;
			j=head;
			for(;i<index;i++,j=j.getNext());
			result= j.getElem();
				
		}
		return result;
	}
	@Override
	public void destroy() {
		if(!isEmpty()) {
		Node<T> i=null;
		for(i=head;i.getNext()!=null;) {
			
			Node<T> j= i.getNext();
			i.destroy();
			i=j;
			length--;
		}
		head.destroy();
		head=null;
		length--;
		}
	}
	@Override
	public void remove() {
		if(isEmpty()) {
			
			return;
		}
		else {
			
			removeLast();
			
		}
		length--;
	}
	
	private void removeLast() {
		
		Node<T> node=trail.getPrev();
		trail.destroy();
		trail=node;
		
		
	}
	private void removeFirst() {
		
		Node<T> node=head.getNext();
		head.destroy();
		head=node;
		
		
	}
	private void removeMiddle(int index) {
		

		Node<T> j = null;
		int i;
		if(index>length/2) {
			
			i=length-1;
			j=trail;
			for(;i>index;i--,j=j.getPrev());
				
		}
		else if(index<=length/2) {
			
			i=0;
			j=head;
			for(;i<index;i++,j=j.getNext());
		}

		j.getNext().setPrev(j.getPrev());
		j.getPrev().setNext(j.getNext());
		j.destroy();
		
	}
	@Override
	public void remove(int index) {
		if(isEmpty()) {
		
			return;
		
		}
		else if(index <0) {
			
			removeFirst();
		}
		else if(index >=length) {

			removeLast();
		}
		else {
			
			removeMiddle(index);
		
		}
		length--;
	}

	@Override
	public InvIterator<T> backwardIterator() {
		return (InvIterator<T>) new DLLIterator<>(head);
	}

	@Override
	public Collection<T> copy() {
		Collection<T> collection= new DoubleLinkedList<>();
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
