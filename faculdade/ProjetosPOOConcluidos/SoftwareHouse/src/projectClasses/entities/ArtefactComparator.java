package projectClasses.entities;

import java.util.Comparator;

import projectClasses.interfaces.Artefact;

public class ArtefactComparator implements Comparator<Artefact> {

	@Override
	public int compare(Artefact o1, Artefact o2) {
		int r=o2.getLastdate().compareTo(o1.getLastdate());
		if(r>0) {
			return 1;
			
		}
		else if(r<0) {
			return -1;
		}
		else {
			return o1.getName().compareTo(o2.getName());
		}
		
	}

}
