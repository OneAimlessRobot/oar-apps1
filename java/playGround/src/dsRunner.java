
import java.io.*;
import java.util.Scanner;

import auxPackage.smallAlgorithms.CollectionAlgorithms;
import customClasses.implem.*;
import customClasses.interfaces.MapExplorer;
import ds.exceptions.CollectionEmptyException;
import ds.exceptions.StackEmptyException;
import ds.implem.*;
import ds.interfaces.Graph;
import ds.interfaces.Iterator;

public class dsRunner {
	
	public static void main(String[] args) throws IOException, CollectionEmptyException, StackEmptyException {

		initFiles();
		ObjectSaverLoader<Graph<Integer>> graphload= new ObjectSaverLoader<>(FilePaths.GRAPHFILE.getValue());
		Graph<Integer> graph=null;
		MapExplorer graphmap=null;
		Scanner optionReader= new Scanner(System.in);
		
		
		
		String option=null;
		do {
			System.out.println("Queres:\nsair(sair)\ngravar(save)\nprintar(print)\ngerar(gen)\ngerarcomplexo(cmplxgen)\ncarregar(load)\nObter forma de arvore(treeform)\ncarregarMapa(loadMap)\nsalvarExplorado(saveExp)\nMostrar caminhos curtos(showspaths)\nVer ilhas do mapa (sislands)\nVer todos os caminhos(showpaths)\nMostrar mapa(showmap)\nIlhas do grafo normal(nislands)\n?");
		
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
					graph=new GraphClass<Integer>();
					System.out.println("Nova arvore carregada!!!!!!");
				}
				else {

					System.out.print("\033[H\033[2J");
				}
				break;
			case "loadMap":

				System.out.print("\033[H\033[2J");
					graphmap=new MapExplorerClass(FilePaths.MAPFILE2.getValue(),FilePaths.EXPLOREDFILE.getValue());

					break;
			case "showspaths":
				
				if(graphmap==null) {
					
					System.out.print("\033[H\033[2J");

					System.out.println("Tough luck. no goodies 4 u");
				}
				else {
					System.out.print("\033[H\033[2J");

					graphmap.showShortestPaths();
						
				}
					break;
			case "showmap":
				
				if(graphmap==null) {
					System.out.print("\033[H\033[2J");
					System.out.println("Tough luck. no goodies 4 u");
					
				}
				else {
					System.out.print("\033[H\033[2J");
					graphmap.showMap();
				}
					break;
			case "showpaths":
				
				if(graphmap==null) {

					System.out.print("\033[H\033[2J");
					System.out.println("Tough luck. no goodies 4 u");
					
				}
				else {
					System.out.print("\033[H\033[2J");
					graphmap.showPaths();
						
				}
					break;
			case "sislands":
				
				if(graphmap==null) {

					System.out.print("\033[H\033[2J");
					System.out.println("Tough luck. no goodies 4 u");
					
				}
				else {
					System.out.print("\033[H\033[2J");
					graphmap.showIslands();
						
				}
					break;
			case "saveExp":

				System.out.print("\033[H\033[2J");
				System.out.println("Tens 2 opçoes para explorar:\nBREADTH (largura)\nDEPTH (profundidade)\n");
				String option1=optionReader.next();
				optionReader.nextLine();
				System.out.println("Saidas encontradas:\n "+graphmap.explore(option1));
					
							break;
			case "treeform":

				System.out.print("\033[H\033[2J");
				System.out.println("Forma de Arvore do grafo normal:\n "+graph.getTreeForm().toString());
					
							break;
			case "print":
				if(graph==null||graphmap==null){
					System.exit(-1);
				}
				System.out.print("\033[H\033[2JCarregado:\n");
				System.out.println(graph.toString());
				System.out.println(graph.getTreeForm().turnIntoGraph().toString());
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
			case "cmplxgen":
				if(graph!=null) {
					Graph<Integer> newGraph=CollectionAlgorithms.genRadialGraph(4,2,3);
					graph= newGraph;
				}
				else {
					System.out.print("\033[H\033[2J");
					System.out.println("Não carregaste nada para memoria!!!\n(Faz 'load' primeiro)\n");
					
				}
				break;
			case "nislands":
				if(graph!=null) {
					
					String allIslands="[\n";
					System.out.println("Ilhas do grafo normal:\n");
					Iterator<Iterator<Integer>> it=graph.getIslands();
					while(it.hasNext()) {
						Iterator<Integer> curr= it.next();
						String thisIsland= "\n[";
						while(curr.hasNext()) {
							Integer currint=curr.next();
							
							thisIsland+=" "+currint+" ";
							
							
						}
						thisIsland+="]\n";
						allIslands+=thisIsland;
					}
					allIslands+="]\n";
					System.out.println(allIslands);
					
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
