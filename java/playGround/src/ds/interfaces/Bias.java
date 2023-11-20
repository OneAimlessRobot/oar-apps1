package ds.interfaces;

import ds.exceptions.StackEmptyException;

public interface Bias<T> extends Stack<T>{
	/**TODO: A new data structure called a Bias, which is going to be initially implemented over a double linked list and it works this way: the operations are the same as a DEque, but this data structure has an initial node called the level and if the bias only has the level as its only node, then its empty. nodes can either be added at the left of the level or at the right of the level. Its a double ended stack, but with a fixed center. And it is empty when either level->left is null or level->right is null**/
	void popBack() throws StackEmptyException;
	T back() throws StackEmptyException;
	
	void pushBack(T elem);
	
}
