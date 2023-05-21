package playGround.aux.smallAlgorithms;

import java.io.*;
import java.util.Scanner;

import playGround.adt.Iterator;
import playGround.adt.collections.List;
import playGround.ds.*;

public class FileOperations {
	

	public static <T> void loadListIntoFile(List<T> list,String fileName){
		
		
		File file= new File(fileName);
		try {
			FileWriter fwrite= new FileWriter(file);
			Iterator<T> it= list.iterator();
			while(it.hasNext()) {
				
				fwrite.write(it.next()+ " ");
			}
			fwrite.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
		}
		
		
		
	}
	
	
	
	public static List<Integer> loadFileIntoList(String fileName){
		
		File file= new File(fileName);
		List<Integer> list= new ListInVector<>();
		try {
			FileReader fwrite= new FileReader(file);
			Scanner in= new Scanner(fwrite);
			while(in.hasNextInt()) {

				int value= in.nextInt();
				list.add(value);
			}
			fwrite.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
			list.destroy();
			return new ListInVector<>();
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
			list.destroy();
			return new ListInVector<>();
		}
		return list;
		
		
	}
}
