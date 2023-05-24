
import myClasses.*;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.*;
import playGround.adt.exceptions.CollectionEmptyException;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
public class Tester {
	private static final String PATH="/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/hashTableStrings.txt";

	public static void main(String[] args) throws CollectionEmptyException {
		
		List<String> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randStringArrAux(10, 0, 10000));
		
//		List<AlphabeticalString> list= FileOperations.loadStrFileIntoList(PATH);
		Set<String> list3= new LinkedHashSet<>();
		long time3= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list3.add(list.get(i));
			
		}
		long time4=System.nanoTime()/1000;
		System.out.println("Tempo: "+ (time4-time3)+" "+"\n");
		list.destroy();
		list=null;
		list3.destroy();
		list3=null;
}
}