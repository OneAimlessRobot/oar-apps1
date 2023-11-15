
import playGround.ds.exceptions.CollectionEmptyException;
import java.io.*;
import playGround.ds.implem.*;
import playGround.auxPackage.smallAlgorithms.CollectionAlgorithms;
import java.util.Scanner;

import customClasses.IntegerPoint;
import customClasses.MapExplorer;

public class dsRunner {
	
	public static void main(String[] args) throws IOException, CollectionEmptyException {

		initFiles();
		ObjectSaverLoader<Graph<Integer>> graphload= new ObjectSaverLoader<>(FilePaths.GRAPHFILE.getValue());
		Graph<Integer> graph=null;
		MapExplorer graphmap=null;
		Scanner optionReader= new Scanner(System.in);
		
		
		
		String option=null;
		do {
			System.out.println("Queres:\nsair(sair)\ngravar(save)\nprintar(print)\ngerar(gen)\ncarregar(load)\ncarregarMapa(loadMap)\nsalvarExplorado(saveExp)\n?");
		
			option= optionReader.next();
			System.out.flush();
			switch(option) {
			case "sair":
				System.out.print("\033[H\033[2J");
				break;
			case "save":
				graphload.save(graph);
				System.out.print("\033[H\033[2J");
				break;
			case "load":
				if((graph=graphload.load())==null) {

					System.out.print("\033[H\033[2J");
					graph=new Graph<Integer>();
					System.out.println("Nova arvore carregada!!!!!!");
				}
				else {

					System.out.print("\033[H\033[2J");
				}
				break;
			case "loadMap":

				System.out.print("\033[H\033[2J");
					graphmap=new MapExplorer(FilePaths.MAPFILE.getValue(),FilePaths.EXPLOREDFILE.getValue());
//
//						graphmap=new MapExplorer(null,null);
//						System.out.println("Nova arvore carregada!!!!!!");
//					}
					break;
			case "saveExp":

				System.out.print("\033[H\033[2J");
				System.out.println("Tens 2 opçoes para explorar:\nBREADTH (largura)\nDEPTH (profundidade)\n");
				String option1=optionReader.next();
				optionReader.nextLine();
				System.out.println("Saidas encontradas:\n "+graphmap.explore(option1));
					
							break;
			case "print":
				System.out.print("\033[H\033[2JCarregado:\n");
				System.out.println(graph);
				System.out.println("Mapa:");
				System.out.println(graphmap);
				break;
			case "gen":
				if(graph!=null) {
					Graph<Integer> newGraph=CollectionAlgorithms.genGraph(1000);
					if(!newGraph.hasCycles()) {
						System.out.print("\033[H\033[2J");
						graph=newGraph;
					}
					else {
						System.out.print("\033[H\033[2J");
						System.out.println("Grafo tem ciclos seu toto!\nN obtens grafo novo so memo pq tiveste azar");
						
					}
				}
				else {
					System.out.print("\033[H\033[2J");
					System.out.println("Não carregaste nada para memoria!!!\n(Faz 'load' primeiro)\n");
					
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
