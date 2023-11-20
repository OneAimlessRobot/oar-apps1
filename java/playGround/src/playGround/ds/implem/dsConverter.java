package playGround.ds.implem;

import playGround.ds.interfaces.Collection;
import playGround.ds.interfaces.Iterator;

public class dsConverter<T> {
	
	public dsConverter(Collection<T> collectionSrc,Collection<T> collectionDst) {
		
		rebuild(collectionSrc,collectionDst);
	}

	public static <T> Collection<T> rebuild(Collection<T> collectionSrc,Collection<T> collectionDst){
		
		Iterator<T> it;
			collectionDst.clear();
			it = collectionSrc.iterator();
			while(it.hasNext()) {
				
				collectionDst.add(it.next());
			}
		return collectionDst;
		
		
		
	}
}
