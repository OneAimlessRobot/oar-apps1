import dsFaculdade.*;

import java.io.*;
import java.util.Scanner;

import auxPackage.smallAlgorithms.CollectionAlgorithms;
import ds.exceptions.CollectionEmptyException;
import ds.interfaces.List;

public class dsRunnerDict {
	public static void main(String[] args) throws IOException, CollectionEmptyException {

		initFiles();
//		Integer[] nums= CollectionAlgorithms.orderedIntArrAux(0, -25,-2);
		ObjectSaverLoader<Dictionary<Integer,Integer>> treeload= new ObjectSaverLoader<>(FilePaths.TREEFILE.getValue());
		Dictionary<Integer,Integer> odint=null;
		Scanner optionReader= new Scanner(System.in);
		
		
		
		String option=null;
		do {
			System.out.println("Queres:\nsair(sair)\napagar(del)\ngravar(save)\nprintar(print)\ngerar(gen)\nremover(rem)\nload(load a sério)\nloadns(Carregar arvore sem ser de cena serializada)\nadicionar(add)\n?");
		
			option= optionReader.next();
			System.out.flush();
			switch(option) {
			case "sair":
				System.out.print("\033[H\033[2J");
				break;
			case "save":
				treeload.save(odint);
				System.out.print("\033[H\033[2J");
				break;
			case "gen":
				
				System.out.print("\033[H\033[2J");
				if(odint==null) {
					System.out.println("Null!!! carrega primeiro!!!");
				}
				else{
				List<Integer> lint= CollectionAlgorithms.toVList(CollectionAlgorithms.orderedIntArrAux(0,25,2));
				for(int i=0;i<lint.size();i++) {
					Integer curr= lint.get(i);
					odint.insert(curr, curr);
				}
				}
				
				
				break;
			case "load":
				if((odint=treeload.load())==null) {

					System.out.print("\033[H\033[2J");
					odint=initTree();
					System.out.println("Nova arvore carregada!!!!!!");
				}
				else {

					System.out.print("\033[H\033[2J");
				}
				break;
			case "loadns":{
				if(odint==null) {
					
					System.out.println("Fds tou farto de escrever esta merda para de carregar cenas que n existem!");
				}
				else {
				Scanner in= new Scanner(new FileInputStream(FilePaths2.GENTREEFILE.getValue()));
				while(in.hasNextInt()) {
					Integer curr= in.nextInt();
					odint.insert(curr,curr);
				}
				in.close();
				}
				
				
			
			}
				break;
			case "del":
				if(odint!=null) {
					
					odint=initTree();
				}
				deleteFiles();
				System.out.print("\033[H\033[2J");
				break;
			case "rem":
				int val=optionReader.nextInt();
				Integer removed=odint.remove(val);
				if(removed==null) {
					
					System.out.println("Nada removido! Elemento n existe!!!");
				}
				break;
			case "add":
                                val=optionReader.nextInt();
				odint.insert(val,val);
                                break;
			case "print":
				if(odint!=null) {
					System.out.print("\033[H\033[2JCarregado:\n");
//				System.out.println("Infixo:\n"+odint+"\nDepth:\n"+((AVLBST<?,?>)odint).toStringDepth()+"\nBreadth\n:"+((AVLBST<?,?>)odint).toStringBreadth());
//				System.out.println("Dicionario:\n"+odint+"\n\nTamanho: "+odint.size());
				System.out.println("\n\nTamanho: "+odint.size());
										
				}
				else {
					System.out.print("\033[H\033[2JNull!!! carrega primeiro:\n");
					
				}
				break;
			default:

				System.out.print("\033[H\033[2J");
				break;
			
			}
			
			
		}while(!option.equals("sair"));
		optionReader.close();
	}
	
	private static void initFiles() {

		for(FilePaths filepath: FilePaths.values()) {
			
			File file= new File(filepath.getValue());
			try {
				if(!file.exists()) {
				file.createNewFile();
				}
			} catch (IOException e) {
				System.out.println("Problemas em criar ficheiros novos!!!");
			}
			
		}
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
	private static Dictionary<Integer,Integer> initTree() {
		return new SepChainHashTable<>();
		
		
	}

	private static void deleteFiles() {
		
		for(FilePaths filepath: FilePaths.values()) {
			
			File file= new File(filepath.getValue());

	        if (!file.delete()) {
	            System.out.println("Problemas ao apagar este ficheiro (talvez já não exista?):\n"+filepath.getValue()+"\n");
		        
	        }
		}
		
		
		
	}
}
