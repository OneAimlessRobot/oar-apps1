package auxClasses;

import dataStructures.Iterator;

public interface Student extends Person {
/**
 * Devolve o numero de estudante deste aluno
 * @return
 */
	int getStudentNo();
	
	/**
	 * Calcula o maior numero de dias consecutivos com avaliacoes.
	 * @return Devolve o numero de dias de avaliacoes consecutivas.
	 */
	int daysEvaluations();
	
	/**
	 * Verifica se um aluno tem avaliacoes marcadas.
	 * @return Devolve true caso tenha avaliacoes, e false caso contrario.
	 */
	boolean hasEvaluations();
	
	/**
	 * Retorna o maior numero de avaliacoes consecutivas de um aluno.
	 * @return Devolve o número de avaliacoes.
	 */
	int getConsecEvaluations();

	
}
