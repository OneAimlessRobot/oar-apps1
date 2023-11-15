package playGround.auxPackage.smallAlgorithms;
import playGround.ds.exceptions.CollectionEmptyException;
import playGround.ds.exceptions.StackEmptyException;
import playGround.ds.implem.DoubleLinkedList;
import playGround.ds.implem.Graph;
import playGround.ds.implem.LinkedList;
import playGround.ds.implem.StackInLinkedList;
import playGround.ds.implem.TreeSet;
import playGround.ds.implem.Vector;
import playGround.ds.interfaces.Iterator;
import playGround.ds.interfaces.List;
import playGround.ds.interfaces.MySet;
import playGround.ds.interfaces.Stack;
import playGround.auxPackage.numeric.*;
public class CollectionAlgorithms {
	
	public static Integer[] orderedIntArrAux(int min,int size) {
		Integer[] arr= new Integer[size];
		for(int i=0;i<arr.length;i++) {
			
			arr[i]=min+i;
			
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
		Graph<Integer> graph=new Graph<>();
//		MySet<Integer> ints=CollectionAlgorithms.toTSet(CollectionAlgorithms.toVList(randIntArrAux(0,25,10)));
//		List<Integer> list=new DoubleLinkedList<>();
//		Iterator<Integer> it= ints.iterator();
//		while(it.hasNext()) {
//			graph.addNode(it.next());
//		}
//		it.rewind();
//		while(it.hasNext()) {
//			graph.addNode(it.next());
//		}
		
//		dsConverter<Integer> conv= new dsConverter<>(ints,list);
//		System.out.println("Lista:\n"+list+"Tree:\n"+ints);
		List<Integer> list=CollectionAlgorithms.toDList(randIntArrAux(0,25,10));
		for(int i=0;i<list.size();i++) {
			
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
