package ds.implem;

import java.io.Serializable;
import java.util.NoSuchElementException;

import customClasses.implem.ListOperations;
import ds.exceptions.QueueEmptyException;
import ds.exceptions.StackEmptyException;
import ds.interfaces.Graph;
import ds.interfaces.Iterator;
import ds.interfaces.List;
import ds.interfaces.Queue;
import ds.interfaces.Stack;


public class GraphClass<T> implements Serializable, Graph<T> {

private static class GraphCloner<T> implements Serializable {
	
	private static final long serialVersionUID = 1L;

	public GraphCloner(GraphClass<T> collectionSrc,Graph<T> collectionDst) {
		
		clone(collectionSrc,collectionDst);
	}

	public Graph<T> clone(GraphClass<T> collectionSrc,Graph<T> collectionDst){

		Iterator<T> it;
			it = collectionSrc.graphNodes.iterator();
			while(it.hasNext()) {
				
				collectionDst.addNode(it.next());
			}
		Iterator<GraphEdge<T>> it2;
			it2 = collectionSrc.graphEdges.iterator();
			while(it2.hasNext()) {
				GraphEdge<T> edge=it2.next();
				collectionDst.addEdge(edge.getFirst(),edge.getSecond());
			}
		return collectionDst;
		
		
		
	}
}
private static final long serialVersionUID = 1L;
protected static class GraphIteratorDepth<T> implements Iterator<T>,Serializable{
	
	private static final long serialVersionUID = 1L;
	protected T startFire;
	protected List<T> visited;
	protected Stack<T> path;
	private GraphClass<T> some;
	public GraphIteratorDepth(GraphClass<T> root,T begining) {
		this.some=root;
		this.visited=new DoubleLinkedList<>();
		this.startFire=begining;
		rewind();
		
	}
	
	
	@Override
	public boolean hasNext() {
		if(some==null) {
			return false;
		}
		return !path.isEmpty();
	}

	@Override
	public T next() throws NoSuchElementException{
			if(!hasNext()) {
				throw new NoSuchElementException();
			}
			T node=null;
			try {
				node = path.pop();
			} catch (StackEmptyException e) {
			}
			T result= node;
			Iterator<T> it= some.adjacentOnes(result).iterator();
			while(it.hasNext()) {
				T curr= it.next();
				if(!visited.contains(curr)) {

					path.push(curr);

					visited.add(curr);
					
				}
			}
			return result;
	}
	@Override
	public void rewind() {
		if(some==null) {
			return;
		}
		path= new StackInLinkedList<>();
		path.push(startFire);
		visited.add(startFire);
	}


	
}protected static class GraphIteratorBreadth<T> implements Iterator<T>,Serializable{
	
	private static final long serialVersionUID = 1L;
	protected T startFire;
	protected List<T> visited;
	protected Queue<T> path;
	private GraphClass<T> some;
	public GraphIteratorBreadth(GraphClass<T> root,T begining) {
		this.some=root;
		this.visited=new DoubleLinkedList<>();
		this.startFire=begining;
		rewind();
		
	}
	
	
	@Override
	public boolean hasNext() {
		if(some==null) {
			return false;
		}
		return !path.isEmpty();
	}

	@Override
	public T next() throws NoSuchElementException{
			if(!hasNext()) {
				throw new NoSuchElementException();
			}
			T node=null;
			try {
				node = path.dequeue();
			} catch (QueueEmptyException e) {
			}
			T result= node;
			Iterator<T> it= some.adjacentOnes(result).iterator();
			while(it.hasNext()) {
				T curr= it.next();
				if(!visited.contains(curr)) {

					path.enqueue(curr);

					visited.add(curr);
					
				}
			}
			return result;
	}
	@Override
	public void rewind() {
		if(some==null) {
			return;
		}
		path= new QueueInDoubleLinkedList<>();
		path.enqueue(startFire);
		visited.add(startFire);
	}


	
}
private static class GraphEdge<T> implements Serializable {
	
	private static final long serialVersionUID = 1L;
	private List<T> info;
	GraphEdge(T first,T second){
		
		info= new DoubleLinkedList<>();
		info.add(first);
		info.add(second);
	}

	T getFirst(){
		
		return info.get(0);
	}
	T getSecond(){
		
		return info.get(1);
	}

	public boolean equals(Object otherEdge) {
		boolean result=false;
		if(otherEdge instanceof GraphEdge) {
			return ((GraphEdge<?>)otherEdge).getFirst().equals(this.getFirst())
			&& ((GraphEdge<?>)otherEdge).getSecond().equals(this.getSecond());
			
		}
		return result;
		
		
	}
	public String toString() {
		
		return "["+getFirst()+" "+getSecond()+"]";
	}
}
 private List<GraphEdge<T>> graphEdges;
 private List<T> graphNodes;
 private T start;
 public GraphClass(T start) {

	 this.start=start;
	 graphEdges=new Vector<>();
	 graphNodes=new Vector<>();
	 graphNodes.add(this.start);
	 
 }
 public GraphClass() {

	 graphEdges=new Vector<>();
	 graphNodes=new Vector<>();
	 
 }

 @Override
public void addNode(T newNode) {
	 T node= newNode;
	 if(!graphNodes.contains(node)) {
		 
		 graphNodes.add(node);
	 }
	 
 }
 @Override
public void addEdge(T firstData,T secondData) {

	 T first= firstData,
			 second= secondData;
	 if(first.equals(second)) {
		 return;
	 }
	 int index1=-1,index2=-1;
	 GraphEdge<T> edge=null;
	 if(((index1=graphNodes.getIndex(first))>=0)&&((index2=graphNodes.getIndex(second))>=0)) {
		 
		 edge= new GraphEdge<>(graphNodes.get(index1),graphNodes.get(index2));

	} 
	if(!graphEdges.contains(edge)) {
		 graphEdges.add(edge);
	}
	 
	 
 }
 
 public String toString() {
	 String result="";
	 if(graphNodes.isEmpty()) {
		 return  "[ ]";
	 }
	 else if(graphEdges.isEmpty()) {
		 return "[ "+graphNodes.get(0)+" ]";
	 }
	 else{
		 result+="[";
	 Iterator<T> it= new GraphIteratorDepth<>(this,graphNodes.get(0));
	 
	 while(it.hasNext()) {
		 
		 result+=" "+it.next()+" ";
	 }
	 result+="]";
	 }
	 result+="\n"+graphNodes+"\n"+graphEdges+"\n";
	 
 return result;
	 
 }
 List<T> adjacentOnes(T elem){
	 T node= elem;
	 List<T> result=new DoubleLinkedList<>();
	 if(!(graphNodes.contains(node))) {
		 
		 return result;
	 }
	 Iterator<GraphEdge<T>> it= graphEdges.iterator();
	 while(it.hasNext()) {
		 GraphEdge<T> curr= it.next();
		 
		 if(curr.getFirst().equals(node)){
			 if(!result.contains(node)) {
			 result.add(curr.getSecond(),result.size());
			 }
		 }
		 
	 }
	 it= graphEdges.iterator();
	 while(it.hasNext()) {
		 GraphEdge<T> curr= it.next();
		 
		 if(curr.getSecond().equals(node)){
			 if(!result.contains(node)) {
			 result.add(curr.getFirst());
			 }
		 }
		 
	 }
	 return result;
	 
	 
 } 
 List<T> nextOnes(T elem){
	 T node= elem;
	 List<T> result=new DoubleLinkedList<>();
	 if(!(graphNodes.contains(node))) {
		 
		 return result;
	 }
	 Iterator<GraphEdge<T>> it= graphEdges.iterator();
	 while(it.hasNext()) {
		 GraphEdge<T> curr= it.next();
		 
		 if(curr.getFirst().equals(node)){
			 if(!result.contains(node)) {
			 result.add(curr.getSecond());
			 }
		 }
		 
	 }
	 return result;
	 
	 
 } 
 
 @Override
public void removeGraphNode(T content) {
	 
	 T node= content;
	 if(!graphNodes.contains(node)) {
		 return;
		 
	 }
	 
		 T currNode= graphNodes.get(graphNodes.getIndex(node));
		 Iterator<GraphEdge<T>> it2= graphEdges.iterator();
		 while(it2.hasNext()) {
			 GraphEdge<T> currEdge= it2.next();
			 if(currNode.equals(currEdge.getFirst())||currNode.equals(currEdge.getSecond())) {
				 
				 graphEdges.remove(currEdge);
				 it2.rewind();
			 }
			 
		 }

		graphNodes.remove(currNode);
 }
 
 @Override
public Graph<T> getGraphClone() {
	 
	 Graph<T> graph= new GraphClass<>(start);
	 GraphCloner<T> cloner= new GraphCloner<>(null,null);
	 
	 return cloner.clone(this, graph);
	 
	 
 }
 @Override
public int sumDegrees() {
	 Iterator<T> it= graphNodes.iterator();
	 int result=0;
	 while(it.hasNext()) {
		 result+=adjacentOnes(it.next()).size();
		 
	 }
	 return result;
	 
	 
 }
 @Override
 public boolean hasCycles() {
 	 
 	return ((graphNodes.size()*2)-2)!=sumDegrees();
 	 
  }
  @Override
 public Iterator<Iterator<T>> getIslands(){
 	 List<T> totalNodes=new DoubleLinkedList<>();
 	 List<Iterator<T>> islands= new DoubleLinkedList<>();
 	 List<T> island= new DoubleLinkedList<>();
 	 if(graphNodes.isEmpty()) {
 		 islands.add(island.iterator());
 		 return islands.iterator();
 	 }
 	 if(graphEdges.isEmpty()) {
 		 island.add(graphNodes.get(0));
 		 islands.add(island.iterator());
 		 return islands.iterator();
 		 
 		 
 	 }
 	 Iterator<T> it2=graphNodes.iterator();
 	 while(it2.hasNext()) {
 		 totalNodes.add(it2.next());
 		 
 	 }
 	 while(!totalNodes.isEmpty()) {
 	 Iterator<T> it= new GraphIteratorBreadth<>(this,totalNodes.get(0)); 
 	 while(it.hasNext()) {
 		 T curr= it.next();
 		 if(!island.contains(curr)) {
 			 island.add(curr);
 			 totalNodes.remove(curr);
 		 }
 		 
 	 }
 	 islands.add(island.iterator());
 	 island=new DoubleLinkedList<>();
 	 }
 	 return islands.iterator();
 	 
 	 
 	 
 	 
  }
  

private List<List<T>> allPathsExplode(T bNode,T currNode,List<T> visited){

	if(!visited.contains(currNode)) {
		 
		 visited.add(currNode);
	 }
	List<T> frontier=nextOnes(currNode);

	 List<List<T>> last=(List<List<T>>) allPathsAdvance(bNode,(List<T>) frontier.copy(),(List<T>) visited.copy());
	 
	 return ListOperations.mapAppend(currNode, last);
 }
		    

private List<List<T>> allPathsAdvance(T bNode,List<T> frontier,List<T> visited){
		
		 if(frontier.isEmpty()) {
			 return new DoubleLinkedList<>();
		 }
		 else {
			 while(!frontier.isEmpty()) {
				 T head= frontier.get(0);
				 frontier.remove(0);
				 if(!visited.contains(head)) {
					 if(head.equals(bNode)) {
						 List<T> list3= new DoubleLinkedList<>();
						 List<List<T>> list7= new DoubleLinkedList<>();
						 list3.add(bNode);
						 
						 list7.add(list3);
						 return list7;
						 
						 
					 }
					 else {
						 
						 List<List<T>> list4=allPathsExplode(bNode,head,(List<T>) visited.copy());
						 List<List<T>> list5=allPathsAdvance(bNode,(List<T>)  frontier.copy(),(List<T>)  visited.copy());
						 Iterator<List<T>> it= list4.iterator();						 
						 while(it.hasNext()) {
							 
							 List<T> curr= it.next();
							 list5.add(curr);
							 
						 }
						 return list5;
						 
					 }
				 }
				 else {

					 
					 return allPathsAdvance(bNode,(List<T>)  frontier.copy(),(List<T>)  visited.copy());
				 }
			 }
			 
		 }
		return null;
}

@Override
public Iterator<Iterator<T>> allPaths(T aNode,T bNode){
		
	List<List<T>> extracted= allPathsExplode(bNode,aNode,new DoubleLinkedList<>());
	List<Iterator<T>> result= new DoubleLinkedList<>();
	 Iterator<List<T>> it= extracted.iterator();
	 while(it.hasNext()) {
		 List<T> curr= it.next();
			 result.add(curr.iterator());
		 
	 }
	 return result.iterator();
}

 @Override
public Iterator<Iterator<T>> shortestPathsBetween(T a,T b){
		List<Iterator<T>> results=new DoubleLinkedList<>();
	 	Iterator<Iterator<T>> candidates=allPaths(a,b);
	 	int minLength=ListOperations.iteratorOfIteratorsMinSize(candidates);
	 	System.out.println(minLength);
	 	while(candidates.hasNext()) {
	 		Iterator<T> curr=candidates.next();
	 		if(minLength==ListOperations.iteratorSize(curr)) {
	 			results.add(curr);
	 		}
	 		
	 	}
	 	
		 return results.iterator();
 }
@Override
public VarAryTree<T> getTreeForm(){
	
		return getTreeFormExplode(start,new DoubleLinkedList<>());
		
	
}

private VarAryTree<T> getTreeFormExplode(T currNode,List<T> visited){
	

	if(!visited.contains(currNode)) {
		 
		 visited.add(currNode);
	 }
	List<T> frontier=nextOnes(currNode);
	
	
	 return new VarAryTree<>(currNode,getTreeFormAdvance((List<T>)frontier.copy(),(List<T>) visited.copy()));
	
}
private List<VarAryTree<T>> getTreeFormAdvance(List<T> frontier,List<T> visited){

	 if(frontier.isEmpty()) {
		 return new DoubleLinkedList<>();
	 }
	 else {
		 while(!frontier.isEmpty()) {
			 T head=frontier.get(0);
			 frontier.remove(0);
			 if(visited.contains(head)) {

					return getTreeFormAdvance((List<T> )  frontier.copy(),(List<T>)  visited.copy());
						 						 
					 
			 }
			 else {
					VarAryTree<T> appended= getTreeFormExplode(head,(List<T>) visited.copy());
					 List<VarAryTree<T>> list5=(List<VarAryTree<T>>) getTreeFormAdvance((List<T> )  frontier.copy(),(List<T>)  visited.copy());
						 			
					 list5.add(appended);
					 return  list5;
			}
		 }
		 
	 }
	return null;
	
}
 @Override
public Iterator<T> breadthIterator(){
	 
	 return new GraphIteratorBreadth<>(this,start);
 }
 @Override
public Iterator<T> depthIterator(){
	 
	 return new GraphIteratorDepth<>(this,start);
 }
 
 


}
