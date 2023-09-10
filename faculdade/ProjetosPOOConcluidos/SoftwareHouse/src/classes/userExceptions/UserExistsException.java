package classes.userExceptions;

@SuppressWarnings("serial")
public class UserExistsException extends Exception {
	private static final String NOTIFICATION="User %s already exists.\n";
	public UserExistsException() {
		super(NOTIFICATION);
		
	}

}
