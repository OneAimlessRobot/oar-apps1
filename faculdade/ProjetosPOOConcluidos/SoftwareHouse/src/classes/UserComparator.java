package classes;

import java.util.Comparator;
import userClasses.interfaces.User;
public class UserComparator implements Comparator<User> {
	
	public int compare(User a,User b) {
		return a.getName().compareTo(b.getName());
	}
	
	

}
