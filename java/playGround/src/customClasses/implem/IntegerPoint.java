package customClasses.implem;

import java.io.Serializable;

import ds.implem.DoubleLinkedList;
import ds.interfaces.List;

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
	public List<IntegerPoint> neighbours(){
		
		List<IntegerPoint> result= new DoubleLinkedList<>();
		for(int i=x-1;i<=x+1;i++) {
			for(int j=y-1;j<y+1;j++) {
				
				result.add(new IntegerPoint(i,j));
			}
		}
		result.remove(new IntegerPoint(x,y));
		
		return result;
	}

}
