package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Iterator;
import ds.interfaces.StackIterable;

public class StackInDoubleLinkedList<T> implements StackIterable<T>, Serializable {

	private static final long serialVersionUID = 1L;
	protected DoubleLinkedList<T> support;
	
	
	public StackInDoubleLinkedList() {
		
		support= new DoubleLinkedList<>();
		
		
	}
	public StackInDoubleLinkedList(T[] elems) {
		
		support= new DoubleLinkedList<>();
		
		for(int i=0;i<elems.length;i++) {
			
			this.push(elems[i]);
		}
		
		
	}
	@Override
	public boolean contains(T elem){
		
		return support.contains(elem);
		
	}
	@Override
	public void push(T elem) {
		
		support.add(elem,0);
		
		
	}

	@Override
	public T pop() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		T elem= support.get(0);
		support.remove(0);
		
		return elem;
	}

	@Override
	public T top() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		T elem= support.get(0);
		return elem;
	}

	@Override
	public boolean isEmpty() {
		return support.isEmpty();
	}

	@Override
	public int size() {
		return support.size();
	}
	public String toString() {
		

		if(isEmpty()){
			
			return "[ ]";
		}
		return support.toString();
	}

	@Override
	public void destroy() {
		try {
		while(!isEmpty()) {
			
			pop();
		}
		}catch (StackEmptyException e) {
			
			System.out.println("Stack empty????????");
		}
		
	}
	@Override
	public Iterator<T> iterator() {
		return this.support.iterator();
	}
	
	
}
