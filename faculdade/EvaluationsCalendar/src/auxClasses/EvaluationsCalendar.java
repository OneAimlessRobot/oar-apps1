package auxClasses;
import java.time.LocalDate;
import java.time.LocalTime;

import dataStructures.*;

public interface EvaluationsCalendar {
	/**
	 * Verdade se nao houverem pessoas inscritas. Falso caso contrario.
	 * @return
	 */
	boolean isEmptyPeople();
	/**
	 * Devolve true se este objeto tem professores. Falso caso contrario. 
	 * @return
	 */
	boolean hasTeachers();
	/**
	 * Verdade se houver um numero de aluno "number" registado na plataforma.
	 * Falso caso contrario.
	 * @return
	 */
	boolean hasStudentNumber(int number);
	/**
	 * Verdade se a coleccao de cursos estiver vazia.
	 * Falso caso contrario.
	 * @return
	 */
	boolean isEmptyCourses();
	
	/**
	 * Consulta o numero do aluno com um determinado nome.
	 * @param name - Nome do aluno.
	 * @return - O numero de aluno.
	 */
	int getStudentNumber(String name);
	/**
	 * Adiciona um curso de nome "name" a coleccao.
	 * pre: !hasCourse(name)
	 * pre: name!=null
	 * @param name
	 */
	void addCourse(String name);
	/**
	 * Adiciona um professor de nome "name" a coleccao.
	 * pre: !hasPerson(name)&&name!=null
	 * @param name
	 */
	void addTeacher(String name);
	/**
	 * Adiciona um aluno de nome "name" a coleccao, 
	 * pre: !hasPerson(name) && !hasStudentNumber(number) && name!=null
	 * @param name - Nome do aluno.
	 * @param number - Numero do aluno.
	 */
	void addStudent(String name, int number);
	/**
	 * Retorna um iterador dos cursos deste EvaluationsCalendar.
	 * @return
	 */
	Iterator<Course> coursesIterator();
	/**
	 * Retorna um iterador das pessoas inscritas neste EvaluationsCalendar.
	 * @return
	 */
	Iterator<Person> peopleIterator();
	/**
	 * Retorna um iterador dos estudantes inscritos num curso de nome "course".
	 * pre: hasCourse(course)
	 * @param course
	 * @return
	 */
	Iterator<Person> studentIterator(String course);
	/**
	 * Retorna um iterador dos professores inscritos num curso de nome "course".
	 * pre: hasCourse(course)
	 * @param course
	 * @return
	 */
	Iterator<Person> teacherIterator(String course);
	/**
	 * pre: hasTeacher(name) && hasCourse(course)
	 * Adiciona um Professor de nome "name" a um curso de nome "course"
	 * @param name
	 * @param course
	 */
	void assignTeacherToCourse(String name,String course);
	
	/**
	 * Calcula quantas pessoas um determinado curso tem.
	 * @param name - Nome do curso.
	 * @return - Devolve o numero de pessoas.
	 */
	int getCoursePeople(String name);
	/**
	 *  pre: hasStudent(name) && hasCourse(course)
	 * Adiciona um estudante de nome "name" a um curso de nome "course"
	 * @param name
	 * @param course
	 */
	
	void assignStudentToCourse(String name,String course);
	
	/**
	 * Devolve true se houver um professor de nome "name". Devolve false caso contrario.
	 * @return
	 */
	//boolean hasTeacher(String name);
	/**
	 * Devolve true se houver um aluno de nome "name". Devolve false caso contrario.
	 * @param name
	 * @return
	 */
	
	//boolean hasStudent(String name);

	/**
	 * Devolve true se houver um curso de nome "name". Devolve false caso contrario.
	 * name!=null
	 * @param name
	 * @return
	 */
	boolean hasCourse(String name);
	/**
	 * Verifica se uma pessoa com nome "name" existe.
	 * name!=null
	 * @param name
	 * @return
	 */
	boolean hasPerson(String name);
	/**
	 * Verifica se um curso com nome "course" ja possui um professor de nome "name" atribuido
	 * pre: hasCourse(course)&& hasPerson(name) && course!=null && name!=null
	 * @param name
	 * @param course
	 * @return
	 */
	boolean professorIsAssigned(String name, String course);
	/**
	 * Verifica se um curso com nome "course" ja possui um aluno de nome "name" inscrito
	 * pre: hasCourse(course)&& hasPerson(name) && course!=null && name!=null
	 * @param name
	 * @param course
	 * @return
	 */
	boolean studentIsAssigned(String name, String course);
	/**
	 * Verifica se a coleccao de deadlines deste curso se encontra, ou nao, vazia.
	 * pre: hasCourse(course) && course !=null
	 * @param course
	 * @return
	 */
	boolean courseHasDeadlines(String course);
	/**
	 * Verifica se a coleção de testes deste curso se encontra, ou nao, vazia.
	 * pre: hasCourse(course) && course !=null
	 * @param course
	 * @return
	 */
	boolean courseHasTests(String course);
	/**
	 * Verifica se aluno de nome "name" possui pelo menos 1 deadline.
	 * pre: hasPerson(name)  && name!=null
	 * @param name
	 * @return
	 */
	boolean studentHasDeadlines(String name);

	/**
	 * Agenda um teste para um curso de nome "courseName". 

	 * pre: courseName!=null && testName!=null && hasCourse(courseName) && duration >0
	 * @param date - Data do teste.
	 * @param start - Hora de inicio.
	 * @param end - Hora de fim.
	 * @param courseName - Nome do curso.
	 * @param testName - Nome do teste.
	 */
	DataCarrier scheduleTest(LocalDate date, LocalTime start, LocalTime end, String courseName,String testName);

	/**
	 * Agenda um novo deadline num curso.
	 * @param date - Data do deadline.
	 * @param courseName - Nome do curso.
	 * @param deadlineName - Nome do deadline.
	 */
	void scheduleDeadline(LocalDate date, String courseName,String deadlineName);
	/**
	 * Devolve um iterador dos prazos de um curso de nome "courseName"
	 * pre: hasCourse(coursName) && courseName!=null
	 * @return
	 */
	Iterator<Evaluation> courseDeadlineIterator(String courseName);
	/**
	 * Devolve um iterador dos testes de um curso de nome "courseName"
	 * pre: hasCourse(coursName) && courseName!=null
	 * @return
	 */
	Iterator<Evaluation> courseTestsIterator(String courseName);
	
	/**
	 * Verdade se o curso de nome "course" possui um prazo de nome "deadlineName" na sua coleccao
	 * Falso caso contrario.
	 * pre: hasCourse(course) && course!=null && deadlineName != null
	 * @param course
	 * @param deadlineName
	 * @return
	 */
	boolean courseHasDeadline(String course,String deadlineName);
/**
	 * Verifica se um teste de nome "testName" se encontra agendado para este EvaluationsCalendar.
	 * True caso isso se verifique. Falso, caso contrario.
	 * pre: hasCourse(course) && course!=null && deadlineName != null
	 * @param course
	 * @param testName
	 * @return
	 */
	boolean courseHasTest(String course,String testName);
	/**
	 * 
	 * @return Retorna o professor encarregado de ensinar mais alunos.
	 */
	Person getSuperProfessor();
	/**
	 * Retorna o maior numero de estudantes que um professor tem.
	 * @return
	 */
	int getSuperProfessorStudents();
	/**
	 * Retorna o nome do professor com mais alunos.
	 * @return
	 */
	String getSuperProfessorName();
	/**
	 * Devolve true se existirem Professores neste objeto. Falso caso contrario.
	 * @param course
	 * @return
	 */
	boolean courseHasTeachers(String course);
	/**
	 * Devolve true se existirem Estudantes neste objeto. Falso caso contrario.
	 * @param course
	 * @return
	 */
	boolean courseHasStudents(String course);
	
	/**
	 * Verifica se uma dada pessoa se contra em simultaneo nos cursos indicados.
	 * @param person - Nome da pessoa.
	 * @param course1 - Nome do primeiro curso.
	 * @param course2 - Nome do segundo curso.
	 * @return - Devolve true caso a pessoa esteja nos dois cursos, e false caso contrario.
	 */
	boolean isInBothCourses(String person, String course1, String course2);
	
	
	/**
	 * Adiciona um aluno que esteja em simultaneo em varios cursos.
	 * @param name - Nome do aluno.
	 */
	void addStudentIntersec(String name);
	
	/**
	 * Adiciona um professor que leccione em simultaneo varios cursos.
	 * @param name - Nome do professor.
	 */
	void addTeacherIntersec(String name);
	
	/**
	 * Devolve um iterador dos deadlines de uma pessoa
	 * pre: personName!=null
	 * @param personName - Nome da pessoa.
	 * @return
	 */
	Iterator<Evaluation> getPersonalTests(String personName);
	
	/**
	 * Lista os alunos que existem em varios cursos em simultaneo.
	 * @return Devolve os alunos dessa lista.
	 */
	Iterator<Person> intersecStudents();
	
	/**
	 * Lista os professores que existem em varios cursos em simultaneo.
	 * @return Devolve os professores dessa lista.
	 */
	Iterator<Person> intersecTeachers();
	
	/**
	 * Verifica se existem pessoas em varios cursos em simultaneo.
	 * @return Devolve true caso existam, e false caso contrario.
	 */
	boolean areIntersectedPeople();
	
	/**
	 * Devolve uma pessoa que esteja num determinado curso e numa dada posicao da coleccao.
	 * @param course - Nome do curso.
	 * @param n - Numero da posicao.
	 * @return - Devolve a pessoa nessa posicao.
	 */
	Person getPersonCourse(String course, int n);
	/**
	 * Devolve um iterador dos testes de uma pessoa
	 * pre: personName!=null
	 * @param personName - Nome da pessoa.
	 * @return
	 */
	Iterator<Evaluation> getPersonalDeadlines(String personName);
	/**
	 * Verifica se o estudante de nome "name" possui pelo menos 1 teste. Verdadeiro caso isto se verifique.
	 * Falso, caso contrario.
	 * pre: name!=null
	 * 
	 * @param name
	 * @return
	 */
	boolean studentHasTests(String name);
	
	/**
	 * Apaga todas as pessoas resultantes da interseccao de cursos.
	 */
	void eraseIntersec();
	
	/**
	 * Verifica se o teste a inserir intersecta algum ja existente.
	 * @param course - Nome do curso.
	 * @return
	 */
	boolean intersecTest(String course);
	
	/**
	 * Conta o numero de deadlines de um aluno.
	 * @param name - Nome do aluno.
	 * @return Devolve o n�mero de deadlines.
	 */
	int countStudentDeadlines(String name);

	/**
	 * Conta o numero de testes de um aluno.
	 * @param name - Nome do aluno.
	 * @return Devolve o n�mero de testes.
	 */
	int countStudentTests(String name);
	
	/**
	 * Lista com os alunos mais stressados.
	 * @return Devolve um iterador com os alunos mais stressados.
	 */
	Iterator<Person> sortedStudents();
	/**
	 * Verifica se existem alunos stressados.
	 * @return Devolve true caso existam, ou false caso contrario.
	 */
	boolean areStressedStudents();
	boolean conflictInCourse(String course, LocalDate date, LocalTime start, LocalTime end, String testName);
}
