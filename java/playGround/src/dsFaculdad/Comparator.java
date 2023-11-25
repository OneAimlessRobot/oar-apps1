package dsFaculdad;

import java.io.Serializable;

public interface Comparator<K> extends Serializable {
	
	int compare(K first,K second );

}
