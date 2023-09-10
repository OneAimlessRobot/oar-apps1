package auxClasses;
import java.time.LocalDate;
import java.time.LocalTime;

import dataStructures.*;

public class CourseClass implements Course {

	private Array<Person> teachers,students, people;
	private String name;
	private Array<Evaluation> tests,deadlines;
	
	public CourseClass(String name) {
		
		this.name=name;
		teachers=new ArrayClass<>();
		students=new ArrayClass<>();
		people=new ArrayClass<>();
		deadlines=new ArrayClass<>();
		tests=new ArrayClass<>();
		
	}
	public String getName() {
		return this.name;
	}
	
	@Override
	public Iterator<Person> studentIterator() {
		return students.iterator();
	}


	@Override
	public Iterator<Person> teacherIterator() {
		
		return teachers.iterator();
	}
	
	public boolean equals(Course e) {
		if(this == e) 
			return true;
		if(e == null)
			return false;
		if(!(e instanceof CourseClass))
			return false;
		CourseClass other = (CourseClass) e;
		if(name == null) {
			if(other.name != null)
				return false;
		} else if(!name.equals(other.name))
			return false;
		return true;
	}
	
	@Override
	public void addTeacher(Person teacher) {		
		teachers.insertLast(teacher);
		people.insertLast(teacher);
	}
	
	@Override
	public void addStudent(Person student) {		
		students.insertLast(student);
		people.insertLast(student);
	}
	
	@Override
	public int getStudents() {
		return students.size();
	}
	
	public int getProfessors() {
		return teachers.size();
	}
	
	public int getAmmountOfTests() {
		return tests.size();
	}
	
	public int getAmmountOfDeadlines() {
		return deadlines.size();
	}
	
	public DataCarrier scheduleTest(LocalDate date, LocalTime start, LocalTime end, String name) {
		tests.insertLast(new Test(date, start, end, name, this.getName()));
		int profsInConflict=0;
		int studentsInConflict=0;
		boolean thereIsConflict= false;
		String conflict ="free";
		for(int i=0;i<people.size();i++) {
			Iterator<Evaluation> it=people.get(i).getPersonalTests();
			while(it.hasNext()) {
				Test test= (Test) it.next();
				if(test.getDate().compareTo(date) == 0){
					if(test.equals(new Test(date, start, end, name, this.getName()))) {
						thereIsConflict=false;
					}
					else {
					thereIsConflict=true;
					if(!test.intersects(((Test)tests.get(tests.searchIndexOf(new Test(date,start,end,name,this.getName())))))) {
						
						if(conflict.equals("severe")) {}
						else
							conflict="mild";
					}
					//Esta a detetar como severe quando o primeiro teste e agendado porque como o teste e igual a si proprio 
					else {
						conflict="severe";
					}
					}
				}
			else{
			thereIsConflict=false;
			
			}
				}
			if(thereIsConflict) {
			if(people.get(i) instanceof TeacherClass) {
				profsInConflict++;
			}
			else if(people.get(i) instanceof Student) {
				studentsInConflict++;
			}
			}
			thereIsConflict=false;
		}
		return new DataCarrier(profsInConflict,studentsInConflict,conflict);
		}

	
	public void scheduleDeadline(LocalDate date, String name) {
		deadlines.insertLast(new Deadline(date,name,this.getName()));
	}
	
	@Override
	public Iterator<Evaluation> testsIterator() {
		
		return tests.sort().iterator();
	}
	
	@Override
	public Iterator<Evaluation> deadlinesIterator() {
		return deadlines.sort().iterator();
	}
	
	public boolean hasDeadline(String deadlineName) {	
		return deadlines.searchForward(new Deadline(null,deadlineName,""));		
	}
	
	@Override
	public boolean hasTest(String testName) {
		return testIndexOf(testName) != -1;	
	}
	
	public boolean hasTeachers() {
		return teachers.size() > 0;
	}
	
	public boolean hasStudents() {
		return students.size() > 0;
	}
	
	public Person getPerson(int n) {
		return people.get(n);
	}
	
	private int testIndexOf(String test) {
		Iterator<Evaluation> it = tests.iterator();
		int currentPos = 0;
		while (it.hasNext()) {
			Evaluation e = it.next();
			if (e.getName().equals(name))
				return currentPos;
			currentPos++;
		}
		return -1;
	}
	//Isto nao funciona como deve ser porque o que isto faz e fazer uma espécie de bubble sort que nem sequer envolve um teste novo ao barulho.
	//Pega num teste da lista de testes deste curso, itera pela própria lista e ve se esse teste interseta com os restantes elementos do vetor.
	//Faz isto para cada teste. Isto em principio nao deveria fazer nada de jeito porque nao deveria ser possivel inserir um teste nestas condicoes.
	
	public boolean intersecTestWhatIsThisSuposedToDo() {
		boolean r = false;
		int i = 0;
		while(i < tests.size() && !r) {
			int j = i+1;
			while(j < tests.size() && !r) {
				if(((Test)tests.get(i)).intersects(((Test)tests.get(j)))){
					r = true;
				}
				else
					j++;
			}
			if(!r)
				i++;
		}
		return r;
	}
	public boolean intersecTest(Test test) {
		int i = 0;
		while(i < tests.size()) {
			if(((Test)tests.get(i)).intersects(test)) {
				return true;
			}
		}
		return false;
	}
	

	
//	
//	public LocalDate getDeadlineDate(String deadlineName) {
//		LocalDate date = null;
//		Iterator<Evaluation> it = deadlines.iterator();
//		while(it.hasNext()) {
//			Evaluation e = it.next();
//			if(e.getName().equals(deadlineName))
//				date = e.getDate();
//		}							
//		return date;
//	}
	
	
}
