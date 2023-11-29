package ds.interfaces;

import java.io.Serializable;

public interface Comparator<T> extends Serializable {

	int compare(T arg0,T arg1);
}
