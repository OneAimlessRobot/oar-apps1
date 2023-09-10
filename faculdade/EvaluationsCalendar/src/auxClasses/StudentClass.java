package auxClasses;

import java.time.temporal.ChronoUnit;

import dataStructures.*;

public class StudentClass extends AbstractPerson implements Student {
	
	private int studentNo;
	private int maxConsecEvaluations;
	
	public StudentClass(String name, int studentNo) {
		super(name);
		type="Aluno";
		this.studentNo = studentNo;
		maxConsecEvaluations = 0;
	}
	
	@Override
	public int getStudentNo() {
		return this.studentNo;
	}

	@Override
	public int daysEvaluations() {
		addEvaluations();
		int nDays = 1;
		int max = 1;
		int consecEvaluations = 1;
		Array<Evaluation> aux = new ArrayClass<>();
		for(int i = 0; i < evaluations.size(); i++) {
			aux.insertLast(evaluations.get(i));			
		}
		aux.sort();
		for(int j = 1; j < aux.size(); j++) {
			if(ChronoUnit.DAYS.between(aux.get(j-1).getDate(), aux.get(j).getDate()) < 1) {
				consecEvaluations++;
			}
			else if(ChronoUnit.DAYS.between(aux.get(j-1).getDate(), aux.get(j).getDate()) == 1) {
				nDays++;
				consecEvaluations++;
			}
			else {
				nDays = 1;
				consecEvaluations = 1;
			}
			if(nDays > max) {
				max = nDays;
			}
			if(consecEvaluations > maxConsecEvaluations) {
				maxConsecEvaluations = consecEvaluations;
			}				
		}
		return max;
	}
	
	
	@Override
	public boolean hasEvaluations() {
		addEvaluations();
		return (evaluations.size() > 0);
	}
	
	@Override
	public int getConsecEvaluations() {
		return maxConsecEvaluations;
	}
	
	
	public int compareTo(Person other) {
		int n = this.daysEvaluations() - ((Student)other).daysEvaluations();
		if(n == 0) {
			n = maxConsecEvaluations - ((Student)other).getConsecEvaluations();
			if(n == 0) {
				n = this.getNumCourses() - other.getNumCourses();
				if(n == 0) {
					n = studentNo - ((Student)other).getStudentNo();
				}
			}
		}
		return n;
	}

	


	
}
