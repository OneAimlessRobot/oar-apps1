/**
* @author Adriano Antonio Campos Valente (62411) aa.valente@campus.fct.unl.pt
* @author Pedro Miguel Martinho Assuncao (68840) pedroassuncao@gmail.com
*/

package dsFaculdad.implem;

import java.io.Serializable;

import dsFaculdad.interfaces.Entry;

public class AVLBSTNode<K, V> extends BSTNode<K,V> implements Entry<K, V>, Serializable {

    
	private static final long serialVersionUID = 1L;
	public static enum NodeType{
		L,R,E;
		
	}
	private NodeType type;
	public AVLBSTNode(K key, V value,NodeType type) {
		super(key,value);
		this.type=type;
	}

	public NodeType getType() {
		return type;
	}
	public void setType(NodeType type) {
		this.type = type;
	}
	public String toString() {
		
		return "[ "+entry.getKey()+" "+entry.getValue()+ " "+ type.toString()+" ]";
	}


}
