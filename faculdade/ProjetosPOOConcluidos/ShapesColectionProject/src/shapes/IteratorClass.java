package shapes;

public class IteratorClass implements Iterator {

	private Shape[] array;
	private int size,nextSlot;
	
	public IteratorClass(Shape[] array,int size) {
		this.array=array;
		this.size=size;
		nextSlot=0;
		
	}
	@Override
	public void init() {
		nextSlot=0;
		// TODO Auto-generated method stub

	}

	@Override
	public boolean hasNext() {
		
		return nextSlot<size;
	}

	@Override
	public Shape next() {
		return array[nextSlot++];
	}

}
