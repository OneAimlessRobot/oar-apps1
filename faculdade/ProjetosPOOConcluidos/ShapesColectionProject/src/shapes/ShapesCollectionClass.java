package shapes;

public class ShapesCollectionClass implements ShapesCollection {

	private Shape[] shapes;
	private static final int STARTING_SIZE=100;
	private int usefulSize,currentSlot;
	public ShapesCollectionClass() {
		this.usefulSize=STARTING_SIZE;
		this.currentSlot=0;
		shapes =new Shape[usefulSize];
	}
	@Override
	public boolean isEmpty() {
		
		return currentSlot==0;
	}

	@Override
	public boolean hasShape(String ID) {
		boolean hasShape=false;
		for(int i=0;i<currentSlot;i++) {
			
			if(shapes[i].getID().equals(ID)){
				hasShape=true;
			}
		}
		return hasShape;
	}
	@Override
	public Shape getShapeFromID(String ID) {
		Shape r=null;
		for(int i=0;i<currentSlot;i++) {
			
			if(shapes[i].getID().equalsIgnoreCase(ID)){
				r=shapes[i];
			}
		}
		return r;
	}

	@Override
	public void addCircle(String ID, int x, int y, int radius) {
		if(!hasShape(ID)) {
			if(isFull()) {
				grow();
				this.shapes[currentSlot]=new CircleClass(ID,x,y,radius,currentSlot++);

			}
			this.shapes[currentSlot]=new CircleClass(ID,x,y,radius,currentSlot++);

		
		}

	}

	@Override
	public void addRectangle(String ID, int x, int y, int height, int width) {
		if(!hasShape(ID)) {
			if(isFull()) {
				grow();
				this.shapes[currentSlot]=new RectangleClass(ID,x,y,height,width,currentSlot++);

			}
			this.shapes[currentSlot]=new RectangleClass(ID,x,y,height,width,currentSlot++);

		
		}
	}
	private void grow() {
		Shape[] tmp= new Shape[this.usefulSize*2];
		
		for(int i=0;i<usefulSize;i++) {
			tmp[i]=this.shapes[i];
		}
		 shapes=tmp;
		 usefulSize*=2;
	}
	private boolean isFull() {
		return this.currentSlot==usefulSize;
	}

	@Override
	public void move(String ID, int x, int y) {
		
		getShapeFromID(ID).move(x, y);

	}

	@Override
	public Shape smallestArea() {
		Shape smallest=shapes[0];
		for(int i=1;i<currentSlot;i++) {
			
			if(compareShapeSizes(smallest, shapes[i])>0) {
				 smallest=shapes[i];
			}
		}
		return smallest;
		
	}

	@Override
	public Iterator allShapesIterator() {
		
		return new IteratorClass(shapes,currentSlot);
	}
	private int compareShapeSizes(Shape a,Shape b) {
		int res=0;
		if(a.area()<b.area()) {
			res=-1;
		}
		else if(a.area()>b.area()) {
				res=1;
			}
		else {

			if(a.getModelNo()>b.getModelNo()) {
				res=-1;
			}
			else if(a.getModelNo()<b.getModelNo()) {
					res=1;
				}
			
		}
		return res;
		
	}


}
