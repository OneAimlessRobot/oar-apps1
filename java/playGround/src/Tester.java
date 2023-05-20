import java.util.Arrays;
import java.util.Scanner;
import playGround.ds.*;
import playGround.adt.collections.List;
import playGround.adt.collections.Set;
import playGround.aux.smallAlgorithms.CollectionAlgorithms;
public class Tester {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String str = "";
		List<Integer> intVec= new ListInVector<>();
		Set<Integer> tree= new TreeSet<>();
		do {
			int value= in.nextInt();
			intVec.add(value);
			in.nextLine();

			System.out.printf("Continue? (*/N)");
			str=in.nextLine();
			
			
			
		}while(!str.equals("N"));
		System.out.println(intVec);
		in.close();
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