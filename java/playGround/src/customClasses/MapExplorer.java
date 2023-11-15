package customClasses;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.util.Scanner;

import playGround.ds.implem.DoubleLinkedList;
import playGround.ds.implem.Graph;
import playGround.ds.implem.Vector;
import playGround.ds.interfaces.Iterator;
import playGround.ds.interfaces.List;

public class MapExplorer implements Serializable {

private static class GraphTools implements Serializable {

	private static final long serialVersionUID = 1L;
	private static final char VALID='o',
							INVALID='#',
							START='S',
							EXP='X',
							GOAL='G';

public static Character[][] loadMap(String fileName){
		
		File file= new File(fileName);
		Character[][] points;
		try {
			FileReader fwrite= new FileReader(file);
			Scanner in= new Scanner(fwrite);
			int width=in.nextInt();
			int height=in.nextInt();
			points= new Character[width][height];
			List<IntegerPoint> pos= new DoubleLinkedList<>();
			in.nextLine();
			System.out.println("Width: "+width+"\nHeight: "+height);
			for(int i=0;i<width;i++) {
				
				String row= in.next();
				in.nextLine();
				for(int j=0;j<height;j++) {
					char c= row.charAt(j);
					points[i][j]=c;
				
				}
			}
			System.out.println(pos);
			fwrite.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
			return null;
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
			return null;
		}
		return points;
		
		
	}




public static List<IntegerPoint> loadValidPositions(Character[][] map, int width,int height){

	List<IntegerPoint> pos= new Vector<>();
	for(int i=0;i<width;i++) {


	for(int j=0;j<height;j++) {
		switch (map[i][j]) {
		
		case VALID:
			pos.add(new IntegerPoint(i,j));
			break;
		case INVALID:
			break;
		case GOAL:
			pos.add(new IntegerPoint(i,j));
			break;
		case START:
			pos.add(new IntegerPoint(i,j));
			break;
		default:
			break;
		
		}
		System.out.println("Vou ler a maldita linha\n");
	
	}
	}
	return pos;
}
public static IntegerPoint loadStart(Character[][] map, int width,int height){

	IntegerPoint pos=new IntegerPoint(0,0);
	for(int i=0;i<width;i++) {


	for(int j=0;j<height;j++) {
		switch (map[i][j]) {
		
		case START:
			pos=new IntegerPoint(i,j);
			break;
		default:
			break;
		
		}
		System.out.println("Vou ler a maldita linha\n");
	
	}
	}
	return pos;
}
public static List<IntegerPoint> loadGoals(Character[][] map, int width,int height){

	List<IntegerPoint> pos= new Vector<>();
	for(int i=0;i<width;i++) {


	for(int j=0;j<height;j++) {
		switch (map[i][j]) {
		
		case GOAL:
			pos.add(new IntegerPoint(i,j));
			break;
		default:
			break;
		
		}
		System.out.println("Vou ler a maldita linha\n");
	
	}
	}
	return pos;
}
public static Graph<IntegerPoint> explore(List<IntegerPoint> valid,List<IntegerPoint> goals,IntegerPoint start,int width,int height){

Graph<IntegerPoint> graph= new Graph<>(start);
Iterator<IntegerPoint> it= valid.iterator();
while(it.hasNext()) {
	IntegerPoint point= it.next();
	graph.addNode(point);
}
it= valid.iterator();
while(it.hasNext()) {
	IntegerPoint point= it.next();
	IntegerPoint explored=null;
	for(int i=point.getX()-1;i<=point.getX()+1;i++) {
		for(int j=point.getY()-1;j<=point.getY()+1;j++) {
		if(!(i<0||i>width-1||j<0||j>height-1)) {
			IntegerPoint currPoint=new IntegerPoint(i,j);
			if(valid.contains(currPoint)||goals.contains(currPoint)||currPoint.equals(start)) {
				explored=valid.get(valid.getIndex(currPoint));
				graph.addEdge(point, explored);
			}
		}
		}
		
	}
	
}
return graph;
}
public static int saveExploredBreadth(String fileName,int width,int height,Graph<IntegerPoint> explorer,List<IntegerPoint> exits){
	
	int exitsFound=0;
	File file= new File(fileName);
	List<IntegerPoint> list= new Vector<>();
	try {
		FileWriter fwrite= new FileWriter(file);
		Character[][] points= new Character[width][height];
		System.out.println("Width: "+width+"\nHeight: "+height);
		
		for(int i=0;i<width;i++) {
			
			for(int j=0;j<height;j++) {
				
				points[i][j]=INVALID;
			}
		}
		Iterator<IntegerPoint> it= explorer.breadthIterator();
		while(it.hasNext()) {
			IntegerPoint curr= it.next();
			points[curr.getX()][curr.getY()]=EXP;
			if(exits.contains(curr)) {
				exitsFound++;
			}
			printMap(points,width,height);
		}
		fwrite.write(((Integer)width).toString());
		fwrite.flush();
		fwrite.write(' ');
		fwrite.flush();
		fwrite.write(((Integer)height).toString());
		fwrite.flush();
		fwrite.write('\n');
		fwrite.flush();
		for(int i=0;i<width;i++) {
			
			for(int j=0;j<height;j++) {
				
				fwrite.write(points[i][j]);
			}
			fwrite.write('\n');
			fwrite.flush();
		}
		fwrite.close();
		return exitsFound;
	} catch (FileNotFoundException e) {
		System.out.println("Ficheiro nao encontrado!!!!\n");
		list.clear();
		return 0;
	} catch (IOException e) {

		System.out.println("Erro de escrita!!!!\n");
		list.clear ();
		return 0;
	}
	
	
}
public static int saveExploredDepth(String fileName,int width,int height,Graph<IntegerPoint> explorer,List<IntegerPoint> exits){
	
	int exitsFound=0;
	File file= new File(fileName);
	List<IntegerPoint> list= new Vector<>();
	try {
		FileWriter fwrite= new FileWriter(file);
		Character[][] points= new Character[width][height];
		System.out.println("Width: "+width+"\nHeight: "+height);
		
		for(int i=0;i<width;i++) {
			
			for(int j=0;j<height;j++) {
				
				points[i][j]=INVALID;
			}
		}
		Iterator<IntegerPoint> it= explorer.depthIterator();
		while(it.hasNext()) {
			IntegerPoint curr= it.next();
			points[curr.getX()][curr.getY()]=EXP;
			if(exits.contains(curr)) {
				exitsFound++;
			}
			printMap(points,width,height);
		}
		fwrite.write(((Integer)width).toString());
		fwrite.flush();
		fwrite.write(' ');
		fwrite.flush();
		fwrite.write(((Integer)height).toString());
		fwrite.flush();
		fwrite.write('\n');
		fwrite.flush();
		for(int i=0;i<width;i++) {
			
			for(int j=0;j<height;j++) {
				
				fwrite.write(points[i][j]);
			}
			fwrite.write('\n');
			fwrite.flush();
		}
		fwrite.close();
		return exitsFound;
	} catch (FileNotFoundException e) {
		System.out.println("Ficheiro nao encontrado!!!!\n");
		list.clear();
		return 0;
	} catch (IOException e) {

		System.out.println("Erro de escrita!!!!\n");
		list.clear ();
		return 0;
	}
	
	
}
public static void printMap(Character[][] points, int width,int height){
	
	List<IntegerPoint> list= new Vector<>();
	try {
		System.out.print('\n');
		System.out.flush();
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print('\n');
		System.out.flush();
		for(int i=0;i<width;i++) {
			
			for(int j=0;j<height;j++) {
				
				System.out.print(points[i][j]);
			}
			System.out.print('\n');
		}
		System.in.read();
		System.out.print("\033[H\033[2J");
		System.out.flush();
		
	} catch (FileNotFoundException e) {
		System.out.println("Ficheiro nao encontrado!!!!\n");
		list.clear();
	} catch (IOException e) {

		System.out.println("Erro de escrita!!!!\n");
		list.clear ();
	}
	
	
}

}
	private static final long serialVersionUID = 1L;
	
	private Graph<IntegerPoint> knowledge;
	private String inFileName,outFileName;
	private Character[][] map;
	private int width,height;
	List<IntegerPoint> positions,exits;
	IntegerPoint start;
	
	public MapExplorer(String inFileName,String outFileName) {
		
		this.inFileName=inFileName;
		this.outFileName=outFileName;
		map= GraphTools.loadMap(inFileName);
		this.height=map[0].length;
		this.width=map.length;
		this.positions= GraphTools.loadValidPositions(map, width,height);
				this.exits=GraphTools.loadGoals(map, width, height);
		this.start=GraphTools.loadStart(map, width, height);
		
		knowledge= GraphTools.explore(positions,exits,start,width,height);
		
		
		
	}
	
	public int explore(String mode) {
		int result=0;
		switch(mode) {
		case "DEPTH":
			return GraphTools.saveExploredDepth(outFileName, width, height, knowledge,exits);
		case "BREADTH":
			return GraphTools.saveExploredBreadth(outFileName, width, height, knowledge,exits);
		default:
			break;
		
		}
		return result;
	}

}
