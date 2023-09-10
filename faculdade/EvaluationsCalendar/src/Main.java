

import java.time.*;
import java.time.format.*;
import java.util.Scanner;
import auxClasses.*;
import dataStructures.*;

public class Main {
	private static final String WRITE_DATE_FORMAT = "yyyy-MM-dd";
	private static final String WRITE_TIME_FORMAT = "HH'h'mm";
	
	private static final String EXIT = "EXIT";//x
	private static final String HELP = "HELP";//x
	private static final String LIST_PEOPLE = "PEOPLE";//x
	private static final String ADD_PROF = "PROFESSOR";//x
	private static final String ADD_STD = "STUDENT";//x
	private static final String LIST_COURSES = "COURSES";//x
	private static final String ADD_COURSE = "COURSE";//x
	private static final String ROSTER = "ROSTER";//x
	private static final String ASSIGN_PROF = "ASSIGN";//x
	private static final String ENROL_STD = "ENROL";//x
	private static final String INTERSECTION = "INTERSECTION";
	private static final String LIST_DEADLINES = "COURSEDEADLINES";//x
	private static final String OWN_DEADLINES = "PERSONALDEADLINES";//x
	private static final String GIVE_DEADLINE = "DEADLINE";//x
	private static final String LIST_TESTS = "COURSETESTS";
	private static final String OWN_TESTS = "PERSONALTESTS";
	private static final String SCHEDULE = "SCHEDULE";
	private static final String SUP_PROF = "SUPERPROFESSOR";//x
	private static final String TOP_STRESS = "STRESSOMETER";
	
	private static final String NO_COMMAND = "Unknown command ";
	private static final String TYPE_HELP = "Type help to see available commands.";
	private static final String END = "Bye!";
	private static final String COMMANDS = "Available commands:";
	private static final String COMM_PEOPLE = "people - lists all people";
	private static final String COMM_PROF = "professor - adds a new professor";
	private static final String COMM_STD = "student - adds a new student";
	private static final String COMM_COURSES = "courses - lists all courses";
	private static final String COMM_COURSE = "course - adds a new course";
	private static final String COMM_ROSTER = "roster - lists the professors and students of a course";
	private static final String COMM_ASSIGN = "assign - adds a teacher to a course";
	private static final String COMM_ENROL = "enrol - adds students to a course";
	private static final String COMM_INTERSEC = "intersection - lists all the people involved in all the given courses";
	private static final String COMM_COURSEDEADL = "coursedeadlines - lists all deadlines in a given course";
	private static final String COMM_PERSONALDEADL = "personaldeadlines - lists all the deadlines of a given person";
	private static final String COMM_DEADLINE = "deadline - adds a new deadline";
	private static final String COMM_COURSETESTS = "coursetests - lists all tests in a given course";
	private static final String COMM_PERSONALTESTS = "personaltests - lists all tests for a given student";
	private static final String COMM_SCHEDULE = "schedule - add a new test to a course";
	private static final String COMM_SUPERPROF = "superprofessor - presents the professor with more students";
	private static final String COMM_STRESS = "stressometer - presents the students with the top N stressful sequences of evaluations";
	private static final String COMM_HELP = "help - shows the available commands";
	private static final String COMM_EXIT = "exit - terminates the execution of the program";
	private static final String DATA_EMPTY = "No people registered!";
	private static final String ALL_PEOPLE = "All people:";
	private static final String ALL_COURSES = "All courses:";
	private static final String SUC_ADD = " added.";
	private static final String EXISTS = " already exists!";
	private static final String NUMBER_EXISTS = "There is already a student with the number ";
	private static final String NO_COURSES = "No courses registered!";
	private static final String PROFS = " professors";
	private static final String STDS = " students";
	private static final String TESTS = " tests and ";
	private static final String DEADLINES = " deadlines.";
	private static final String ROSTER_COURSE = "Roster for course ";
	private static final String ROSTER_PROF = "Professors:";
	private static final String ROSTER_STDS = "Students:";
	private static final String NOT_EXIST = " does not exist!";
	private static final String PROF = "Professor ";
	private static final String ASSIGNED = " assigned to ";
	private static final String COURSE = "Course ";
	private static final String NO_ONE = " has no assigned professors and no enrolled students.";
	private static final String ALREADY_ASSIGNED = " is already assigned to course ";
	private static final String ADDED_STUDENTS = " students added to course ";
	private static final String INADEQUATE_STDS = "Inadequate number of students!";
	private static final String STUDENT = "Student ";
	private static final String ENROLLED = " is already enrolled in course ";
	private static final String EMPTY_INTERSEC = "No professors or students to list!";
	private static final String INVALID_COURSES = "Inadequate number of courses!";
	private static final String INTERSEC = "Intersection:";
	private static final String NO_DEADLINES = "No deadlines defined for ";
	private static final String DEADLINE = "Deadline ";
	private static final String PERS_DEADL = "Deadlines for ";
	private static final String ADDED_TO = " added to ";
	private static final String DEADL_FOR_COURSE = "Deadlines for course ";
	private static final String NO_TESTS = "No scheduled tests for ";
	private static final String TESTS_PERSON = "Tests for ";
	private static final String TESTS_COURSE = "Tests for course ";
	private static final String ALREADY_TEST = " already has a test named ";
	private static final String INVALID_SCHEDULE = "Cannot schedule test ";
	private static final String TIME = " at that time!";
	private static final String NO_PROFS = "There are no professors!";
	private static final String DAYS = " days ";
	private static final String EVALUATIONS = " evaluations ";
	private static final String NO_STRESSED = "There are no stressed students right now!";
	private static final String INVALID_STDS = "Invalid number of students!";
	private static final String MOST_STRESSED = "Most stressed students:";
	
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		EvaluationsCalendar ec = new EvaluationsCalendarClass();
		String command;
		do {
			command = in.next().toUpperCase();
			executeCommand(in, ec, command);			
		} while(!command.equals(EXIT));
		in.close();
	}
	
	private static void executeCommand(Scanner in, EvaluationsCalendar ec, String command) {
		switch(command) {
			case EXIT:
				System.out.println(END);
				break;
			case HELP:
				printMenu();
				break;
			case LIST_PEOPLE:
				listPeople(ec);
				break;
			case ADD_PROF:
				addProfessor(in, ec);
				break;
			case ADD_STD:
				addStudent(in, ec);
				break;
			case LIST_COURSES:
				listCourses(ec);
				break;
			case ADD_COURSE:
				addCourse(in, ec);
				break;
			case ROSTER:
				listCoursePeople(in, ec);
				break;
			case ASSIGN_PROF:
				assignProfessor(in, ec);
				break;
			case ENROL_STD:
				enrolStudent(in, ec);
				break;
			case INTERSECTION:
				createIntersectedPeople(in, ec);
				break;
			case LIST_DEADLINES:
				listCourseDeadlines(in, ec);
				break;
			case OWN_DEADLINES:
				listPersonDeadlines(in, ec);
				break;
			case GIVE_DEADLINE:
				addDeadline(in, ec);
				break;
			case LIST_TESTS:
				listCourseTests(in, ec);
				break;
			case OWN_TESTS:
				listPersonTests(in, ec);
				break;
			case SCHEDULE:
				scheduleTest(in, ec);
				break;
			case SUP_PROF:
				printSuperprofessorName(ec);
				break;
			case TOP_STRESS:
				listMostStressedStudents(in, ec);
				break;
			default:
				System.out.println(NO_COMMAND + command + "." + " " + TYPE_HELP);
				break;			
		}
	}

	private static void printMenu() {
		System.out.println(COMMANDS);
		System.out.println(COMM_PEOPLE);
		System.out.println(COMM_PROF);
		System.out.println(COMM_STD);
		System.out.println(COMM_COURSES);
		System.out.println(COMM_COURSE);
		System.out.println(COMM_ROSTER);
		System.out.println(COMM_ASSIGN);
		System.out.println(COMM_ENROL);
		System.out.println(COMM_INTERSEC);
		System.out.println(COMM_COURSEDEADL);
		System.out.println(COMM_PERSONALDEADL);
		System.out.println(COMM_DEADLINE);
		System.out.println(COMM_COURSETESTS);
		System.out.println(COMM_PERSONALTESTS);
		System.out.println(COMM_SCHEDULE);
		System.out.println(COMM_SUPERPROF);
		System.out.println(COMM_STRESS);
		System.out.println(COMM_HELP);
		System.out.println(COMM_EXIT);
	}

	private static void listPeople(EvaluationsCalendar ec) {
		if(ec.isEmptyPeople())
			System.out.println(DATA_EMPTY);
		else {
			System.out.println(ALL_PEOPLE);
			Iterator<Person> it = ec.peopleIterator();
			while(it.hasNext()) {
				Person p = it.next();
				if(p instanceof StudentClass)
					System.out.println("[" + ((Student)p).getStudentNo() + "]" + " " + p.getName() + " "  + "(" + p.getNumCourses() + ")");
				else
					System.out.println(p.getName() + " " + "(" + p.getNumCourses() + ")");
			}
		}
				
	}

	private static void addProfessor(Scanner in, EvaluationsCalendar ec) {
		String name = in.nextLine().trim();
		if(ec.hasPerson(name))
			System.out.println(name + EXISTS);
		else {
			ec.addTeacher(name);
			System.out.println(name + SUC_ADD);
		}	
	}

	private static void addStudent(Scanner in, EvaluationsCalendar ec) {
		int number = in.nextInt();
		String name = in.nextLine().trim();
		if(ec.hasStudentNumber(number))
			System.out.println(NUMBER_EXISTS + number + "!");
		else if (ec.hasPerson(name))
			System.out.println(name + EXISTS);
		else {
			ec.addStudent(name, number);
			System.out.println(name + SUC_ADD);
		}
	}

	private static void listCourses(EvaluationsCalendar ec) {
		if(ec.isEmptyCourses())
			System.out.println(NO_COURSES);
		else {
			System.out.println(ALL_COURSES);
			Iterator<Course> it = ec.coursesIterator();
			while(it.hasNext()) {
				Course c = it.next();
				System.out.println(c.getName() + ":" + " " + c.getProfessors() + PROFS + "," + " " + c.getStudents() + STDS + "," + " " + c.getAmmountOfTests() + TESTS + c.getAmmountOfDeadlines() + DEADLINES);
			}
		}	
	}

	private static void addCourse(Scanner in, EvaluationsCalendar ec) {
		String name = in.nextLine().trim();
		if(ec.hasCourse(name))
			System.out.println(COURSE + name + EXISTS);
		else {
			ec.addCourse(name);
			System.out.println(COURSE + name + SUC_ADD);
		}		
	}

	private static void listCoursePeople(Scanner in, EvaluationsCalendar ec) {
		String course = in.nextLine().trim();
		if(!ec.hasCourse(course)) {
			System.out.println(COURSE + course + NOT_EXIST);
		}
		else if(!ec.courseHasTeachers(course) && !ec.courseHasStudents(course)) {

			System.out.println(COURSE + course + NO_ONE);
		}
		else {
			System.out.println(ROSTER_COURSE + course + ":");
			Iterator<Person> it1 = ec.teacherIterator(course);
			System.out.println(ROSTER_PROF);
			while(it1.hasNext()) {
				Person p = it1.next();
				System.out.println(p.getName());
			}
			Iterator<Person> it2 = ec.studentIterator(course);
			System.out.println(ROSTER_STDS);
			while(it2.hasNext()) {
				Person p = it2.next();
				System.out.println(((Student)p).getStudentNo() + " " + p.getName());
			}
		}			
	}

	private static void assignProfessor(Scanner in, EvaluationsCalendar ec) {
		String prof = in.nextLine().trim();
		String course = in.nextLine().trim();
		if(!ec.hasPerson(prof))
			System.out.println(PROF + prof + NOT_EXIST);
		else if(!ec.hasCourse(course))
			System.out.println(COURSE + course + NOT_EXIST);
		else if(ec.professorIsAssigned(prof, course))
			System.out.println(PROF + prof + ALREADY_ASSIGNED + course + "!");
		else {
			ec.assignTeacherToCourse(prof, course);
			System.out.println(PROF + prof + ASSIGNED + course + ".");
		}
	}

	private static void enrolStudent(Scanner in, EvaluationsCalendar ec) {
		int number = in.nextInt();
		int enrolled = number;
		Array<String> names = new ArrayClass<>();
		String course = in.nextLine().trim();
		String name;
		if(number <= 0)
			System.out.println(INADEQUATE_STDS);
		else {
			for(int i = 0; i < enrolled; i++) {
				name = in.nextLine().trim();
				names.insertLast(name);
			}
			if(!ec.hasCourse(course)) {
				System.out.println(COURSE + course + NOT_EXIST);
			}
			else {
			Iterator<String> it = names.iterator();
			while(it.hasNext() && ec.hasCourse(course)) {
				String s = it.next();			
					
					if(!ec.hasPerson(s)) {
					System.out.println(STUDENT + s + NOT_EXIST);
					enrolled--;					
					}
					else if(ec.studentIsAssigned(s, course)) {
						System.out.println(STUDENT + s + ENROLLED + course + "!");
						enrolled--;					
					}
					else {
						ec.assignStudentToCourse(s, course);						
					}
			}
			System.out.println(enrolled + ADDED_STUDENTS + course + ".");
			}
		}		
	}

	private static void createIntersectedPeople(Scanner in, EvaluationsCalendar ec) {
		ec.eraseIntersec();
		int number = in.nextInt();
		String course = in.nextLine().trim();
		if(number < 2)
			System.out.println(INVALID_COURSES);
		else {
			Array<String> aux = new ArrayClass<>();
			aux.insertLast(course);
			for(int i = 1; i < number; i++) {
				String nextCourse = in.nextLine().trim();
				aux.insertLast(nextCourse);
			}
			Iterator<String> it = aux.iterator();
			while(it.hasNext()) {
				String s = it.next();
				if(!ec.hasCourse(s)) {
					System.out.println(COURSE + s + NOT_EXIST);
					number--;
				}
			}
			if(ec.hasCourse(course) && number >= 2) {
			for(int j = 0; j < ec.getCoursePeople(course); j++) {
				Person p = ec.getPersonCourse(course, j);
				int k = 1;
				while(k < aux.size() && ec.isInBothCourses(p.getName(), course, aux.get(k))) {					
					k++;
				}
					
				if(k == aux.size()) {
					if(p instanceof Student) {
						ec.addStudentIntersec(p.getName());
					}
					else if(p instanceof Teacher)
						ec.addTeacherIntersec(p.getName());
				}
				
			}
			listIntersectedPeople(ec);
			}
			
		}
		
	}
	
	private static void listIntersectedPeople(EvaluationsCalendar ec) {
		if(!ec.areIntersectedPeople()) {
			System.out.println(EMPTY_INTERSEC);
		}
		else {
			System.out.println(INTERSEC);
			System.out.println(ROSTER_PROF);
			Iterator<Person> it1 = ec.intersecTeachers();
			while(it1.hasNext()) {
				Person p = it1.next();
				System.out.println(p.getName());
			}
			System.out.println(ROSTER_STDS);
			Iterator<Person> it2 = ec.intersecStudents();
			while(it2.hasNext()) {
				Person p = it2.next();
				System.out.println(((Student)p).getStudentNo() + " " + p.getName());
			}
		}
	}

	private static void listCourseDeadlines(Scanner in, EvaluationsCalendar ec) {	
		String course=in.nextLine().trim();
		if(!ec.hasCourse(course)) {
			System.out.println(COURSE + course + NOT_EXIST);
		}
		else if(!ec.courseHasDeadlines(course))
			System.out.println(NO_DEADLINES + course + "!");
		else {
			System.out.println(DEADL_FOR_COURSE + course + ":");
			Iterator<Evaluation> it=ec.courseDeadlineIterator(course);
		
			while(it.hasNext()) {
				Evaluation r=it.next();
				System.out.printf("%s: %s\n",r.getName(),r.getDate());
			}
		}	
	}

	private static void listPersonDeadlines(Scanner in, EvaluationsCalendar ec){
		String name=in.nextLine().trim();
		if(ec.hasPerson(name)) {
			if(ec.studentHasDeadlines(name)) {
		Iterator<Evaluation> it= ec.getPersonalDeadlines(name);
		System.out.println(PERS_DEADL + name + ":");
		while(it.hasNext()) {
			Evaluation r=it.next();
			LocalDate date=r.getDate();
			DateTimeFormatter formatterDate= DateTimeFormatter.ofPattern(WRITE_DATE_FORMAT);
			String dateAsString=formatterDate.format(date);
			System.out.println("["+ r.getCourseName()+ "]" + " "+r.getName()+": "+dateAsString );
		}
		}
			else {
				System.out.printf("No deadlines defined for %s!\n",name);
			}
		}
		else {
			System.out.printf("%s does not exist!\n",name);
		}
	}

	private static void addDeadline(Scanner in, EvaluationsCalendar ec) {
		String course =in.nextLine().trim();
		int year= in.nextInt(),month=in.nextInt(),day=in.nextInt();
		String deadlineName=in.nextLine().trim();
		if(!ec.hasCourse(course)) {
			System.out.printf("Course %s does not exist!\n",course);
			return;
		}
		else if(!ec.courseHasDeadline(course,deadlineName)) {
			
			LocalDate date= LocalDate.of(year, month, day);
			DateTimeFormatter formatterDate= DateTimeFormatter.ofPattern(WRITE_DATE_FORMAT);
			String dateAsString= formatterDate.format(date);
			ec.scheduleDeadline(date, course, deadlineName);
			System.out.printf("Deadline %s added to %s.\n", dateAsString,course);
			
		}
		else {
			System.out.printf("Deadline %s%s\n",deadlineName,EXISTS );
			return;
		}
	}

	private static void listCourseTests(Scanner in, EvaluationsCalendar ec) {
		String course=in.nextLine().trim();
		if(!ec.hasCourse(course)) {
			System.out.printf("Course %s does not exist!\n",course);

		}
		else if(!ec.courseHasTests(course)) {
			
			System.out.printf("No scheduled tests for %s!\n",course);
		}
		else {
			System.out.println(TESTS_COURSE + course + ":");
			Iterator<Evaluation> it=ec.courseTestsIterator(course);
			while(it.hasNext()) {
				Evaluation r=it.next();
				DateTimeFormatter formatterDate= DateTimeFormatter.ofPattern(WRITE_DATE_FORMAT);
				LocalDate date= r.getDate();
				LocalTime startTime =((Test) r).getStart();
				
				LocalTime endTime = (((Test)r).getEnd());
				DateTimeFormatter formatterTime = DateTimeFormatter.ofPattern(WRITE_TIME_FORMAT);
				String dateAsString=formatterDate.format(date),
						startTimeAsString=formatterTime.format(startTime),
						endTimeAsString=formatterTime.format(endTime);
				System.out.println(dateAsString + " " +startTimeAsString+"-"+endTimeAsString+": "+r.getName());
				
			}
		}
	}

	private static void listPersonTests(Scanner in, EvaluationsCalendar ec) {
		String person=in.nextLine().trim();
		if(!ec.hasPerson(person)) {
			System.out.println(STUDENT + person + NOT_EXIST);
		}
		else if(ec.countStudentTests(person) == 0)
			System.out.println(NO_TESTS + person + "!");
		else {
			System.out.println(TESTS_PERSON + person + ":");
			Iterator<Evaluation> it=ec.getPersonalTests(person);
		while(it.hasNext()) {
			Evaluation r=it.next();
			DateTimeFormatter formatterDate= DateTimeFormatter.ofPattern(WRITE_DATE_FORMAT);
			LocalDate date= r.getDate();
			LocalTime startTime =((Test) r).getStart();
			
			LocalTime endTime = (((Test)r).getEnd());
			DateTimeFormatter formatterTime = DateTimeFormatter.ofPattern(WRITE_TIME_FORMAT);
			String dateAsString=formatterDate.format(date),
					startTimeAsString=formatterTime.format(startTime),
					endTimeAsString=formatterTime.format(endTime);
			System.out.println(dateAsString +" "+startTimeAsString+"-"+endTimeAsString+": "+ r.getCourseName()+ " - "+r.getName());
			
		}
		}
		
	}

	private static void scheduleTest(Scanner in, EvaluationsCalendar ec) {
		int 
		year= in.nextInt(),month=in.nextInt(),day=in.nextInt(),
		hour=in.nextInt(),mins=in.nextInt(),
		duration=in.nextInt();
		
		String course =in.nextLine().trim();
		String testName=in.nextLine().trim();
		
		DataCarrier dc=new DataCarrier(0,0,null);

		DateTimeFormatter formatterDate = DateTimeFormatter.ofPattern(WRITE_DATE_FORMAT);
		DateTimeFormatter formatterTime = DateTimeFormatter.ofPattern(WRITE_TIME_FORMAT);
		
		LocalDate date= LocalDate.of(year, month, day);
		LocalTime startTime = LocalTime.of(hour, mins);
		LocalTime endTime = startTime.plusHours(duration);
		
		String dateAsString= formatterDate.format(date),
			   endTimeAsString= formatterTime.format(endTime),
			   startTimeAsString= formatterTime.format(startTime);
	
		if(!ec.hasCourse(course)) {
			System.out.println(COURSE + course + NOT_EXIST);
		}
		else if(ec.courseHasTest(course, testName)) {
			System.out.println(COURSE + course + ALREADY_TEST + testName + "!");
		}
		else if(ec.conflictInCourse(course,date,startTime,endTime,testName)) {
			System.out.println(INVALID_SCHEDULE + testName + TIME);
		}
			else {
			dc = ec.scheduleTest(date, startTime, endTime, course, testName);
			System.out.println(dc.getConflictType()+ " "+course+ " "+ testName+ " "+dateAsString+ " "+startTimeAsString+"-"+endTimeAsString+ " ("+ dc.getProfsInConflict()+ "," + " " + dc.getStudentsInConflict()+ ")");
		}
			
	}

	private static void printSuperprofessorName(EvaluationsCalendar ec) {
		if (!ec.hasTeachers())
			System.out.println(NO_PROFS);
		else
			System.out.println(ec.getSuperProfessorName() + " (" + ec.getSuperProfessorStudents() + ")" + ".");
		
	}

	private static void listMostStressedStudents(Scanner in, EvaluationsCalendar ec) {
		int N = in.nextInt(); in.nextLine();
		if(N <= 0) {
			System.out.println(INVALID_STDS);
		}
		else if(!ec.areStressedStudents()) {
			System.out.println(NO_STRESSED);
		}
		else {
			System.out.println(MOST_STRESSED);
			Iterator<Person> it = ec.sortedStudents();
			while(N > 0) {
				Person p = it.next();
				System.out.println(((Student)p).getStudentNo() + " " + p.getName() + " " + "(" + ((Student)p).daysEvaluations() + " " + "days" + "," + " " + ((Student)p).getConsecEvaluations() + " " + "evaluations" + ")");
				N--;
			}
		}
	}
	
}
