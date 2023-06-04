package playGround.aux.smallAlgorithms;

import playGround.adt.collections.List;
import playGround.ds.Vector;

public class SortingAlgorithms extends CollectionAlgorithms {
	
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
		public void setFirst(List<T> first) {
			this.first = first;
		}
		public List<T> getSecond() {
			return second;
		}
		public void setSecond(List<T> second) {
			this.second = second;
		}
		
		
	}
	private static <T extends Comparable<T>> int betterSplitList(List<T> list,int start,int end){
		
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
	private static <T extends Comparable<T>> Partition<T> mySplitList(T elem,List<T> list){
		if(list.isEmpty()) {
			
			return new Partition<T>(new Vector<>(),new Vector<>());
		}
		if(!list.contains(elem)) {
			
			return null;
		}
			T pivot= list.get(list.size()-1);
			list.remove();
			Partition<T> p=mySplitList(elem,list);
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
	public static <T extends Comparable<T>> List<T> myQuickSort(List<T> list){
		
		if(list.isEmpty()) {
			
			return (List<T>) list.copy();
		}
		T elem=list.get(0);
		list.remove(0);
		Partition<T> p=mySplitList(elem,(List<T>) list.copy());
		List<T> l1=p.getFirst(),l2=p.getSecond(),l3=new Vector<>();
		ListConcatenator lc= new ListConcatenatorWithRAM();
		return 	 lc.concatenate(myQuickSort(l1), lc.concatenate(l3,myQuickSort(l2)));

		
		
	}
	public static <T extends Comparable<T>> void betterQuickSort(List<T> list) {
		
		betterQuickSortAux(list,0,0);
		
		
	}
	private static <T extends Comparable<T>> void betterQuickSortAux(List<T> list,int init,int end){
		
		if(init>=end) {
			
			return ;
		}
		int pivot= betterSplitList(list,init,end);
		betterQuickSortAux(list,pivot+1,end);
		betterQuickSortAux(list,init,pivot-1);
		
		

		
		
	}
	

	public static <T extends Comparable<T>> void bubbleSort(List<T> list){
		
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

}
