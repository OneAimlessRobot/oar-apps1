package projectClasses.entities;

import projectClasses.interfaces.InhouseProject;

public class InhouseProjectClass extends AbstractProject implements InhouseProject{
	

	private final int confidentialityLevel;
	public InhouseProjectClass(String name,int confidentialityLevel,String managerName,int number) {
		super(name,managerName,number);
		this.confidentialityLevel=confidentialityLevel;
	}
	@Override
	public int getConfidentialityLevel() {
		return confidentialityLevel;
	}

}
