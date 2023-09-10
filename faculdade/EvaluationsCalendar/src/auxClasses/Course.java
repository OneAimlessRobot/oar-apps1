package auxClasses;
import java.time.LocalDate;
import java.time.LocalTime;

import dataStructures.*;

public interface Course {

	/**
	 * Devolve um iterador com os alunos deste curso.
	 * @return
	 */
	Iterator<Person> studentIterator();
	
	/**
	 * Devolve um iterador de todos os professores deste curso.
	 * @return
	 */
	Iterator<Person> teacherIterator();
	/**
	 * Devolve o nome do curso.
	 * @return
	 */
	String getName();
	/**
	 * Adiciona um professor a este curso
	 * @param teacher
	 */
	void addTeacher(Person teacher);
	/**
	 * Adiciona um aluno ao curso.
	 * @param student
	 */
	void addStudent(Person student);

	/**
	 * Devolve o numero de estudantes inscritos neste curso.
	 * @return
	 */
	int getStudents();
	/**
	 * Devolve o numero de professores atribuidos a este curso.
	 * @return
	 */
	int getProfessors();
	/**
	 * Agenda um teste para a hora "time" do dia "date" para este curso.
	 * O teste vai ter nome "name"
	 * @param date
	 * @param time
	 * @param end
	 * @param name
	 */
	
	DataCarrier scheduleTest(LocalDate date, LocalTime start, LocalTime end, String name);

	/**
	 * Adiciona uma nova deadline ao curso
	 * @param date - data da deadline
	 * @param name - nome da deadline
	 */
	void scheduleDeadline(LocalDate date,String name);
	/**
	 * Devolve o numero de testes atualmente agendados neste curso.
	 * @return
	 */
	int getAmmountOfTests();
	/**
	 * Devolve o numero de prazos atualmente agendados neste curso
	 * @return
	 */
	int getAmmountOfDeadlines();
	/**
	 * Devolve um iterador dos testes deste curso.
	 * @return
	 */
	Iterator<Evaluation> testsIterator();
	/**
	 * Devolve um iterador dos prazos deste curso
	 * @return
	 */
	Iterator<Evaluation> deadlinesIterator();
	
	/**
	 * Verdade se existe um deadline com nome "deadlineName" agendado para este curso.
	 * Falso, caso contrario.
	 * @param deadlineName
	 * @return
	 */
	boolean hasDeadline(String deadlineName);
	
	/**
	 * Verdade se existe um deadline com nome "deadlineName" agendado para este curso.
	 * Falso, caso contrario.
	 * @param deadlineName
	 * @return
	 */
	
	/**
	 * Consulta a pessoa numa determinada posicao da coleccao de pessoas.
	 * @param n - Numero da posicao.
	 * @return - Devolve a pessoa nessa posicao.
	 */
	Person getPerson(int n);
	boolean hasTest(String testName);
	boolean equals(Course e);
	boolean hasTeachers();
	boolean hasStudents();
	boolean intersecTestWhatIsThisSuposedToDo();
	boolean intersecTest(Test test);
}
