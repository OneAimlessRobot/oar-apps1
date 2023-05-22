

import playGround.adt.TwoWayIterator;
import playGround.adt.collections.List;
import playGround.adt.collections.Set;
import playGround.aux.smallAlgorithms.*;
public class Tester {
	
	private static final String PATH ="/home/k/oar-apps1/java/playGround/src/testStuff/numberLists/mediumTree.txt";
	public static void main(String[] args) {
		
		List<Integer> list= FileOperations.loadFileIntoList(PATH);
		System.out.println(list);
		Set<Integer> set= CollectionAlgorithms.toTSet(list);
		System.out.println(set);
		TwoWayIterator<Integer> it= set.twoWayIterator();
		int i=0;
		while(i<10&&it.hasNext()) {
			
			System.out.println(it.next());
			i++;
		}
		i=0;
		System.out.println(it.hasPrev());
		while(i<100&&it.hasPrev()) {

			System.out.println(it.prev());
			i++;
			
		}
		it.close();
		set.destroy();
		list.destroy();
	
}
}
//import java.util.*;
//public class Tester {
//
//public static void main(String[] args) {
//
//	List<Integer> list= new ArrayList<>();
//
//}
//
//}