package classes.addingArtefactException;

@SuppressWarnings("serial")
public class NoSuchMemberException extends Exception {

	private static final String msg="User %s does not belong to the team of %s.\n";
	public NoSuchMemberException() {
		super(msg);
	}
	
	
}
