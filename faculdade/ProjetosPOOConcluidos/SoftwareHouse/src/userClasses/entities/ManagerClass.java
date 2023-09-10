package userClasses.entities;
import usefulEnums.Job;
import userClasses.interfaces.Manager;

public class ManagerClass extends AbstractUser implements Manager{
	
	public ManagerClass(String name,int clearance) {
		
		super(name);
		this.pos=Job.MANAGER;
		this.clearance=clearance;
	}
}
