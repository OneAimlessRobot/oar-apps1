
import playGround.adt.collections.*;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
public class CollectionTester {
	private static final String PATH="/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/hashTableStrings.txt";

	private static final String HEADER_PATH="/home/k/oar-apps1/java/playGround/src/playGround/res/HEADER";
	private static final int DEFAULT_SIZE=200000;
	public static void main(String[] args){
		int intValue=DEFAULT_SIZE;
		if (args.length > 0) {
            String arg1 = args[0];
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
		
//		List<String> list= FileOperations.loadStrFileIntoList(PATH);
		MySet<String> set1= new MyHashSet<>();
		MySet<String> set2= new TreeSet<>();
		FileOperations.catFile(HEADER_PATH);
		
		
		long time3= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			set1.add(list.get(i));
			
		}
		
		long time4=System.nanoTime()/1000;
		long time5= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			set2.add(list.get(i));
			
		}
		long time6=System.nanoTime()/1000;
		System.out.println("Tempo de fill(HashSet): "+ (time4-time3)+" "+"Tamanho:\n"+ set1.size());
		System.out.println("Tempo de fill(TreeSet): "+ (time6-time5)+" "+"Tamanho:\n"+ set2.size());
		list.destroy();
		list=null;
		long time9= System.nanoTime()/1000;
		set1.destroy();
		list=null;
		long time10=System.nanoTime()/1000;
		long time11= System.nanoTime()/1000;
		set2.destroy();
		list=null;
		long time12=System.nanoTime()/1000;
		System.out.println("Tempo de destruição(HashSet): "+ (time10-time9)+" "+"\n");
		System.out.println("Tempo de destruição(TreeSet): "+ (time12-time11)+" "+"\n");
}
}