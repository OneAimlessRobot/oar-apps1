package classes.addingDevExceptions;

@SuppressWarnings("serial")
public class NonOfUrBusinessException extends Exception {
	private static final String msg="%s: insufficient clearance level.";
	public NonOfUrBusinessException() {
		super(msg);
	}

}
