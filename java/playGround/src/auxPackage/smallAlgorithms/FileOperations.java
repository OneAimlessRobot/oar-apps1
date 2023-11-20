package auxPackage.smallAlgorithms;

import java.io.*;
import java.util.Scanner;

import ds.exceptions.CollectionEmptyException;
import ds.implem.Vector;
import ds.interfaces.Iterator;
import ds.interfaces.List;

public class FileOperations {
	

	public static <T> void loadListIntoFile(List<T> list,String fileName) throws CollectionEmptyException{
		
		
		File file= new File(fileName);
		try {
			FileWriter fwrite= new FileWriter(file,true);
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
	public static <T> void serializeObjectList(List<T> list,String fileName) throws CollectionEmptyException{
		
		
		File file= new File(fileName);
		try {
			Iterator<T> it= list.iterator();				
			ObjectOutputStream stream= new ObjectOutputStream(new FileOutputStream(fileName,true));

			while(it.hasNext()) {
				stream.writeObject(it.next());
			}
			stream.close();
			
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
		}
		
		
		
	}
	public static <T> List<T> deserializeObjectList(String fileName) throws CollectionEmptyException{
		
		
		File file= new File(fileName);
		List<T> list =new Vector<>();
		try {				
			ObjectInputStream stream= new ObjectInputStream(new FileInputStream(fileName));
	
			while(true) {
				
				list.add((T)stream.readObject());
				
			}
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
			return list;
		} catch (ClassNotFoundException e) {
			System.out.println("Classes incompativeis!!!!!");
		}
		return list;
		
		
		
	}
	
	
	public static void catFile(String fileName) {
		

		File file= new File(fileName);
		try {
			FileReader fwrite= new FileReader(file);
			Scanner in= new Scanner(fwrite);
			while(in.hasNext()) {

				String line= in.nextLine();
				System.out.println(line);
			}
			fwrite.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
		}
		
	}

	public static void printToFile(String fileName,String data) {
		

		File file= new File(fileName);
		try {
			FileWriter fwrite= new FileWriter(file,true);
			fwrite.append(data);
			fwrite.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");

			System.out.println();
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
		}
		
	}
	
	public static List<Integer> loadFileIntoList(String fileName){
		
		File file= new File(fileName);
		List<Integer> list= new Vector<>();
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
			list.clear();
			return new Vector<>();
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
			list.clear ();
			return new Vector<>();
		}
		return list;
		
		
	}
	

	public static List<String> loadStrFileIntoList(String fileName){
		
		File file= new File(fileName);
		List<String> list= new Vector<>();
		try {
			FileReader fwrite= new FileReader(file);
			Scanner in= new Scanner(fwrite);
			while(in.hasNext()) {

				String value= in.next();
				list.add(value);
			}
			fwrite.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("Ficheiro nao encontrado!!!!\n");
			list.clear();
			return new Vector<>();
		} catch (IOException e) {

			System.out.println("Erro de escrita!!!!\n");
			list.clear();
			return new Vector<>();
		}
		return list;
		
		
	}
}
