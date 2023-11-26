/**
* @author Adriano Antonio Campos Valente (62411) aa.valente@campus.fct.unl.pt
* @author Pedro Miguel Martinho Assuncao (68840) pedroassuncao@gmail.com
*/

package dsFaculdad.interfaces;

public interface ConcatenableQueue<E> extends Queue<E>{
	
	void append(ConcatenableQueue<E> addition);

}
