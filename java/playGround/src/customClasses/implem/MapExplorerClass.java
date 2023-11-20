package customClasses.implem;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.util.Scanner;

import customClasses.interfaces.MapExplorer;
import ds.implem.DoubleLinkedList;
import ds.implem.GraphClass;
import ds.implem.Vector;
import ds.interfaces.Graph;
import ds.interfaces.Iterator;
import ds.interfaces.List;

public class MapExplorerClass implements Serializable, MapExplorer {

	private static final long serialVersionUID = 1L;

	private static final char VALID='O',
							INVALID='#',
							EXP='X',
							GOAL='G';
	private Graph<IntegerPoint> knowledge;
	private String outFileName;
	private Character[][] map;
	private int width,height;
	List<IntegerPoint> positions,exits;
	IntegerPoint start;
	
	public MapExplorerClass(String inFileName,String outFileName) {
		
		this.outFileName=outFileName;
		loadMap(inFileName);
		this.positions= loadValidPositions(map, width,height);
				this.exits=loadGoals(map, width, height);
		
		knowledge= explore(positions,exits,start,width,height);
		
		
		
	}
	
	@Override
	public int explore(String mode) {
		int result=0;
		switch(mode) {
		case "DEPTH":
			return saveExploredDepth(outFileName, width, height, knowledge,exits);
		case "BREADTH":
			return saveExploredBreadth(outFileName, width, height, knowledge,exits);
		default:
			break;
		
		}
		return result;
	}
	@Override
	public String printIslands() {
		
		return knowledge.getIslands().toString();
	}
	@Override
	public int getNumOfIslands() {
		
		return ListOperations.iteratorSize(knowledge.getIslands());
	}
	@Override
	public String showShortestPaths(){
		
		Iterator<IntegerPoint> it=exits.iterator();
		String result="";
		while(it.hasNext()) {
			System.out.print("\033[H\033[2J");
		
			Iterator<Iterator<IntegerPoint>> it2=knowledge.shortestPathsBetween(start, it.next());
			while(it2.hasNext()) {
				showAnimatedPath(width, height,it2.next());
					
			}	
		}
		return result;
	}
	@Override
	public String showPaths(){
		Iterator<IntegerPoint> it=exits.iterator();
		String result="";
		while(it.hasNext()) {
			System.out.print("\033[H\033[2J");
		Iterator<Iterator<IntegerPoint>> it2=knowledge.allPaths(start, it.next());
		while(it2.hasNext()) {
			showAnimatedPath(width, height,it2.next());
				
		}	
		}
		return result;
		
			
}
	@Override
	public String printExits() {
		
		return exits+"";
	}

	@Override
	public int countExits() {
		
		return exits.size();
	}
	@Override
	public int countValidPaths() {
		Iterator<IntegerPoint> it=exits.iterator();
		int result=0;
		while(it.hasNext()) {
			System.out.print("\033[H\033[2J");
		Iterator<Iterator<IntegerPoint>> it2=knowledge.allPaths(start, it.next());
		while(it2.hasNext()) {
			it2.next();
		result++;
		}
		}
	return result;	
	}

private void loadMap(String fileName){
		
		File file= new File(fileName);
		try {
			FileReader fwrite= new FileReader(file);
			Scanner in= new Scanner(fwrite);
			int width=in.nextInt();
			int height=in.nextInt();
			int startx=in.nextInt();
			int starty=in.nextInt();
			start=new IntegerPoint(startx,starty);
			map= new Character[width][height];
			in.nextLine();
			System.out.println("Width: "+width+"\nHeight: "+height);
			for(int i=0;i<width;i++) {
				
				String row= in.next();
				in.nextLine();
				for(int j=0;j<height;j++) {
					char c= row.charAt(j);
					map[i][j]=c;
				
				}
			}

			this.height=map[0].length;
			this.width=map.length;
			fwrite.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
		}
		
		
	}




private List<IntegerPoint> loadValidPositions(Character[][] map, int width,int height){

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
		default:
			break;
		
		}
	
	}
	}
	return pos;
}
private List<IntegerPoint> loadGoals(Character[][] map, int width,int height){

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
	
	}
	}
	return pos;
}
private Graph<IntegerPoint> explore(List<IntegerPoint> valid,List<IntegerPoint> goals,IntegerPoint start,int width,int height){

Graph<IntegerPoint> graph= new GraphClass<>(start);
Iterator<IntegerPoint> it= valid.iterator();
while(it.hasNext()) {
	IntegerPoint point= it.next();
	graph.addNode(point);
}
it= valid.iterator();
while(it.hasNext()) {
	IntegerPoint point= it.next();
	Iterator<IntegerPoint> it2= getValidPositionsAround(map,point).iterator();
		while(it2.hasNext()) {
			IntegerPoint explored= it2.next();
		if(valid.contains(explored)) {
			graph.addEdge(point, explored);
		}
		}
		
	
}
return graph;
}
private List<IntegerPoint> getValidPositionsAround(Character[][] map,IntegerPoint position){
	List<IntegerPoint> result=new DoubleLinkedList<>();
	int i,j;
	for(i=Math.max(position.getX()-1, 0);i<Math.min(position.getX()+2,map.length-1);i++) {
		for(j=Math.max(position.getY()-1, 0);j<Math.min(position.getY()+2,map[0].length-1);j++) {
			
				result.add(new IntegerPoint(i,j));
		
		}
		
	}
	result.remove(position);
	return result;
	
	
}
private int saveExploredBreadth(String fileName,int width,int height,Graph<IntegerPoint> explorer,List<IntegerPoint> exits){
	
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
			System.out.print("\033[H\033[2J");
			printMap(points,width,height);
			try {
				System.in.read();
			} catch (IOException e) {
			}
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
private int saveExploredDepth(String fileName,int width,int height,Graph<IntegerPoint> explorer,List<IntegerPoint> exits){
	
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
			System.out.print("\033[H\033[2J");
			printMap(points,width,height);
			System.out.println("Posicao:\nx = "+curr.getX()+"\ny = "+curr.getY());
			try {
				System.in.read();
			} catch (IOException e) {
			}
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
private void showAnimatedPath(int width,int height,Iterator<IntegerPoint> it){
	
	Character[][] points= new Character[width][height];
	System.out.println("Width: "+width+"\nHeight: "+height);
	
	for(int i=0;i<width;i++) {
		
		for(int j=0;j<height;j++) {
			
			points[i][j]=INVALID;
		}
	}
	while(it.hasNext()) {
		IntegerPoint curr= it.next();
		points[curr.getX()][curr.getY()]=EXP;
		printMap(points,width,height);
		try {
			System.in.read();
		} catch (IOException e) {
		}
	}



}
@Override
public void showIslands(){
	Iterator<Iterator<IntegerPoint>> it = knowledge.getIslands();
	Character[][] points= new Character[width][height];
	
	for(int i=0;i<width;i++) {
		
		for(int j=0;j<height;j++) {
			
			points[i][j]=INVALID;
		}
	}
	printMap(points,width,height);
	while(it.hasNext()) {
		Iterator<IntegerPoint> it2= it.next();
		while(it2.hasNext()) {
		IntegerPoint curr= it2.next();
		points[curr.getX()][curr.getY()]=EXP;
		}
		System.out.print("\033[H\033[2J");
		printMap(points,width,height);
		try {
			System.in.read();
		} catch (IOException e) {
		}
	}



}

public String toString() {
	
	String result="Posicoes:\nSaidas:\n"+exits+"\nEntrada:\n"+start+"\nValidas:\n"+positions+
			"\nMapa de posicoes validas e caminhos:\n"+knowledge+
			"\nCaracteres usados:\n"+VALID+"(validas)\n"+
			GOAL+"(saidas)\n"+
			INVALID+"(paredes)\n"+
			EXP+"(explorado)\n";
	
	return result;
	
}
@Override
public void showMap() {
	
	printMap(map,width,height);
	
}
private static void printMap(Character[][] points, int width,int height){
	
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
		System.out.flush();
	
	
}
}
