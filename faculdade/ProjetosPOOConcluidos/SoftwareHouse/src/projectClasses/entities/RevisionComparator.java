package projectClasses.entities;

import java.util.Comparator;

import projectClasses.interfaces.Revision;

public class RevisionComparator implements Comparator<Revision> {

	@Override
	public int compare(Revision o1, Revision o2) {
		int r= o2.getDate().compareTo(o1.getDate());
		if(r>0) {
			return 1;
		}
		else if(r<0) {
			return -1;
		}
		else {
			return o1.getDescription().compareTo(o2.getDescription());
		}
	}
	
}
