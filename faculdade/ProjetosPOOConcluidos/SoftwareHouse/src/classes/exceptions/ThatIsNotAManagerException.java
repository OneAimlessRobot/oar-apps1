package classes.exceptions;

@SuppressWarnings("serial")
public class ThatIsNotAManagerException extends Exception {
	private static final String msg="Project manager %s does not exist.";
	public ThatIsNotAManagerException() {
		super(msg);
	}
	
	

}
