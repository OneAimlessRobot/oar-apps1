package playGround.auxPackage.smallAlgorithms;

import playGround.ds.interfaces.Iterator;
import playGround.ds.interfaces.List;

public class ListConcatenatorWithRAM implements ListConcatenator{


	@Override
	public <T>  List<T> concatenate(List<T> l1, List<T> l2) {
			Iterator<T> it=l2.iterator();
			while(it.hasNext()) {
				
				l1.add(it.next());
			}
			return (List<T>) l1.copy();
			
		
	}

}
