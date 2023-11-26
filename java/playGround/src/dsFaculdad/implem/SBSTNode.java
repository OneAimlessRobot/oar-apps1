package dsFaculdad.implem;

import java.io.Serializable;

import dsFaculdad.interfaces.Entry;

public class SBSTNode<K, V> extends BSTNode<K, V> implements Entry<K, V>, Serializable {

	private static final long serialVersionUID = 1L;

	public SBSTNode(K key, V value) {
		super(key, value);
	}

}
