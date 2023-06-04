package playGround.aux.smallAlgorithms;
import playGround.adt.Iterator;
import playGround.adt.*;
import playGround.adt.collections.List;
import playGround.adt.collections.MySet;
import playGround.adt.exceptions.CollectionEmptyException;
import playGround.adt.exceptions.StackEmptyException;
import playGround.ds.*;
import playGround.aux.numeric.*;
public class CollectionAlgorithms {
	
	
	public static Integer[] randIntArrAux(int max,int min,int size) {
		Integer[] arr= new Integer[size];
		for(int i=0;i<arr.length;i++) {
			
			arr[i]=AuxNumeric.boundedRandNum(max, min);
			
		}
		return arr;
		
		
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
		it.close();
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
