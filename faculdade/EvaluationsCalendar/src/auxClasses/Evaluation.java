package auxClasses;

import java.time.LocalDate;

public interface Evaluation extends Comparable<Evaluation> {
	
	
	/**
	 * Devolve o nome desta avaliacao.
	 * @return
	 */
	
	String getName();
	/**
	 * Devolve um objeto do tipo LocalDate que representa a data desta Evaluation.
	 * @return
	 */
	LocalDate getDate();
	/**
	 * Devolve o nome do curso em que esta avaliacao se encontra inserida.
	 * @return
	 */
	String getCourseName();
	
	
	

}
