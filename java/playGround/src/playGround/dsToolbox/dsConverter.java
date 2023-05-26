package playGround.dsToolbox;

import playGround.adt.Collection;
import playGround.adt.Iterator;
import playGround.adt.exceptions.CollectionEmptyException;

public class dsConverter<T> {
	
	public dsConverter(Collection<T> collectionSrc,Collection<T> collectionDst) {
		
		rebuild(collectionSrc,collectionDst);
	}

	public Collection<T> rebuild(Collection<T> collectionSrc,Collection<T> collectionDst){
		
		Iterator<T> it;
			collectionDst.destroy();
			it = collectionSrc.iterator();
			while(it.hasNext()) {
				
				collectionDst.add(it.next());
			}
			it.close();
		return collectionDst;
		
		
		
	}
}
