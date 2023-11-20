package ds.implem;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Collection;
import ds.interfaces.Iterator;
import ds.interfaces.Stack;
import ds.interfaces.TwoWayIterator;

//TODO: Acrescentar variaveis que indiquem final de iteraçao e um rewind para as mudar ( e mudalas no next)
public class LinkedList<T> extends AbstractList<T>{

	private static final long serialVersionUID = 1L;
	private static class LLIterator<T> implements Iterator<T>{

		private Node<T> next,head;
		
		public LLIterator(LinkedList<T> list) {
			next=head=list.head;
			
			
			
		}
		@Override
		public T next() {
			T elem=next.getElem();
			next=next.getNext();
			return elem;
		}

		@Override
		public boolean hasNext() {
			return next!=null;
		}

		@Override
		public void rewind() {
			next=head;
			
			
		}
		
		
	}
	private static class Node<T>{
		
		private T elem;
		private Node<T> next;
		
		public Node(T elem,Node<T> next) {
			
			this.elem=elem;
			this.next=next;
			
			
		}
		
		public Node<T> getNext(){
			
			return this.next;
		}
		public void setNext(Node<T> node) {
			
			this.next=node;
		}
		
		public void setElem(T elem) {
			
			this.elem= elem;
		}
		
		public T getElem() {
			
			return this.elem;
			
		}
		public void destroy() {
			
			this.elem=null;
			this.next=null;
		}
		
		
		
		
	}
	
	private Node<T> head;
	private int length;
	//O valor da cabeça nao importa
	public LinkedList() {

		head=null;
		length=0;
		
		
		
	}
	@Override
	public boolean isEmpty() {
		return head==null;
	}
	@Override
	public void add(T elem) {
		Node<T> node=new Node<>(elem,null);
		if(isEmpty()) {
			
			head=node;
			length++;
			return;
		
		}
		else {
			addLast(node);
			length++;
		}
	}

	@Override
	public void add(T elem, int index) {
		Node<T> node=new Node<>(elem,null);
		if(isEmpty()) {
		
			head=node;
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
			Node<T> j =head;
			int i=0;
			for(;i<index;i++,j=j.getNext());
			node.setNext(j.getNext());
			j.setNext(node);
			
		}
		
		
	}
	private void addLast(Node<T> node) {
		
		if(node!=null) {
			if(isEmpty()) {
				head=node;
				return;
			}
			Node<T> j =head;
			for(;j.getNext()!=null;j=j.getNext()) {
				
			}
			j.setNext(node);
		}
		
	}
	private void addFirst(Node<T> node) {

		if(node!=null) {
		
			node.setNext(head);
			head=node;
		}
		
	}


	@Override
	public Iterator<T> iterator() {
		return new LLIterator<T>(this);
	}
	
	public int size() {
		
		return length;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return null;
	}
	
	@Override
	public void invert() {
		
		Stack<T> stck= new StackInArray<>();
		for(Node<T> i= head;i!=null;i=i.getNext()) {
			
			
			stck.push(i.getElem());
			
		}
		
		LinkedList<T> aux= new LinkedList<>();
		try {
		while(!stck.isEmpty()) {
				aux.add(stck.pop());
			
		}
		}catch (StackEmptyException e) {
			System.out.println("Stack vazia(????????)");
		}
		stck.destroy();
		this.finalize();
		this.head=aux.head;
		
		
		
	}

	@Override
	public T get(int index) {

		Node<T> j = head;
		T result=null;
		int i=0;
		if(index <=0) {
			
			result= head.getElem();
		}
		else if(index >= length-1) {
			
			for(;i<length-1;i++,j=j.getNext());
			result= j.getElem();
		}
		else {
			
			for(;i<index;i++,j=j.getNext());
			result= j.getElem();
		}
		return result;
	}
	public void finalize() {
		if(!isEmpty()) {
		Node<T> i=null;
		for(i=head;i.getNext()!=null;) {
			
			Node<T> j= i.getNext();
			i.destroy();
			i=j;
			length--;
		}
		}
	}

	private void removeLast() {

		Node<T> j = null;
		j=head;
		for(;j.getNext()!=null;j=j.getNext());
		j.destroy();
		j=null;
		
		
	}
	private void removeFirst() {
		
		Node<T> node=head.getNext();
		head.destroy();
		head=node;
		
		
	}
	private void removeMiddle(int index) {
		

		Node<T> j = null;
		int i;
		i=0;
		j=head;
		for(;i<index;i++,j=j.getNext());
		
		j.setNext(j.getNext().getNext());
		j.destroy();
		
	}
	@Override
	public void remove(int index) {
		if(isEmpty()) {
		
			return;
		
		}
		if(length==1||index <=0) {
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
	@Override
	public Collection<T> copy() {
		Collection<T> collection= new LinkedList<>();
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
		
		this.finalize();
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
	private void updateLast(T elem) {

		Node<T> j = null;
		j=head;
		for(;j.getNext()!=null;j=j.getNext());
		j.setElem(elem);
		
	}
	private void updateMiddle(T elem,int index) {

		Node<T> j = head;
		int i=0;
		for(;i<index;j=j.getNext(),i++);
		j.setElem(elem);
		
	}
	
	
	

}
