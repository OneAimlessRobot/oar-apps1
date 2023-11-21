package dsFaculdade;

import java.io.Serializable;


/**
* Separate Chaining Hash table implementation
 * @author AED  Team
 * @version 1.0
 * @param <K> Generic Key, must extend comparable
 * @param <V> Generic Value 
 */

public class SepChainHashTable<K extends Comparable<K>, V> 
    extends HashTable<K,V> 
{ 

	private static class HashSetIterator<K extends Comparable<K>,V> implements IteratorEntries<K,V>,Serializable{
		
		private static final long serialVersionUID = 1L;
		private int mainPos,last;
		private IteratorEntries<K,V> current;
		private Dictionary<K,V>[] entries;
		public HashSetIterator(SepChainHashTable<K,V> set){
			
			this.entries=set.table;
			fullForward();
			last=mainPos;
			rewind();
		}
		@Override
		public Entry<K,V> next() {
			if(!current.hasNext()) {
				skipOneListForward();
				skipEmptyListsForward();
				
			}
			
			return current.next();
		}
		@Override
		public boolean hasNext() {
			if(current.hasNext()) {
				return true;
			}
			else if(mainPos<last) {
				
				return true;
			}
			return false;
			
		}

		@Override
		public void rewind() {
			mainPos=0;
			skipEmptyListsForward();
		}

		private void skipEmptyListsForward() {
			while(entries[mainPos].isEmpty()&&mainPos<entries.length-1) {mainPos++;}
			
					this.current =entries[mainPos].iterator();
					
		}
		private void skipOneListForward() {
			

			mainPos++;	
		}

		private void skipEmptyListsBackwards() {
			while(entries[mainPos].isEmpty()&&mainPos>0) {mainPos--;}
			
					this.current =entries[mainPos].iterator();
					
		}
		private void fullForward() {
				mainPos=entries.length-1;
				skipEmptyListsBackwards();
		}
		
		
		
	}
	/**
	 * Serial Version UID of the Class.
	 */
    static final long serialVersionUID = 0L;

	/**
	 * The array of dictionaries.
	 */
    protected Dictionary<K,V>[] table;
    
    /**
     * Constructor of an empty separate chaining hash table,
     * with the specified initial capacity.
     * Each position of the array is initialized to a new ordered list
     * maxSize is initialized to the capacity.
     * @param capacity defines the table capacity.
     */
    @SuppressWarnings("unchecked")
    public SepChainHashTable( int capacity )
    {
        int arraySize = HashTable.nextPrime((int) (1.1*capacity));
        // Compiler gives a warning.
        table = (Dictionary<K,V>[]) new Dictionary[arraySize];
        for ( int i = 0; i < arraySize; i++ )
             table[i] = new OrderedDoubleList<>();
        maxSize = capacity;
        currentSize = 0;
    }                                      


    public SepChainHashTable( )
    {
        this(DEFAULT_CAPACITY);
    }                                                                

    /**
     * Returns the hash value of the specified key.
     * @param key to be encoded
     * @return hash value of the specified key
     */
    protected int hash( K key )
    {
        return Math.abs( key.hashCode() ) % table.length;
    }

    @Override
    public V find( K key )
    {
        return table[ this.hash(key) ].find(key);
    }

    @Override
    public V insert( K key, V value )
    {
        if ( this.isFull() ) {
             this.rehash();

        }

    	V  oldValue=table[ this.hash(key) ].insert(key,value);
        if(oldValue==null) {
            currentSize++;
            }
        return oldValue;
    }

    @Override
    public V remove( K key )
    {
    	V value=table[ this.hash(key) ].remove(key);
        if(value!=null) {
            currentSize--;
           }
        return value;
    }

    @Override
    public IteratorEntries<K,V> iterator( )
    {
        return new HashSetIterator<>(this);
    } 
    
    private void rehash() {
    	int newSize=(int)(maxSize*2);
    	SepChainHashTable<K,V> newdict = new SepChainHashTable<>(newSize);
    	IteratorEntries<K,V> it= iterator();
    	while(it.hasNext()) {
    		Entry<K,V> curr= it.next();
    		newdict.insert(curr.getKey(), curr.getValue());
    		
    		
    	}
    	this.table=newdict.table;
    	this.maxSize=newSize;
    	
    }
    protected boolean isFull( )
    {    
        return getLoadFactor()<LOAD_FACTOR;
    }
    public double getLoadFactor() {
    	
    	return (double)maxSize/(double)currentSize;
    }
   
}
































