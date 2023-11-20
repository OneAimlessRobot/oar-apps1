package auxPackage.smallAlgorithms;

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

		private static <T extends Comparable<T>> Partition<T> splitList(T elem,List<T> list){
			if(list.isEmpty()) {
				
				return new Partition<T>(new Vector<>(),new Vector<>());
			}
			if(!list.contains(elem)) {
				
				return null;
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
				
				return (List<T>) list.copy();
			}
			T elem=list.get(0);
			list.remove(0);
			Partition<T> p=splitList(elem,(List<T>) list.copy());
			List<T> l1=p.getFirst(),l2=p.getSecond(),l3=new Vector<>();
			ListConcatenator lc= new ListConcatenatorWithRAM();
			return 	 lc.concatenate(sort(l1), lc.concatenate(l3,sort(l2)));

			
			
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
