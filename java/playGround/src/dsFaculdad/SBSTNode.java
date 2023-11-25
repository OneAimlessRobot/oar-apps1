package dsFaculdad;

import java.io.Serializable;

public class SBSTNode<K, V> extends BSTNode<K, V> implements Entry<K, V>, Serializable {

	private static final long serialVersionUID = 1L;

	public SBSTNode(K key, V value) {
		super(key, value);
	}

}
