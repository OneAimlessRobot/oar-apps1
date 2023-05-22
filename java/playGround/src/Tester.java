
import java.util.Arrays;

import playGround.adt.collections.*;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
public class Tester {
	private static final String PATH="/home/k/oar-apps1/java/playGround/src/testStuff/numberLists/numList1.txt";

	public static void main(String[] args) {
		List<Integer> list= FileOperations.loadFileIntoList(PATH);
		Set<Integer> list2= new LinkedHashSet<>();
		for(int i=0;i<list.size();i++) {
			list2.add(list.get(i));
			
		}
		System.out.println(list2);
		System.out.println(list);
		list.destroy();
		list=null;
		list2.destroy();
		list2=null;
}
}