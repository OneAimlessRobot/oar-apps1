
import playGround.adt.collections.*;
import playGround.ds.*;
public class CollectionPlayground {

	public static void main(String[] args) {
		MySet<Integer> set= new MyHashSet<>();
		set.add(5);
		set.add(5);
		set.add(5);
		set.add(5);
		set.add(5);
		set.add(5);
		set.add(5);
		set.add(5);
		System.out.println(set);
		set.remove(5);
		System.out.println(set);

	}

}
