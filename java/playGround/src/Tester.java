
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
		Set<AlphabeticalString> list2= new LinkedHashSet<>();
		for(int i=0;i<list.size();i++) {
			list2.add(list.get(i));
			
		}
		TwoWayIterator<AlphabeticalString> it= list2.twoWayIterator();
		while(it.hasNext()) {
			AlphabeticalString elem= it.next();
			System.out.println(elem);
		}while(it.hasPrev()) {
			AlphabeticalString elem= it.prev();
			System.out.println(elem);
		}
		list.destroy();
		list=null;
		list2.destroy();
		list2=null;
}
}