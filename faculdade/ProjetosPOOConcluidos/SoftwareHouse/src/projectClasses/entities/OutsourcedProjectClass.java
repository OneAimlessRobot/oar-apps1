package projectClasses.entities;

import projectClasses.interfaces.OutsourcedProject;


public class OutsourcedProjectClass extends AbstractProject implements OutsourcedProject {
	
	private final String companyName;
	public OutsourcedProjectClass(String name,String companyName,String managerName,int number) {
		super(name,managerName,number);
		this.companyName=companyName;
	}
	@Override
	public String getCompanyName() {
		return companyName;
	}

}
