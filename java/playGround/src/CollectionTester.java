
import myClasses.AlphabeticalString;
import playGround.adt.collections.*;
import playGround.adt.exceptions.CollectionEmptyException;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
import java.util.HashSet;
import java.util.Set;
public class CollectionTester {
	private static final String PATH="/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/hashTableStrings.txt";

	private static final String HEADER_PATH="/home/k/oar-apps1/java/playGround/src/playGround/res/HEADER";

	public static void main(String[] args){
//		
		List<String> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randStringArrAux(10, 0, 100000));
//		
//		List<String> list= FileOperations.loadStrFileIntoList(PATH);
		MySet<String> list3= new LinkedHashSet<>();
		MySet<String> list5= new TreeSet<>();
		FileOperations.catFile(HEADER_PATH);
		long time3= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list3.add(list.get(i));
			
		}
		long time4=System.nanoTime()/1000;
		long time5= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list5.add(list.get(i));
			
		}
		long time6=System.nanoTime()/1000;
		System.out.println("Tempo de fill(HashSet): "+ (time4-time3)+" "+"\n");
		System.out.println("Tempo de fill(HashSet java): "+ (time6-time5)+" "+"\n");
		list.destroy();
		list=null;
		long time9= System.nanoTime()/1000;
		list3.destroy();
		list=null;
		long time10=System.nanoTime()/1000;
		long time11= System.nanoTime()/1000;
		list5.destroy();
		list=null;
		long time12=System.nanoTime()/1000;
		System.out.println("Tempo de destruição(HashSet): "+ (time10-time9)+" "+"\n");
		System.out.println("Tempo de destruição(HashSet java): "+ (time12-time11)+" "+"\n");
}
}