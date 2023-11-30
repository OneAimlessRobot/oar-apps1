import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.util.Scanner;

import auxPackage.smallAlgorithms.*;
import ds.exceptions.CollectionEmptyException;
import ds.implem.DoubleLinkedList;
import ds.interfaces.List;
import dsFaculdade.FilePaths2;
public class NumberFileGenerator implements Serializable {
	
	private static final long serialVersionUID = 1L;

	public static void main(String[] args) {
		initFiles();
	Scanner in= new Scanner(System.in);
	try {
		FileWriter fwriter= new FileWriter(FilePaths2.GENTREEFILE.getValue());
		fwriter.close();
	} catch (IOException e) {
		e.printStackTrace();
	}
		menuLoop(in);
		in.close();
	}
	private static void printMenu() {
		
		System.out.println("Opçoes:\nrand n p q(n Numeros aleatorios de 'p' a 'q'\nord n p s(Numeros ordenados de n até n+(p-n)*s)\nman n (inserir n numeros aleatorios)\n");
		
	}
	private static void menuLoop(Scanner in) {
		printMenu();
		String option=in.next();
			processMenu(in,option);
		
		
	}
	private static void processMenu(Scanner in,String option) {
		List<Integer> list= new DoubleLinkedList<>();
		switch (option) {
		case "rand":
			int n=in.nextInt(),p=in.nextInt(),q=in.nextInt();
			in.nextLine();
			list= CollectionAlgorithms.toVList(CollectionAlgorithms.randIntArrAux(p, q, n));
			try {
				FileOperations.loadListIntoFile(list, FilePaths2.GENTREEFILE.getValue());
			} catch (CollectionEmptyException e) {
				System.out.println("Erro a escrever lista!!!!");
			}
			break;
		case "ord":
			int r=in.nextInt(),s=in.nextInt(),t=in.nextInt();
			list= CollectionAlgorithms.toVList(CollectionAlgorithms.orderedIntArrAux(r, s, t));
			try {
				FileOperations.loadListIntoFile(list, FilePaths2.GENTREEFILE.getValue());
			} catch (CollectionEmptyException e) {
				System.out.println("Erro a escrever lista!!!!");
			}
			break;
		case "man":
			int u=Math.abs(in.nextInt());
			int curr=0;
			in.nextLine();
			while(curr<u) {
				
				list.add(in.nextInt());
				curr++;
			}
			try {
				FileOperations.loadListIntoFile(list, FilePaths2.GENTREEFILE.getValue());
			} catch (CollectionEmptyException e) {
				System.out.println("Erro a escrever lista!!!!");
			}
			break;
		} 
		
		
	}

	private static void initFiles() {
	for(FilePaths2 filepath: FilePaths2.values()) {
		
		File file= new File(filepath.getValue());
		try {
			if(!file.exists()) {
			file.createNewFile();
			}
		} catch (IOException e) {
			System.out.println("Problemas em criar ficheiros novos!!!");
		}
		
	}
	}
	
	

}
