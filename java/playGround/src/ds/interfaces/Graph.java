package ds.interfaces;

import ds.implem.VarAryTree;

public interface Graph<T> {

	void addNode(T newNode);

	void addEdge(T firstData, T secondData);

	void removeGraphNode(T content);

	Graph<T> getGraphClone();

	int sumDegrees();

	boolean hasCycles();

	Iterator<Iterator<T>> getIslands();

	Iterator<Iterator<T>> allPaths(T aNode, T bNode);

	Iterator<Iterator<T>> shortestPathsBetween(T a, T b);

	Iterator<T> breadthIterator();

	Iterator<T> depthIterator();

	VarAryTree<T> getTreeForm();

}