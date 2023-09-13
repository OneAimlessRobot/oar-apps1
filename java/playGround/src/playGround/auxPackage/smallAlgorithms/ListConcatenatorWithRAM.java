package playGround.auxPackage.smallAlgorithms;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import playGround.adt.Iterator;
import playGround.adt.collections.List;
import playGround.adt.exceptions.CollectionEmptyException;

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
