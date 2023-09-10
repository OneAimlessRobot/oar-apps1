package auxClasses;

import dataStructures.*;

public class TeacherClass extends AbstractPerson implements Teacher {
		
	public TeacherClass(String name) {
		super(name);
		this.type="Professor";
		
	}
	
	public int getNumberOfStudents() {
		Iterator<Course> it = courses.iterator();
		int n = 0;
		while(it.hasNext()) {
			Course c = it.next();
			n += c.getStudents();
		}
		return n;
	}
	
	public int compareTo(Person other) {
		return getName().compareTo(((Teacher)other).getName());
	}
	
}
