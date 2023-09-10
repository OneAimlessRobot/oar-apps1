package auxClasses;

import java.time.LocalDate;
import java.time.LocalTime;

public class Test extends AbstractEvaluation {

	private LocalTime start;
	private LocalTime end;
	
	/**
	 * Par
	 * @param date
	 * @param startTime
	 * @param endTime
	 * @param name
	 * @param courseName
	 */
	public Test(LocalDate date,LocalTime startTime, LocalTime endTime, String name, String courseName) {
		super(date, name, courseName);
		this.start = startTime;
		this.end = endTime;
	}
	
	
	public LocalTime getStart() {
		return start;
	}
	
	
	public LocalTime getEnd() {
		return end;
	}
	
	
	public boolean intersects(Test other) {
		if(start.compareTo(other.getStart())<=0 && end.compareTo(other.getStart())>0) {
			return true;
		}
		if(start.compareTo(other.getStart())<0 && end.compareTo(other.getStart())>=0) {
			return true;
		}
		
		if(start.compareTo(other.getStart())>=0 && start.compareTo(other.getEnd()) < 0) {
			return true;
		}
		if(start.compareTo(other.getStart())>0 && start.compareTo(other.getEnd()) <= 0) {
			return true;
		}
		return false;
	}
	public boolean compareStartingTime(Test other) {
		return this.getStart().equals(other.getStart());
	}
	
}
