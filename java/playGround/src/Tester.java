
import myClasses.*;
import playGround.adt.TwoWayIterator;
import playGround.adt.collections.*;
import playGround.adt.exceptions.CollectionEmptyException;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
public class Tester {
	private static final String PATH="/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/hashTableStrings.txt";

	public static void main(String[] args) throws CollectionEmptyException {
		
		List<AlphabeticalString> list= FileOperations.loadStrFileIntoList(PATH);
		
		Set<AlphabeticalString> list2= new VectorHashSet<>();
		Set<AlphabeticalString> list3= new LinkedHashSet<>();
		Set<AlphabeticalString> list4= new TreeSet<>();
		long time= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list2.add(list.get(i));
			
		}
		long time2=System.nanoTime()/1000;
		long time3= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list3.add(list.get(i));
			
		}
		long time4=System.nanoTime()/1000;
		long time5= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			list4.add(list.get(i));
			
		}
		long time6=System.nanoTime()/1000;
		System.out.println("Tempo: "+ (time2-time)+" "+"\n");
		System.out.println("Tempo: "+ (time4-time3)+" "+"\n");
		System.out.println("Tempo: "+ (time6-time5)+" "+"\n");
		System.out.println(list2);
		System.out.println(list3);
		System.out.println(list4);
		list.destroy();
		list=null;
		list2.destroy();
		list2=null;
		list3.destroy();
		list3=null;
		list4.destroy();
		list4=null;
}
}