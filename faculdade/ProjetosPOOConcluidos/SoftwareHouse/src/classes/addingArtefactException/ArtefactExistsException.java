package classes.addingArtefactException;

@SuppressWarnings("serial")
public class ArtefactExistsException extends Exception {

	private static final String NOTIFICATION="%s: already in the project.";
	public ArtefactExistsException() {
		super(NOTIFICATION);
		
	}

}
