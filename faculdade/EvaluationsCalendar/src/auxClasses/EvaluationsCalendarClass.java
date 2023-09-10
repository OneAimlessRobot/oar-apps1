package auxClasses;

import java.time.LocalDate;
import java.time.LocalTime;

import dataStructures.*;

public class EvaluationsCalendarClass implements EvaluationsCalendar {

	private Array<Person> people,teachers,students, intersecTeachers, intersecStudents;
	private Array<Course> courses;
	
	public EvaluationsCalendarClass() {
		
		people = new ArrayClass<>();
		courses = new ArrayClass<>();	
		teachers = new ArrayClass<>();
		students = new ArrayClass<>();
		intersecTeachers = new ArrayClass<>();
		intersecStudents = new ArrayClass<>();
	}
	
	@Override
	public void addTeacher(String name) {		
		people.insertLast(new TeacherClass(name));
		teachers.insertLast(new TeacherClass(name));		
	}

	@Override
	public Iterator<Person> peopleIterator() {
		return people.iterator();
	}	
	
	@Override
	public Iterator<Person> studentIterator(String course) {
		return courses.get(courseIndexOf(course)).studentIterator();
	}
	
	@Override
	public Iterator<Person> teacherIterator(String course) {
		return courses.get(courseIndexOf(course)).teacherIterator();
	}
	
	@Override
	public Iterator<Course> coursesIterator(){
		return courses.iterator();
	}
	
	@Override
	public int getCoursePeople(String name) {
		return (courses.get(courseIndexOf(name)).getStudents() + courses.get(courseIndexOf(name)).getProfessors());
	}
	
	@Override
	public void assignTeacherToCourse(String name, String course) {	
		courses.get(courseIndexOf(course)).addTeacher(people.get(people.searchIndexOf(new TeacherClass(name))));
		people.get(people.searchIndexOf(new TeacherClass(name))).addCourse(courses.get(courseIndexOf(course)));
		teachers.get(teachers.searchIndexOf(new TeacherClass(name))).addCourse(courses.get(courseIndexOf(course)));

	}
	
	@Override
	public void assignStudentToCourse(String name, String course) {
		courses.get(courseIndexOf(course)).addStudent(people.get(people.searchIndexOf(new StudentClass(name,0))));
		people.get(people.searchIndexOf(new StudentClass(name,0))).addCourse(courses.get(courseIndexOf(course)));
		students.get(students.searchIndexOf(new StudentClass(name,0))).addCourse(courses.get(courseIndexOf(course)));

		}
	
	
	@Override
	public boolean hasPerson(String name) {
		return people.searchIndexOf(new TeacherClass(name)) != -1;
	}
	
	public boolean hasTeachers() {
		return teachers.size() > 0;
	}
	
	@Override
	public boolean hasCourse(String name) {
		return courseIndexOf(name) != -1;
	}
	
	@Override
	public boolean isEmptyPeople() {
		return people.size() == 0;
	}
	
	@Override
	public boolean hasStudentNumber(int number) {
		return studentsIndexOfByNum(number) != -1;
	}
	
	@Override
	public int getStudentNumber(String name) {
		int n = 0;
		Iterator<Person> it = people.iterator();
		while(it.hasNext()) {
			Person p = it.next();
			if(p instanceof Student) {
				if(p.getName().equals(name))
					n = ((Student)p).getStudentNo();
			}							
		}
		return n;
	}
	
	@Override
	public boolean isEmptyCourses() {
		return courses.size() == 0;
	}
	
	@Override
	public void addCourse(String name) {
		courses.insertLast(new CourseClass(name));
		
	}
	@Override
	public boolean professorIsAssigned(String name, String course) {
		return people.get(people.searchIndexOf(new TeacherClass(name))).isInCourse(course);
	}
	
	@Override
	public boolean studentIsAssigned(String name, String course) {
		return people.get(people.searchIndexOf(new StudentClass(name,0))).isInCourse(course);
	}
	
	@Override
	public boolean courseHasDeadline(String course,String deadlineName) {		
		return courses.get(courseIndexOf(course)).hasDeadline(deadlineName);
	}
	@Override
	public boolean studentHasDeadlines(String name) {
		return countStudentDeadlines(name)>0;
	}
	@Override
	public boolean studentHasTests(String name) {
		return countStudentTests(name)>0;
	}
	@Override
	public void addStudent(String name, int number) {
		people.insertLast(new StudentClass(name, number));
		students.insertLast(new StudentClass(name, number));
	}
	
	
	
	private int studentsIndexOfByNum(int n) {
		Iterator<Person> it = students.iterator();
		int currentPos = 0;
		while (it.hasNext()) {
			Person p = it.next();
			if (((Student)p).getStudentNo() == n)
				return currentPos;
			currentPos++;
		}
		return -1;
	}
	
	private int courseIndexOf(String name) {
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
	
	@Override
	public  DataCarrier scheduleTest(LocalDate date, LocalTime start, LocalTime end, String courseName,String testName){	
		return courses.get(courseIndexOf(courseName)).scheduleTest(date, start,end, testName);	
	}
	
	@Override	
	public void scheduleDeadline(LocalDate date, String courseName,String deadlineName) {			
		courses.get(courseIndexOf(courseName)).scheduleDeadline(date,deadlineName);		
	}
	
	@Override
	public Iterator<Evaluation> courseDeadlineIterator(String courseName) {
		return courses.get(courseIndexOf(courseName)).deadlinesIterator();
	}
	
	@Override
	public Iterator<Evaluation> courseTestsIterator(String courseName) {	
		return courses.get(courseIndexOf(courseName)).testsIterator();
	}
	
	@Override
	public boolean courseHasDeadlines(String course) {
		return courses.get(courseIndexOf(course)).getAmmountOfDeadlines() > 0;
	}
	@Override
	public boolean courseHasTests(String course) {
		return courses.get(courseIndexOf(course)).getAmmountOfTests() > 0;
	}
	
	@Override
	public Person getSuperProfessor() {
		Teacher s = (Teacher)teachers.get(0);
		for(int i = 1; i < teachers.size(); i++) {
			if(((TeacherClass)teachers.get(i)).getNumberOfStudents() > s.getNumberOfStudents() ) {
				s = (Teacher)teachers.get(i);
			}
		}
		return s;									
	}
	
	@Override
	public int getSuperProfessorStudents() {
		return ((TeacherClass) getSuperProfessor()).getNumberOfStudents();
	}
	
	@Override
	public String getSuperProfessorName() {
		return getSuperProfessor().getName();
	}
	
	@Override
	public boolean courseHasTeachers(String course) {
		return courses.get(courseIndexOf(course)).hasTeachers();
	}
	
	@Override
	public boolean courseHasStudents(String course) {
		return courses.get(courseIndexOf(course)).hasStudents();
	}
	
	public boolean isInBothCourses(String name, String course1, String course2) {
		return (people.get(people.searchIndexOf(new TeacherClass(name)))).isInCourse(course1) && people.get(people.searchIndexOf(new TeacherClass(name))).isInCourse(course2);
	}
	
	
	@Override
	public void addStudentIntersec(String name) {
		intersecStudents.insertLast(people.get(people.searchIndexOf(new StudentClass(name,0))));
	}
	
	@Override
	public void addTeacherIntersec(String name) {
		intersecTeachers.insertLast(people.get(people.searchIndexOf(new TeacherClass(name))));
	}
	
	@Override
	public Person getPersonCourse(String course, int n) {
		return courses.get(courseIndexOf(course)).getPerson(n);
	}
	
	@Override
	public void eraseIntersec() {
		intersecTeachers = new ArrayClass<>();
		intersecStudents = new ArrayClass<>();
	}
	
	@Override
	public Iterator<Person> intersecStudents(){
		return intersecStudents.iterator();
	}
	
	@Override
	public Iterator<Person> intersecTeachers(){
		return intersecTeachers.iterator();
	}
	
	@Override
	public boolean areIntersectedPeople() {
		return (intersecStudents.size() > 0 || intersecTeachers.size() > 0);
	}

	@Override
	public Iterator<Evaluation> getPersonalDeadlines(String name) throws ArrayIndexOutOfBoundsException {
		return (people.get(people.searchIndexOf(new TeacherClass(name)))).getPersonalDeadlines();
		
		}
	@Override
	public Iterator<Evaluation> getPersonalTests(String name) {		
		return (people.get(people.searchIndexOf(new StudentClass(name, 0)))).getPersonalTests();
	}
	
	public int countStudentDeadlines(String name) {
		int count=0;
		Iterator<Evaluation> it = people.get(people.searchIndexOf(new TeacherClass(name))).getPersonalDeadlines();
		while(it.hasNext()) {
			Evaluation r=it.next();
			count++;
		}
		return count;
	}
	public int countStudentTests(String name) {
		int count=0;
		Iterator<Evaluation> it=people.get(people.searchIndexOf(new StudentClass(name, 0))).getPersonalTests();
		while(it.hasNext()) {
			Evaluation r=it.next();
			count++;
		}
		return count;
	}

	@Override
	public boolean courseHasTest(String course,String testName) {		
		return courses.get(courseIndexOf(course)).hasTest(testName);
	}
	
	@Override
	public boolean conflictInCourse(String course,LocalDate date,LocalTime start,LocalTime end,String testName) {
		return courses.get(courseIndexOf(course)).intersecTest(new Test(date,start,end,testName,course));
	}
	
	public Iterator<Person> sortedStudents(){
		Array<Person> aux = new ArrayClass<>();
		for(int i = 0; i < students.size(); i++) {
			aux.insertLast(students.get(i));
		}
		return aux.sort().iterator();
	}
	
	@Override
	public boolean areStressedStudents() {
		boolean res = false;
		int i = 0;
		while(i < students.size() && !res) {
			if(((Student)students.get(i)).hasEvaluations()) {
				res = true;
			}
			else
				i++;
		}
		return res;
	}

	@Override
	public boolean intersecTest(String course) {
		// TODO Auto-generated method stub
		return false;
	}
	
	
	//tanto faz ser teacher como student
//	public boolean hasPerson(String name) {
//		return people.searchForward(new Teacher(name))
	//}
	
}