package ds.implem;

import java.io.Serializable;

import ds.exceptions.StackEmptyException;
import ds.interfaces.Bias;
import ds.interfaces.DEStack;
import ds.interfaces.Iterator;
public class BiasInDoubleLinkedList<T extends Comparable<T>> implements Bias<T>, Serializable {

	private static final long serialVersionUID = 1L;
	
	private DEStack<T> support;
	private int size,bias;
	private T fulcrum;
	public BiasInDoubleLinkedList(T fulcrum) {
		
		support= new DEStackInDoubleList<>();
		bias=0;
		size=0;
		this.fulcrum=fulcrum;
	}
	@Override
	public int getBias() {
		return bias;
	}

	@Override
	public void insert(T elem) {
		if(!support.contains(elem)) {
			if(fulcrum.compareTo(elem)>0) {
				
				support.push(elem);
				bias++;
			}
			else if(fulcrum.compareTo(elem)<0) {
				
				support.pushBack(elem);
				bias--;
			}
			
		size++;
		}
		
	}

	@Override
	public void remove(T elem) throws StackEmptyException {
		if(!isEmpty()) {
			if(fulcrum.compareTo(elem)>0) {
				
				support.popBack();
				bias--;
			}
			else if(fulcrum.compareTo(elem)<0) {
				
				support.pop();
				bias++;
			}
		}
		size--;
		
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public Iterator<T> iterator() {
		return support.iterator();
	}
	
	@Override
	public boolean isEmpty() {
		
		return size==0;
	}
	@Override
	public boolean isBalanced() {
		return bias==0;
	}
	@Override
	public void balance() {
		//TODO: ??????
	}
	

}
