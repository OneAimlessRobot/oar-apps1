package auxPackage.smallAlgorithms;
import auxPackage.numeric.*;
import ds.exceptions.CollectionEmptyException;
import ds.exceptions.StackEmptyException;
import ds.implem.DoubleLinkedList;
import ds.implem.GraphClass;
import ds.implem.LinkedList;
import ds.implem.StackInLinkedList;
import ds.implem.TreeSet;
import ds.implem.Vector;
import ds.interfaces.Graph;
import ds.interfaces.Iterator;
import ds.interfaces.List;
import ds.interfaces.MySet;
import ds.interfaces.Stack;
public class CollectionAlgorithms {

	public static Integer[] orderedIntArrAux(int min,int size,int step) {
		Integer[] arr= new Integer[size];
		int j=0,i=0;
		for(;i<arr.length;j+=step,i++) {
			
			arr[i]=min+j;
			
		}
		return arr;
		
		
	}
	public static Integer[] randIntArrAux(int max,int min,int size) {
		Integer[] arr= new Integer[size];
		for(int i=0;i<arr.length;i++) {
			
			arr[i]=AuxNumeric.boundedRandNum(max, min);
			
		}
		return arr;
		
		
	}

	public static Graph<Integer> genGraph(int size) throws CollectionEmptyException{
		List<Integer> list=CollectionAlgorithms.toDList(randIntArrAux(0,25,10));
		Graph<Integer> graph=new GraphClass<>(list.get(0));
		for(int i=1;i<list.size();i++) {
			
			graph.addNode(list.get(i));
		}
 		while(true) {
			if(list.isEmpty()) {
				System.out.println("Vazio!!!\n");
				break;
			}
			int first=((List<Integer>)list).get(0);
			
			((List<Integer>)list).remove((int)(0));

			if(list.isEmpty()) {
				break;
			}
			int second=((List<Integer>)list).get(0);
			graph.addEdge(first, second);
		}
		return graph;
		}
	public static Graph<Integer> genRadialGraph(int upperDegree,int lowerDegree,int numLayers) throws CollectionEmptyException{
		int currStart=AuxNumeric.boundedRandNum(0, 10000);
		Graph<Integer> graph=new GraphClass<>(currStart);
		genRadialGraphExpand(graph,currStart,upperDegree,lowerDegree,numLayers);
		return graph;
		}
	private static void genRadialGraphExpand(Graph<Integer> graph,int currStart,int upperDegree,int lowerDegree,int numLayers) throws CollectionEmptyException{
			if(numLayers==0) {
				
				return;
			}
			graph.addNode(currStart);
			List<Integer> list=CollectionAlgorithms.toDList(randIntArrAux(0,1000,AuxNumeric.boundedRandNum(lowerDegree, upperDegree)));
			for(int j=0;j<list.size();j++) {
				
				graph.addNode(list.get(j));
			}
	 		while(true) {
				if(list.isEmpty()) {
					System.out.println("Vazio!!!\n");
					break;
				}
				int first=((List<Integer>)list).get(0);
				
				((List<Integer>)list).remove((int)(0));

				if(list.isEmpty()) {
					break;
				}
				graph.addEdge(currStart, first);
				graph.addEdge( first,currStart);
				genRadialGraphExpand(graph,first,upperDegree,lowerDegree,numLayers-1);
			}
			}
	

	public static String[] randStringArrAux(int minSize,int maxSize,int size) {
		String[] arr= new String[size];
		for(int i=0;i<arr.length;i++) {
			
			arr[i]=AuxNumeric.randString(AuxNumeric.boundedRandNum(minSize,maxSize));
			
		}
		return arr;
		
		
	}
	
	public static int sumArr(Integer[] arr,int pos) {
		
		if(pos>=arr.length-1) {
			
			return arr[arr.length-1];
		}
		else {
			
			return sumArr(arr,pos-1)+ arr[pos];
		}
		
		
	}
	public static <T> List<T> toList(T[] arr){
		
		List<T> list=new LinkedList<>();

		for(int i=0;i<arr.length;i++) {
			
			list.add(arr[i]);
			
		}
		return list;
		
		
		
		
	}
	public static <T extends Comparable<T>> MySet<T> toTSet(List<T> arr) throws CollectionEmptyException{
		
		MySet<T> set= new TreeSet<>();
		Iterator<T> it= arr.iterator();
		while(it.hasNext()) {
			
			set.add(it.next());
		}
		return set;
		
		
		
		
	}
	public static <T> List<T> toDList(T[] arr){
		
		List<T> list=new DoubleLinkedList<>();

		for(int i=0;i<arr.length;i++) {
			
			list.add(arr[i]);
			
		}
		return list;
		
		
		
		
	}
	public static <T> List<T> toVList(T[] arr){
		
		List<T> list=new Vector<>();

		for(int i=0;i<arr.length;i++) {
			
			list.add(arr[i]);
			
		}
		return list;
		
		
		
		
	}
	
	public static  <T> boolean listIsPalindrome(List<T> list){
		if(list.isEmpty()) {
			
			return false;
			
		}
		Stack<T> aux= new StackInLinkedList<>();
		int length= list.size();
		int middle=(int) Math.floor(length/2);
		for(int i=middle;i<length;i++) {
			
			aux.push(list.get(i));
			
		}
		try {
			for(int i=0;i<middle;i++) {
				
				if(!aux.pop().equals(list.get(i))) {
					
					
					return false;
				}
			}
		}
		catch(StackEmptyException e) {
			
			System.out.println("Stack vazia no algoritmo de listas palindromos!!!!!\n");
			
		}
		return true;
		
		
		
		
		
	}
	
	

}
