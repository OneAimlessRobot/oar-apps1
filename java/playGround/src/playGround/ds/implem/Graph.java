package playGround.ds.implem;

import java.io.Serializable;
import java.util.NoSuchElementException;

import playGround.ds.exceptions.QueueEmptyException;
import playGround.ds.exceptions.StackEmptyException;
import playGround.ds.interfaces.Iterator;
import playGround.ds.interfaces.List;
import playGround.ds.interfaces.Queue;
import playGround.ds.interfaces.Stack;


public class Graph<T> implements Serializable {

private static class GraphCloner<T> implements Serializable {
	
	private static final long serialVersionUID = 1L;

	public GraphCloner(Graph<T> collectionSrc,Graph<T> collectionDst) {
		
		clone(collectionSrc,collectionDst);
	}

	public Graph<T> clone(Graph<T> collectionSrc,Graph<T> collectionDst){

		Iterator<GraphNode<T>> it;
			it = collectionSrc.graphNodes.iterator();
			while(it.hasNext()) {
				
				collectionDst.addNode(it.next().getData());
			}
		Iterator<GraphEdge<T>> it2;
			it2 = collectionSrc.graphEdges.iterator();
			while(it2.hasNext()) {
				GraphEdge<T> edge=it2.next();
				collectionDst.addEdge(edge.getFirst().getData(),edge.getSecond().getData());
			}
		return collectionDst;
		
		
		
	}
}
private static final long serialVersionUID = 1L;
protected static class GraphIteratorDepth<T> implements Iterator<T>,Serializable{
	
	private static final long serialVersionUID = 1L;
	protected GraphNode<T> startFire;
	protected List<GraphNode<T>> visited;
	protected Stack<GraphNode<T>> path;
	private Graph<T> some;
	public GraphIteratorDepth(Graph<T> root,GraphNode<T> begining) {
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
			GraphNode<T> node=null;
			try {
				node = path.pop();
			} catch (StackEmptyException e) {
			}
			T result= node.getData();
			Iterator<GraphNode<T>> it= some.nextOnes(result).iterator();
			while(it.hasNext()) {
				GraphNode<T> curr= it.next();
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
	protected GraphNode<T> startFire;
	protected List<GraphNode<T>> visited;
	protected Queue<GraphNode<T>> path;
	private Graph<T> some;
	public GraphIteratorBreadth(Graph<T> root,GraphNode<T> begining) {
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
			GraphNode<T> node=null;
			try {
				node = path.dequeue();
			} catch (QueueEmptyException e) {
			}
			T result= node.getData();
			Iterator<GraphNode<T>> it= some.nextOnes(result).iterator();
			while(it.hasNext()) {
				GraphNode<T> curr= it.next();
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
	private List<GraphNode<T>> info;
	GraphEdge(GraphNode<T> first,GraphNode<T> second){
		
		info= new DoubleLinkedList<>();
		info.add(first);
		info.add(second);
	}

	GraphNode<T> getFirst(){
		
		return info.get(0);
	}
	GraphNode<T> getSecond(){
		
		return info.get(1);
	}

	public boolean equals(Object otherEdge) {
		boolean result=false;
		if(otherEdge instanceof GraphEdge) {
			return ((GraphEdge<T>)otherEdge).getFirst().equals(this.getFirst())
			&& ((GraphEdge<T>)otherEdge).getSecond().equals(this.getSecond());
			
		}
		return result;
		
		
	}
	public String toString() {
		
		return "["+getFirst()+" "+getSecond()+"]";
	}
}
private static class GraphNode<T> implements Serializable {
	
	private static final long serialVersionUID = 1L;
	T data;
	GraphNode(T data){
		
		this.data=data;
	}
	T getData() {
		return data;
	}

	public boolean equals(Object otherNode) {
		boolean result=false;
		if(otherNode instanceof GraphNode) {
			return ((GraphNode<T>)otherNode).getData().equals(this.data);
			
		}
		return result;
		
		
	}
	public String toString() {
		
		return "[ "+data+" ]";
	}
	

}

 private List<GraphEdge<T>> graphEdges;
 private List<GraphNode<T>> graphNodes;
 private GraphNode<T> start;
 public Graph(T start) {

	 this.start=new GraphNode<>(start);
	 graphEdges=new Vector<>();
	 graphNodes=new Vector<>();
	 graphNodes.add(this.start);
	 
 }
 public Graph() {

	 graphEdges=new Vector<>();
	 graphNodes=new Vector<>();
	 
 }

 public void addNode(T newNode) {
	 GraphNode<T> node= new GraphNode<>(newNode);
	 if(!graphNodes.contains(node)) {
		 
		 graphNodes.add(node);
	 }
	 
 }
 public int sumDegrees() {
	 Iterator<GraphNode<T>> it= graphNodes.iterator();
	 int result=0;
	 while(it.hasNext()) {
		 result+=nextOnes(it.next().getData()).size();
		 
	 }
	 return result;
	 
	 
 }
 public boolean hasCycles() {
	 
	return ((graphNodes.size()*2)-2)!=sumDegrees();
	 
 }
 public void addEdge(T firstData,T secondData) {

	 GraphNode<T> first= new GraphNode<>(firstData),
			 second= new GraphNode<>(secondData);
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
	 if(graphNodes.isEmpty()) {
		 return "[ ]";
	 }
	 if(graphEdges.isEmpty()) {
		 return "[ "+graphNodes.get(0)+" ]";
	 }
	 String result="[";
	 Iterator<T> it= new GraphIteratorDepth<>(this,graphNodes.get(0));
	 
	 while(it.hasNext()) {
		 
		 result+=" "+it.next()+" ";
	 }
	 result+="]";
	 return result;
	 
 }
 public List<GraphNode<T>> nextOnes(T elem){
	 GraphNode<T> node= new GraphNode<>(elem);
	 List<GraphNode<T>> result=new DoubleLinkedList<>();
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
 
 public void removeGraphNode(T content) {
	 
	 GraphNode<T> node= new GraphNode<>(content);
	 if(!graphNodes.contains(node)) {
		 return;
		 
	 }
	 
		 GraphNode<T> currNode= graphNodes.get(graphNodes.getIndex(node));
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
 
 public Graph<T> getGraphClone() {
	 
	 Graph<T> graph= new Graph<>(start.getData());
	 GraphCloner<T> cloner= new GraphCloner(this,graph);
	 
	 return graph;
	 
	 
 }

 public Iterator<T> breadthIterator(){
	 
	 return new GraphIteratorBreadth<>(this,start);
 }
 public Iterator<T> depthIterator(){
	 
	 return new GraphIteratorDepth<>(this,start);
 }
 
 


}
