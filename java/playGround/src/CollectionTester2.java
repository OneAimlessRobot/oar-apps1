
import playGround.adt.collections.*;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.*;
public class CollectionTester2 {


	private static final String PATH_TO_DS="/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/SecondDsResults";

	private static final String HEADER_PATH="/home/k/oar-apps1/java/playGround/src/playGround/res/HEADER";
	private static final int DEFAULT_SIZE=2000;
	
	//Teste de coleçoes
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
		
		MySet<String> set= new TreeSet<>();
		System.out.println("Cheguei!! Init");
		FileOperations.catFile(HEADER_PATH);
		long time1= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			set.add(list.get(i));
			
		}
		long time2=System.nanoTime()/1000;		
		FileOperations.printToFile(PATH_TO_DS,arg1+","+(time2-time1)+"\n");
		list.destroy();
		list=null;
		set.destroy();
		set=null;
	}
}