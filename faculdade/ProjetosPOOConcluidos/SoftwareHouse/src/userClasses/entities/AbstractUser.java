package userClasses.entities;

import java.util.Objects;

import usefulEnums.Job;
import userClasses.interfaces.User;

public abstract class AbstractUser implements User{
	
	protected String name;
	protected Job pos;
	protected int clearance;
	
	public AbstractUser(String name) {
		this.name=name;
		
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof AbstractUser)) {
			return false;
		}
		AbstractUser other = (AbstractUser) obj;
		return Objects.equals(name, other.name);
	}

	public boolean isManager() {
		return this instanceof ManagerClass;
	}

	@Override
	public Job getPos() {
		return pos;
	}
	@Override
	public int getClearance() {
		return clearance;
	}
	@Override
	public String getName() {
		return this.name;
	}
	

}
