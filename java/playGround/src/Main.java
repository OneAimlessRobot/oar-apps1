import playGround.ds.*;
import playGround.adt.collections.*;
import playGround.aux.smallAlgorithms.*;
public class Main {

	public static void main(String[] args) {
		
		List<Integer> list= new Vector<>();
		
		list.add(1);
		list.add(2);
		list.add(1);
		list.add(2);
		list.add(1);
		list.clear();
		
		System.out.println(CollectionAlgorithms.listIsPalindrome(list));
		
	}

}
