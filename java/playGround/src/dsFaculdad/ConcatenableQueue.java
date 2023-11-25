package dsFaculdad;

public interface ConcatenableQueue<E> extends Queue<E>{
	
	void append(ConcatenableQueue<E> addition);

}
