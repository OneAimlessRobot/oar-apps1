package auxPackage.smallAlgorithms;

import ds.implem.DoubleLinkedList;
import ds.implem.Vector;
import ds.interfaces.List;

public class SortingAlgorithms extends CollectionAlgorithms {
	public static class myQuickSort{
		

		private static class Partition<T extends Comparable<T>> {
			
			private List<T> first,second;
			public Partition(List<T> first,List<T> second) {
				
				this.first=first;
				this.second=second;
				
				
				
			}
			public String toString() {
				
				return "["+ first.toString()+"\n"+second.toString()+"]";
				
			}
			public List<T> getFirst() {
				return first;
			}
			public List<T> getSecond() {
				return second;
			}
			
			
		}

		private static <T extends Comparable<T>> Partition<T> splitList(T elem,List<T> list){
			if(list.isEmpty()) {
				
				return new Partition<T>(new DoubleLinkedList<>(),new DoubleLinkedList<>());
			}
				T pivot= list.get(list.size()-1);
				list.remove(list.size()-1);
				Partition<T> p=splitList(elem,list);
				if(pivot.compareTo(elem)<=0) {

					 p.getFirst().add(pivot);
					return p;
					
				}
				else 
				{

					p.getSecond().add(pivot);
					return p;
					
				}
			
			
		}
		public static <T extends Comparable<T>> List<T> sort(List<T> list){
			
			if(list.isEmpty()) {
				
				return list;
			}
			T elem=list.get(0);
			list.remove(0);
			Partition<T> p=splitList(elem,list);
			List<T> l1=p.getFirst(),l2=p.getSecond(),l3=new Vector<>();
			l3.add(elem);
			ListConcatenator lc= new ListConcatenatorWithRAM();
			return 	 lc.concatenate(sort(l1),lc.concatenate(l3,  sort(l2)));

			
			
		}
		
	}
	
	public static class QuickSort{
		
	private  static <T extends Comparable<T>> int splitList(List<T> list,int start,int end){
		
		T pivot= list.get(end);
		int balancePoint=start;
		for(int i=start;i<end;i++) {
			
			if(list.get(i).compareTo(pivot)<=0) {
			T tmp=list.get(i);

			list.update(list.get(balancePoint),i);
			list.update(tmp,balancePoint);
			balancePoint++;
			}
			
			
			
		}
		
		T tmp=list.get(end);

		list.update(list.get(balancePoint),end);
		list.update(tmp,balancePoint);
		return balancePoint;
	}
	public static <T extends Comparable<T>> void sort(List<T> list) {
		
		sortAux(list,0,list.size()-1);
		
		
	}
	private static  <T extends Comparable<T>> void sortAux(List<T> list,int init,int end){
		
		if(init>=end) {
			
			return ;
		}
		int pivot= splitList(list,init,end);
		sortAux(list,pivot+1,end);
		sortAux(list,init,pivot-1);
		
		

		
		
	}
	
	
	
}
	public static class HeapSort{

		public static <T extends Comparable<T>> void sort(List<T> arr){
			
			
			
			
	        int N = arr.size();
	 
	        // Build heap (rearrange array)
	        for (int i = N / 2 - 1; i >= 0; i--)
	            heapify(arr, N, i);
	 
	        // One by one extract an element from heap
	        for (int i = N - 1; i > 0; i--) {
	            // Move current root to end
	            T temp = arr.get(0);
	            arr.update(arr.get(i),0);
	            arr.update(temp,i);
	 
	            // call max heapify on the reduced heap
	            heapify(arr, i, 0);
	        }
		}
		 // To heapify a subtree rooted with node i which is
	    // an index in arr[]. n is size of heap
	    static <T extends Comparable<T>>  void heapify(List<T> arr, int N, int i)
	    {
	        int largest = i; // Initialize largest as root
	        int l = 2 * i + 1; // left = 2*i + 1
	        int r = 2 * i + 2; // right = 2*i + 2
	 
	        // If left child is larger than root
	        if (l < N && arr.get(l).compareTo( arr.get(largest))>0)
	            largest = l;
	 
	        // If right child is larger than largest so far
	        if (r < N && arr.get(r).compareTo( arr.get(largest))>0)
	            largest = r;
	 
	        // If largest is not root
	        if (largest != i) {
	            T swap = arr.get(i);
	            arr.update(arr.get(largest),i);
	            arr.update(swap,largest);
	 
	            // Recursively heapify the affected sub-tree
	            heapify(arr, N, largest);
	        }
	    }
	 
	}
	
	public static class BubbleSort{
		

		public static <T extends Comparable<T>> void sort(List<T> list){
			
			for(int i=0;i<list.size()-1;i++) {

				for(int j=i+1;j<list.size();j++) {
					
					if(list.get(i).compareTo(list.get(j))>0) {
						T tmp=list.get(i);

						list.update(list.get(j),i);
						list.update(tmp,j);
						
						
					}
					
				}
				
			}
			
			
			
		}
		
		public static <T extends Comparable<T>> boolean isSorted(List<T> list,int index,boolean orientation) {
			if(list.isEmpty()||list.size()==1) {
				
				return true;
			}
			if(index==list.size()-1) {
				
				return true;
			}
			if(orientation) {
			return list.get(index).compareTo(list.get(index+1))<=0 && isSorted(list,index+1,orientation);
			}
			else {
				return list.get(index).compareTo(list.get(index+1))>=0 && isSorted(list,index+1,orientation);
			
				
			}
		}

}
}
