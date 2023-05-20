import java.util.Arrays;

import playGround.adt.*;
import playGround.adt.collections.List;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.CollectionAlgorithms;
public class Tester {
	
	public static void main(String[] args) {
		
		Integer[] intArr= CollectionAlgorithms.randIntArrAux(0, 1000, 1111111);
		
		long time1=System.currentTimeMillis();
		Stack<Integer> arrStck= new StackInArray<>(intArr);
		long time2=System.currentTimeMillis();
		Stack<Integer> lnkdStck= new StackInLinkedList<>(intArr);
		long time3=System.currentTimeMillis();
		System.out.printf("Tempo primeira stack: %d\nTempo segunda stack: %d\n",(time2-time1),(time3-time2));
		

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