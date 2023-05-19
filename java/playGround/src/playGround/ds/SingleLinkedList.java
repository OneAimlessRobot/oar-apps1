package playGround.ds;

import playGround.adt.collections.List;
import playGround.adt.Iterator;
import playGround.adt.TwoWayIterator;

public class SingleLinkedList<T> implements List<T> {

	private static class SLLIterator<T> implements Iterator<T>{

		private SingleLinkedList<T> list;
		private Node<T> next;
		
		public SLLIterator(SingleLinkedList<T> list) {
			this.list=list;
			this.next=this.list.head.getNext();
			
			
			
		}
		@Override
		public T next() {
			T elem=null;
			if(!hasNext()) {
				return elem;
				
			}
			else {
				elem=next.getElem();
				next=next.getNext();
				return elem;
			}
		}

		@Override
		public boolean hasNext() {
			return next!=null;
		}

		@Override
		public void rewind() {
			next=list.head;
			
			
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
		
		
		
		
	}
	
	private Node<T> head;
	private int length;
	//O valor da cabeça nao importa
	public SingleLinkedList() {
		
		head= new Node<>(null,null);
		length=0;
		
		
		
	}
	@Override
	public boolean isEmpty() {
		return head.getNext()==null;
	}
	@Override
	public void add(T elem) {
		Node<T> node=new Node<>(elem,null),i;
		for(i=this.head;i.getNext()!=null;i=i.getNext());
		i.setNext(node);
		length++;
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
		return str;
		
	}


	@Override
	public Iterator<T> iterator() {
		return new SLLIterator<T>(this);
	}
	
	public int size() {
		
		return length;
	}

	@Override
	public TwoWayIterator<T> twoWayIterator() {
		return (TwoWayIterator<T>) new SLLIterator<T>(this);
	}
	
	

}
