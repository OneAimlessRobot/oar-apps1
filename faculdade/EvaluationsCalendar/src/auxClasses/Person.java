package auxClasses;

import dataStructures.Iterator;

public interface Person extends Comparable<Person> {
	
	/**
	 * Devolve o nome desta pessoa	
	 * @return
	 */
	String getName();
	/**
	 * Verdade se existir uma pessoa de nome "name" inscrita neste curso
	 * Falso caso contrario.
	 * pre: name!=null
	 * @param name
	 * @return
	 */
	boolean isInCourse(String name);
	/**
	 * Acrescenta um curso a coleccao.
	 * pre: course!=null
	 * @param course
	 */
	void addCourse(Course course);
	/**
	 * Devolve o numero de cursos em que esta pessoa se encontra inscrita.
	 * @return
	 */
	int getNumCourses();
	/**
	 * Retorna um iterador dos cursos em que esta Person se encontra inscrita.
	 * @return
	 */
	Iterator<Course> getCourseIterator();
	
	
	/**
	 * Retorna um iterador de testes desta pessoa
	 * @return
	 */
	Iterator<Evaluation> getPersonalTests();
	/**
	 * Retorna um iterador de deadlines desta pessoa
	 * @return
	 */
	Iterator<Evaluation> getPersonalDeadlines();
	
	
}
