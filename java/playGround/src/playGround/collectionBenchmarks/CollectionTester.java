package playGround.collectionBenchmarks;


import playGround.adt.collections.*;
import playGround.ds.*;
import playGround.auxPackage.smallAlgorithms.*;
public class CollectionTester {

	private static final String PATH_TO_DS=System.getProperty("user.dir")+"/src/testStuff/stringFiles/FirstDsResults";
	
	private static final String HEADER_PATH=System.getProperty("user.dir")+"/src/playGround/res/sTestHeader";
	

	private static final int DEFAULT_SIZE=2000;
	public static void main(String[] args){
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
		List<String> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randStringArrAux(99, 0,intValue));
		
		MySet<String> set= new MyHashSet<>();
		
		System.out.println("Cheguei!! Init");
		FileOperations.catFile(HEADER_PATH);

		System.out.println("Warming-up VM");
		for(int i=0;i<list.size();i++) {
			set.add(list.get(i));
			
		}
		System.out.println(set.size());
		set.clear();
		System.out.println(set.size());
		System.out.println("Finished warming-up VM");
		long time1= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			set.add(list.get(i));
			
		}
		long time2=System.nanoTime()/1000;	
		System.out.println(set.size());	
		FileOperations.printToFile(PATH_TO_DS,arg1+","+(time2-time1)+"\n");

		list.clear();
		list=null;
		set.clear();
		System.out.println(set.size());
		set=null;
		
	}
}
