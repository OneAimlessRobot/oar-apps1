package shapes;

public abstract class AbstractShapeClass implements Shape {
	
	protected int xPos,yPos,modelNo;
	protected String id,type;
	protected AbstractShapeClass(String id, int xPos,int yPos,int modelNo) {
		
		this.id=id;
		this.xPos=xPos;
		this.yPos=yPos;
		type="";
		this.modelNo=modelNo;
	}
	
	

	@Override
	public String getID() {
		// TODO Auto-generated method stub
		return this.id;
	}

	@Override
	public String getType() {
		// TODO Auto-generated method stub
		return type;
	}

	@Override
	public int getCenterX() {
		// TODO Auto-generated method stub
		return xPos;
	}

	@Override
	public int getCenterY() {
		// TODO Auto-generated method stub
		return yPos;
	}

	@Override
	public void move(int x, int y) {
		
		this.xPos=x;
		this.yPos=y;
		// TODO Auto-generated method stub

	}
	public int getModelNo() {
		return this.modelNo;
	}

}
