package auxPackage.smallAlgorithms;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import ds.exceptions.CollectionEmptyException;
import ds.interfaces.Iterator;
import ds.interfaces.List;

public class ListConcatenatorWithFiles implements ListConcatenator {

	@Override
	public <T>  List<T> concatenate(List<T> l1, List<T> l2) {
		String fileName1=System.getProperty("user.dir")+"/f1";
		List<T> list=null;
		try {
			Iterator<T> it= l1.iterator(),it2=l2.iterator();
			ObjectOutputStream stream= new ObjectOutputStream(new FileOutputStream(fileName1,true));

			while(it.hasNext()) {
				stream.writeObject(it.next());
			}
			while(it2.hasNext()) {
				stream.writeObject(it2.next());
			}
			stream.close();
			list =FileOperations.deserializeObjectList(fileName1);
			Path path1 =Paths.get(fileName1);
		Files.delete(path1);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		catch (CollectionEmptyException e) {
			e.printStackTrace();
		}
		
		return list;
		
		
	}
	public  List<Integer> concatenateInts(List<Integer> l1, List<Integer> l2) {
		String fileName1=System.getProperty("user.dir")+"/f1";
		System.out.println(fileName1);
		List<Integer> list=null;
		try {
			File f1= new File(fileName1);
			FileOperations.loadListIntoFile(l1, fileName1);
			FileOperations.loadListIntoFile(l2, fileName1);
			list =FileOperations.loadFileIntoList(fileName1);
			Path path1 =Paths.get(fileName1);
		Files.delete(path1);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		catch (CollectionEmptyException e) {
			e.printStackTrace();
		}
		
		return list;
		
		
	}
}
