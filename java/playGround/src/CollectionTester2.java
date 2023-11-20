

import java.io.File;
import java.io.IOException;

import auxPackage.smallAlgorithms.*;
import ds.implem.TreeSet;
import ds.interfaces.List;
import ds.interfaces.MySet;
public class CollectionTester2 {



	private static final String PATH_TO_DS=System.getProperty("user.dir")+"/SecondDsResults";
	
	

	private static final int DEFAULT_SIZE=2000;
	
	//Teste de coleçoes
	public static void main(String[] args){
		initFiles();
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
		
		System.out.println("Warming-up VM");
		for(int i=0;i<list.size();i++) {
			set.add(list.get(i));
			
		}
		set.clear();
		System.out.println("Finished warming-up VM");
		
		long time1= System.nanoTime()/1000;
		for(int i=0;i<list.size();i++) {
			set.add(list.get(i));
			
		}
		System.out.println(set.size());
		long time2=System.nanoTime()/1000;		
		FileOperations.printToFile(PATH_TO_DS,arg1+","+(time2-time1)+"\n");
		list=null;
		set.clear();
		set=null;
	}

	private static void initFiles() {
		
			File file= new File(PATH_TO_DS);
			try {
				if(!file.exists()) {
				file.createNewFile();
				}
			} catch (IOException e) {
				System.out.println("Problemas em criar ficheiros novos!!!");
			}
		
		
		
	}
}
