package shapes;

public class RectangleClass extends AbstractShapeClass implements Shape {

	private double length,width;
	
	public RectangleClass(String id,int xPos,int yPos,int length,int width,int modelNo) {
		super(id,xPos,yPos,modelNo);
		this.length=length;
		this.width=width;
		this.type="RECTANGLE";
	}
	@Override
	public double area() {
		// TODO Auto-generated method stub
		return length*width;
	}

}
