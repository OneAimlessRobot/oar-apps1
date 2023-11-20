package customClasses.implem;

import java.io.Serializable;

import ds.implem.DoubleLinkedList;
import ds.implem.dsConverter;
import ds.interfaces.Iterator;
import ds.interfaces.List;

public class ListOperations<T> implements Serializable {

	 private static final long serialVersionUID = 1L;
	public static <T> List<List<T>> appendNodeToLists(T node,List<List<T>> list){
		 
		 Iterator<List<T>> it= list.iterator();
		 while(it.hasNext()) {
			 List<T> curr= it.next();
			 if(!curr.contains(node)) {
				 curr.add(node);
			 }
		 }
		 return list;
		 
	 }

	public static <T> int getListofListsMaxLength(List<List<T>> list){
		 
		 Iterator<List<T>> it= list.iterator();
		 int result=-1;
		 while(it.hasNext()) {
			 List<T> curr= it.next();
			 if(result<=curr.size()) {
				 
				 result=curr.size();
			 }
		 }
		 return result;
		 
	 }
	 public static <T> int getListofListsMinLength(List<List<T>> list){
		 
		 Iterator<List<T>> it= list.iterator();
		 int result=1000000;
		 while(it.hasNext()) {
			 List<T> curr= it.next();
			 if(result>=curr.size()) {
				 
				 result=curr.size();
			 }
		 }
		 return result;
		 
	 }

	 public static <T> boolean listOfListsContainsList(List<T> list, List<List<T>> llist) {
		Iterator<List<T>> it= llist.iterator();
		while(it.hasNext()) {
			
			List<T> curr= it.next();
			
			if(listContainsList(curr,list)&&listContainsList(list,curr)) {
				
				return true;
			}
		}
		return false;
		 
		 
	 }

	 public static <T> int iteratorSize(Iterator<T> it) {
		int result=0;
		while(it.hasNext()) {
			result++;
			it.next();
		}
		it.rewind();
		return result;
		 
		 
	 }
	 public static<T> int iteratorOfIteratorsMinSize(Iterator<Iterator<T>> it) {
		int min=1000000000;
		while(it.hasNext()) {
			Iterator<T> it2= it.next();
			min=Math.min(min, iteratorSize(it2));
		}
		it.rewind();
		return min;
		 
		 
	 }
	 public static <T> int iteratorOfIteratorsMaxSize(Iterator<Iterator<T>> it) {
		int max=-1;
		while(it.hasNext()) {
			Iterator<T> it2= it.next();
			max=Math.max(max, iteratorSize(it2));
		}
		it.rewind();
		return max;
		 
		 
	 }
	 public static <T> boolean listOfListsContainsElem(T elem, List<List<T>> llist) {
		Iterator<List<T>> it= llist.iterator();
		while(it.hasNext()) {
			
			List<T> curr= it.next();
			
			if(curr.contains(elem)) {
				
				return true;
			}
		}
		return false;
		 
		 
	 }
		public static <T> List<List<T>> multiplyLists(List<T> nodes,List<List<T>> list){
			 
			 Iterator<List<T>> it= list.iterator();
			 while(it.hasNext()) {
				List<T> node= it.next();
				 Iterator<T> itlist= nodes.iterator();
			 while(itlist.hasNext()) {
				 T curr= itlist.next();

				 List<T> copy= new DoubleLinkedList<>();
				 dsConverter.rebuild( node,copy);
				 if(!copy.contains(curr)) {
				 
				 copy.add(curr,copy.size()-1);
			
				 
				}
				 if(copy.size()>=getListofListsMaxLength(list)&&!ListOperations.listOfListsContainsList(copy, list)) {
				 list.add(copy);
				 }
				 	 
			 }
			 }
			 return list;
			 
		 }

		 public static <T> List<List<T>> cloneListNTimes(List<T> list,int n){
			 List<List<T>> llist= new DoubleLinkedList<>();
			 for(int i=0;i<n;i++) {
				 llist.add((List<T>) list.copy());
				 
			 }
			 return llist;
			 
		 }
		public static <T> List<List<T>> mapAppend(T node,List<List<T>> list){
			 
			 Iterator<List<T>> it= list.iterator();
			 while(it.hasNext()) {
				 List<T> curr=it.next();
				 curr.add(node,0);
				 	 
			 }
			 return list;
			 
		 }
		 
	 public static <T> boolean listContainsList(List<T> container,List<T> contained) {
		 Iterator<T> it= contained.iterator();
		 while(it.hasNext()) {
			 T node= it.next();
			 if(!container.contains(node)) {
				 return false;
			 }
		 }
		 return true;
		 
		 
	 }
	 public static <T> List<T> intersect(List<T> list1,List<T> list2){
		 List<T> inter= new DoubleLinkedList<>();
		 Iterator<T> it= list1.iterator();
		 while(it.hasNext()) {
			 T curr= it.next();
			 if(list2.contains(curr)) {
				 inter.add(curr);
			 }
		 }
	 return inter;
	 
	 }
}
