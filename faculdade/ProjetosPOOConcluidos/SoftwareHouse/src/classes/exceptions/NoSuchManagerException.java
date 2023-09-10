package classes.exceptions;

@SuppressWarnings("serial")
public class NoSuchManagerException extends Exception {
	private static final String msg="Project manager %s does not exist.\n";
	public NoSuchManagerException() {
		super(msg);
	}
	
	

}
