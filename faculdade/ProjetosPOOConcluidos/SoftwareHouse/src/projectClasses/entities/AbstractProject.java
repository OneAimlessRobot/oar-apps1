/**
 * 
 */
package projectClasses.entities;

import java.util.Objects;

import projectClasses.interfaces.Project;

/**
 * @author oneaimlessrobot
 *
 */
public abstract class AbstractProject implements Project {
	
	protected final String name,managerName;
	protected final int number;
	
	public AbstractProject(String name,String managerName,int number) {
		this.name=name;
		this.managerName=managerName;
		this.number=number;
	}
	public int getNumber() {
		return number;
	}

	@Override
	public String getName() {
		return name;
	}
	public String getManagerName() {
		return this.managerName;
	}
	


	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		AbstractProject other = (AbstractProject) obj;
		return Objects.equals(name, other.name);
	}
}
