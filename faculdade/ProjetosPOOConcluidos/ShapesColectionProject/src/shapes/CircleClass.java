package shapes;

public class CircleClass extends AbstractShapeClass implements Shape{

	private double radius;
	
	public CircleClass(String id,int xPos,int yPos,int radius,int modelNo) {
		super(id,xPos,yPos,modelNo);
		this.radius=radius;
		this.type="CIRCLE";
		}
	public double area() {
		return this.radius*this.radius*Math.PI;
	}
}
