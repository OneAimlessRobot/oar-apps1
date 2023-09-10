package classes.exceptions;

@SuppressWarnings("serial")
public class NoSuchProjectException extends Exception {

	private static final String NOTIFICATION="%s project does not exist.\n";
	@SuppressWarnings("resource")
	public NoSuchProjectException() {
		super(NOTIFICATION);
	}
}
