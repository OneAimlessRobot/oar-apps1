package auxClasses;

import java.time.*;

public class AbstractEvaluation implements Evaluation {

	protected String name, courseName;
	protected LocalDate date;

	public AbstractEvaluation(LocalDate date, String name, String courseName) {
		this.name = name;
		this.date = date;
		this.courseName = courseName;
	}

	public String getCourseName() {
		return this.courseName;
	}
	
	
	public boolean equals(Object e) {
		if (this == e)
			return true;
		if (e == null)
			return false;
		if (!(e instanceof AbstractEvaluation))
			return false;
		AbstractEvaluation other = (AbstractEvaluation) e;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		return true;
	}

	@Override
	public String getName() {
		return name;
	}
	
	@Override
	public LocalDate getDate() {
		return date;
	}
	
	
	public int compareTo(Evaluation other) {
		int result = 0;
		if (other == null) {
			result = -1;
		} else if (this == other) {
			result = 0;
		} else if ((this instanceof Test) && (other instanceof Test)) {
			result = ((Test) this).compareTests((Test) other);
		} else if ((this instanceof Deadline) && (other instanceof Deadline)) {
			result = ((Deadline) this).compareDeadlines((Deadline) other);
		}

		return result;
	}
	
	
	public int compareDeadlines(Evaluation other) {
		int result;
		result=this.date.compareTo(other.getDate());
		if (result==0) {
			result=this.courseName.compareTo(other.getCourseName());
			if(result == 0) {
			result=this.name.compareTo(other.getName());
		}
	}
		return result;
	}
	
	
	public int compareTests(Evaluation other) {
		int result;
		result=this.date.compareTo(other.getDate());
		if (result==0) {
			result = (((Test) this).getStart().compareTo(((Test) other).getStart()));
			if(result == 0) {
				result=this.courseName.compareTo(other.getCourseName());
			}
		}
		return result;
	}

}
