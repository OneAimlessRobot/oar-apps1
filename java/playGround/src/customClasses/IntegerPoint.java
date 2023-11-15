package customClasses;

import java.io.Serializable;

public class IntegerPoint implements Serializable {

	private static final long serialVersionUID = 1L;
	private int x,y;
	public IntegerPoint(int x, int y) {
		this.x=x;
		this.y=y;
	}
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}
	public String toString() {
		
		return "( "+x+" , "+y+" )";
	}
	public boolean equals(Object anotherPoint) {
		boolean result= false;
		if(anotherPoint instanceof IntegerPoint) {
			
			return ((IntegerPoint)anotherPoint).getX()==getX()&&((IntegerPoint)anotherPoint).getY()==getY();
		}
		return result;
	}

}
