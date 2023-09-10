
public class RobotII {

	// Constants
	public static final String NORTH = "N";
	public static final String SOUTH = "S";
	public static final String EAST = "E";
	public static final String WEST = "O";
	// ...

	// Instance variables
	private int currentX, currentY;
	private String currentHeading;
	private int totalDistance;
	private int markedX, markedY;
	private int largestDistance;
	private int id;

	public RobotII(int initX, int initY,int mn) {

		currentX=initX;
		currentY=initY;
		markedX=initX;
		markedY=initY;
		currentHeading=NORTH;
		largestDistance=0;
		id=mn;

	}
	
	public int getXPos() {

		return currentX;
	}

	public int getYPos() {
		return currentY;
	}
	
	public int getTotalDistance() {
		return totalDistance;
	}
	
	
	
	public void setHeading(String heading) {

			currentHeading=heading.toUpperCase();

		
	}
	
	public void mark() {

		markedX=currentX;
		markedY=currentY;
	}
	public int getMarkedX(){

		return markedX;
	}
	public int getMarkedY(){

		return markedY;
	}
	public String GetHeading(){

		return currentHeading;
	}

	public int getLargestDistance(){
		return largestDistance;

	}
	public void setLargestDistance(int dist){

		largestDistance=dist;
		
	}
	public void setTotalDistance(int dist){

		totalDistance+=Math.abs(dist);
	}

	public int getId(){

		return id;
	}

	public void SetX(int dist){
		currentX=currentX+dist;

	}
	public void SetY(int dist){
		currentY=currentY+dist;
		
	}
		
}
