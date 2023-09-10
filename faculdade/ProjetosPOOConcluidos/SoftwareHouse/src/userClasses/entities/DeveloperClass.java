package userClasses.entities;

import usefulEnums.Job;
import userClasses.interfaces.Developer;

public class DeveloperClass extends AbstractUser implements Developer{
	private final String managerName;
	public DeveloperClass(String name,int clearance,String managerName) {
		
		super(name);
		this.pos=Job.DEVELOPER;
		this.clearance=clearance;
		this.managerName=managerName;
		
	}
	
	public String getManagerName() {
		return managerName;
	}
}
