package classes.addingDevExceptions;

public class DevAlreadyInProjectException extends Exception {

	private static final String msg="%s: already a member.";
	public DevAlreadyInProjectException() {
		super(msg);
	}
	
}
