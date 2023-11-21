package ds.implem;

import java.io.Serializable;
import java.util.NoSuchElementException;

import ds.exceptions.QueueEmptyException;
import ds.interfaces.Graph;
import ds.interfaces.Iterator;
import ds.interfaces.List;
import ds.interfaces.Queue;

public class VarAryTree<T> implements Serializable {
	private static final long serialVersionUID = 1L;
	protected static class VarAryTreeIteratorBreadth<T> implements Iterator<T>,Serializable{
		
		private static final long serialVersionUID = 1L;
		protected VarAryTree<T> startFire;
		protected List<VarAryTree<T>> visited;
		protected Queue<VarAryTree<T>> path;
		public VarAryTreeIteratorBreadth(VarAryTree<T> begining) {
			this.visited=new DoubleLinkedList<>();
			this.startFire=begining;
			rewind();
			
		}
		
		
		@Override
		public boolean hasNext() {
			if(startFire==null) {
				return false;
			}
			return !path.isEmpty();
		}

		@Override
		public T next() throws NoSuchElementException{
				if(!hasNext()) {
					throw new NoSuchElementException();
				}
				VarAryTree<T> node=null;
				try {
					node = path.dequeue();
				} catch (QueueEmptyException e) {
				}
				T result= node.getElem();
				Iterator<VarAryTree<T>> it= node.children().iterator();
				while(it.hasNext()) {
					VarAryTree<T> curr= it.next();
					if(!visited.contains(curr)) {

						path.enqueue(curr);

						visited.add(curr);
						
					}
				}
				return result;
		}
		@Override
		public void rewind() {
			if(startFire==null) {
				return;
			}
			path= new QueueInDoubleLinkedList<>();
			path.enqueue(startFire);
			visited.add(startFire);
		}


		
	}
		private List<VarAryTree<T>> children;
		private T elem;
		private int size;
		public VarAryTree(T stored) {
			
			elem=stored;
			children= new DoubleLinkedList<>();
		}
		public VarAryTree(T stored,List<VarAryTree<T>> children) {
	
		elem=stored;
		this.children= children;
		}

		
		public T getElem() {
			return elem;
		}
		public void addChild(T elem) {
			children.add(new VarAryTree<>(elem));
		}
		public List<VarAryTree<T>> children(){
			return children;
		}
		public boolean equals(Object anotherNode) {
			boolean result= false;
			if(anotherNode instanceof VarAryTree) {
				result= ((VarAryTree<?>)anotherNode).getElem().equals(elem);
			}
			return result;
				
		}
		public Graph<T> turnIntoGraph(){
			Graph<T> result= new GraphClass<>(elem);
			turnIntoGraphExplode(this,result);
			return result;
			
		}
		public void turnIntoGraphExplode(VarAryTree<T> currNode,Graph<T> result){
			if(!currNode.isLeaf()) {
				Iterator<VarAryTree<T>> it= currNode.children().iterator();
				while(it.hasNext()) {
					VarAryTree<T> curr= it.next();
					result.addNode(curr.getElem());
					result.addEdge(currNode.getElem(),curr.getElem());
					turnIntoGraphExplode(curr,result);
				}
			}
			
			
		}
		public boolean isLeaf() {
			
			return children.isEmpty();
			
		}
		
		public Iterator<T> iterator(){
			
			return new VarAryTreeIteratorBreadth<>(this);
		}
		public String toString() {

			if(isLeaf()) {
				

				return "[ folha!!!]";
			}
			String str="[";
			Iterator<T> it = iterator();
				while(it.hasNext()) {
					str+= " "+it.next().toString()+" ";
				}
				str+="]";
			return str;
			
			
		}
		
		
	
}
