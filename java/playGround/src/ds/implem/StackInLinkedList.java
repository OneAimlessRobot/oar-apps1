package ds.implem;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Iterator;
import ds.interfaces.StackIterable;

public class StackInLinkedList<T> implements StackIterable<T> {

	private LinkedList<T> support;
	private int topPos;
	
	public StackInLinkedList() {
		
		support= new LinkedList<>();
		topPos=-1;
		
		
	}
	public StackInLinkedList(T[] elems) {
		
		support= new LinkedList<>();
		topPos=-1;
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
		topPos++;
		
	}

	@Override
	public T pop() throws StackEmptyException {
		if(isEmpty()) {
			throw new StackEmptyException();
		}
		T elem= support.get(0);
		support.remove(0);
		topPos--;
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
		return topPos==-1;
	}

	@Override
	public int size() {
		return topPos+1;
	}
	public String toString() {
		

		if(isEmpty()){
			
			return "[ ]";
		}
		String str="[ ";
		for(int i=0;i<=topPos;i++) {
			
			str+= support.get(i).toString()+" ";
		}
		str+="]";
				
		return str;
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
