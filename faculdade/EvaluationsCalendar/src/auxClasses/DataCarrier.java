package auxClasses;

public class DataCarrier {

private int profsInConflict, studentsInConflict;
private String conflictType;
	public DataCarrier(int profsInConflict,int studentsInConflict,String conflictType) {
		
		this.profsInConflict=profsInConflict;
		this.studentsInConflict=studentsInConflict;
		this.conflictType=conflictType;
		
	}
	public int getProfsInConflict() {
		return profsInConflict;
	}
	public int getStudentsInConflict() {
		return studentsInConflict;
	}
	public String getConflictType() {
		return conflictType;
	}

}
