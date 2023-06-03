import playGround.ds.*;
import playGround.adt.collections.*;
import playGround.adt.exceptions.CollectionEmptyException;
import playGround.aux.smallAlgorithms.*;
public class Main {

	public static void main(String[] args) {
		
		List<Integer> list= new Vector<>();
		
		List<Integer> list2= new Vector<>();
		
		list.add(1);
		list.add(2);
		list.add(1);
		list.add(2);
		list.add(1);
		list2.add(1);
		list2.add(1);
		list2.add(1);
		list2.add(1);
		list2.add(1);
		try {
			FileOperations.serializeObjectList(list, System.getProperty("user.dir")+"/file");
			System.out.println(FileOperations.deserializeObjectList(System.getProperty("user.dir")+"/file"));

		} catch (CollectionEmptyException e) {
			e.printStackTrace();
		}
		ListConcatenator conc= new ListConcatenatorWithFiles();
		
		List<Integer> list3 = conc.concatenate(list, list2);
		
		
		System.out.println(list3);
		
	}

}
