package projectClasses.entities;

import java.util.Comparator;
import java.lang.Math;
import projectClasses.interfaces.Project;

public class ProjectComparator implements Comparator<Project> {

	@Override
	public int compare(Project o1, Project o2) {
		
		return (int) Math.signum(o1.getNumber()-(o2.getNumber()));
	}

}
