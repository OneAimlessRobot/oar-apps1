

import auxPackage.smallAlgorithms.*;
import ds.interfaces.List;
public class SortingAlgorithmTests1 {
	private static final String PATH_TO_SA=System.getProperty("user.dir")+"/src/testStuff/stringFiles/FirstSortingResults";


	private static final String HEADER_PATH=System.getProperty("user.dir")+"/src/playGround/res/sTestHeader";
	private static final int DEFAULT_SIZE=10;

	public static <T> void main(String[] args) {

			int intValue=DEFAULT_SIZE;
	        String arg1 = "";
			if (args.length > 0) {
				arg1=args[0];
	            try {
	                intValue = Integer.parseInt(arg1); 
	                System.out.println("The captured integer value is: " + intValue);
	            } catch (NumberFormatException e) {
	                System.out.println("Invalid integer format: " + arg1);
	            }
	        } else {
	            System.out.println("No command-line arguments provided.");
	        }
			List<Integer> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randIntArrAux(99, 0,intValue));
			
			List<Integer> list2= (List<Integer>)list.copy();
			
			System.out.println("Cheguei!! Init");
			FileOperations.catFile(HEADER_PATH);

			System.out.println("Warming-up VM");

			SortingAlgorithms.myQuickSort.sort(list);
			
			System.out.println("Finished warming-up VM");
			long time1= System.nanoTime()/1000;
			SortingAlgorithms.myQuickSort.sort(list2);
			long time2=System.nanoTime()/1000;
			FileOperations.printToFile(PATH_TO_SA,intValue+","+(time2-time1)+"\n");
			

			System.out.println("Done! This is the list:"+list2);
		
	}

}
