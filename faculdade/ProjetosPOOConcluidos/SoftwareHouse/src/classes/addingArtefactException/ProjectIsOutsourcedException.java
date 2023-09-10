package classes.addingArtefactException;

@SuppressWarnings("serial")
public class ProjectIsOutsourcedException extends Exception{

	private static final String NOTIFICATION="%s is an outsourced project.\n";
	@SuppressWarnings("resource")
	public ProjectIsOutsourcedException() {
		super(NOTIFICATION);
	}
}
