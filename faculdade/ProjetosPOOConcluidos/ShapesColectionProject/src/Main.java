import java.util.Scanner;

import shapes.*;

public class Main {
	private static final String ADD_CIRCLE ="CIRCLE",
			ADD_RECTANGLE ="RECTANGLE", 
	       LIST_SHAPES ="LIST", 
	       MOVE_SHAPE ="MOVE", 
	       SMALLEST="MINAREA", 
	       EXIT="EXIT";
	public static void main(String[] args) {
		Scanner in= new Scanner(System.in);
		ShapesCollection s= new ShapesCollectionClass();
		boolean quit=false;
		do {
			String option=in.next();
			quit=menu(in,s,option);
			
		}while(!quit);
		
		System.out.println("Exiting...");
		System.out.println();
		
				
	}
	private static boolean menu(Scanner in, ShapesCollection s,String option) {
		

		boolean wantsToExit=false;
		
		switch(option.toUpperCase()) {
		
    	case ADD_CIRCLE:{
			String id=in.next();
			if(s.hasShape(id)) {
				System.out.println("Identifier already exists.");
			}
			else {
			int initX=in.nextInt(),
				initY=in.nextInt(),
				radius=in.nextInt();
			in.nextLine();
			s.addCircle(id,initX,initY,radius);
			System.out.println("A new circle was added.");
			}
			break;
		}
		case ADD_RECTANGLE:{
			String id=in.next();
			if(s.hasShape(id)) {
				System.out.println("Identifier already exists.");
			}
			else {
			int initX=in.nextInt(),
				initY=in.nextInt(),
				length=in.nextInt(),
				width=in.nextInt();
			in.nextLine();
			s.addRectangle(id,initX,initY,length,width);
			System.out.println("A new rectangle was added.");
			}
			break;
		}
		case LIST_SHAPES:{
			
			if(s.isEmpty()) {
				System.out.println("Empty collection.");
			}
			else {
			Iterator it=s.allShapesIterator();
			System.out.println("All shapes in the collection:");
			while(it.hasNext()) {
				Shape r=it.next();
				System.out.println(r.getID()+ " ("+r.getCenterX()+", "+r.getCenterY()+") "+ r.getType());
				
			}
			}
			break;
			
		}
		case MOVE_SHAPE:{
			String id=in.next();
			if(s.hasShape(id)) {
			int newX=in.nextInt(),
				newY=in.nextInt();
			in.nextLine();
			s.move(id,newX,newY);
			System.out.println("Shape was moved.");
			}
			else {
			System.out.println("Identifier does not exist.");
			}
			break;
		}
		case SMALLEST:{
			if(s.isEmpty()) {
				System.out.println("Empty collection.");
			}
			else {
			Shape r= s.smallestArea();
			System.out.println(r.getID()+ " ("+r.getCenterX()+", "+r.getCenterY()+") "+ r.getType());
			}
			break;
		}
		case EXIT:{
			wantsToExit=true;
			break;
		}
		
		}
		return wantsToExit;
		
	}
}
