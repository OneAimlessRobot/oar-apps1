package auxClasses;

import dataStructures.*;

public abstract class AbstractPerson implements Person {
	
	protected Array<Course> courses;
	protected Array<Evaluation> evaluations;
	private String name;
	protected String type="";
	
	public AbstractPerson(String name) {
		this.name=name;
		courses = new ArrayClass<>();
		evaluations = new ArrayClass<>();
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getType() {
		return this.type;
	}
	
	public boolean isInCourse(String name) {
		return courseIndexOf(name) != -1;
	}
	
	public void addCourse(Course course) {
		courses.insertLast(course);
	}
	
	public int getNumCourses() {
		return courses.size();
	}
	
	
	protected int courseIndexOf(String name) {
		Iterator<Course> it = courses.iterator();
		int currentPos = 0;
		while (it.hasNext()) {
			Course c = it.next();
			if (c.getName().equals(name))
				return currentPos;
			currentPos++;
		}
		return -1;
	}
	
	public boolean equals(Object e) {
		if(this == e) 
			return true;
		if(e == null)
			return false;
		if(!(e instanceof AbstractPerson))
			return false;
		AbstractPerson other = (AbstractPerson) e;
		if(name == null) {
			if(other.name != null)
				return false;
		} else if(!name.equals(other.name))
			return false;
		return true;
	}
	

	public int compareTeachers(Person other) {
		
		int result=0;
		if(((TeacherClass)this).getNumberOfStudents()>((TeacherClass)other).getNumberOfStudents()) {
			result=1;
		}

		else if(((TeacherClass)this).getNumberOfStudents()<((TeacherClass)other).getNumberOfStudents()) {
			result=-1;
		}
		else {
			result= ((TeacherClass)this).getName().compareTo(((TeacherClass)other).getName());
		}
		return result;
	}
	
	
	public Iterator<Course> getCourseIterator(){
		
		return this.courses.iterator();
	}
	
	@Override
	public Iterator<Evaluation> getPersonalDeadlines() {
		
		Iterator<Course> it= this.getCourseIterator();
		Array<Evaluation> tmp=new ArrayClass<>();
		
		while(it.hasNext()) {
			Course r= it.next();
			Iterator<Evaluation> it2= r.deadlinesIterator();
			while(it2.hasNext()) {
				Evaluation e=it2.next();
				tmp.insertLast(e);
			}
			
		}
		return tmp.sort().iterator();
		
	}
	
	@Override
	public Iterator<Evaluation> getPersonalTests() {
		
		Iterator<Course> it= getCourseIterator();
		Array<Evaluation> tmp=new ArrayClass<>();
		
		while(it.hasNext()) {
			Course r= it.next();
			Iterator<Evaluation> it2= r.testsIterator();
			while(it2.hasNext()) {
				Evaluation e=it2.next();
				tmp.insertLast(e);
			}
			
		}
		return tmp.sort().iterator();
		
	}
	
	public void addEvaluations() {
		evaluations = new ArrayClass<>();
		for(int i = 0; i < courses.size(); i++) {
			Iterator<Evaluation> it1 = courses.get(i).deadlinesIterator();
			while(it1.hasNext()) {
				Evaluation e1 = it1.next();
				evaluations.insertLast(e1);				
			}
			Iterator<Evaluation> it2 = courses.get(i).testsIterator();
			while(it2.hasNext()) {
				Evaluation e2 = it2.next();
				evaluations.insertLast(e2);	
			}
		}
	}
	

}
