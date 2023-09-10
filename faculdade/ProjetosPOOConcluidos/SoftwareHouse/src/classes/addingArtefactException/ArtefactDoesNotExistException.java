package classes.addingArtefactException;

@SuppressWarnings("serial")
public class ArtefactDoesNotExistException extends Exception {

	private static final String NOTIFICATION="%s does not exist in the project.\n";
	public ArtefactDoesNotExistException() {
		super(NOTIFICATION);
		
	}
}
