package playGround.ds;

import playGround.adt.collections.List;
import playGround.adt.exceptions.StackEmptyException;
import playGround.adt.Iterator;
import playGround.adt.Stack;
import playGround.adt.TwoWayIterator;

public class DoubleLinkedList<T> implements List<T> {

	private static class DLLIterator<T> implements TwoWayIterator<T>{

		private DoubleLinkedList<T> list;
		private Node<T> next,prev;
		
		public DLLIterator(DoubleLinkedList<T> list) {
			this.list=list;
			this.next=this.prev=this.list.head;
			
			
			
		}
		@Override
		public T next() {
			T elem=next.getElem();
			prev=next;
			next=next.getNext();
			return elem;
		}

		@Override
		public boolean hasNext() {
			return next!=null;
		}

		@Override
		public void rewind() {
			while(this.hasPrev()) {
				this.prev();
			}
			
		}
		@Override
		public T prev() {
			T elem=prev.getElem();
			next=prev;
			prev=prev.getPrev();
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
			
			return prev!=null;
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


		if(isEmpty()){
			
			return "";
		}
		String str="[ ";
		TwoWayIterator<T> it=this.twoWayIterator();
		it.fullForward();
		while(it.hasPrev()) {
			str+= it.prev().toString()+" ";
		}
		str+="]";
		return str;
		
		
	}


	@Override
	public Iterator<T> iterator() {
		return (Iterator<T>) new DLLIterator<T>(this);
	}
	
	public int size() {
		
		return length;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return new DLLIterator<T>(this);
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
		i.destroy();
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
	
	
	

}
