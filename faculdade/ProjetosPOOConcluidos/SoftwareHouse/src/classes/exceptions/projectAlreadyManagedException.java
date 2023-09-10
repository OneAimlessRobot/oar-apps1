package classes.exceptions;

@SuppressWarnings("serial")
public class projectAlreadyManagedException extends Exception {

	private static final String NOTIFICATION="%s is managed by %s.\n";
	@SuppressWarnings("resource")
	public projectAlreadyManagedException(String projName,String managerName) {
		super(String.format(NOTIFICATION,projName,managerName));
	}
}
