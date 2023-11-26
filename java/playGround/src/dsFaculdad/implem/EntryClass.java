package dsFaculdad.implem;
import java.io.Serializable;

import dsFaculdad.interfaces.Entry;

public class EntryClass<K, V> implements Entry<K, V>, Serializable {

	private static final long serialVersionUID = 1L;

	private K key;
	private V value;
	
	public EntryClass(K key, V value) {
		this.key=key;
		this.value=value;
		
	}
	@Override
	public K getKey() {
		return key;
	}

	@Override
	public V getValue() {
		return value;
	}
	
	public void setKey(K key) {
		this.key=key;
	}

	public void setValue(V value) {
		this.value=value;
	}
	
	public String toString() {
		return "[ " +key + " "+ value +" ]";
		
		
	}
	
	

}
