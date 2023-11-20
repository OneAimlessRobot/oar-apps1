package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.Stack;
import ds.interfaces.TwoWayIterator;


public class DoubleLinkedList<T> extends AbstractList<T> implements Serializable {

	private static final long serialVersionUID = 1L;
	private static class DLLIterator<T> implements TwoWayIterator<T>{

		private Node<T> next;
		private int status;
		
		public DLLIterator(Node<T> initNode) {
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
			status=1;
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
			status=1;
		}
		@Override
		public boolean hasPrev() {
			
			return next!=null&&  status!=1;
		}
		
		
		
	}
	private static class Node<T> implements Serializable{
		
		private static final long serialVersionUID = 1L;
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
	int length;
	//O valor da cabeça nao importa
	public DoubleLinkedList() {
		
		
		trail=head=null;
		length=0;
		
		
		
	}
	@Override
	public boolean isEmpty() {
		return length==0;
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
		else if(index <=0) {
			
			addFirst(node);
		}
		else if(index >=length-1) {
		
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
	public void remove(int index) {
		if(isEmpty()) {
			
			return;
		
		}
		if(index <=0) {
			
			removeFirst();
		}
		else if(index >=length-1) {

			removeLast();
		}
		else {
			
			removeMiddle(index);
		
		}
		length--;
	}
private void removeLast() {
		
		Node<T> node=trail.getPrev();
		trail=node;
		
		
	}
	private void removeFirst() {
		
		Node<T> node=head.getNext();
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
	void append(DoubleLinkedList<T> doubleLinkedList) {
		if(isEmpty()) {
			this.head=doubleLinkedList.head;
		}
		else{
			this.trail.setNext(doubleLinkedList.head);
		}
		this.trail=doubleLinkedList.trail;
		this.length+=doubleLinkedList.size();
		
	}
	@Override
	public int getIndex(T elem) {
		if(isEmpty()) {
			return -1;
		}
		Node<T> node=this.head;
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
	@Override
	public boolean contains(T elem) {
		return getIndex(elem)!=-1;
	}
	@Override
	public void clear() {
		head=trail=null;
		
	}
	@Override
	public void update(T elem, int index) {
		if(isEmpty()) {
			
			return;
		
		}
		if(length==1) {
			updateFirst(elem);
		}
		else if(index <=0) {

			updateFirst(elem);
		}
		else if(index >=length) {

			updateLast(elem);
		}
		else {

			updateMiddle(elem,index);
		
		}
	}
	private void updateFirst(T elem) {
		
		head.setElem(elem);
		
		
	}
	private void updateMiddle(T elem,int index) {


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

		j.setElem(elem);
		
	}
	private void updateLast( T elem) {
		
		trail.setElem(elem);
		
	}
	
	

}
