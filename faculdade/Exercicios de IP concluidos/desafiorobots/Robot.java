
public class Robot {

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

	public Robot(int initX, int initY) {

		currentX=initX;
		currentY=initY;
		markedX=initX;
		markedY=initY;
		currentHeading=NORTH;
		largestDistance=0;

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
	
	public int getPIDistance() {
/*
		return(int)Math.round(Math.sqrt(Math.pow((this.getXPos()-markedX),2)+Math.pow((this.getYPos()-markedY),2)));*/
	return Math.abs(this.getXPos()-markedX)+Math.abs(this.getYPos()-markedY);
	}
	
	public void move(int distance) {


switch(currentHeading){
	case NORTH:
			currentY=currentY+distance;
			totalDistance=totalDistance+Math.abs(distance);
			if(distance>largestDistance){
				largestDistance=distance;
			}
			else{

			}
			break;
case SOUTH:
			currentY=currentY-distance;

			totalDistance=totalDistance+Math.abs(distance);
			if(distance>largestDistance){
				largestDistance=distance;
			}
			else{
				
			}
			break;
case WEST:
			currentX=currentX-distance;
			totalDistance=totalDistance+Math.abs(distance);
			if(distance>largestDistance){
				largestDistance=distance;
			}
			else{
				
			}
			break;
case EAST:
			currentX=currentX+distance;
			totalDistance=totalDistance+Math.abs(distance);
			if(distance>largestDistance){
				largestDistance=distance;
			}
			else{
				
			}
			break;
			default:
			break;
	}
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

	public int CompareDistance(Robot r1){


		if(this.getTotalDistance()>r1.getTotalDistance()){

			return 0;
		}
		else if(this.getTotalDistance()<r1.getTotalDistance()){

			return 1;
		}
		else if(this.getTotalDistance()==r1.getTotalDistance()){

			return 2;
		}
		else{

			return 3;
		}


	}
	public int DistanceBetweenBots(Robot r1){
/*
		return(int)Math.round(Math.sqrt(Math.pow((this.getXPos()-r1.getXPos()),2)+Math.pow((this.getYPos()-r1.getYPos()),2)));*/
	return Math.abs(this.getXPos()-r1.getXPos())+Math.abs(this.getYPos()-r1.getYPos());


	}
	public int getLargestDistance(){
		return largestDistance;

	}

	public int compareLargestDistance(Robot r1){

		if(this.getLargestDistance()>r1.getLargestDistance()){

			return 0;
		}
		else if(this.getLargestDistance()<r1.getLargestDistance()){

			return 1;
		}
		else {

			return 2;
		}

	}
		
}
