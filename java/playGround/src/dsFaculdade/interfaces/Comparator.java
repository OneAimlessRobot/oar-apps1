/**
* @author Adriano Antonio Campos Valente (62411) aa.valente@campus.fct.unl.pt
* @author Pedro Miguel Martinho Assuncao (68840) pedroassuncao@gmail.com
*/

package dsFaculdade.interfaces;

import java.io.Serializable;

public interface Comparator<K> extends Serializable {
	
	int compare(K first,K second );

}
