package playGround.aux.smallAlgorithms;

import playGround.adt.collections.List;
import playGround.adt.exceptions.CollectionEmptyException;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class ListConcatenatorWithFiles implements ListConcatenator {

	@Override
	public <T>  List<T> concatenate(List<T> l1, List<T> l2) {
		String fileName1=System.getProperty("user.dir")+"/f1";
		System.out.println(fileName1);
		List<T> list=null;
		try {
			File f1= new File(fileName1);
			FileOperations.serializeObjectList(l1, fileName1);
			FileOperations.serializeObjectList(l2, fileName1);
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

}
