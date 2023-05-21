package playGround.ds;

import playGround.adt.collections.List;
import playGround.adt.exceptions.StackEmptyException;
import playGround.adt.Iterator;
import playGround.adt.Stack;
import playGround.adt.TwoWayIterator;
//TODO: Acrescentar variaveis que indiquem final de iteraçao e um rewind para as mudar ( e mudalas no next)
public class LinkedList<T> implements List<T> {

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
			return next.getNext()!=null;
		}

		@Override
		public void rewind() {
			next=head;
			
			
		}
		@Override
		public void close() {
			next=null;
			head=null;
			
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
	public String toString() {

		if(isEmpty()){
			
			return "";
		}
		String str="[ ";
		Iterator<T> it=this.iterator();
		while(it.hasNext()) {
			str+= it.next().toString()+" ";
		}
		str+="]";
		it.close();
		return str;
		
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
		this.destroy();
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