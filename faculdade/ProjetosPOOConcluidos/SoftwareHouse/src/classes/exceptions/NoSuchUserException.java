package classes.exceptions;


@SuppressWarnings("serial")
public class NoSuchUserException extends Exception {

	private static final String NOTIFICATION="%s: does not exist.";
	@SuppressWarnings("resource")
	public NoSuchUserException() {
		super(NOTIFICATION);
	}
}
